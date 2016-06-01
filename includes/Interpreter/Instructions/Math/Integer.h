//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_INTEGER_H
#define VIRTGL_INTEGER_H

#include "../../Globals.h"

static const unsigned long IADD = 0x0021;
void iadd( ){
    int b = (int)g_stack[g_sp--];
    int a = (int)g_stack[g_sp--];
    g_stack[++g_sp] = a + b;
}

void isubtract(){
    int b = g_stack[g_sp];
    g_sp -= sizeof(int);
    int a = g_stack[g_sp];
    g_sp -= sizeof(int);
    g_sp += sizeof(int);
    g_stack[g_sp] = a - b;
}

void imultipuly(){
    int b = g_stack[g_sp];
    g_sp -= sizeof(int);
    int a = g_stack[g_sp];
    g_sp -= sizeof(int);
    g_sp += sizeof(int);
    g_stack[g_sp] = a * b;
}

void idivid(){
    int b = g_stack[g_sp];
    g_sp -= sizeof(int);
    int a = g_stack[g_sp];
    g_sp -= sizeof(int);
    g_sp += sizeof(int);
    g_stack[g_sp] = a / b;
}

#endif //VIRTGL_INTEGER_H
