#include <iostream>
#include "ByteCode.h"


using namespace std;

int fp = 0; //frame pointer
int cp = 0; //code pointer
int sp = 0; //stack pointer
int *stack = NULL;
int *codeMemory = NULL;
int *dataMemory = NULL;
bool _running = true;

void print(const char *msg) {
    std::printf("%s\r\n",msg);
}

void CPU() {
    std::printf("CP:%04d\t",cp);
    int opcode = codeMemory[cp++];
    switch (opcode) {
        case ByteCode::IADD : {
            break;
        }
        case ByteCode::PRINT : {
            print("printing some stuff");
            break;
        }
        case ByteCode::HALT : {
            _running = false;
            break;
        }
    }
}

void loadInstructionSet() {
    codeMemory[0] = ByteCode::PRINT;
    //codeMemory[1] = ByteCode::PRINT;
    codeMemory[1] = ByteCode::HALT;

}

int main(int argc, const char *argv[]) {


    int dataSize = 100;
    int codeSize = 100;
    int stackSize = 100;
    int startPoint = 0;

    fp = 0;
    cp = startPoint;
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