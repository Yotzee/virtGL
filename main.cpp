#include <iostream>
#include "includes/Interpreter/CPU/CPU.h"

using namespace std;


int main(int argc, const char *argv[]) {

    CPU cpu;
    cpu.debug = false;
    cpu.run();

    return 0;
}