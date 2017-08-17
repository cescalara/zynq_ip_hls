// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.2
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xscurve_adder.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XScurve_adder_CfgInitialize(XScurve_adder *InstancePtr, XScurve_adder_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_bus_BaseAddress = ConfigPtr->Ctrl_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XScurve_adder_Start(XScurve_adder *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_AP_CTRL) & 0x80;
    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XScurve_adder_IsDone(XScurve_adder *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XScurve_adder_IsIdle(XScurve_adder *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XScurve_adder_IsReady(XScurve_adder *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XScurve_adder_EnableAutoRestart(XScurve_adder *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_AP_CTRL, 0x80);
}

void XScurve_adder_DisableAutoRestart(XScurve_adder *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_AP_CTRL, 0);
}

void XScurve_adder_Set_param(XScurve_adder *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_PARAM_DATA, Data);
}

u32 XScurve_adder_Get_param(XScurve_adder *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_PARAM_DATA);
    return Data;
}

void XScurve_adder_InterruptGlobalEnable(XScurve_adder *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_GIE, 1);
}

void XScurve_adder_InterruptGlobalDisable(XScurve_adder *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_GIE, 0);
}

void XScurve_adder_InterruptEnable(XScurve_adder *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_IER);
    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_IER, Register | Mask);
}

void XScurve_adder_InterruptDisable(XScurve_adder *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_IER);
    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_IER, Register & (~Mask));
}

void XScurve_adder_InterruptClear(XScurve_adder *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XScurve_adder_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_ISR, Mask);
}

u32 XScurve_adder_InterruptGetEnabled(XScurve_adder *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_IER);
}

u32 XScurve_adder_InterruptGetStatus(XScurve_adder *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XScurve_adder_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XSCURVE_ADDER_CTRL_BUS_ADDR_ISR);
}

