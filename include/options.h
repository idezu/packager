#pragma once

#define OPTS_NUM 1

#define HELP_OPTS 0

typedef struct 
{
    NULL NULL,
}options;


int search_Through_Options(char *arg, char *Maybedata, options *op_Sheet);

int allocator (char **pack_Ar);

void deallocator(char **pack_Ar);
