#virtGL 
OpenGL based Graphic Engine

##ByteCodes
Implemented Instructions

System

    Operator    Instruction     Description
    DEBUG       0x06            Sets Debug Flag to true
    CALL        0x07            Call function
    RET         0x08            Return from Function
    HALT        0x09            HALT VM
    ICONST      0x10            Push Integer onto Stack
    IPRINT      0x11            Integer Print
    GISTORE     0x12            g_stack to datamemory at addr
    GILOAD      0x13            move datamemory at addr to g_stack


Maths

    Operator    Instruction     Description
    IADD        0x21            Integer Add
    ISUB        0x22            Integer Subtract
    IMUL        0x23            Integer Multiply
    IDIV        0x24            Integer Divid
    FADD        0x25            Float Add
    FSUB        0x26            Float Subtract
    FMUL        0x27            Float Multiply
    FDIV        0x28            Float Divid