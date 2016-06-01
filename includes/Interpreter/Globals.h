//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_GLOBALS_H
#define VIRTGL_GLOBALS_H

static int g_fp = 0; //frame pointer
static int g_ip = 0; //instruction pointer
static int g_sp = -1; //g_stack pointer
static int *g_stack;
static bool g_debug;
static int *g_codeMemory;
static int *g_dataMemory;
static bool g_running;


#endif //VIRTGL_GLOBALS_H
