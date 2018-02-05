//
// Created by Greg Yotz on 6/2/16.
//

#ifndef VIRTGL_TIME_H
#define VIRTGL_TIME_H

#include "../../includes.h"
#include "../../Globals.h"

void time(){
    std::time_t timev;
    std::time(&timev);
    g_stack[++g_sp] = (long)timev;
}

void init(){

}
#endif //VIRTGL_TIME_H
