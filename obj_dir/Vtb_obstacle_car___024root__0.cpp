// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_obstacle_car.h for the primary calling header

#include "Vtb_obstacle_car__pch.h"

VlCoroutine Vtb_obstacle_car___024root___eval_initial__TOP__Vtiming__0(Vtb_obstacle_car___024root* vlSelf);
VlCoroutine Vtb_obstacle_car___024root___eval_initial__TOP__Vtiming__1(Vtb_obstacle_car___024root* vlSelf);

void Vtb_obstacle_car___024root___eval_initial(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_initial\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_obstacle_car___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_obstacle_car___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(Vtb_obstacle_car___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_obstacle_car___024root___eval_initial__TOP__Vtiming__0(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_obstacle_car__DOT__seen_music_start;
    tb_obstacle_car__DOT__seen_music_start = 0;
    CData/*0:0*/ tb_obstacle_car__DOT__seen_music_win;
    tb_obstacle_car__DOT__seen_music_win = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__tb_obstacle_car__DOT__unnamedblk1_2__DOT____Vrepeat1;
    __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__tb_obstacle_car__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__press_count;
    __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__press_count = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__2__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__2__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__3__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__3__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__3__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__3__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__4__condition;
    __Vtask_tb_obstacle_car__DOT__check__4__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__5__condition;
    __Vtask_tb_obstacle_car__DOT__check__5__condition = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__6__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__6__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__6__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__6__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__7__condition;
    __Vtask_tb_obstacle_car__DOT__check__7__condition = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__test_game_core_collision_and_loss__8__tb_obstacle_car__DOT__unnamedblk1_3__DOT____Vrepeat2;
    __Vtask_tb_obstacle_car__DOT__test_game_core_collision_and_loss__8__tb_obstacle_car__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__10__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__10__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__10__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__10__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__11__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__11__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__11__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__11__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__12__condition;
    __Vtask_tb_obstacle_car__DOT__check__12__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__13__condition;
    __Vtask_tb_obstacle_car__DOT__check__13__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__14__condition;
    __Vtask_tb_obstacle_car__DOT__check__14__condition = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__15__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__15__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__16__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__16__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__16__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__16__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__17__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__17__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__17__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__17__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__18__condition;
    __Vtask_tb_obstacle_car__DOT__check__18__condition = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__19__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__19__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__20__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__20__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__20__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__20__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__21__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__21__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__21__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__21__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__22__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__22__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__23__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__23__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__23__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__23__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__24__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__24__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__24__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__24__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__25__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__25__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__26__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__26__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__26__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__26__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__27__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__27__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__27__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__27__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__28__condition;
    __Vtask_tb_obstacle_car__DOT__check__28__condition = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__29__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__29__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__30__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__30__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__30__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__30__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__31__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__31__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__31__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__31__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__32__condition;
    __Vtask_tb_obstacle_car__DOT__check__32__condition = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__33__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__33__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__34__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__34__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__34__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__34__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__35__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__35__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__35__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__35__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__36__condition;
    __Vtask_tb_obstacle_car__DOT__check__36__condition = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__37__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__37__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__38__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__38__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__38__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__38__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__39__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__39__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__39__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__39__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__40__condition;
    __Vtask_tb_obstacle_car__DOT__check__40__condition = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__42__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__42__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__42__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__42__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__43__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__43__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__43__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__43__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__44__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__44__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__45__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__45__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__45__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__45__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__46__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__46__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__46__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__46__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__47__condition;
    __Vtask_tb_obstacle_car__DOT__check__47__condition = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__49__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__49__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__49__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__49__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__50__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__50__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__50__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__50__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__51__condition;
    __Vtask_tb_obstacle_car__DOT__check__51__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__52__condition;
    __Vtask_tb_obstacle_car__DOT__check__52__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__53__condition;
    __Vtask_tb_obstacle_car__DOT__check__53__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__54__condition;
    __Vtask_tb_obstacle_car__DOT__check__54__condition = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__56__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__56__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__56__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__56__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__57__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__57__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__57__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__57__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__58__condition;
    __Vtask_tb_obstacle_car__DOT__check__58__condition = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__test_game_core_victory__59__tb_obstacle_car__DOT__unnamedblk1_4__DOT____Vrepeat3;
    __Vtask_tb_obstacle_car__DOT__test_game_core_victory__59__tb_obstacle_car__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__61__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__61__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__61__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__61__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__62__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__62__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__62__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__62__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__63__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__63__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__64__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__64__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__64__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__64__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__65__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__65__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__65__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__65__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__66__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__66__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__67__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__67__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__67__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__67__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__68__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__68__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__68__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__68__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__69__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__69__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__70__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__70__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__70__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__70__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__71__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__71__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__71__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__71__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__72__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__72__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__73__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__73__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__73__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__73__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__74__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__74__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__74__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__74__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*3:0*/ __Vtask_tb_obstacle_car__DOT__pulse_key__75__value;
    __Vtask_tb_obstacle_car__DOT__pulse_key__75__value = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__76__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__76__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__76__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__76__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__77__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__77__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__77__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__77__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__78__condition;
    __Vtask_tb_obstacle_car__DOT__check__78__condition = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__80__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__80__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__80__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__80__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__81__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__81__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__81__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__81__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__82__condition;
    __Vtask_tb_obstacle_car__DOT__check__82__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__83__condition;
    __Vtask_tb_obstacle_car__DOT__check__83__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__84__condition;
    __Vtask_tb_obstacle_car__DOT__check__84__condition = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__85__condition;
    __Vtask_tb_obstacle_car__DOT__check__85__condition = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__87__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__87__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__87__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__87__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__88__cycles;
    __Vtask_tb_obstacle_car__DOT__wait_clock__88__cycles = 0;
    IData/*31:0*/ __Vtask_tb_obstacle_car__DOT__wait_clock__88__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__88__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_obstacle_car__DOT__check__89__condition;
    __Vtask_tb_obstacle_car__DOT__check__89__condition = 0;
    // Body
    __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__tb_obstacle_car__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__press_count = 0U;
    vlSelfRef.tb_obstacle_car__DOT__rst = 1U;
    vlSelfRef.tb_obstacle_car__DOT__db_key_n = 0x0fU;
    vlSelfRef.tb_obstacle_car__DOT__core_step_tick = 0U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    vlSelfRef.tb_obstacle_car__DOT__core_melody_done = 0U;
    tb_obstacle_car__DOT__seen_music_start = 0U;
    tb_obstacle_car__DOT__seen_music_win = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__2__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__2__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__2__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__2__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__rst = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__3__cycles = 2U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__3__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__3__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__3__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__3__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__3__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__3__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__press_count = 0U;
    vlSelfRef.tb_obstacle_car__DOT__db_key_n = (0x0eU 
                                                & (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_n));
    __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__tb_obstacle_car__DOT__unnamedblk1_2__DOT____Vrepeat1 = 8U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__tb_obstacle_car__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             126);
        if ((1U & (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_pressed))) {
            __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__press_count 
                = ((IData)(1U) + __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__press_count);
        }
        __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__tb_obstacle_car__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (__Vtask_tb_obstacle_car__DOT__test_key_debounce__0__tb_obstacle_car__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__4__message = "KEY1 should be held after low-active press"s;
    __Vtask_tb_obstacle_car__DOT__check__4__condition 
        = (1U & (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_held));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__4__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__4__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__5__message = "KEY1 low-active press should create one pulse"s;
    __Vtask_tb_obstacle_car__DOT__check__5__condition 
        = (1U == __Vtask_tb_obstacle_car__DOT__test_key_debounce__0__press_count);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__5__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__5__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.tb_obstacle_car__DOT__db_key_n = (1U 
                                                | (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_n));
    __Vtask_tb_obstacle_car__DOT__wait_clock__6__cycles = 6U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__6__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__6__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__6__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__6__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__6__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__6__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__7__message = "KEY1 release should clear held state"s;
    __Vtask_tb_obstacle_car__DOT__check__7__condition 
        = (1U & (~ (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_held)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__7__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__7__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__test_game_core_collision_and_loss__8__tb_obstacle_car__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    vlSelfRef.tb_obstacle_car__DOT__rst = 1U;
    vlSelfRef.tb_obstacle_car__DOT__db_key_n = 0x0fU;
    vlSelfRef.tb_obstacle_car__DOT__core_step_tick = 0U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    vlSelfRef.tb_obstacle_car__DOT__core_melody_done = 0U;
    tb_obstacle_car__DOT__seen_music_start = 0U;
    tb_obstacle_car__DOT__seen_music_win = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__10__cycles = 3U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__10__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__10__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__10__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__10__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__10__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__10__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__rst = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__11__cycles = 2U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__11__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__11__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__11__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__11__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__11__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__11__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__12__message = "game should reset to idle"s;
    __Vtask_tb_obstacle_car__DOT__check__12__condition 
        = (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__12__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__12__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__13__message = "idle should show four chances"s;
    __Vtask_tb_obstacle_car__DOT__check__13__condition 
        = (4U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_hp_count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__13__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__13__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__14__message = "car should start at column 3"s;
    __Vtask_tb_obstacle_car__DOT__check__14__condition 
        = (3U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__14__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__14__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__15__value = 4U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__15__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__16__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__16__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__16__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__16__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__16__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__16__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__16__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__17__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__17__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__17__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__17__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__17__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__17__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__17__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__18__message = "any key should start the game"s;
    __Vtask_tb_obstacle_car__DOT__check__18__condition 
        = (1U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__18__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__18__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__19__value = 2U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__19__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__20__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__20__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__20__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__20__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__20__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__20__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__20__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__21__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__21__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__21__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__21__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__21__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__21__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__21__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__22__value = 2U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__22__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__23__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__23__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__23__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__23__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__23__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__23__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__23__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__24__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__24__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__24__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__24__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__24__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__24__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__24__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__25__value = 2U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__25__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__26__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__26__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__26__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__26__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__26__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__26__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__26__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__27__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__27__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__27__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__27__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__27__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__27__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__27__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__28__message = "KEY2 should move the car left to boundary"s;
    __Vtask_tb_obstacle_car__DOT__check__28__condition 
        = (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__28__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__28__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__29__value = 2U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__29__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__30__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__30__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__30__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__30__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__30__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__30__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__30__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__31__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__31__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__31__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__31__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__31__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__31__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__31__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__32__message = "left boundary should clamp car column"s;
    __Vtask_tb_obstacle_car__DOT__check__32__condition 
        = (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__32__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__32__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__33__value = 1U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__33__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__34__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__34__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__34__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__34__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__34__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__34__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__34__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__35__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__35__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__35__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__35__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__35__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__35__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__35__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__36__message = "KEY1 should move the car right"s;
    __Vtask_tb_obstacle_car__DOT__check__36__condition 
        = (1U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__36__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__36__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__37__value = 3U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__37__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__38__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__38__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__38__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__38__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__38__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__38__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__38__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__39__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__39__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__39__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__39__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__39__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__39__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__39__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__40__message = "simultaneous left/right should not move"s;
    __Vtask_tb_obstacle_car__DOT__check__40__condition 
        = (1U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__40__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__40__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.tb_obstacle_car__DOT__rst = 1U;
    vlSelfRef.tb_obstacle_car__DOT__db_key_n = 0x0fU;
    vlSelfRef.tb_obstacle_car__DOT__core_step_tick = 0U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    vlSelfRef.tb_obstacle_car__DOT__core_melody_done = 0U;
    tb_obstacle_car__DOT__seen_music_start = 0U;
    tb_obstacle_car__DOT__seen_music_win = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__42__cycles = 3U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__42__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__42__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__42__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__42__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__42__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__42__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__rst = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__43__cycles = 2U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__43__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__43__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__43__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__43__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__43__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__43__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__44__value = 8U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__44__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__45__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__45__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__45__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__45__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__45__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__45__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__45__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__46__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__46__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__46__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__46__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__46__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__46__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__46__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__47__message = "KEY4 should also start the game"s;
    __Vtask_tb_obstacle_car__DOT__check__47__condition 
        = (1U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__47__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__47__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__test_game_core_collision_and_loss__8__tb_obstacle_car__DOT__unnamedblk1_3__DOT____Vrepeat2 = 6U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__test_game_core_collision_and_loss__8__tb_obstacle_car__DOT__unnamedblk1_3__DOT____Vrepeat2)) {
        vlSelfRef.tb_obstacle_car__DOT__core_step_tick = 1U;
        __Vtask_tb_obstacle_car__DOT__wait_clock__49__cycles = 1U;
        __Vtask_tb_obstacle_car__DOT__wait_clock__49__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
        __Vtask_tb_obstacle_car__DOT__wait_clock__49__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = __Vtask_tb_obstacle_car__DOT__wait_clock__49__cycles;
        while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__49__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
            Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                                   "@(posedge tb_obstacle_car.clk)");
            co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_obstacle_car.clk)", 
                                                                 "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                                 54);
            __Vtask_tb_obstacle_car__DOT__wait_clock__49__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
                = (__Vtask_tb_obstacle_car__DOT__wait_clock__49__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
                   - (IData)(1U));
        }
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                             74);
        vlSelfRef.tb_obstacle_car__DOT__core_step_tick = 0U;
        __Vtask_tb_obstacle_car__DOT__wait_clock__50__cycles = 1U;
        __Vtask_tb_obstacle_car__DOT__wait_clock__50__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
        __Vtask_tb_obstacle_car__DOT__wait_clock__50__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = __Vtask_tb_obstacle_car__DOT__wait_clock__50__cycles;
        if (vlSelfRef.tb_obstacle_car__DOT__core_music_start) {
            tb_obstacle_car__DOT__seen_music_start = 1U;
            tb_obstacle_car__DOT__seen_music_win = vlSelfRef.tb_obstacle_car__DOT__core_music_win;
        }
        while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__50__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
            Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                                   "@(posedge tb_obstacle_car.clk)");
            co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_obstacle_car.clk)", 
                                                                 "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                                 54);
            __Vtask_tb_obstacle_car__DOT__wait_clock__50__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
                = (__Vtask_tb_obstacle_car__DOT__wait_clock__50__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
                   - (IData)(1U));
        }
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                             81);
        if (vlSelfRef.tb_obstacle_car__DOT__core_music_start) {
            tb_obstacle_car__DOT__seen_music_start = 1U;
            tb_obstacle_car__DOT__seen_music_win = vlSelfRef.tb_obstacle_car__DOT__core_music_win;
        }
        __Vtask_tb_obstacle_car__DOT__test_game_core_collision_and_loss__8__tb_obstacle_car__DOT__unnamedblk1_3__DOT____Vrepeat2 
            = (__Vtask_tb_obstacle_car__DOT__test_game_core_collision_and_loss__8__tb_obstacle_car__DOT__unnamedblk1_3__DOT____Vrepeat2 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__51__message = "four collisions should enter lose state"s;
    __Vtask_tb_obstacle_car__DOT__check__51__condition 
        = (3U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__51__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__51__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__52__message = "lose state should have zero chances"s;
    __Vtask_tb_obstacle_car__DOT__check__52__condition 
        = (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_hp_count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__52__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__52__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__53__message = "lose state should start music"s;
    __Vtask_tb_obstacle_car__DOT__check__53__condition 
        = tb_obstacle_car__DOT__seen_music_start;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__53__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__53__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__54__message = "lose music should be sad song"s;
    __Vtask_tb_obstacle_car__DOT__check__54__condition 
        = (1U & (~ (IData)(tb_obstacle_car__DOT__seen_music_win)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__54__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__54__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.tb_obstacle_car__DOT__core_melody_done = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__56__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__56__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__56__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__56__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__56__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__56__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__56__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                         91);
    vlSelfRef.tb_obstacle_car__DOT__core_melody_done = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__57__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__57__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__57__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__57__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__57__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__57__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__57__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                         94);
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__58__message = "melody done should return to idle after loss"s;
    __Vtask_tb_obstacle_car__DOT__check__58__condition 
        = (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__58__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__58__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__test_game_core_victory__59__tb_obstacle_car__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0;
    vlSelfRef.tb_obstacle_car__DOT__rst = 1U;
    vlSelfRef.tb_obstacle_car__DOT__db_key_n = 0x0fU;
    vlSelfRef.tb_obstacle_car__DOT__core_step_tick = 0U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    vlSelfRef.tb_obstacle_car__DOT__core_melody_done = 0U;
    tb_obstacle_car__DOT__seen_music_start = 0U;
    tb_obstacle_car__DOT__seen_music_win = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__61__cycles = 3U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__61__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__61__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__61__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__61__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__61__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__61__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__rst = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__62__cycles = 2U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__62__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__62__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__62__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__62__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__62__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__62__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__63__value = 1U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__63__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__64__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__64__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__64__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__64__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__64__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__64__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__64__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__65__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__65__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__65__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__65__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__65__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__65__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__65__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__66__value = 2U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__66__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__67__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__67__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__67__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__67__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__67__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__67__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__67__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__68__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__68__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__68__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__68__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__68__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__68__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__68__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__69__value = 2U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__69__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__70__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__70__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__70__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__70__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__70__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__70__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__70__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__71__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__71__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__71__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__71__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__71__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__71__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__71__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__72__value = 2U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__72__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__73__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__73__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__73__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__73__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__73__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__73__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__73__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__74__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__74__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__74__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__74__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__74__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__74__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__74__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    __Vtask_tb_obstacle_car__DOT__pulse_key__75__value = 2U;
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed 
        = __Vtask_tb_obstacle_car__DOT__pulse_key__75__value;
    __Vtask_tb_obstacle_car__DOT__wait_clock__76__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__76__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__76__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__76__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__76__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__76__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__76__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_obstacle_car__DOT__core_key_pressed = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__77__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__77__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__77__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__77__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__77__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__77__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__77__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__78__message = "victory path should park car in safe left column"s;
    __Vtask_tb_obstacle_car__DOT__check__78__condition 
        = (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__78__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__78__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    __Vtask_tb_obstacle_car__DOT__test_game_core_victory__59__tb_obstacle_car__DOT__unnamedblk1_4__DOT____Vrepeat3 = 0x00000018U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__test_game_core_victory__59__tb_obstacle_car__DOT__unnamedblk1_4__DOT____Vrepeat3)) {
        vlSelfRef.tb_obstacle_car__DOT__core_step_tick = 1U;
        __Vtask_tb_obstacle_car__DOT__wait_clock__80__cycles = 1U;
        __Vtask_tb_obstacle_car__DOT__wait_clock__80__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
        __Vtask_tb_obstacle_car__DOT__wait_clock__80__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = __Vtask_tb_obstacle_car__DOT__wait_clock__80__cycles;
        while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__80__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
            Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                                   "@(posedge tb_obstacle_car.clk)");
            co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_obstacle_car.clk)", 
                                                                 "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                                 54);
            __Vtask_tb_obstacle_car__DOT__wait_clock__80__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
                = (__Vtask_tb_obstacle_car__DOT__wait_clock__80__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
                   - (IData)(1U));
        }
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                             74);
        vlSelfRef.tb_obstacle_car__DOT__core_step_tick = 0U;
        __Vtask_tb_obstacle_car__DOT__wait_clock__81__cycles = 1U;
        __Vtask_tb_obstacle_car__DOT__wait_clock__81__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
        __Vtask_tb_obstacle_car__DOT__wait_clock__81__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = __Vtask_tb_obstacle_car__DOT__wait_clock__81__cycles;
        if (vlSelfRef.tb_obstacle_car__DOT__core_music_start) {
            tb_obstacle_car__DOT__seen_music_start = 1U;
            tb_obstacle_car__DOT__seen_music_win = vlSelfRef.tb_obstacle_car__DOT__core_music_win;
        }
        while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__81__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
            Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                                   "@(posedge tb_obstacle_car.clk)");
            co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_obstacle_car.clk)", 
                                                                 "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                                 54);
            __Vtask_tb_obstacle_car__DOT__wait_clock__81__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
                = (__Vtask_tb_obstacle_car__DOT__wait_clock__81__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
                   - (IData)(1U));
        }
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                             81);
        if (vlSelfRef.tb_obstacle_car__DOT__core_music_start) {
            tb_obstacle_car__DOT__seen_music_start = 1U;
            tb_obstacle_car__DOT__seen_music_win = vlSelfRef.tb_obstacle_car__DOT__core_music_win;
        }
        __Vtask_tb_obstacle_car__DOT__test_game_core_victory__59__tb_obstacle_car__DOT__unnamedblk1_4__DOT____Vrepeat3 
            = (__Vtask_tb_obstacle_car__DOT__test_game_core_victory__59__tb_obstacle_car__DOT__unnamedblk1_4__DOT____Vrepeat3 
               - (IData)(1U));
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__82__message = "passing all obstacles should enter win state"s;
    __Vtask_tb_obstacle_car__DOT__check__82__condition 
        = (2U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__82__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__82__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__83__message = "safe path should preserve all chances"s;
    __Vtask_tb_obstacle_car__DOT__check__83__condition 
        = (4U == (IData)(vlSelfRef.tb_obstacle_car__DOT__core_hp_count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__83__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__83__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__84__message = "win state should start music"s;
    __Vtask_tb_obstacle_car__DOT__check__84__condition 
        = tb_obstacle_car__DOT__seen_music_start;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__84__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__84__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__85__message = "win music should be happy song"s;
    __Vtask_tb_obstacle_car__DOT__check__85__condition 
        = tb_obstacle_car__DOT__seen_music_win;
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__85__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__85__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    vlSelfRef.tb_obstacle_car__DOT__core_melody_done = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__87__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__87__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__87__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__87__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__87__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__87__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__87__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                         91);
    vlSelfRef.tb_obstacle_car__DOT__core_melody_done = 0U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__88__cycles = 1U;
    __Vtask_tb_obstacle_car__DOT__wait_clock__88__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_obstacle_car__DOT__wait_clock__88__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_obstacle_car__DOT__wait_clock__88__cycles;
    while (VL_LTS_III(32, 0U, __Vtask_tb_obstacle_car__DOT__wait_clock__88__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(vlSelf, 
                                                               "@(posedge tb_obstacle_car.clk)");
        co_await vlSelfRef.__VtrigSched_h034c33ec__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_obstacle_car.clk)", 
                                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                                             54);
        __Vtask_tb_obstacle_car__DOT__wait_clock__88__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_obstacle_car__DOT__wait_clock__88__tb_obstacle_car__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                         94);
    vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__89__message = "melody done should return to idle after win"s;
    __Vtask_tb_obstacle_car__DOT__check__89__condition 
        = (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_obstacle_car__DOT__check__89__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Error: tb_obstacle_car.sv:59: Assertion failed in %m: %s\n",4, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , 'S',&(vlSelfRef.__Vtask_tb_obstacle_car__DOT__check__89__message));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 59, "");
        VL_WRITEF_NX("[%0t] %%Fatal: tb_obstacle_car.sv:60: Assertion failed in %m\n",3, 'M',vlSymsp->name(),"tb_obstacle_car.check", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 60, "", false);
    }
    VL_WRITEF_NX("tb_obstacle_car: all tests passed\n",0);
    VL_FINISH_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 115, "");
    co_return;
}

