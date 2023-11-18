// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->LEDR = vlTOPp->SW;
    vlTOPp->LEDG = ((7U & (IData)(vlTOPp->LEDG)) | 
                    (8U & ((IData)(vlTOPp->KEY) << 3U)));
    vlTOPp->top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i 
        = (1U & (IData)(vlTOPp->KEY));
    vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_wire 
        = ((IData)(1U) + vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg);
    vlTOPp->top__DOT__dut__DOT__timeCounter_wire = 
        (0x17d7840U == vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg);
    vlTOPp->LEDG = ((0xeU & (IData)(vlTOPp->LEDG)) 
                    | (IData)(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__doneLed_o));
    vlTOPp->LEDG = ((0xdU & (IData)(vlTOPp->LEDG)) 
                    | ((IData)(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dashLed_o) 
                       << 1U));
    vlTOPp->LEDG = ((0xbU & (IData)(vlTOPp->LEDG)) 
                    | ((IData)(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dotLed_o) 
                       << 2U));
    if (vlTOPp->top__DOT__dut__DOT__FSM__DOT__sysProcessing_Flag) {
        vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_wire 
            = vlTOPp->top__DOT__dut__DOT__FSM__DOT__codeShift_reg;
        vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_wire 
            = vlTOPp->top__DOT__dut__DOT__FSM__DOT__lengthCounter_reg;
    } else {
        vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_wire 
            = vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_reg;
        vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_wire 
            = vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_reg;
    }
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP__top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i 
        = vlTOPp->top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i;
    vlTOPp->__Vclklast__TOP__top__DOT__dut__DOT__timeCounter_wire 
        = vlTOPp->top__DOT__dut__DOT__timeCounter_wire;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk_i = VL_RAND_RESET_I(1);
    SW = VL_RAND_RESET_I(3);
    KEY = VL_RAND_RESET_I(4);
    LEDR = VL_RAND_RESET_I(3);
    LEDG = VL_RAND_RESET_I(4);
    top__DOT__dut__DOT__timeCounter_wire = VL_RAND_RESET_I(1);
    top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i = VL_RAND_RESET_I(1);
    top__DOT__dut__DOT____Vcellout__FSM__doneLed_o = VL_RAND_RESET_I(1);
    top__DOT__dut__DOT____Vcellout__FSM__dashLed_o = VL_RAND_RESET_I(1);
    top__DOT__dut__DOT____Vcellout__FSM__dotLed_o = VL_RAND_RESET_I(1);
    top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE = VL_RAND_RESET_I(4);
    top__DOT__dut__DOT__CODE_GENERATER__DOT___L = VL_RAND_RESET_I(3);
    top__DOT__dut__DOT__FSM__DOT__MorseCharacter_wire = VL_RAND_RESET_I(4);
    top__DOT__dut__DOT__FSM__DOT__MorseLength_wire = VL_RAND_RESET_I(3);
    top__DOT__dut__DOT__FSM__DOT__MorseCharacter_reg = VL_RAND_RESET_I(4);
    top__DOT__dut__DOT__FSM__DOT__MorseLength_reg = VL_RAND_RESET_I(3);
    top__DOT__dut__DOT__FSM__DOT__sysProcessing_Flag = VL_RAND_RESET_I(1);
    top__DOT__dut__DOT__FSM__DOT__codeShift_reg = VL_RAND_RESET_I(4);
    top__DOT__dut__DOT__FSM__DOT__lengthCounter_reg = VL_RAND_RESET_I(3);
    top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg = VL_RAND_RESET_I(32);
    top__DOT__dut__DOT__timeCounter__DOT__timeCounter_wire = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
