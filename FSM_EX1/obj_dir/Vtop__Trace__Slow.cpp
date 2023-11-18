// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedFstC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+14,"clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+15,"SW",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+16,"KEY",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBus(c+17,"LEDR",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+18,"LEDG",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBit(c+14,"top clk_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+15,"top SW",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+16,"top KEY",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBus(c+17,"top LEDR",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+18,"top LEDG",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBit(c+14,"top dut CLOCK_50",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+15,"top dut SW",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+16,"top dut KEY",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBus(c+17,"top dut LEDR",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+18,"top dut LEDG",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBus(c+4,"top dut MorseCharacter_wire",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
        tracep->declBus(c+5,"top dut MorseLength_wire",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBit(c+1,"top dut timeCounter_wire",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+15,"top dut CODE_GENERATER SW_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBus(c+4,"top dut FSM MorseCharacter_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
        tracep->declBus(c+5,"top dut FSM MorseLength_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
        tracep->declBit(c+1,"top dut FSM timeCounter_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+19,"top dut FSM pushButton_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+8,"top dut FSM dotLed_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+9,"top dut FSM dashLed_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+10,"top dut FSM doneLed_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+20,"top dut FSM MorseCharacter_wire",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
        tracep->declBus(c+21,"top dut FSM MorseLength_wire",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBus(c+6,"top dut FSM MorseCharacter_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
        tracep->declBus(c+7,"top dut FSM MorseLength_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBit(c+11,"top dut FSM sysProcessing_Flag",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
        tracep->declBus(c+12,"top dut FSM codeShift_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 3,0);
        tracep->declBus(c+13,"top dut FSM lengthCounter_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
        tracep->declBit(c+14,"top dut timeCounter CLOCK50_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBit(c+1,"top dut timeCounter timeCounter_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
        tracep->declBus(c+2,"top dut timeCounter timeCounter_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
        tracep->declBus(c+3,"top dut timeCounter timeCounter_wire",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    }
}

void Vtop::traceRegister(VerilatedFst* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->top__DOT__dut__DOT__timeCounter_wire));
        tracep->fullIData(oldp+2,(vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg),32);
        tracep->fullIData(oldp+3,(((IData)(1U) + vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg)),32);
        tracep->fullCData(oldp+4,(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE),4);
        tracep->fullCData(oldp+5,(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L),3);
        tracep->fullCData(oldp+6,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_reg),4);
        tracep->fullCData(oldp+7,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_reg),3);
        tracep->fullBit(oldp+8,(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dotLed_o));
        tracep->fullBit(oldp+9,(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dashLed_o));
        tracep->fullBit(oldp+10,(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__doneLed_o));
        tracep->fullBit(oldp+11,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__sysProcessing_Flag));
        tracep->fullCData(oldp+12,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__codeShift_reg),4);
        tracep->fullCData(oldp+13,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__lengthCounter_reg),3);
        tracep->fullBit(oldp+14,(vlTOPp->clk_i));
        tracep->fullCData(oldp+15,(vlTOPp->SW),3);
        tracep->fullCData(oldp+16,(vlTOPp->KEY),4);
        tracep->fullCData(oldp+17,(vlTOPp->LEDR),3);
        tracep->fullCData(oldp+18,(vlTOPp->LEDG),4);
        tracep->fullBit(oldp+19,(vlTOPp->top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i));
        tracep->fullCData(oldp+20,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_wire),4);
        tracep->fullCData(oldp+21,(((IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__sysProcessing_Flag)
                                     ? (IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__lengthCounter_reg)
                                     : (IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_reg))),3);
    }
}
