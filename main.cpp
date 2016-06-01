#include <iostream>
#include "ByteCode.h"


using namespace std;

int fp = 0;
int ip = 0;
int sp = 0;
int *stack;
int *codeMemory;
int *dataMemory;
//int codeMemory
//int dataMemory = [];

void init(int dataSize, int codeSize, int stackSize){
    fp = 0;
    ip = 0;
    sp = 0;
    stack       = new int[  stackSize   ];
    codeMemory  = new int[  codeSize    ];
    dataMemory  = new int[  dataSize    ];

}

bool CPU() {
    cout << "test" << endl;
    int opcode = codeMemory[fp];
    switch (opcode) {
        case ByteCode::IADD : {
                int x = stack[sp];
            break;
        }
        case ByteCode::HALT : {
            return false;
            break;
        }
    }
}

int main(int argc, const char* argv[]) {
    bool _running = true;
    init(0,0,100);
    while (_running) {

        //CPU cycle
        _running = CPU();
#ifdef debug
        // if in debug mode then output trace
        outputStackTrace();
#endif

    }


    return 0;
}