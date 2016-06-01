#include <iostream>
#include "includes/Interpreter/CPU/CPU.h"
#include <stdio.h>

using namespace std;

int main(int argc, const char *argv[]) {

    CPU cpu;
    cpu.run(argc, argv);

    return 0;
}