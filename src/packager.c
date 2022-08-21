/* packager.c
 *
 * Copyright 2022 idezu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <global.h>

struct cmd_s 
{
  	char *name;
  	void (*callback)( int, char ** );
  	void (*help)( void );
} 
cmd_table[] = {
//  	{ "convert", convert_main, convert_help },
//  	{ "convertdb", convertdb_main, convertdb_help },
//  	{ "create", create_main, create_help },
//  	{ "createdb", createdb_main, createdb_help },
//  	{ "dumpdb", dumpdb_main, dumpdb_help },
	{ "sources", sources, sources_help },
  	{ "install", install, install_help },
//  	{ "remove", remove_main, remove_help },
//  	{ "repairdb", repairdb_main, repairdb_help },
//  	{ "status", status_main, status_help },
  	{ NULL, NULL, NULL }
};

void version_callback();
void Help();



int main (int argc, char *argv[], char *env[])
{

		// allocate the variable needed
	
	char *exec_Name = *argv, *cmd_Name = NULL, **cmd_argv = NULL;
	int arg_Add = 0, cmd_argc = 0, error = 0;
	bool help = false;
		//for global variables
	for (size_t i = 0; i < argc; i++)
	{
		char *curr = argv[i];
		if (!strcmp(curr,"--help") || !strcmp(curr,"-h"))
		{
			help = true;
		}else if (!strcmp(curr, "--version") || strcmp(curr,"-v"))
		{
			version_callback();
			exit(EXIT_SUCCESS);
		}else if (*curr = '-')
		{
			cmd_Name = curr;
			cmd_argc = argc - i - 1;
			if ( cmd_argc > 0 ) cmd_argv = argv + i + 1;
     		else cmd_argv = NULL;
      		break;
		}else
		{
			cmd_argc = argc - i - 1;
			if ( cmd_argc > 0 ) cmd_argv = argv + i + 1;
     		else cmd_argv = NULL;
			break;
		}
		

	}

	if (!strcmp(exec_Name, "installck"))
	{
		if (help)
		{
			install_help();
		}
		
		install(cmd_argc,cmd_argv);
	}else if (!strcmp(exec_Name, "sourcesck"))
	{
		if (help)
		{
			sources_help();
		}

		sources(cmd_argc,cmd_argv);
	}else
	{	//we'll search the command name		
		
		if ( help )
		{
			if (cmd_Name)
			{
				for (int i = 0, error = 5; cmd_table[i].name != NULL ; ++i)
				{
					if ( cmd_table[i].help ) 
					{
						cmd_table[i].help();
						error = 0;
					}
					else fprintf( stderr, "Unknown command %s.  Try 'mpkg --help'.\n", cmd_Name );
					break;
				}
			}else Help();
		}else if ( error == 0 ) 
		{
			if ( cmd_Name ) 
			{
				for(int i = 0, error = 5; cmd_table[i].name != NULL ; ++i) 
				{
					if ( strcmp( cmd_Name, cmd_table[i].name ) == 0 ) 
					{
						if ( cmd_table[i].callback ) 
						{
							cmd_table[i].callback( cmd_argc, cmd_argv );
							error = 0;
						}
						else fprintf( stderr, "Command %s not implemented\n", cmd_table[i].name );
						break;
					}
				}

				if ( error != 0 ) fprintf( stderr, "Unknown command %s.  Try 'mpkg --help'.\n", cmd_Name );
			}
			else fprintf( stderr, "A command is required.  Try 'mpkg --help'.\n" );
		}
		
	}

	return EXIT_SUCCESS;
}

void Help()
{
	printf( "This is the package global options.  It gives usage information" );
  	printf( " on specified packager commands.  Usage:\n" );
  	printf( "\n" );
  	printf( "packager --help [command]\n" );
	for (size_t i = 0; i < 3; i++)
	{
		cmd_table[i].help();
	}
	for (size_t i = 0; i < NUMBER_OF_INSTALL_OPTIONS; i++)
	{
		printf("%s, %s\t%s\n\t%s",install_options->symbole,install_options->truc,install_options->name,install_options->usage);
	}
	for (size_t i = 0; i < NUMBER_OF_SOURCES_OPTIONS; i++)
	{
		printf("%s, %s\t%s\n\t%s",sources_options->symbole,sources_options->truc,sources_options->name,sources_options->usage);
	}
	
	
}

void version_callback()
{
#ifdef BUILD_DATE
	printf( "packager %s, built on %s\n", VERSION, BUILD_DATE );
#else /* !defined(BUILD_DATE) */	
	printf( "packager %s\n", VERSION );
#endif /* BUILD_DATE */
	printf("packager  Copyright (C) 2022  idezu\n");
	printf("This program comes with ABSOLUTELY NO WARRANTY;\n");
	printf("This is free software, and you are welcome to \n");
	printf("redistribute it under certain conditions;");
}
