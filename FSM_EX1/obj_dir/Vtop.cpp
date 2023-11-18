// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->LEDR = vlTOPp->SW;
    vlTOPp->LEDG = ((7U & (IData)(vlTOPp->LEDG)) | 
                    (8U & ((IData)(vlTOPp->KEY) << 3U)));
    vlTOPp->top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i 
        = (1U & (IData)(vlTOPp->KEY));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg 
        = ((0x17d7840U == vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_wire)
            ? 0U : vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_wire);
    vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_wire 
        = ((IData)(1U) + vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg);
    vlTOPp->top__DOT__dut__DOT__timeCounter_wire = 
        (0x17d7840U == vlTOPp->top__DOT__dut__DOT__timeCounter__DOT__timeCounter_reg);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_reg 
        = vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L;
    vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_reg 
        = vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE;
    vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L 
        = ((3U & (IData)(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L)) 
           | (4U & (((((~ ((IData)(vlTOPp->SW) >> 1U)) 
                       & (IData)(vlTOPp->SW)) << 2U) 
                     | (0xfffffffcU & ((((~ ((IData)(vlTOPp->SW) 
                                             >> 2U)) 
                                         << 2U) & ((IData)(vlTOPp->SW) 
                                                   << 1U)) 
                                       & ((~ (IData)(vlTOPp->SW)) 
                                          << 2U)))) 
                    | (0xfffffffcU & ((IData)(vlTOPp->SW) 
                                      & ((IData)(vlTOPp->SW) 
                                         << 2U))))));
    vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L 
        = ((5U & (IData)(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L)) 
           | (2U & ((((((~ ((IData)(vlTOPp->SW) >> 2U)) 
                        & (~ ((IData)(vlTOPp->SW) >> 1U))) 
                       & (~ (IData)(vlTOPp->SW))) << 1U) 
                     | (0xfffffffeU & ((((~ ((IData)(vlTOPp->SW) 
                                             >> 2U)) 
                                         << 1U) & (IData)(vlTOPp->SW)) 
                                       & ((IData)(vlTOPp->SW) 
                                          << 1U)))) 
                    | (0x7ffffffeU & ((((IData)(vlTOPp->SW) 
                                        >> 1U) & (IData)(vlTOPp->SW)) 
                                      & ((~ (IData)(vlTOPp->SW)) 
                                         << 1U))))));
    vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L 
        = ((6U & (IData)(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___L)) 
           | (1U & ((((~ ((IData)(vlTOPp->SW) >> 2U)) 
                      & ((IData)(vlTOPp->SW) >> 1U)) 
                     & (IData)(vlTOPp->SW)) | (((IData)(vlTOPp->SW) 
                                                >> 2U) 
                                               & (~ (IData)(vlTOPp->SW))))));
    vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE 
        = (7U & (IData)(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE));
    vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE 
        = ((0xbU & (IData)(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE)) 
           | (4U & (((((~ ((IData)(vlTOPp->SW) >> 2U)) 
                       << 2U) & ((IData)(vlTOPp->SW) 
                                 << 1U)) & ((~ (IData)(vlTOPp->SW)) 
                                            << 2U)) 
                    | (((IData)(vlTOPp->SW) & ((~ ((IData)(vlTOPp->SW) 
                                                   >> 1U)) 
                                               << 2U)) 
                       & ((IData)(vlTOPp->SW) << 2U)))));
    vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE 
        = ((0xdU & (IData)(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE)) 
           | (2U & (((((~ ((IData)(vlTOPp->SW) >> 2U)) 
                       & (~ ((IData)(vlTOPp->SW) >> 1U))) 
                      & (~ (IData)(vlTOPp->SW))) << 1U) 
                    | (0x7ffffffeU & ((((IData)(vlTOPp->SW) 
                                        >> 1U) & (IData)(vlTOPp->SW)) 
                                      & ((~ (IData)(vlTOPp->SW)) 
                                         << 1U))))));
    vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE 
        = ((0xeU & (IData)(vlTOPp->top__DOT__dut__DOT__CODE_GENERATER__DOT___CODE)) 
           | (1U & (((~ ((IData)(vlTOPp->SW) >> 2U)) 
                     & (IData)(vlTOPp->SW)) | (((IData)(vlTOPp->SW) 
                                                >> 1U) 
                                               & (~ (IData)(vlTOPp->SW))))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__dut__DOT__FSM__DOT__codeShift_reg 
        = (0xfU & ((IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_wire) 
                   >> 1U));
    vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dashLed_o 
        = (1U & (IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_wire));
    vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dotLed_o 
        = (1U & (~ (IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseCharacter_wire)));
    vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__doneLed_o 
        = (1U & (~ (IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__sysProcessing_Flag)));
    vlTOPp->LEDG = ((0xdU & (IData)(vlTOPp->LEDG)) 
                    | ((IData)(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dashLed_o) 
                       << 1U));
    vlTOPp->LEDG = ((0xbU & (IData)(vlTOPp->LEDG)) 
                    | ((IData)(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__dotLed_o) 
                       << 2U));
    vlTOPp->LEDG = ((0xeU & (IData)(vlTOPp->LEDG)) 
                    | (IData)(vlTOPp->top__DOT__dut__DOT____Vcellout__FSM__doneLed_o));
    vlTOPp->top__DOT__dut__DOT__FSM__DOT__sysProcessing_Flag 
        = (0U != (IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__lengthCounter_reg));
    vlTOPp->top__DOT__dut__DOT__FSM__DOT__lengthCounter_reg 
        = (7U & ((IData)(vlTOPp->top__DOT__dut__DOT__FSM__DOT__MorseLength_wire) 
                 - (IData)(1U)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__dut__DOT__timeCounter_wire) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__dut__DOT__timeCounter_wire)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if ((((IData)(vlTOPp->top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i))) 
         | ((IData)(vlTOPp->top__DOT__dut__DOT__timeCounter_wire) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__dut__DOT__timeCounter_wire))))) {
        vlTOPp->_multiclk__TOP__6(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP__top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i 
        = vlTOPp->top__DOT__dut__DOT____Vcellinp__CODE_GENERATER___KEY_i;
    vlTOPp->__Vclklast__TOP__top__DOT__dut__DOT__timeCounter_wire 
        = vlTOPp->top__DOT__dut__DOT__timeCounter_wire;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((SW & 0xf8U))) {
        Verilated::overWidthError("SW");}
    if (VL_UNLIKELY((KEY & 0xf0U))) {
        Verilated::overWidthError("KEY");}
}
#endif  // VL_DEBUG
