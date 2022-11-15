// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__top__DOT__clock_tick__DOT__count;
    // Body
    __Vdly__top__DOT__clock_tick__DOT__count = vlSelf->top__DOT__clock_tick__DOT__count;
    if (vlSelf->rst) {
        vlSelf->top__DOT__tick = 0U;
        __Vdly__top__DOT__clock_tick__DOT__count = vlSelf->N;
    } else if (vlSelf->en) {
        if ((0U == (IData)(vlSelf->top__DOT__clock_tick__DOT__count))) {
            vlSelf->top__DOT__tick = 1U;
            __Vdly__top__DOT__clock_tick__DOT__count 
                = vlSelf->N;
        } else {
            __Vdly__top__DOT__clock_tick__DOT__count 
                = (0xffffU & ((IData)(vlSelf->top__DOT__clock_tick__DOT__count) 
                              - (IData)(1U)));
            vlSelf->top__DOT__tick = 0U;
        }
    }
    vlSelf->top__DOT__clock_tick__DOT__count = __Vdly__top__DOT__clock_tick__DOT__count;
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__f1__DOT__current_state = ((IData)(vlSelf->rst)
                                                 ? 0U
                                                 : vlSelf->top__DOT__f1__DOT__next_state);
    vlSelf->data_out = (((((((((0U == vlSelf->top__DOT__f1__DOT__current_state) 
                               | (1U == vlSelf->top__DOT__f1__DOT__current_state)) 
                              | (2U == vlSelf->top__DOT__f1__DOT__current_state)) 
                             | (3U == vlSelf->top__DOT__f1__DOT__current_state)) 
                            | (4U == vlSelf->top__DOT__f1__DOT__current_state)) 
                           | (5U == vlSelf->top__DOT__f1__DOT__current_state)) 
                          | (6U == vlSelf->top__DOT__f1__DOT__current_state)) 
                         | (7U == vlSelf->top__DOT__f1__DOT__current_state))
                         ? ((0U == vlSelf->top__DOT__f1__DOT__current_state)
                             ? 0U : ((1U == vlSelf->top__DOT__f1__DOT__current_state)
                                      ? 1U : ((2U == vlSelf->top__DOT__f1__DOT__current_state)
                                               ? 3U
                                               : ((3U 
                                                   == vlSelf->top__DOT__f1__DOT__current_state)
                                                   ? 7U
                                                   : 
                                                  ((4U 
                                                    == vlSelf->top__DOT__f1__DOT__current_state)
                                                    ? 0xfU
                                                    : 
                                                   ((5U 
                                                     == vlSelf->top__DOT__f1__DOT__current_state)
                                                     ? 0x1fU
                                                     : 
                                                    ((6U 
                                                      == vlSelf->top__DOT__f1__DOT__current_state)
                                                      ? 0x3fU
                                                      : 0x7fU)))))))
                         : ((8U == vlSelf->top__DOT__f1__DOT__current_state)
                             ? 0xffU : 0U));
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__f1__DOT__next_state = (((((((
                                                   ((0U 
                                                     == vlSelf->top__DOT__f1__DOT__current_state) 
                                                    | (1U 
                                                       == vlSelf->top__DOT__f1__DOT__current_state)) 
                                                   | (2U 
                                                      == vlSelf->top__DOT__f1__DOT__current_state)) 
                                                  | (3U 
                                                     == vlSelf->top__DOT__f1__DOT__current_state)) 
                                                 | (4U 
                                                    == vlSelf->top__DOT__f1__DOT__current_state)) 
                                                | (5U 
                                                   == vlSelf->top__DOT__f1__DOT__current_state)) 
                                               | (6U 
                                                  == vlSelf->top__DOT__f1__DOT__current_state)) 
                                              | (7U 
                                                 == vlSelf->top__DOT__f1__DOT__current_state))
                                              ? ((0U 
                                                  == vlSelf->top__DOT__f1__DOT__current_state)
                                                  ? 
                                                 ((IData)(vlSelf->en)
                                                   ? 1U
                                                   : vlSelf->top__DOT__f1__DOT__current_state)
                                                  : 
                                                 ((1U 
                                                   == vlSelf->top__DOT__f1__DOT__current_state)
                                                   ? 
                                                  ((IData)(vlSelf->en)
                                                    ? 2U
                                                    : vlSelf->top__DOT__f1__DOT__current_state)
                                                   : 
                                                  ((2U 
                                                    == vlSelf->top__DOT__f1__DOT__current_state)
                                                    ? 
                                                   ((IData)(vlSelf->en)
                                                     ? 3U
                                                     : vlSelf->top__DOT__f1__DOT__current_state)
                                                    : 
                                                   ((3U 
                                                     == vlSelf->top__DOT__f1__DOT__current_state)
                                                     ? 
                                                    ((IData)(vlSelf->en)
                                                      ? 4U
                                                      : vlSelf->top__DOT__f1__DOT__current_state)
                                                     : 
                                                    ((4U 
                                                      == vlSelf->top__DOT__f1__DOT__current_state)
                                                      ? 
                                                     ((IData)(vlSelf->en)
                                                       ? 5U
                                                       : vlSelf->top__DOT__f1__DOT__current_state)
                                                      : 
                                                     ((5U 
                                                       == vlSelf->top__DOT__f1__DOT__current_state)
                                                       ? 
                                                      ((IData)(vlSelf->en)
                                                        ? 6U
                                                        : vlSelf->top__DOT__f1__DOT__current_state)
                                                       : 
                                                      ((6U 
                                                        == vlSelf->top__DOT__f1__DOT__current_state)
                                                        ? 
                                                       ((IData)(vlSelf->en)
                                                         ? 7U
                                                         : vlSelf->top__DOT__f1__DOT__current_state)
                                                        : 
                                                       ((IData)(vlSelf->en)
                                                         ? 8U
                                                         : vlSelf->top__DOT__f1__DOT__current_state))))))))
                                              : ((8U 
                                                  == vlSelf->top__DOT__f1__DOT__current_state)
                                                  ? 
                                                 ((IData)(vlSelf->en)
                                                   ? 0U
                                                   : vlSelf->top__DOT__f1__DOT__current_state)
                                                  : 0U));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
    }
    if ((((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))) 
         | ((IData)(vlSelf->__VinpClk__TOP__top__DOT__tick) 
            & (~ (IData)(vlSelf->__Vclklast__TOP____VinpClk__TOP__top__DOT__tick))))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
    }
    Vtop___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
    vlSelf->__Vclklast__TOP____VinpClk__TOP__top__DOT__tick 
        = vlSelf->__VinpClk__TOP__top__DOT__tick;
    vlSelf->__VinpClk__TOP__top__DOT__tick = vlSelf->top__DOT__tick;
}

QData Vtop___024root___change_request_1(Vtop___024root* vlSelf);

VL_INLINE_OPT QData Vtop___024root___change_request(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request\n"); );
    // Body
    return (Vtop___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vtop___024root___change_request_1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->top__DOT__tick ^ vlSelf->__Vchglast__TOP__top__DOT__tick));
    VL_DEBUG_IF( if(__req && ((vlSelf->top__DOT__tick ^ vlSelf->__Vchglast__TOP__top__DOT__tick))) VL_DBG_MSGF("        CHANGE: top.sv:11: top.tick\n"); );
    // Final
    vlSelf->__Vchglast__TOP__top__DOT__tick = vlSelf->top__DOT__tick;
    return __req;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
}
#endif  // VL_DEBUG
