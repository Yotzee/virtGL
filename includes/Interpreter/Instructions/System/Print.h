//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_PRINT_H
#define VIRTGL_PRINT_H

#include "../../includes.h"
#include "../../Globals.h"

static const int IPRINT = 0x11;

void print(int msg){
    std::printf("%d\r\n",msg);
}

void print(float msg){
    std::printf("%f\r\n",msg);
}

void print(const char* msg){
    std::printf("%s\r\n",msg);
}

void iprint(){
    int i = g_stack[g_sp--];
    print(i);
}

void fprint(){
    float f = g_stack[g_sp--];
    print(f);
}

void print_init() {
    g_instructionMap[IPRINT] = &fprint;
    //g_instructionMap[BC::FPRINT] = &iprint;

}

#endif //VIRTGL_PRINT_H
