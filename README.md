# zynq_ip_hls

Custom IP for the Mini-EUSO PDM-DP Zynq system. 
This code is designed to run on the Xilinx Zynq XC7Z030 ARM + FPGA architecture. 
This IP is used in the FPGA firmware of the front-end data acquisition of Mini-EUSO, 
see [the pdm_zynq_board project](https://github.com/aabcompass/pdm_zynq_board).

## l2_trigger

This is the level 2 trigger of the Mini-EUSO data acquisition system, 
optimised for the detection of 100 us - ms UV phenomena in the Earth's atmosphere. For more information see: 
*Belov, A. et al., 2017. The integration and testing of the Mini-EUSO multi-level trigger system. arXiv.org, astro-ph.IM.*  

The advantage of the HLS design over previous triggers implemented in EUSO projects is the fast development time and ability 
to easily add configuration parameters to the completed design. A potential disadvantage of this method is larger resource 
utilisation when very high throughput is required (us scale triggering), however with a simplified algorithm and careful use 
of dataflow optimisation this approach could also be effective for the development of triggers with stricter requirements on
execution time.

To validate the HLS trigger, it will be compared and tested against a pure VHDL implementation. 

The basic functionality of the L2 trigger IP has been tested using 
[a custom designed hardware testbench](https://github.com/cescalara/l2trigger_hw_testbench), 
which allows to simulate the data flow of the full firmware and check the trigger behaviour using the Vivado chipscope.
Additionally, the L2 trigger has also been tested successfully using a variety of light sources at the TurLab facility in 
the University of Turin. The results will be published in the future. 

The Mini-EUSO trigger algorithm is summarised below:

![The Mini-EUSO trigger](https://github.com/cescalara/zynq_ip_hls/blob/master/images/trigger.png)



## scurve_adder

This is a simple IP block used to sum data in batches of 128 GTU in various parts of the full firmware project. 
Data is input as a 16bit AXI4 stream with each 16bit entry containing 2 8bit unsigned int data entries for efficiency. 
The output behaves similarly but instead using a 32bit AXI4 stream to handle the larger summed ints. Loops are pipelined to 
avoid throttling of the data and to optimise the throughput. 

the code was designed to be used to perform in-FPGA calculation of the S-curves (basically PMT threshold scans). This allows   for fast S-curve calculations (useful when testing and characterising PMTs in the lab) and also minimises the filesize of a single S-curve on disk without the need for any post-processing during the mission.
