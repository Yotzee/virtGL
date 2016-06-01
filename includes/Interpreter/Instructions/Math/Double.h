//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_DOUBLE_H
#define VIRTGL_DOUBLE_H
#include "../../Globals.h"

static const int DADD = 0x41;
static const int DSUB = 0x42;
static const int DMUL = 0x43;
static const int DDIV = 0x44;


void dadd( ){
    double b = g_stack[g_sp--];
    double a = g_stack[g_sp--];
    g_stack[++g_sp] = a + b;
}

void dsubtract(){
    double b = g_stack[g_sp--];
    double a = g_stack[g_sp--];
    g_stack[++g_sp] = a - b;
}

void dmultipuly(){
    double b = g_stack[g_sp--];
    double a = g_stack[g_sp--];
    g_stack[++g_sp] = a * b;
}

void ddivid(){
    double b = g_stack[g_sp--];
    double a = g_stack[g_sp--];
    g_stack[++g_sp] = a / b;
}

void float_init(){
    g_instructionMap[DADD] = &dadd;
    g_instructionMap[DSUB] = &dsubtract;
    g_instructionMap[DMUL] = &dmultipuly;
    g_instructionMap[DDIV] = &ddivid;
}
#endif //VIRTGL_DOUBLE_H
