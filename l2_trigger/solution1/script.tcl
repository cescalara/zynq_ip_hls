############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
############################################################
open_project l2_trigger
set_top l2_trigger
add_files l2_trigger/cpp_code/v9/l2_trigger.cpp
add_files l2_trigger/cpp_code/v9/l2_trigger.h
add_files -tb l2_trigger/cpp_code/v9/l2_trigger_test.cpp
open_solution "solution1"
set_part {xc7z030ffg676-2} -tool vivado
create_clock -period 10 -name default
#source "./l2_trigger/solution1/directives.tcl"
csim_design -setup
csynth_design
cosim_design -trace_level port -rtl vhdl
export_design -format ip_catalog
