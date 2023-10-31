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
    vlTOPp->z_o = ((0x10U == (IData)(vlTOPp->top__DOT__dut__DOT__Stage_wire)) 
                   | (0x100U == (IData)(vlTOPp->top__DOT__dut__DOT__Stage_wire)));
    vlTOPp->Stage_o = vlTOPp->top__DOT__dut__DOT__Stage_wire;
}

VL_INLINE_OPT void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__dut__DOT__Stage_wire = ((IData)(vlTOPp->res_ni)
                                               ? ((
                                                   (((((((1U 
                                                          == (IData)(vlTOPp->Stage_o)) 
                                                         | (2U 
                                                            == (IData)(vlTOPp->Stage_o))) 
                                                        | (4U 
                                                           == (IData)(vlTOPp->Stage_o))) 
                                                       | (8U 
                                                          == (IData)(vlTOPp->Stage_o))) 
                                                      | (0x10U 
                                                         == (IData)(vlTOPp->Stage_o))) 
                                                     | (0x20U 
                                                        == (IData)(vlTOPp->Stage_o))) 
                                                    | (0x40U 
                                                       == (IData)(vlTOPp->Stage_o))) 
                                                   | (0x80U 
                                                      == (IData)(vlTOPp->Stage_o)))
                                                   ? 
                                                  ((1U 
                                                    == (IData)(vlTOPp->Stage_o))
                                                    ? 
                                                   ((IData)(vlTOPp->w_i)
                                                     ? 0x20U
                                                     : 2U)
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlTOPp->Stage_o))
                                                     ? 
                                                    ((IData)(vlTOPp->w_i)
                                                      ? 0x20U
                                                      : 4U)
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->Stage_o))
                                                      ? 
                                                     ((IData)(vlTOPp->w_i)
                                                       ? 0x20U
                                                       : 8U)
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->Stage_o))
                                                       ? 
                                                      ((IData)(vlTOPp->w_i)
                                                        ? 0x20U
                                                        : 0x10U)
                                                       : 
                                                      ((0x10U 
                                                        == (IData)(vlTOPp->Stage_o))
                                                        ? 
                                                       ((IData)(vlTOPp->w_i)
                                                         ? 0x20U
                                                         : 0x10U)
                                                        : 
                                                       ((0x20U 
                                                         == (IData)(vlTOPp->Stage_o))
                                                         ? 
                                                        ((IData)(vlTOPp->w_i)
                                                          ? 0x40U
                                                          : 2U)
                                                         : 
                                                        ((0x40U 
                                                          == (IData)(vlTOPp->Stage_o))
                                                          ? 
                                                         ((IData)(vlTOPp->w_i)
                                                           ? 0x80U
                                                           : 2U)
                                                          : 
                                                         ((IData)(vlTOPp->w_i)
                                                           ? 0x100U
                                                           : 2U))))))))
                                                   : 
                                                  ((0x100U 
                                                    == (IData)(vlTOPp->Stage_o))
                                                    ? 
                                                   ((IData)(vlTOPp->w_i)
                                                     ? 0x100U
                                                     : 2U)
                                                    : 1U))
                                               : 1U);
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
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
    if (VL_UNLIKELY((clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((w_i & 0xfeU))) {
        Verilated::overWidthError("w_i");}
    if (VL_UNLIKELY((res_ni & 0xfeU))) {
        Verilated::overWidthError("res_ni");}
}
#endif  // VL_DEBUG
