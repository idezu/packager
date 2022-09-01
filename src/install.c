#include <stdio.h>
#include <stdlib.h>

#include <install.h>



void i_r_usage(void)
{
    printf( "-r <directory>, --install-root <directory>\t" );
    printf( "<directory> can be either a relative path or a direct path\n" );
}

void install_root(char *directory,char **packages)
{

}

// TODO  install function
void install(int argc,char *argv[])
{

}

void install_help( void ) {
    printf( "Install packages.  Usage:\n" );
    printf( "\n" );
    printf( "packager [global options] install <package 1> <package 2> ...\n" );
    printf( "\n" );
    printf( "<package 1>, etc., are filenames of packages to install.\n" );
}