#pragma once

struct S_options
{
    char *name;
    char *usage;
    char *symbole;
    char *truc;
}
sources_options[] = {
    { "", "", "", ""}
};

#define NUMBER_OF_SOURCES_OPTIONS 1

void sources_help( void );
void sources (int , char **);