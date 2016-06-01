#include <iostream>
#include "includes/BC.h"


using namespace std;

int fp = 0; //frame pointer
int ip = 0; //instruction pointer
int sp = 0; //stack pointer
int *stack = NULL;
int *codeMemory = NULL;
int *dataMemory = NULL;
bool _running = true;

void iprint(int msg) {
    std::printf("SYSOUT: %d\r\n", msg);
}

void print(const char *msg) {
    std::printf("SYSOUT: %s\r\n", msg);
}

void CPU() {

    int opcode = codeMemory[ip];
    std::printf("CP:%04d\t Inst:%d\r\n", ip, opcode);

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
            _running = false;
            break;
        }
        case 0: {
            _running = false;
            // code memory overflow?
            std::printf("%s", "code memory overflow?");
        }
    }
}

const int instructions[] = {

        BC::ICONST, 800,
        BC::GSTORE, 1,
        BC::GLOAD, 1,
        BC::ICONST, 45,
        BC::IADD,
        BC::IPRINT,
        BC::HALT,
};

void loadInstructionSet() {
    //TODO: load from file at some point
    for (int i = 0; i < sizeof(instructions); i++) {
        codeMemory[i] = instructions[i];
    }
}

int main(int argc, const char *argv[]) {


    int dataSize = 100;
    int codeSize = 100;
    int stackSize = 100;
    int startPoint = 0;

    fp = 0;
    ip = startPoint;
    sp = -1;

    stack = new int[stackSize];
    memset(stack,0,stackSize * sizeof(int));

    codeMemory = new int[codeSize];
    memset(codeMemory,0,codeSize * sizeof(int));

    dataMemory = new int[dataSize];
    memset(dataMemory,0,dataSize * sizeof(int));

    loadInstructionSet();

    while (_running) {
        //CPU cycle
        CPU();
    }

    delete[] stack;
    delete[] codeMemory;
    delete[] dataMemory;

    return 0;
}