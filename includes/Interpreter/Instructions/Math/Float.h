//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_FLOAT_H
#define VIRTGL_FLOAT_H

#include "../../Globals.h"


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
