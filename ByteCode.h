//
// Created by Greg Yotz on 5/31/16.
//

#ifndef VIRTGL_BYTECODE_H
#define VIRTGL_BYTECODE_H

//static enum ByteCode{
//    HALT = 0x10, // system codes
//    ICONST,PRINT,
//    IADD,ISUB,IMUL,IDIV, //integer math codes
//    FADD,FSUB,FMUL,FDIV  //float math codes
//
//} byteCode;

static class ByteCode {
public:
    // System

    static const int POP = 0x01;
    static const int PUSH = 0x02;
    static const int ICONST = 0x09;
    static const int HALT = 0x10;
    static const int IPRINT = 0x11;

    //set value at addr into data memory
    static const int GSTORE = 0x12;
    //load value at addr into stack
    static const int GLOAD = 0x13;


    // Maths
    static const int IADD = 0x21;
    static const int ISUB = 0x22;
    static const int IMUL = 0x23;
    static const int IDIV = 0x24;
    static const int FADD = 0x25;
    static const int FSUB = 0x26;
    static const int FMUL = 0x27;
    static const int FDIV = 0x28;




};


#endif //VIRTGL_BYTECODE_H
