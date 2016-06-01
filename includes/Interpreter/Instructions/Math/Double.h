//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_DOUBLE_H
#define VIRTGL_DOUBLE_H
#include "../../Globals.h"

//TODO: change to doubles and double stack
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

#endif //VIRTGL_DOUBLE_H
