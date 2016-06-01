//
// Created by Greg Yotz on 5/31/16.
//

#ifndef VIRTGL_BYTECODE_H
#define VIRTGL_BYTECODE_H

static enum ByteCode{
    HALT = 0x100, // system codes
    ICONST,PRINT,
    IADD,ISUB,IMUL,IDIV, //integer math codes
    FADD,FSUB,FMUL,FDIV  //float math codes

} byteCode;




#endif //VIRTGL_BYTECODE_H
