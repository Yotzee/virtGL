#include <iostream>
#include "ByteCode.h"


using namespace std;

int fp = 0; //frame pointer
int cp = 0; //code pointer
int sp = 0; //stack pointer
int *stack;
int *codeMemory;
int *dataMemory;

void print(const char* msg){
    cout << msg << endl;
}

void init(int dataSize, int codeSize, int stackSize, int startPoint){
    fp = 0;
    cp = startPoint;
    sp = -1;
    stack       = new int[  stackSize   ];
    codeMemory  = new int[  codeSize    ];
    dataMemory  = new int[  dataSize    ];

}

bool CPU() {
    cout << "test" << endl;
    int opcode = codeMemory[cp++];
    switch (opcode) {
        case ByteCode::IADD : {
                int x = stack[sp];
            break;
        }
        case ByteCode::PRINT : {
                print("test");
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