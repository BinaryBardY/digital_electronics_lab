// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_obstacle_car__pch.h"

//============================================================
// Constructors

Vtb_obstacle_car::Vtb_obstacle_car(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_obstacle_car__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_obstacle_car::Vtb_obstacle_car(const char* _vcname__)
    : Vtb_obstacle_car(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_obstacle_car::~Vtb_obstacle_car() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_obstacle_car___024root___eval_debug_assertions(Vtb_obstacle_car___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_obstacle_car___024root___eval_static(Vtb_obstacle_car___024root* vlSelf);
void Vtb_obstacle_car___024root___eval_initial(Vtb_obstacle_car___024root* vlSelf);
void Vtb_obstacle_car___024root___eval_settle(Vtb_obstacle_car___024root* vlSelf);
void Vtb_obstacle_car___024root___eval(Vtb_obstacle_car___024root* vlSelf);

void Vtb_obstacle_car::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_obstacle_car::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_obstacle_car___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_obstacle_car___024root___eval_static(&(vlSymsp->TOP));
        Vtb_obstacle_car___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_obstacle_car___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_obstacle_car___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_obstacle_car::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_obstacle_car::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_obstacle_car::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_obstacle_car___024root___eval_final(Vtb_obstacle_car___024root* vlSelf);

VL_ATTR_COLD void Vtb_obstacle_car::final() {
    contextp()->executingFinal(true);
    Vtb_obstacle_car___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_obstacle_car::hierName() const { return vlSymsp->name(); }
const char* Vtb_obstacle_car::modelName() const { return "Vtb_obstacle_car"; }
unsigned Vtb_obstacle_car::threads() const { return 1; }
void Vtb_obstacle_car::prepareClone() const { contextp()->prepareClone(); }
void Vtb_obstacle_car::atClone() const {
    contextp()->threadPoolpOnClone();
}
