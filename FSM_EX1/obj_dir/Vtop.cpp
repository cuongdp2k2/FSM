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

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->_KEY1) {
        vlTOPp->top__DOT__dut__DOT___L = ((3U & (IData)(vlTOPp->top__DOT__dut__DOT___L)) 
                                          | (4U & (
                                                   ((((~ 
                                                       ((IData)(vlTOPp->SW_i) 
                                                        >> 1U)) 
                                                      & (IData)(vlTOPp->SW_i)) 
                                                     << 2U) 
                                                    | (0xfffffffcU 
                                                       & ((((~ 
                                                             ((IData)(vlTOPp->SW_i) 
                                                              >> 2U)) 
                                                            << 2U) 
                                                           & ((IData)(vlTOPp->SW_i) 
                                                              << 1U)) 
                                                          & ((~ (IData)(vlTOPp->SW_i)) 
                                                             << 2U)))) 
                                                   | (0xfffffffcU 
                                                      & ((IData)(vlTOPp->SW_i) 
                                                         & ((IData)(vlTOPp->SW_i) 
                                                            << 2U))))));
        vlTOPp->top__DOT__dut__DOT___L = ((5U & (IData)(vlTOPp->top__DOT__dut__DOT___L)) 
                                          | (2U & (
                                                   (((((~ 
                                                        ((IData)(vlTOPp->SW_i) 
                                                         >> 2U)) 
                                                       & (~ 
                                                          ((IData)(vlTOPp->SW_i) 
                                                           >> 1U))) 
                                                      & (~ (IData)(vlTOPp->SW_i))) 
                                                     << 1U) 
                                                    | (0xfffffffeU 
                                                       & ((((~ 
                                                             ((IData)(vlTOPp->SW_i) 
                                                              >> 2U)) 
                                                            << 1U) 
                                                           & (IData)(vlTOPp->SW_i)) 
                                                          & ((IData)(vlTOPp->SW_i) 
                                                             << 1U)))) 
                                                   | (0x7ffffffeU 
                                                      & ((((IData)(vlTOPp->SW_i) 
                                                           >> 1U) 
                                                          & (IData)(vlTOPp->SW_i)) 
                                                         & ((~ (IData)(vlTOPp->SW_i)) 
                                                            << 1U))))));
        vlTOPp->top__DOT__dut__DOT___L = ((6U & (IData)(vlTOPp->top__DOT__dut__DOT___L)) 
                                          | (1U & (
                                                   (((~ 
                                                      ((IData)(vlTOPp->SW_i) 
                                                       >> 2U)) 
                                                     & ((IData)(vlTOPp->SW_i) 
                                                        >> 1U)) 
                                                    & (IData)(vlTOPp->SW_i)) 
                                                   | (((IData)(vlTOPp->SW_i) 
                                                       >> 2U) 
                                                      & (~ (IData)(vlTOPp->SW_i))))));
    }
    if (vlTOPp->_KEY1) {
        vlTOPp->top__DOT__dut__DOT___CODE = (7U & (IData)(vlTOPp->top__DOT__dut__DOT___CODE));
        vlTOPp->top__DOT__dut__DOT___CODE = ((0xbU 
                                              & (IData)(vlTOPp->top__DOT__dut__DOT___CODE)) 
                                             | (4U 
                                                & (((((~ 
                                                       ((IData)(vlTOPp->SW_i) 
                                                        >> 2U)) 
                                                      << 2U) 
                                                     & ((IData)(vlTOPp->SW_i) 
                                                        << 1U)) 
                                                    & ((~ (IData)(vlTOPp->SW_i)) 
                                                       << 2U)) 
                                                   | (((IData)(vlTOPp->SW_i) 
                                                       & ((~ 
                                                           ((IData)(vlTOPp->SW_i) 
                                                            >> 1U)) 
                                                          << 2U)) 
                                                      & ((IData)(vlTOPp->SW_i) 
                                                         << 2U)))));
        vlTOPp->top__DOT__dut__DOT___CODE = ((0xdU 
                                              & (IData)(vlTOPp->top__DOT__dut__DOT___CODE)) 
                                             | (2U 
                                                & (((((~ 
                                                       ((IData)(vlTOPp->SW_i) 
                                                        >> 2U)) 
                                                      & (~ 
                                                         ((IData)(vlTOPp->SW_i) 
                                                          >> 1U))) 
                                                     & (~ (IData)(vlTOPp->SW_i))) 
                                                    << 1U) 
                                                   | (0x7ffffffeU 
                                                      & ((((IData)(vlTOPp->SW_i) 
                                                           >> 1U) 
                                                          & (IData)(vlTOPp->SW_i)) 
                                                         & ((~ (IData)(vlTOPp->SW_i)) 
                                                            << 1U))))));
        vlTOPp->top__DOT__dut__DOT___CODE = ((0xeU 
                                              & (IData)(vlTOPp->top__DOT__dut__DOT___CODE)) 
                                             | (1U 
                                                & (((~ 
                                                     ((IData)(vlTOPp->SW_i) 
                                                      >> 2U)) 
                                                    & (IData)(vlTOPp->SW_i)) 
                                                   | (((IData)(vlTOPp->SW_i) 
                                                       >> 1U) 
                                                      & (~ (IData)(vlTOPp->SW_i))))));
    }
    vlTOPp->_L_o = vlTOPp->top__DOT__dut__DOT___L;
    vlTOPp->_CODE_o = vlTOPp->top__DOT__dut__DOT___CODE;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
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
    if (VL_UNLIKELY((SW_i & 0xf8U))) {
        Verilated::overWidthError("SW_i");}
    if (VL_UNLIKELY((_KEY1 & 0xfeU))) {
        Verilated::overWidthError("_KEY1");}
    if (VL_UNLIKELY((clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
}
#endif  // VL_DEBUG
