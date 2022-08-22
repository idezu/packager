#pragma once

#include <install.h>
#include <sources.h>
#include <packages.h>

struct options
{
    char *name;
    char *symbole;
    char *option;
    void (*usage)(void);
    void (*callback)(char *, char**);
};

#define PROG_VER "0.0.1"