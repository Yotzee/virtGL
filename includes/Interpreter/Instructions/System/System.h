//
// Created by Greg Yotz on 6/1/16.
//


#ifndef VIRTGL_SYSTEM_H
#define VIRTGL_SYSTEM_H
#include "../../Globals.h"


static const int BPOP = 0x01;
static const int PUSH = 0x02;

static const int RET = 0x07;
static const int CALL = 0x08;
static const int ICONST = 0x09;
static const int HALT = 0x10;

static const int GISTORE = 0x12;
static const int GILOAD = 0x13;

static const int STORE = 0x14;
static const int LOAD = 0x14;

void iconst(){

    int i = (int)g_codeMemory[g_ip++];
    g_stack[++g_sp] = i;
}


void giload(){
    int addr = (int)g_codeMemory[g_ip++];
    int v = (int)g_dataMemory[addr];
    g_stack[++g_sp] = v;

}

void gistore(){
    int v = (int)g_stack[g_sp--];
    int addr = (int)g_codeMemory[g_ip++];
    g_dataMemory[addr] = v;

}

void halt(){
    g_running = false;
}

void system_init() {
    g_instructionMap[HALT] = &halt;
    g_instructionMap[GISTORE] = &gistore;
    g_instructionMap[GILOAD] = &giload;
    g_instructionMap[ICONST] = &iconst;

}
#endif //VIRTGL_SYSTEM_H
