//
// Created by Greg Yotz on 5/31/16.
//

#ifndef VIRTGL_CPU_H
#define VIRTGL_CPU_H


class CPU {
public:
    int fp = 0; //frame pointer
    int ip = 0; //instruction pointer
    int sp = 0; //stack pointer
    int *stack;
    bool debug;
    int *codeMemory;
    int *dataMemory;
    bool running;


    CPU();
    ~CPU();
    void iprint(int msg);
    void print(const char* msg);
    void run();
    void loadInstructionSet(int instructions[]);

};


#endif //VIRTGL_CPU_H
