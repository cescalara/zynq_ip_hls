#include <hls_stream.h>
#include "ap_axi_sdata.h"


//Declare types
typedef ap_axis<32,2,5,6> intSdCh_32;
typedef ap_axis<16,2,5,6> intSdCh_16;
typedef unsigned char uint8_t;


void scurve_adder(hls::stream<intSdCh_16> &inStream, hls::stream<intSdCh_32> &outStream) {

	//Define the interfaces
#pragma HLS INTERFACE axis port=inStream
#pragma HLS INTERFACE axis port=outStream
//#pragma HLS INTERFACE s_axilite port=param bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS

	int i, j, k, l;
	uint8_t in_pix1[192], in_pix2[192];
	int sum_pix1[192], sum_pix2[192];
	intSdCh_16 dub_pix[192];
	intSdCh_32 sum_pix_tot;

	//initialise sum_pix
	scurve_adder_label0:for (i=0; i<192; i++) {
		sum_pix1[i] = 0;
		sum_pix2[i] = 0;
	}

	//Read data and perform addition for 128 iterations
	for (j=0; j<128; j++) {

		//Make a loop over 384 different pixels for now
		scurve_adder_label1:for (k=0; k<192; k++) {

			//Read the input pixel values for 1 GTU and add to accumulator
			dub_pix[k] = inStream.read();

			//Split input into 2 separate pixels
			in_pix1[k] = dub_pix[k].data & 0xFF;
			in_pix2[k] = (dub_pix[k].data >> 8);

			//Perform accumulation for each pixel
			sum_pix1[k] += in_pix1[k];
			sum_pix2[k] += in_pix2[k];

		}
	}

	scurve_adder_label2:for (l=0; l<384; l++){
		//populate output with one int per iteration
		if (l % 2 == 0) {
			//for even l, output sum_pix2
			sum_pix_tot.data = sum_pix2[l/2];
		}
		else {
			//for even l, output sum_pix1
			sum_pix_tot.data = sum_pix1[int(l/2)];
		}
		sum_pix_tot.keep = dub_pix[0].keep;
		sum_pix_tot.strb = dub_pix[0].strb;
		sum_pix_tot.user = dub_pix[0].user;
		sum_pix_tot.last = dub_pix[0].last;
		//sum_pix_tot.last = 1;
		sum_pix_tot.id = dub_pix[0].id;
		sum_pix_tot.dest = dub_pix[0].dest;
		outStream.write(sum_pix_tot);
	}

}
