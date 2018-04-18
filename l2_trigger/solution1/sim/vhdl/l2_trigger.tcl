
log_wave [get_objects -filter {type == in_port || type == out_port || type == inout_port || type == port} /apatb_l2_trigger_top/AESL_inst_l2_trigger/*]
set designtopgroup [add_wave_group "Design Top Signals"]
set cinoutgroup [add_wave_group "C InOuts" -into $designtopgroup]
set n_pixels_in_bus__N_BG__LOW_THRESH__return_group [add_wave_group n_pixels_in_bus__N_BG__LOW_THRESH__return(axi_slave) -into $cinoutgroup]
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/interrupt -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_BRESP -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_BREADY -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_BVALID -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_RRESP -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_RDATA -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_RREADY -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_RVALID -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_ARREADY -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_ARVALID -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_ARADDR -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_WSTRB -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_WDATA -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_WREADY -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_WVALID -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_AWREADY -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_AWVALID -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/s_axi_CTRL_BUS_AWADDR -into $n_pixels_in_bus__N_BG__LOW_THRESH__return_group -radix hex
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set trig_pixel_group [add_wave_group trig_pixel(wire) -into $coutputgroup]
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/trig_pixel_ap_vld -into $trig_pixel_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/trig_pixel -into $trig_pixel_group -radix hex
set trig_data_group [add_wave_group trig_data(wire) -into $coutputgroup]
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/trig_data_ap_vld -into $trig_data_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/trig_data -into $trig_data_group -radix hex
set double_trig_group [add_wave_group double_trig(wire) -into $coutputgroup]
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/double_trig_ap_vld -into $double_trig_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/double_trig -into $double_trig_group -radix hex
set out_stream_group [add_wave_group out_stream(axis) -into $coutputgroup]
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TDEST -into $out_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TID -into $out_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TLAST -into $out_stream_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TUSER -into $out_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TSTRB -into $out_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TKEEP -into $out_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TREADY -into $out_stream_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TVALID -into $out_stream_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/out_stream_TDATA -into $out_stream_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set in_stream_group [add_wave_group in_stream(axis) -into $cinputgroup]
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TDEST -into $in_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TID -into $in_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TLAST -into $in_stream_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TUSER -into $in_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TSTRB -into $in_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TKEEP -into $in_stream_group -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TREADY -into $in_stream_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TVALID -into $in_stream_group -color #ffff00 -radix hex
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/in_stream_TDATA -into $in_stream_group -radix hex
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/ap_rst_n -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_l2_trigger_top/AESL_inst_l2_trigger/ap_clk -into $clockgroup
save_wave_config l2_trigger.wcfg
run all
quit

