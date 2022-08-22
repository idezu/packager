#pragma once

#include <global.h>

struct options install_options[] = 
{
    { NULL, NULL, NULL, NULL, NULL }    
};


void install_help( void );
void install (int , char **);
void i_r_usage(void);
void install_root(char *,char **);


#define NUMBER_OF_INSTALL_OPTIONS 1