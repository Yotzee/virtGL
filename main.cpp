#include <iostream>
#include "ByteCode.h"


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
        case ByteCode::IADD : {
            int b = stack[sp--];
            int a = stack[sp--];
            stack[++sp] = a + b;
            break;
        }
        case ByteCode::ISUB : {
            int b = stack[sp--];
            int a = stack[sp--];
            stack[++sp] = a - b;
            break;
        }
        case ByteCode::IPRINT : {
            int i = stack[sp--];
            iprint(i);
            break;
        }
        case ByteCode::ICONST : {
            int i = codeMemory[ip++];
            stack[++sp] = i;
            break;
        }
        case ByteCode::GLOAD: {
            int addr = codeMemory[ip++];
            int v = dataMemory[addr];
            stack[++sp] = v;
            break;
        }
        case ByteCode::GSTORE : {
            int v = stack[sp--];
            int addr = codeMemory[ip++];
            dataMemory[addr] = v;
            break;
        }
        case ByteCode::HALT : {
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

        ByteCode::ICONST, 455,
        ByteCode::GSTORE, 1,
        ByteCode::GLOAD, 1,
        ByteCode::ICONST, 45,
        ByteCode::IADD,
        ByteCode::IPRINT,
        ByteCode::HALT,
};

void loadInstructionSet() {
    //TODO: load from file at some point

    int i = 0;
    for (i = 0; i < sizeof(instructions); i++) {
        codeMemory[i] = instructions[i];
    }

    cout << "nInstructions: " << i << endl;

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
    codeMemory = new int[codeSize];
    dataMemory = new int[dataSize];

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