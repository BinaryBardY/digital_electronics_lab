// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_obstacle_car.h for the primary calling header

#ifndef VERILATED_VTB_OBSTACLE_CAR___024ROOT_H_
#define VERILATED_VTB_OBSTACLE_CAR___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_obstacle_car__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_obstacle_car___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_obstacle_car__DOT__clk;
    CData/*0:0*/ tb_obstacle_car__DOT__rst;
    CData/*3:0*/ tb_obstacle_car__DOT__db_key_n;
    CData/*3:0*/ tb_obstacle_car__DOT__db_key_pressed;
    CData/*3:0*/ tb_obstacle_car__DOT__db_key_held;
    CData/*0:0*/ tb_obstacle_car__DOT__core_step_tick;
    CData/*3:0*/ tb_obstacle_car__DOT__core_key_pressed;
    CData/*0:0*/ tb_obstacle_car__DOT__core_melody_done;
    CData/*2:0*/ tb_obstacle_car__DOT__core_car_col;
    CData/*2:0*/ tb_obstacle_car__DOT__core_hp_count;
    CData/*0:0*/ tb_obstacle_car__DOT__core_music_start;
    CData/*0:0*/ tb_obstacle_car__DOT__core_music_win;
    CData/*4:0*/ tb_obstacle_car__DOT__core_spawn_count;
    CData/*3:0*/ tb_obstacle_car__DOT__u_key_debounce__DOT__sync_0;
    CData/*3:0*/ tb_obstacle_car__DOT__u_key_debounce__DOT__sync_1;
    CData/*0:0*/ tb_obstacle_car__DOT__u_key_debounce__DOT__unnamedblk2__DOT__unnamedblk3__DOT__sampled_pressed;
    CData/*0:0*/ tb_obstacle_car__DOT__u_game_core__DOT____Vlvbound_h3e594082__0;
    CData/*1:0*/ tb_obstacle_car__DOT__u_game_core__DOT__state;
    CData/*5:0*/ tb_obstacle_car__DOT__u_game_core__DOT__row_top;
    CData/*5:0*/ tb_obstacle_car__DOT__u_game_core__DOT__row_mid;
    CData/*5:0*/ tb_obstacle_car__DOT__u_game_core__DOT__row_bottom;
    CData/*2:0*/ tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_car_col;
    CData/*2:0*/ tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_hp_count;
    CData/*4:0*/ tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_spawn_count;
    CData/*5:0*/ tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_top;
    CData/*5:0*/ tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_mid;
    CData/*5:0*/ tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__next_bottom;
    CData/*0:0*/ tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__hit;
    CData/*0:0*/ tb_obstacle_car__DOT__u_game_core__DOT__unnamedblk1__DOT__finished;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_obstacle_car__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<CData/*0:0*/, 4> tb_obstacle_car__DOT__u_key_debounce__DOT__cnt;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    std::string __Vtask_tb_obstacle_car__DOT__check__4__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__5__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__7__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__12__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__13__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__14__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__18__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__28__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__32__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__36__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__40__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__47__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__51__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__52__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__53__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__54__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__58__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__78__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__82__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__83__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__84__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__85__message;
    std::string __Vtask_tb_obstacle_car__DOT__check__89__message;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h034c33ec__0;

    // INTERNAL VARIABLES
    Vtb_obstacle_car__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_obstacle_car___024root(Vtb_obstacle_car__Syms* symsp, const char* namep);
    ~Vtb_obstacle_car___024root();
    VL_UNCOPYABLE(Vtb_obstacle_car___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
