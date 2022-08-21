#include <stdio.h>
#include <stdlib.h>

#include <install.h>

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