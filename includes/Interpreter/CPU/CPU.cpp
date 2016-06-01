//
// Created by Greg Yotz on 5/31/16.
//

#include "../includes.h"
#include "../Globals.h"
#include "CPU.h"
#include "../ByteCodes/BC.h"
#include "../Instructions/Math/Integer.h"
#include "../Instructions/System/Print.h"
#include "../Instructions/System/System.h"

CPU::CPU() {
    g_running = true;


    char instructions[] = {
            BC::ICONST, 22,
            BC::GISTORE, 0,
            BC::GILOAD, 0,
            BC::ICONST, 45,
            BC::IADD,
            BC::IPRINT,
            BC::HALT,
    };



    g_fp = 0;
    g_ip = startPoint;
    g_sp = -1;
    codeSize = sizeof(instructions);
    dataSize = 100;
    stackSize = 100;
    startPoint = 0;

    g_stack = (char*)malloc(stackSize * sizeof(char));
    memset(g_stack, 0, stackSize * sizeof(char));

    g_codeMemory = (char*)malloc(stackSize * sizeof(char));
    memset(g_codeMemory, 0, codeSize * sizeof(char));

    g_dataMemory = (char*)malloc(stackSize * sizeof(char));
    memset(g_dataMemory, 0, dataSize * sizeof(char));


    loadInstructionSet(instructions);

};

CPU::~CPU() {

    free(g_stack);
    free(g_codeMemory);
    free(g_dataMemory);
};

void CPU::run(int argc, const char *argv[]) {
    g_debug = true;
    while (g_running) {
        int opcode = (int)g_codeMemory[g_ip];
        if(g_debug){
            std::printf("CP:%04d\t Inst:%d\r\n", g_ip, opcode);
        }

        g_ip++;

        switch (opcode) {

            case BC::IADD : {
                iadd();
                break;
            }
            case BC::ISUB : {
                break;
            }
            case BC::IPRINT : {
                iprint();
                break;
            }
            case BC::ICONST : {
                iconst();
                break;
            }
            case BC::GISTORE : {
                gistore();
                break;
            }
            case BC::GILOAD : {
                giload();
                break;
            }
//            case BC::GLOAD: {
//                int addr = g_codeMemory[g_ip++];
//                int v = g_dataMemory[addr];
//                g_stack[++g_sp] = v;
//                break;
//            }
//            case BC::GSTORE : {
//                int v = g_stack[g_sp--];
//                int addr = g_codeMemory[g_ip++];
//                g_dataMemory[addr] = v;
//                break;
//            }
//            case BC::BC_POP : {
//                break;
//            }
//            case BC::CALL : {
//                break;
//            }
//            case BC::RET : {
//                break;
//            }
            case BC::HALT : {
                halt();
//                g_running = false;
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


void CPU::loadInstructionSet(char instructions[]) {
    //TODO: load from file at some point
    std::printf("\r\n");
    for (int i = 0; i < codeSize; i++) {
        g_codeMemory[i] = (char)instructions[i];
        std::printf("{{\\x%04x || %d}}\t",g_codeMemory[i],g_codeMemory[i]);
    }
    std::printf("\r\n");
}