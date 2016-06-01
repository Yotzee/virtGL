//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_FLOAT_H
#define VIRTGL_FLOAT_H

#include "../../Globals.h"
static const int FADD = 0x25;
static const int FSUB = 0x26;
static const int FMUL = 0x27;
static const int FDIV = 0x28;

void fadd( ){
    float b = g_stack[g_sp--];
    float a = g_stack[g_sp--];
    g_stack[++g_sp] = a + b;
}

void fsubtract(){
    float b = g_stack[g_sp--];
    float a = g_stack[g_sp--];
    g_stack[++g_sp] = a - b;
}

void fmultipuly(){
    float b = g_stack[g_sp--];
    float a = g_stack[g_sp--];
    g_stack[++g_sp] = a * b;
}

void fdivid(){
    float b = g_stack[g_sp--];
    float a = g_stack[g_sp--];
    g_stack[++g_sp] = a / b;
}

#endif //VIRTGL_FLOAT_H
