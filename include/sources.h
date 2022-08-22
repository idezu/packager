#pragma once

#include <global.h>

struct options sources_options[] = 
{
    { NULL, NULL, NULL, NULL, NULL }    
};

#define NUMBER_OF_SOURCES_OPTIONS 1

void sources_help( void );
void sources (int , char **);
