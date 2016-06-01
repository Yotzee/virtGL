//
// Created by Greg Yotz on 5/31/16.
//

#ifndef VIRTGL_CPU_H
#define VIRTGL_CPU_H


class CPU {
public:
    int dataSize;
    int codeSize;
    int stackSize;
    int startPoint;

    CPU();
    ~CPU();
    void run(int argc, const char *argv[]);
    void loadInstructionSet(int instructions[]);

};


#endif //VIRTGL_CPU_H
