//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_SYSTEM_H
#define VIRTGL_SYSTEM_H

#include "../../Globals.h"

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

#endif //VIRTGL_SYSTEM_H
