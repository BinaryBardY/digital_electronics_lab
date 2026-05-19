// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_obstacle_car.h for the primary calling header

#include "Vtb_obstacle_car__pch.h"

void Vtb_obstacle_car___024root___ctor_var_reset(Vtb_obstacle_car___024root* vlSelf);

Vtb_obstacle_car___024root::Vtb_obstacle_car___024root(Vtb_obstacle_car__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_obstacle_car___024root___ctor_var_reset(this);
}

void Vtb_obstacle_car___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_obstacle_car___024root::~Vtb_obstacle_car___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
