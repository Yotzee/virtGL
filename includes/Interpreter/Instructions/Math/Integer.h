//
// Created by Greg Yotz on 6/1/16.
//


#ifndef VIRTGL_INTEGER_H
#define VIRTGL_INTEGER_H
#include "../../Globals.h"

static const int IADD = 0x21;
void iadd() {
    int b = (int) g_stack[g_sp--];
    int a = (int) g_stack[g_sp--];
    g_stack[++g_sp] = a + b;
}

static const int ISUB = 0x22;
void isubtract() {
    int b = g_stack[g_sp--];
    int a = g_stack[g_sp--];
    g_stack[++g_sp] = a - b;
}

static const int IMUL = 0x23;
void imultipuly() {
    int b = g_stack[g_sp--];
    int a = g_stack[g_sp--];
    g_stack[++g_sp] = a * b;
}

static const int IDIV = 0x24;
void idivid() {
    int b = g_stack[g_sp--];
    int a = g_stack[g_sp--];
    g_stack[++g_sp] = a / b;
}

void integer_init() {
    g_instructionMap[IADD] = &iadd;
    g_instructionMap[ISUB] = &isubtract;
    g_instructionMap[IMUL] = &imultipuly;
    g_instructionMap[IDIV] = &idivid;
}

#endif //VIRTGL_INTEGER_H
