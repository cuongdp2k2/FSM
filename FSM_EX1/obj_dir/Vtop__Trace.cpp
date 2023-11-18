// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->top__DOT__dut__DOT__timeCounter_wire));
            tracep->chgIData(oldp+1,(vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg),32);
            tracep->chgIData(oldp+2,(((IData)(1U) + vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg)),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+3,(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE),4);
            tracep->chgCData(oldp+4,(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L),3);
            tracep->chgCData(oldp+5,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_reg),4);
            tracep->chgCData(oldp+6,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_reg),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+7,(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dotLed_o));
            tracep->chgBit(oldp+8,(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dashLed_o));
            tracep->chgBit(oldp+9,(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__doneLed_o));
            tracep->chgBit(oldp+10,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__sysProcessing_Flag));
            tracep->chgCData(oldp+11,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__codeShift_reg),4);
            tracep->chgCData(oldp+12,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__lengthCounter_reg),3);
        }
        tracep->chgBit(oldp+13,(vlTOPp->clk_i));
        tracep->chgCData(oldp+14,(vlTOPp->SW),3);
        tracep->chgCData(oldp+15,(vlTOPp->KEY),4);
        tracep->chgCData(oldp+16,(vlTOPp->LEDR),3);
        tracep->chgCData(oldp+17,(vlTOPp->LEDG),4);
        tracep->chgBit(oldp+18,(vlTOPp->top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i));
        tracep->chgCData(oldp+19,(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_wire),4);
        tracep->chgCData(oldp+20,(((IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__sysProcessing_Flag)
                                    ? (IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__lengthCounter_reg)
                                    : (IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_reg))),3);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedFst* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
