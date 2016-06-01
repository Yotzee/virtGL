//
// Created by Greg Yotz on 5/31/16.
//

#include "../includes.h"
#include "CPU.h"
#include "../ByteCodes/BC.h"

CPU::CPU() {
    g_running = true;
    dataSize = 100;
    codeSize = 11;
    stackSize = 100;
    startPoint = 0;

    int instructions[] = {
            BC::ICONST, 800,
            BC::GSTORE, 0,
            BC::GLOAD, 0,
            BC::ICONST, 45,
            BC::IADD,
            BC::IPRINT,
            BC::HALT,
    };



    g_fp = 0;
    g_ip = startPoint;
    g_sp = -1;

    g_stack = new int[stackSize];
    memset(g_stack, 0, stackSize * sizeof(int));

    g_codeMemory = new int[sizeof(instructions)];
    memset(g_codeMemory, 0, codeSize * sizeof(int));

    g_dataMemory = new int[dataSize];
    memset(g_dataMemory, 0, dataSize * sizeof(int));


    loadInstructionSet(instructions);
};

CPU::~CPU() {

    delete[] g_stack;
    delete[] g_codeMemory;
    delete[] g_dataMemory;
};

void CPU::iprint(int msg) {
    std::printf("SYSOUT: %d\r\n", msg);
}

void CPU::print(const char *msg) {
    std::printf("SYSOUT: %s\r\n", msg);
}

void CPU::run(int argc, const char *argv[]) {
    g_debug = true;
    while (g_running) {
        int opcode = g_codeMemory[g_ip];
        if(g_debug){
            std::printf("CP:%04d\t Inst:%d\r\n", g_ip, opcode);
        }

        g_ip++;

        switch (opcode) {
            case BC::IADD : {
                int b = g_stack[g_sp--];
                int a = g_stack[g_sp--];
                g_stack[++g_sp] = a + b;
                break;
            }
            case BC::ISUB : {
                int b = g_stack[g_sp--];
                int a = g_stack[g_sp--];
                g_stack[++g_sp] = a - b;
                break;
            }
            case BC::IPRINT : {
                int i = g_stack[g_sp--];
                iprint(i);
                break;
            }
            case BC::ICONST : {
                int i = g_codeMemory[g_ip++];
                g_stack[++g_sp] = i;
                break;
            }
            case BC::GLOAD: {
                int addr = g_codeMemory[g_ip++];
                int v = g_dataMemory[addr];
                g_stack[++g_sp] = v;
                break;
            }
            case BC::GSTORE : {
                int v = g_stack[g_sp--];
                int addr = g_codeMemory[g_ip++];
                g_dataMemory[addr] = v;
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
                g_running = false;
                break;
            }
            case 0: {
                g_running = false;
                // code memory overflow?
                std::printf("%s", "code memory overflow?");
                break;
            }
        }
    }

}


void CPU::loadInstructionSet(int instructions[]) {
    //TODO: load from file at some point
    std::printf("\r\n");
    for (int i = 0; i < codeSize; i++) {
        g_codeMemory[i] = instructions[i];
        std::printf("%04x",instructions[i]);
    }
    std::printf("\r\n");
}