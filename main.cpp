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

void init(){


    //need to load code memory

}

bool CPU() {
    cout << "test" << endl;
    int opcode = codeMemory[cp++];
    switch (opcode) {
        case ByteCode::IADD : {

            break;
        }
        case ByteCode::PRINT : {
                print("test");
            break;
        }
        case ByteCode::HALT : {
            return false;
        }
    }
}

int main(int argc, const char* argv[]) {
    bool _running = true;

    int dataSize = 0;
    int codeSize = 0;
    int stackSize = 0;
    int startPoint = 0;

    fp = 0;
    cp = startPoint;
    sp = -1;
    stack       = new int[  stackSize   ];
    codeMemory  = new int[  codeSize    ];
    dataMemory  = new int[  dataSize    ];
    codeMemory[0] = ByteCode::HALT;
    while (_running) {
        //CPU cycle
        _running = CPU();
    }

    free(stack);
    free(codeMemory);
    free(dataMemory);

    return 0;
}