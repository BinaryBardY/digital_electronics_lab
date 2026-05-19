// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_obstacle_car.h for the primary calling header

#include "Vtb_obstacle_car__pch.h"

void Vtb_obstacle_car___024root___timing_ready(Vtb_obstacle_car___024root* vlSelf);

VL_ATTR_COLD void Vtb_obstacle_car___024root___eval_static(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_static\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_obstacle_car__DOT__clk = 0U;
    vlSelfRef.tb_obstacle_car__DOT__rst = 1U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15534144550500989419ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2571774870822642143ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17684132040936942223ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_spawn_count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15417960323374143619ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_top = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 5209908261710692870ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_mid = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8842622980844257550ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 3049918064044581077ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4250471995190791795ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__finished = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2671753276121015365ull);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_obstacle_car__DOT__clk__0 = 0U;
    Vtb_obstacle_car___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_obstacle_car___024root___eval_static__TOP(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_static__TOP\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_obstacle_car__DOT__clk = 0U;
    vlSelfRef.tb_obstacle_car__DOT__rst = 1U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15534144550500989419ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2571774870822642143ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17684132040936942223ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_spawn_count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15417960323374143619ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_top = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 5209908261710692870ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_mid = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8842622980844257550ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 3049918064044581077ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4250471995190791795ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__finished = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2671753276121015365ull);
}

VL_ATTR_COLD void Vtb_obstacle_car___024root___eval_final(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_final\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_obstacle_car___024root___eval_settle(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___eval_settle\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtb_obstacle_car___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_obstacle_car___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_obstacle_car___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_obstacle_car.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_obstacle_car___024root___ctor_var_reset(Vtb_obstacle_car___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_obstacle_car___024root___ctor_var_reset\n"); );
    Vtb_obstacle_car__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_obstacle_car__DOT__db_key_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15681994293463642401ull);
    vlSelf->tb_obstacle_car__DOT__db_key_pressed = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15151264382667752013ull);
    vlSelf->tb_obstacle_car__DOT__db_key_held = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5586375308135392277ull);
    vlSelf->tb_obstacle_car__DOT__core_step_tick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14785053061153092154ull);
    vlSelf->tb_obstacle_car__DOT__core_key_pressed = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4473992070415969061ull);
    vlSelf->tb_obstacle_car__DOT__core_melody_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7280106084184877302ull);
    vlSelf->tb_obstacle_car__DOT__core_car_col = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13375869909162528485ull);
    vlSelf->tb_obstacle_car__DOT__core_hp_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17757887805291957540ull);
    vlSelf->tb_obstacle_car__DOT__core_music_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18302146566529578393ull);
    vlSelf->tb_obstacle_car__DOT__core_music_win = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14183254472361285001ull);
    vlSelf->tb_obstacle_car__DOT__core_spawn_count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 900682032690543304ull);
    vlSelf->tb_obstacle_car__DOT__u_key_debounce__DOT__sync_0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16228695155663329512ull);
    vlSelf->tb_obstacle_car__DOT__u_key_debounce__DOT__sync_1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5991004431685190411ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_obstacle_car__DOT__u_key_debounce__DOT__cnt[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11322283382261829918ull);
    }
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT____Vlvbound_h3e594082__0 = 0;
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5876179042921272551ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__row_top = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11584254502915439250ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__row_mid = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14632701494026370797ull);
    vlSelf->tb_obstacle_car__DOT__u_game_core__DOT__row_bottom = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11131073724906454868ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_obstacle_car__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
