//
// Created by Greg Yotz on 5/31/16.
//

#include "../includes.h"
#include "BC.h"

BC::BC() {
    //BC Constructor
    instructions = new int[65535];
}

BC::~BC(){
    //BC Destructor
    delete[] instructions;
}