############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
open_project scurve_adder
set_top scurve_adder
add_files scurve_adder.cpp
add_files scurve_adder/cpp_code/v4/scurve_adder.h
add_files -tb scurve_adder/cpp_code/v4/scurve_adder_test.cpp
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 5 -name default
source "./scurve_adder/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level port -rtl vhdl -tool xsim
export_design -format ip_catalog