VlCoroutine Vtb_obstacle_car___024root___eval_initial__TOP__Vtiming__1(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 
                                             24);
        vlSelfRef.tb_obstacle_car__DOT__clk = (1U & 
                                               (~ (IData)(vlSelfRef.tb_obstacle_car__DOT__clk)));
    }
    co_return;
}

void Vtb_obstacle_car___024root___eval_triggers_vec__act(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_triggers_vec__act\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.tb_obstacle_car__DOT__clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_obstacle_car__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_obstacle_car__DOT__clk__0 
        = vlSelfRef.tb_obstacle_car__DOT__clk;
}

bool Vtb_obstacle_car___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_obstacle_car___024root___nba_sequent__TOP__0(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___nba_sequent__TOP__0\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__Vfuncout;
    __Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index;
    __Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index = 0;
    CData/*3:0*/ __Vdly__tb_obstacle_car__DOT__db_key_held;
    __Vdly__tb_obstacle_car__DOT__db_key_held = 0;
    CData/*1:0*/ __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state;
    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state = 0;
    CData/*5:0*/ __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top;
    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top = 0;
    CData/*5:0*/ __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid;
    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid = 0;
    CData/*5:0*/ __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom;
    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom = 0;
    CData/*2:0*/ __Vdly__tb_obstacle_car__DOT__core_car_col;
    __Vdly__tb_obstacle_car__DOT__core_car_col = 0;
    CData/*2:0*/ __Vdly__tb_obstacle_car__DOT__core_hp_count;
    __Vdly__tb_obstacle_car__DOT__core_hp_count = 0;
    CData/*4:0*/ __Vdly__tb_obstacle_car__DOT__core_spawn_count;
    __Vdly__tb_obstacle_car__DOT__core_spawn_count = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v0;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v4;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v4 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v5;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v5 = 0;
    CData/*0:0*/ __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6;
    __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v7;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v7 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v8;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v8 = 0;
    CData/*0:0*/ __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9;
    __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v10;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v10 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v11;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v11 = 0;
    CData/*0:0*/ __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12;
    __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v13;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v13 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v14;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v14 = 0;
    CData/*0:0*/ __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15;
    __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15 = 0;
    CData/*0:0*/ __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15 = 0;
    // Body
    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state 
        = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state;
    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top 
        = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_top;
    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid 
        = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_mid;
    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom 
        = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_bottom;
    __Vdly__tb_obstacle_car__DOT__core_car_col = vlSelfRef.tb_obstacle_car__DOT__core_car_col;
    __Vdly__tb_obstacle_car__DOT__core_hp_count = vlSelfRef.tb_obstacle_car__DOT__core_hp_count;
    __Vdly__tb_obstacle_car__DOT__core_spawn_count 
        = vlSelfRef.tb_obstacle_car__DOT__core_spawn_count;
    __Vdly__tb_obstacle_car__DOT__db_key_held = vlSelfRef.tb_obstacle_car__DOT__db_key_held;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v0 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v4 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v5 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v7 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v8 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v10 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v11 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v13 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v14 = 0U;
    __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15 = 0U;
    if (vlSelfRef.tb_obstacle_car__DOT__rst) {
        __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state = 0U;
        __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top = 0U;
        __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid = 0U;
        __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom = 0U;
        __Vdly__tb_obstacle_car__DOT__core_car_col = 3U;
        __Vdly__tb_obstacle_car__DOT__core_hp_count = 4U;
        __Vdly__tb_obstacle_car__DOT__core_spawn_count = 0U;
        vlSelfRef.tb_obstacle_car__DOT__core_music_start = 0U;
        vlSelfRef.tb_obstacle_car__DOT__core_music_win = 0U;
        __Vdly__tb_obstacle_car__DOT__db_key_held = 0U;
        vlSelfRef.tb_obstacle_car__DOT__db_key_pressed = 0U;
        __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v0 = 1U;
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_1 = 0x0fU;
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_0 = 0x0fU;
    } else {
        vlSelfRef.tb_obstacle_car__DOT__core_music_start = 0U;
        if ((2U & (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state))) {
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top = 0U;
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid = 0U;
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom = 0U;
                __Vdly__tb_obstacle_car__DOT__core_hp_count = 0U;
                if (vlSelfRef.tb_obstacle_car__DOT__core_melody_done) {
                    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state = 0U;
                }
            } else {
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top = 0U;
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid = 0U;
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom = 0U;
                if (vlSelfRef.tb_obstacle_car__DOT__core_melody_done) {
                    __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state))) {
            vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col 
                = vlSelfRef.tb_obstacle_car__DOT__core_car_col;
            vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count 
                = vlSelfRef.tb_obstacle_car__DOT__core_hp_count;
            vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_spawn_count 
                = vlSelfRef.tb_obstacle_car__DOT__core_spawn_count;
            vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_top 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_top;
            vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_mid 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_mid;
            vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_bottom;
            if ((IData)(((2U == (3U & (IData)(vlSelfRef.tb_obstacle_car__DOT__core_key_pressed))) 
                         & (0U != (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col))))) {
                vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col 
                    = (7U & ((IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col) 
                             - (IData)(1U)));
            } else if ((IData)(((1U == (3U & (IData)(vlSelfRef.tb_obstacle_car__DOT__core_key_pressed))) 
                                & (5U != (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col))))) {
                vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_obstacle_car__DOT__core_car_col)));
            }
            if (vlSelfRef.tb_obstacle_car__DOT__core_step_tick) {
                vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom 
                    = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_mid;
                vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_mid 
                    = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_top;
                if ((0x14U > (IData)(vlSelfRef.tb_obstacle_car__DOT__core_spawn_count))) {
                    __Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index 
                        = vlSelfRef.tb_obstacle_car__DOT__core_spawn_count;
                    __Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__Vfuncout 
                        = ((0x00000010U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                            ? ((8U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                ? 0U : ((4U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                         ? 0U : ((2U 
                                                  & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                                   ? 0x3cU
                                                   : 0x26U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                                   ? 0x1aU
                                                   : 0x32U))))
                            : ((8U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                ? ((4U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                    ? ((2U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                        ? ((1U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                            ? 0x2aU
                                            : 0x0eU)
                                        : ((1U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                            ? 0x12U
                                            : 0x22U))
                                    : ((2U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                        ? ((1U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                            ? 0x1cU
                                            : 0x2cU)
                                        : ((1U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                            ? 0x34U
                                            : 0x1aU)))
                                : ((4U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                    ? ((2U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                        ? ((1U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                            ? 0x2aU
                                            : 0x16U)
                                        : ((1U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                            ? 0x26U
                                            : 0x32U))
                                    : ((2U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                        ? ((1U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                            ? 0x3aU
                                            : 0x1eU)
                                        : ((1U & (IData)(__Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__index))
                                            ? 0x2eU
                                            : 0x3eU)))));
                    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_top 
                        = __Vfunc_tb_obstacle_car__DOT__u_game_core__DOT__obstacle_pattern__91__Vfuncout;
                    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_spawn_count 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_obstacle_car__DOT__core_spawn_count)));
                } else {
                    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_top = 0U;
                }
            }
            vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__hit 
                = ((5U >= (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col)) 
                   && (1U & ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom) 
                             >> (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col))));
            if (vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__hit) {
                vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT____Vlvbound_h3e594082__0 = 0U;
                if ((0U != (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count))) {
                    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count 
                        = (7U & ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count) 
                                 - (IData)(1U)));
                }
                if ((5U >= (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col))) {
                    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom 
                        = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col))) 
                            & (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom)) 
                           | (0x3fU & ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT____Vlvbound_h3e594082__0) 
                                       << (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col))));
                }
            }
            vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__finished 
                = ((((0x14U <= (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_spawn_count)) 
                     & (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_top))) 
                    & (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_mid))) 
                   & (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom)));
            __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_top;
            __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_mid;
            __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom;
            __Vdly__tb_obstacle_car__DOT__core_car_col 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col;
            __Vdly__tb_obstacle_car__DOT__core_hp_count 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count;
            __Vdly__tb_obstacle_car__DOT__core_spawn_count 
                = vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_spawn_count;
            if (((IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__hit) 
                 & (0U == (IData)(vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count)))) {
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state = 3U;
                vlSelfRef.tb_obstacle_car__DOT__core_music_start = 1U;
                vlSelfRef.tb_obstacle_car__DOT__core_music_win = 0U;
            } else if (vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__finished) {
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state = 2U;
                vlSelfRef.tb_obstacle_car__DOT__core_music_start = 1U;
                vlSelfRef.tb_obstacle_car__DOT__core_music_win = 1U;
            }
        } else {
            __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top = 0U;
            __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid = 0U;
            __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom = 0U;
            __Vdly__tb_obstacle_car__DOT__core_car_col = 3U;
            __Vdly__tb_obstacle_car__DOT__core_hp_count = 4U;
            __Vdly__tb_obstacle_car__DOT__core_spawn_count = 0U;
            vlSelfRef.tb_obstacle_car__DOT__core_music_win = 0U;
            if ((0U != (IData)(vlSelfRef.tb_obstacle_car__DOT__core_key_pressed))) {
                __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state = 1U;
            }
        }
        vlSelfRef.tb_obstacle_car__DOT__db_key_pressed = 0U;
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed 
            = (1U & (~ (IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_1)));
        if (((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
             == (1U & (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_held)))) {
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v4 = 1U;
        } else if (vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[0U]) {
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v5 = 1U;
            __Vdly__tb_obstacle_car__DOT__db_key_held 
                = ((0x0eU & (IData)(__Vdly__tb_obstacle_car__DOT__db_key_held)) 
                   | (IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed));
            vlSelfRef.tb_obstacle_car__DOT__db_key_pressed 
                = ((0x0eU & (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_pressed)) 
                   | (IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed));
        } else {
            __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6 
                = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[0U])));
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6 = 1U;
        }
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed 
            = (1U & (~ ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_1) 
                        >> 1U)));
        if (((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
             == (1U & ((IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_held) 
                       >> 1U)))) {
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v7 = 1U;
        } else if (vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[1U]) {
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v8 = 1U;
            __Vdly__tb_obstacle_car__DOT__db_key_held 
                = ((0x0dU & (IData)(__Vdly__tb_obstacle_car__DOT__db_key_held)) 
                   | ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
                      << 1U));
            vlSelfRef.tb_obstacle_car__DOT__db_key_pressed 
                = ((0x0dU & (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_pressed)) 
                   | ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
                      << 1U));
        } else {
            __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9 
                = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[1U])));
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9 = 1U;
        }
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed 
            = (1U & (~ ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_1) 
                        >> 2U)));
        if (((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
             == (1U & ((IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_held) 
                       >> 2U)))) {
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v10 = 1U;
        } else if (vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[2U]) {
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v11 = 1U;
            __Vdly__tb_obstacle_car__DOT__db_key_held 
                = ((0x0bU & (IData)(__Vdly__tb_obstacle_car__DOT__db_key_held)) 
                   | ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
                      << 2U));
            vlSelfRef.tb_obstacle_car__DOT__db_key_pressed 
                = ((0x0bU & (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_pressed)) 
                   | ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
                      << 2U));
        } else {
            __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12 
                = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[2U])));
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12 = 1U;
        }
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed 
            = (1U & (~ ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_1) 
                        >> 3U)));
        if (((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
             == (1U & ((IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_held) 
                       >> 3U)))) {
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v13 = 1U;
        } else if (vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[3U]) {
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v14 = 1U;
            __Vdly__tb_obstacle_car__DOT__db_key_held 
                = ((7U & (IData)(__Vdly__tb_obstacle_car__DOT__db_key_held)) 
                   | ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
                      << 3U));
            vlSelfRef.tb_obstacle_car__DOT__db_key_pressed 
                = ((7U & (IData)(vlSelfRef.tb_obstacle_car__DOT__db_key_pressed)) 
                   | ((IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed) 
                      << 3U));
        } else {
            __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15 
                = (1U & ((IData)(1U) + (IData)(vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[3U])));
            __VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15 = 1U;
        }
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_1 
            = vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_0;
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__sync_0 
            = vlSelfRef.tb_obstacle_car__DOT__db_key_n;
    }
    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__state 
        = __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__state;
    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_top 
        = __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_top;
    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_mid 
        = __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_mid;
    vlSelfRef.tb_obstacle_car__DOT__u_game_core__DOT__row_bottom 
        = __Vdly__tb_obstacle_car__DOT__u_game_core__DOT__row_bottom;
    vlSelfRef.tb_obstacle_car__DOT__core_car_col = __Vdly__tb_obstacle_car__DOT__core_car_col;
    vlSelfRef.tb_obstacle_car__DOT__core_hp_count = __Vdly__tb_obstacle_car__DOT__core_hp_count;
    vlSelfRef.tb_obstacle_car__DOT__core_spawn_count 
        = __Vdly__tb_obstacle_car__DOT__core_spawn_count;
    vlSelfRef.tb_obstacle_car__DOT__db_key_held = __Vdly__tb_obstacle_car__DOT__db_key_held;
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v0) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[0U] = 0U;
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[1U] = 0U;
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[2U] = 0U;
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[3U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v4) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[0U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v5) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[0U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[0U] 
            = __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v6;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v7) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[1U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v8) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[1U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[1U] 
            = __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v9;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v10) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[2U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v11) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[2U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[2U] 
            = __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v12;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v13) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[3U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v14) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[3U] = 0U;
    }
    if (__VdlySet__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15) {
        vlSelfRef.tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[3U] 
            = __VdlyVal__tb_obstacle_car__DOT__u_key_debounce__DOT__cnt__v15;
    }
}

