//
// Created by Greg Yotz on 5/31/16.
//

#ifndef VIRTGL_BYTECODE_H
#define VIRTGL_BYTECODE_H
#include <iostream>

class BC {
public:

    BC();

    ~BC();

    int* instructions = NULL;

    static const int POP = 1;
    static const int PUSH = 2;

    static const int RET = 3;
    static const int CALL = 4;
    static const int ICONST = 5;
    static const int HALT = 6;
    static const int IPRINT = 7;

    static const int GSTORE = 8;
    static const int GLOAD = 9;

    static const int STORE = 10;
    static const int LOAD = 11;

    static const int IADD = 12;
    static const int ISUB = 13;
    static const int IMUL = 14;
    static const int IDIV = 15;
    static const int FADD = 16;
    static const int FSUB = 17;
    static const int FMUL = 18;
    static const int FDIV = 19;




};


#endif //VIRTGL_BYTECODE_H
