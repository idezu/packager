#ifndef __INSTALL_H__
#define __INSTALL_H__

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

#endif