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
#include <dirent.h>

#include <options.h>
#include <packages.h>

char *version = "packager  Copyright (C) 2022  idezu\nThis program comes with ABSOLUTELY NO WARRANTY;\nThis is free software, and you are welcome to redistribute it\nunder certain conditions;";

int install(bool *flags,char *packages[])
{

}

int install_Local(bool *flags, FILE *package)
{


	fclose(package);
}

int sources(bool * flags,char *packages[])
{

}

void packager(int argc,char *argv[],bool *caller_Flag,char *package_list[])
{
	if (strcmp(argv[1], "install"))
	{
		int local_Pkg_C = 0;
		char **local_Pkg = NULL;
		int package_C = 0;
		for (size_t i = 2; i < argc; i++)
		{
			int arg_Add = 0;
			char *buffer = argv[i];
			printf("searching through the database...\n");
			if (i < argc-1)
			{
				arg_Add = search_Through_Options(buffer, argv[i+1], caller_Flag);
			}else search_Through_Options (buffer, NULL, caller_Flag);

			if (arg_Add < -1)
			{
				exit(EXIT_FAILURE);
			}else if (arg_Add == -1)
			{
				FILE *package_File= NULL;
				//check if it's a local package 
				if ((package_File = fopen(buffer,"r")) != NULL)
				{	
					check_package(buffer,local_Pkg);
					local_Pkg_C ++;
					break;
				}
				fclose(package_File);
				package_C++;
				find_Packages(package_list, buffer);

			}else if (arg_Add == -3)
			{
				printf("%s", version);
				exit(EXIT_SUCCESS);
			}
			i += arg_Add;
		}
		printf("you're going to install"); 
		for (size_t i = 0; i < package_C; i++)
		{
			printf(" %s",package_list[i]);
		}
		printf("and");
		for (size_t i = 0; i < local_Pkg_C; i++)
		{
			printf("%s",local_Pkg);
		}
		
		printf("\n");
		char *answer;
		fscanf(stdin,"%s",&answer);			
		install(caller_Flag,package_list);
	}else if (strcmp(argv[1], "sources"))
	{
		for (size_t i = 2; i < argc; i++)
		{
			int arg_Add = 0;
			char *buffer = argv[i];
			if (i < argc-1)
			{
				arg_Add = search_Through_Options(buffer, argv[i+1], caller_Flag);
			}else search_Through_Options (buffer, NULL, caller_Flag);

			if (arg_Add < -1)
			{
				exit(EXIT_FAILURE);
			}else if (arg_Add == -1)
			{
					find_Packages(package_list, buffer);
			}
			i += arg_Add;
		}
		sources(caller_Flag,package_list);
	}
}


int main (int argc, char *argv[])
{

	// allocate the variable needed
	char **packages_ar = NULL;
	if (allocator(packages_ar))
		{
			deallocator(packages_ar);
		}
	int arg_Add = 0;
	bool *caller_Flag = NULL;

	if (*argv[0] == '-')
	{
		fprintf(stderr, "you entered no name for the application");
		exit(EXIT_FAILURE);
	}
	if (strcmp(*argv, "packager"))
	{
		packager(argc,argv,caller_Flag,packages_ar);
	}
	else if (strcmp(*argv, "installck"))
	{
		for (size_t i = 1; i < argc; i++)
		{
			char *buffer = argv[i];
			if (i < argc-1)
			{
				arg_Add = search_Through_Options(buffer, argv[i+1], caller_Flag);
			}else search_Through_Options (buffer, NULL, caller_Flag);

			if (arg_Add < -1)
			{
				exit(EXIT_FAILURE);
			}else if (arg_Add == -1)
			{
					find_Packages(packages_ar, buffer);
			}
			i += arg_Add;
		}
		install(caller_Flag,packages_ar);
	}else if (strcmp(*argv, "sourcesck"))
	{
		for (size_t i = 1; i < argc; i++)
		{
			char *buffer = argv[i];
			if (i < argc-1)
			{
				arg_Add = search_Through_Options(buffer, argv[i+1], caller_Flag);
			}else search_Through_Options (buffer, NULL, caller_Flag);

			if (arg_Add < -1)
			{
				exit(EXIT_FAILURE);
			}else if (arg_Add == -1)
			{
					find_Packages(packages_ar, buffer);
			}
			i += arg_Add;
		}
		sources(caller_Flag,packages_ar);
	}

	else
	{
		packager(argc,argv,caller_Flag,packages_ar);
	}




	printf("Hello, World!\n");
	return EXIT_SUCCESS;
}

