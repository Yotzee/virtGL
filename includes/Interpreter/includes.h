//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_INCLUDES_H
#define VIRTGL_INCLUDES_H

#include <iostream>
using namespace std;


struct _Instruction{
public:
    static int bytecode;
    static int ftnPtr;
};

static _Instruction POP;

#endif //VIRTGL_INCLUDES_H
