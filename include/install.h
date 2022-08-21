#pragma once

struct I_options
{
    char *name;
    char *usage;
    char *symbole;
    char *truc;
}
install_options[] = {
    { "", "", "", ""}
};

#define NUMBER_OF_INSTALL_OPTIONS 1

void install_help( void );
void install (int , char **);