// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->top__DOT__fsmEn));
        bufp->chgBit(oldp+1,(((0U != vlSelf->top__DOT__myDelay__DOT__current_state) 
                              & ((1U != vlSelf->top__DOT__myDelay__DOT__current_state) 
                                 & (2U == vlSelf->top__DOT__myDelay__DOT__current_state)))));
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__myDelay__DOT__count),7);
        bufp->chgIData(oldp+3,(vlSelf->top__DOT__myDelay__DOT__current_state),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+4,(vlSelf->top__DOT__cmd_seq));
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__cmd_delay));
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__myLfsr__DOT__sreg),7);
        bufp->chgBit(oldp+7,(vlSelf->top__DOT__clockTick));
        bufp->chgSData(oldp+8,(vlSelf->top__DOT__clock_tick__DOT__count),16);
    }
    bufp->chgBit(oldp+9,(vlSelf->clk));
    bufp->chgBit(oldp+10,(vlSelf->rst));
    bufp->chgBit(oldp+11,(vlSelf->trigger));
    bufp->chgSData(oldp+12,(vlSelf->n),16);
    bufp->chgCData(oldp+13,(vlSelf->data_out),8);
    bufp->chgBit(oldp+14,(vlSelf->reset));
    bufp->chgIData(oldp+15,(vlSelf->top__DOT__f1__DOT__current_state),32);
    bufp->chgIData(oldp+16,(vlSelf->top__DOT__f1__DOT__next_state),32);
    bufp->chgBit(oldp+17,(vlSelf->top__DOT__f1__DOT__triggerSet));
    bufp->chgIData(oldp+18,(((0U == vlSelf->top__DOT__myDelay__DOT__current_state)
                              ? ((IData)(vlSelf->top__DOT__cmd_delay)
                                  ? 1U : vlSelf->top__DOT__myDelay__DOT__current_state)
                              : ((1U == vlSelf->top__DOT__myDelay__DOT__current_state)
                                  ? ((0U == (IData)(vlSelf->top__DOT__myDelay__DOT__count))
                                      ? 2U : vlSelf->top__DOT__myDelay__DOT__current_state)
                                  : ((2U == vlSelf->top__DOT__myDelay__DOT__current_state)
                                      ? ((IData)(vlSelf->top__DOT__cmd_delay)
                                          ? 3U : 0U)
                                      : ((3U == vlSelf->top__DOT__myDelay__DOT__current_state)
                                          ? ((IData)(vlSelf->top__DOT__cmd_delay)
                                              ? vlSelf->top__DOT__myDelay__DOT__current_state
                                              : 0U)
                                          : 0U))))),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
