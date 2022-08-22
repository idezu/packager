#pragma once

#include <global.h>

struct options sources_options[] = 
{
    { NULL, NULL, NULL, NULL, NULL }    
};

void sources_help( void );
void sources (int , char **);

#define NUMBER_OF_SOURCES_OPTIONS 1

