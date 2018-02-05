//
// Created by Greg Yotz on 6/1/16.
//


#ifndef VIRTGL_SYSTEM_H
#define VIRTGL_SYSTEM_H
#include "../../Globals.h"


static const int POP = 0x01;
void pop(){

}

static const int PUSH = 0x02;
void push(){

}

static const int DEBUG = 0x06;
void debug(){
    g_debug = true;
}

static const int CALL = 0x07;
void call(){
    int addr = g_codeMemory[g_ip++];
    int args = g_codeMemory[g_ip++];
    g_stack[++g_sp] = args;
    g_stack[++g_sp] = g_fp;
    g_stack[++g_sp] = g_ip;
    g_fp = g_sp;
    g_ip = addr;
}

static const int RET = 0x08;
void ret(){
    int rValue = g_stack[g_sp--];
    g_sp = g_fp;
    g_ip = g_stack[g_sp--];
    g_fp = g_stack[g_sp--];
    int nargs = g_stack[g_sp--];
    g_sp -= nargs;
    g_stack[++g_sp] = rValue;

}


/*
static const int ISTORE = 0x14;
void istore(){

}

static const int ILOAD = 0x14;
void iload(){

}
*/
static const int MAIN = 0x05;
void setmain(){
    int i = (int)g_codeMemory[g_ip++];
    g_ip = i;
}

static const int ICONST = 0x10;
void iconst(){

    int i = (int)g_codeMemory[g_ip++];
    g_stack[++g_sp] = i;
}

static const int GISTORE = 0x12;
void giload(){
    int addr = (int)g_codeMemory[g_ip++];
    int v = (int)g_dataMemory[addr];
    g_stack[++g_sp] = v;

}

static const int GILOAD = 0x13;
void gistore(){
    int v = (int)g_stack[g_sp--];
    int addr = (int)g_codeMemory[g_ip++];
    g_dataMemory[addr] = v;

}

static const int HALT = 0x10;
void halt(){
    g_running = false;
}

void system_init() {
    g_instructionMap[MAIN] = &setmain;
    g_instructionMap[CALL] = &call;
    g_instructionMap[RET] = &ret;
    g_instructionMap[DEBUG] = &debug;
    g_instructionMap[HALT] = &halt;
    g_instructionMap[GISTORE] = &gistore;
    g_instructionMap[GILOAD] = &giload;
    g_instructionMap[ICONST] = &iconst;

}
#endif //VIRTGL_SYSTEM_H
