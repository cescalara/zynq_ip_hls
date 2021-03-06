#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("in_stream_TDATA", 32, hls_in, 0, "axis", "in_data", 1),
	Port_Property("in_stream_TVALID", 1, hls_in, 6, "axis", "in_vld", 1),
	Port_Property("in_stream_TREADY", 1, hls_out, 6, "axis", "in_acc", 1),
	Port_Property("in_stream_TKEEP", 4, hls_in, 1, "axis", "in_data", 1),
	Port_Property("in_stream_TSTRB", 4, hls_in, 2, "axis", "in_data", 1),
	Port_Property("in_stream_TUSER", 2, hls_in, 3, "axis", "in_data", 1),
	Port_Property("in_stream_TLAST", 1, hls_in, 4, "axis", "in_data", 1),
	Port_Property("in_stream_TID", 5, hls_in, 5, "axis", "in_data", 1),
	Port_Property("in_stream_TDEST", 6, hls_in, 6, "axis", "in_data", 1),
	Port_Property("out_stream_TDATA", 64, hls_out, 7, "axis", "out_data", 1),
	Port_Property("out_stream_TVALID", 1, hls_out, 13, "axis", "out_vld", 1),
	Port_Property("out_stream_TREADY", 1, hls_in, 13, "axis", "out_acc", 1),
	Port_Property("out_stream_TKEEP", 8, hls_out, 8, "axis", "out_data", 1),
	Port_Property("out_stream_TSTRB", 8, hls_out, 9, "axis", "out_data", 1),
	Port_Property("out_stream_TUSER", 2, hls_out, 10, "axis", "out_data", 1),
	Port_Property("out_stream_TLAST", 1, hls_out, 11, "axis", "out_data", 1),
	Port_Property("out_stream_TID", 5, hls_out, 12, "axis", "out_data", 1),
	Port_Property("out_stream_TDEST", 6, hls_out, 13, "axis", "out_data", 1),
	Port_Property("double_trig", 32, hls_out, 17, "ap_ovld", "out_data", 1),
	Port_Property("double_trig_ap_vld", 1, hls_out, 17, "ap_ovld", "out_vld", 1),
	Port_Property("trig_data", 32, hls_out, 18, "ap_ovld", "out_data", 1),
	Port_Property("trig_data_ap_vld", 1, hls_out, 18, "ap_ovld", "out_vld", 1),
	Port_Property("trig_pixel", 32, hls_out, 19, "ap_ovld", "out_data", 1),
	Port_Property("trig_pixel_ap_vld", 1, hls_out, 19, "ap_ovld", "out_vld", 1),
	Port_Property("s_axi_CTRL_BUS_AWVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_AWREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_AWADDR", 6, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_WVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_WREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_WDATA", 32, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_WSTRB", 4, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_ARVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_ARREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_ARADDR", 6, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_RVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_RREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_RDATA", 32, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_RRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_BVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_BREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CTRL_BUS_BRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("interrupt", 1, hls_out, -1, "", "", 1),
};
const char* HLS_Design_Meta::dut_name = "l2_trigger";
