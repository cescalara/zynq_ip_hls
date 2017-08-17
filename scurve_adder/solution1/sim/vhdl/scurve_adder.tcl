
log_wave [get_objects -filter {type == in_port || type == out_port || type == inout_port || type == port} /apatb_scurve_adder_top/AESL_inst_scurve_adder/*]
set designtopgroup [add_wave_group "Design Top Signals"]
set cinoutgroup [add_wave_group "C InOuts" -into $designtopgroup]
set param__return_group [add_wave_group param__return(axi_slave) -into $cinoutgroup]
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/interrupt -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_BRESP -into $param__return_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_BREADY -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_BVALID -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_RRESP -into $param__return_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_RDATA -into $param__return_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_RREADY -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_RVALID -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_ARREADY -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_ARVALID -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_ARADDR -into $param__return_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_WSTRB -into $param__return_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_WDATA -into $param__return_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_WREADY -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_WVALID -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_AWREADY -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_AWVALID -into $param__return_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/s_axi_CTRL_BUS_AWADDR -into $param__return_group -radix hex
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set outStream_group [add_wave_group outStream(axis) -into $coutputgroup]
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TDEST -into $outStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TID -into $outStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TLAST -into $outStream_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TUSER -into $outStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TSTRB -into $outStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TKEEP -into $outStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TREADY -into $outStream_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TVALID -into $outStream_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/outStream_TDATA -into $outStream_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set inStream_group [add_wave_group inStream(axis) -into $cinputgroup]
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TDEST -into $inStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TID -into $inStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TLAST -into $inStream_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TUSER -into $inStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TSTRB -into $inStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TKEEP -into $inStream_group -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TREADY -into $inStream_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TVALID -into $inStream_group -color #ffff00 -radix hex
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/inStream_TDATA -into $inStream_group -radix hex
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/ap_rst_n -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_scurve_adder_top/AESL_inst_scurve_adder/ap_clk -into $clockgroup
save_wave_config scurve_adder.wcfg
run all
quit

