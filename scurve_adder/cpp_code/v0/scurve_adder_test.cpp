#include <stdio.h>
#include <hls_stream.h>
#include "ap_axi_sdata.h"

typedef ap_axis<32,2,5,6> intSdCh_32;
typedef ap_axis<16,2,5,6> intSdCh_16;


void scurve_adder(hls::stream<intSdCh_16> &inStream, hls::stream<intSdCh_32> &outStream);

int main() {
	hls::stream<intSdCh_16> inputStream_SW;
	hls::stream<intSdCh_16> inputStream_HW;
	hls::stream<intSdCh_32> outputStream_SW;
	hls::stream<intSdCh_32> outputStream_HW;
	uint16_t concat;
	int error_count;

//Populate the input stream for 128 GTUs (386 pixels x 128 GTU = 49408 inputs in the stream)
	for (uint8_t i=0; i<49408; i+=2) {
		intSdCh_16 A;
		intSdCh_16 A_SW;
		concat = (i << 8) | ((i+1) & 0xff);
		A.data = concat;
		A.keep = 1;
		A.strb = 1;
		A.user = 1;
		A.id = 0;
		A.dest = 0;
		//A.last = 0;
		A_SW.data = concat;
		A_SW.keep = 1;
		A_SW.strb = 1;
		A_SW.user = 1;
		A_SW.id = 0;
		A_SW.dest = 0;
		//A_SW.last = 0;
		inputStream_SW << A_SW;
		inputStream_HW << A;
		//printf("Input is %d | %d \n", (concat & 0xFF), (concat >> 8));
		//printf("Input in stream is %d | %d\n", ((int)A.data & 0xFF), ((int)A.data >> 8));
	}

	//Create the expected output
	//-------------------------------------------------------------------------
	int ii, j, k, l;
	uint8_t in_pix1[192], in_pix2[192];
	uint32_t sum_pix1[192], sum_pix2[192];
	intSdCh_16 dub_pix[192];
	intSdCh_32 sum_pix_tot;

	//initialise sum_pix
	for (ii=0; ii<192; ii++) {
		sum_pix1[ii] = 0;
		sum_pix2[ii] = 0;
	}

	//Read data and perform addition for 128 iterations
	for (j=0; j<128; j++) {

		//Make a loop over 16 different pixels for now
		for (k=0; k<192; k++) {

			//Read the input pixel values for 1 GTU and add to accumulator
			dub_pix[k] = inputStream_SW.read();

			//Split input into 2 separate pixels
			in_pix1[k] = dub_pix[k].data & 0xFF;
			in_pix2[k] = (dub_pix[k].data >> 8);

			//Perform accumulation for each pixel
			sum_pix1[k] += in_pix1[k];
			sum_pix2[k] += in_pix2[k];

		}
	}

	for (l=0; l<384; l++){
		//populate output with one int per iteration
		if (l % 2 == 0) {
			//for even l, output sum_pix2
			sum_pix_tot.data = sum_pix2[l/2];
		}
		else {
			//for even l, output sum_pix2
			sum_pix_tot.data = sum_pix1[int(l/2)];
		}
		sum_pix_tot.keep = dub_pix[0].keep;
		sum_pix_tot.strb = dub_pix[0].strb;
		sum_pix_tot.user = dub_pix[0].user;
		sum_pix_tot.last = dub_pix[0].last;
		sum_pix_tot.id = dub_pix[0].id;
		sum_pix_tot.dest = dub_pix[0].dest;
		outputStream_SW.write(sum_pix_tot);
	}
	//----------------------------------------------------------------------


	//Call the function implemented in IP for 128 GTU
	scurve_adder(inputStream_HW, outputStream_HW);

	//Read the output and test
	for (int j=0; j<384; j++) {
		intSdCh_32 B_HW;
		intSdCh_32 B_SW;
		outputStream_HW.read(B_HW);
		outputStream_SW.read(B_SW);

		if (B_HW.data != B_SW.data) {
			error_count++;
		}
		else {

		}
	}

	if (error_count == 0) {
		printf("TEST PASSED!\n");
	}
	else {
		printf("TEST FAILED!\n");
	}

	return error_count;
}
