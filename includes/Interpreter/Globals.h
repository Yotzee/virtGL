//
// Created by Greg Yotz on 6/1/16.
//

#ifndef VIRTGL_GLOBALS_H
#define VIRTGL_GLOBALS_H

static int g_fp = 0; //frame pointer
static int g_ip = 0; //instruction pointer
static int g_sp = -1; //g_stack pointer
static char* g_stack;
static char *g_codeMemory;
static char *g_dataMemory;
void (*g_instructionMap[255])() = {NULL};

static bool g_running;
static bool g_debug;

#endif //VIRTGL_GLOBALS_H