void Vtb_obstacle_car___024root___eval_nba(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_nba\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_obstacle_car___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtb_obstacle_car___024root___timing_ready(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___timing_ready\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h034c33ec__0.ready("@(posedge tb_obstacle_car.clk)");
    }
}

void Vtb_obstacle_car___024root___timing_resume(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___timing_resume\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h034c33ec__0.moveToResumeQueue(
                                                          "@(posedge tb_obstacle_car.clk)");
    vlSelfRef.__VtrigSched_h034c33ec__0.resume("@(posedge tb_obstacle_car.clk)");
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_obstacle_car___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_obstacle_car___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_obstacle_car___024root___eval_phase__act(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_phase__act\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_obstacle_car___024root___eval_triggers_vec__act(vlSelf);
    Vtb_obstacle_car___024root___timing_ready(vlSelf);
    Vtb_obstacle_car___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_obstacle_car___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_obstacle_car___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_obstacle_car___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_obstacle_car___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_obstacle_car___024root___eval_phase__inact(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_phase__inact\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_obstacle_car___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_obstacle_car___024root___eval_phase__nba(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_phase__nba\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_obstacle_car___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_obstacle_car___024root___eval_nba(vlSelf);
        Vtb_obstacle_car___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_obstacle_car___024root___eval(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_obstacle_car___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 3, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_obstacle_car___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("vivado/Obstacle_Avoidance_Car_Project/Obstacle_Avoidance_Car_Project.srcs/sim_1/new/tb_obstacle_car.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_obstacle_car___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_obstacle_car___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_obstacle_car___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0(Vtb_obstacle_car___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root____VbeforeTrig_h034c33ec__0\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.tb_obstacle_car__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_obstacle_car__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_obstacle_car__DOT__clk__0 
        = vlSelfRef.tb_obstacle_car__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h034c33ec__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_obstacle_car___024root___eval_debug_assertions(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_debug_assertions\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
