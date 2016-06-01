//
// Created by Greg Yotz on 5/31/16.
//

#include "CPU.h"
#include "../ByteCodes/BC.h"
#include <iostream>

using namespace std;

CPU::CPU() {
    running = true;
    int instructions[] = {
            BC::ICONST, 800,
            BC::GSTORE, 1,
            BC::GLOAD, 1,
            BC::ICONST, 45,
            BC::IADD,
            BC::IPRINT,
            BC::HALT,
    };


    int dataSize = 100;
    int codeSize = 100;
    int stackSize = 100;
    int startPoint = 0;

    fp = 0;
    ip = startPoint;
    sp = -1;

    stack = new int[stackSize];
    memset(stack, 0, stackSize * sizeof(int));

    codeMemory = new int[sizeof(instructions)];
    memset(codeMemory, 0, codeSize * sizeof(int));

    dataMemory = new int[dataSize];
    memset(dataMemory, 0, dataSize * sizeof(int));


    loadInstructionSet(instructions);
};

CPU::~CPU() {

    delete[] stack;
    delete[] codeMemory;
    delete[] dataMemory;
};

void CPU::iprint(int msg) {
    std::printf("SYSOUT: %d\r\n", msg);
}

void CPU::print(const char *msg) {
    std::printf("SYSOUT: %s\r\n", msg);
}

void CPU::run() {

    while (running) {
        int opcode = codeMemory[ip];
        if(debug){
            std::printf("CP:%04d\t Inst:%d\r\n", ip, opcode);
        }

        ip++;

        switch (opcode) {
            case BC::IADD : {
                int b = stack[sp--];
                int a = stack[sp--];
                stack[++sp] = a + b;
                break;
            }
            case BC::ISUB : {
                int b = stack[sp--];
                int a = stack[sp--];
                stack[++sp] = a - b;
                break;
            }
            case BC::IPRINT : {
                int i = stack[sp--];
                iprint(i);
                break;
            }
            case BC::ICONST : {
                int i = codeMemory[ip++];
                stack[++sp] = i;
                break;
            }
            case BC::GLOAD: {
                int addr = codeMemory[ip++];
                int v = dataMemory[addr];
                stack[++sp] = v;
                break;
            }
            case BC::GSTORE : {
                int v = stack[sp--];
                int addr = codeMemory[ip++];
                dataMemory[addr] = v;
                break;
            }
            case BC::POP : {
                break;
            }
            case BC::CALL : {
                break;
            }
            case BC::RET : {
                break;
            }
            case BC::HALT : {
                running = false;
                break;
            }
            case 0: {
                running = false;
                // code memory overflow?
                std::printf("%s", "code memory overflow?");
                break;
            }
        }
    }

}


void CPU::loadInstructionSet(int instructions[]) {
    //TODO: load from file at some point
    for (int i = 0; i < sizeof(instructions); i++) {
        codeMemory[i] = instructions[i];
    }
}