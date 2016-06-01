//
// Created by Greg Yotz on 5/31/16.
//
#include "../Globals.h"
#ifndef VIRTGL_CPU_H
#define VIRTGL_CPU_H


class CPU {
public:
    int dataSize = 100;
    int codeSize = 100;
    int stackSize = 100;
    int startPoint = 0;

    CPU();
    ~CPU();
    void iprint(int msg);
    void print(const char* msg);
    void run(int argc, const char *argv[]);
    void loadInstructionSet(int instructions[]);

};


#endif //VIRTGL_CPU_H
