//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_FLOAT_H
#define VIRTGL_FLOAT_H

#include "../../Globals.h"




static const int FADD = 0x25;
void fadd( ){
    float b = g_stack[g_sp--];
    float a = g_stack[g_sp--];
    g_stack[++g_sp] = a + b;
}

static const int FDIV = 0x26;
void fsubtract(){
    float b = g_stack[g_sp--];
    float a = g_stack[g_sp--];
    g_stack[++g_sp] = a - b;
}

static const int FMUL = 0x27;
void fmultipuly(){
    float b = g_stack[g_sp--];
    float a = g_stack[g_sp--];
    g_stack[++g_sp] = a * b;
}

static const int FSUB = 0x28;
void fdivid(){
    float b = g_stack[g_sp--];
    float a = g_stack[g_sp--];
    g_stack[++g_sp] = a / b;
}

void float_init(){
    g_instructionMap[FADD] = &fadd;
    g_instructionMap[FSUB] = &fsubtract;
    g_instructionMap[FMUL] = &fmultipuly;
    g_instructionMap[FDIV] = &fdivid;
}
#endif //VIRTGL_FLOAT_H
