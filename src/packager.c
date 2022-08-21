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

#include <options.h>
#include <packages.h>

char *version = "packager  Copyright (C) 2022  idezu\nThis program comes with ABSOLUTELY NO WARRANTY;\nThis is free software, and you are welcome to redistribute it\nunder certain conditions;";

int install(const options flags,char *packages_Install[])
{

}

int sources(const options flags,char *packages_Merge[])
{

}

void packager(int argc,char *argv[],options *flags ,char *package_list[])
{
	if (strcmp(argv[1], "install"))
	{
		for (size_t i = 2; i < argc; i++)
		{
			int arg_Add = 0;
			char *buffer = argv[i];
			if (i < argc-1)
			{
				arg_Add = search_Through_Options(buffer, argv[i+1], flags );
			}else search_Through_Options (buffer, NULL, flags );

			if (arg_Add < -1)
			{
				exit(EXIT_FAILURE);
			}else if (arg_Add == -1)
			{
					find_Packages(package_list, buffer);
			}else if (arg_Add == -3)
			 	{
			 		printf("%s", version);
			 	}
			i += arg_Add;
		}
		install(*flags ,package_list);
	}else if (strcmp(argv[1], "sources"))
	{
		for (size_t i = 2; i < argc; i++)
		{
			int arg_Add = 0;
			char *buffer = argv[i];
			if (i < argc-1)
			{
				arg_Add = search_Through_Options(buffer, argv[i+1], flags );
			}else search_Through_Options (buffer, NULL, flags );

			if (arg_Add < -1)
			{
				exit(EXIT_FAILURE);
			}else if (arg_Add == -1)
			{
					find_Packages(package_list, buffer);
			}
			i += arg_Add;
		}
		sources(*flags ,package_list);
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
	options flags;
	

	if (*argv[0] == '-')
	{
		fprintf(stderr, "you entered no name for the application");
		exit(EXIT_FAILURE);
	}
	if (strcmp(*argv, "packager"))
	{
		packager(argc,argv,&flags,packages_ar);
	}
	else if (strcmp(*argv, "installck"))
	{
		for (size_t i = 1; i < argc; i++)
		{
			char *buffer = argv[i];
			if (i < argc-1)
			{
				arg_Add = search_Through_Options(buffer, argv[i+1], &flags);
			}else search_Through_Options (buffer, NULL, &flags);

			if (arg_Add < -1)
			{
				exit(EXIT_FAILURE);
			}else if (arg_Add == -1)
			{
					find_Packages(packages_ar, buffer);
			}
			i += arg_Add;
		}
		install(flags,packages_ar);
	}else if (strcmp(*argv, "sourcesck"))
	{
		for (size_t i = 1; i < argc; i++)
		{
			char *buffer = argv[i];
			if (i < argc-1)
			{
				arg_Add = search_Through_Options(buffer, argv[i+1], &flags);
			}else search_Through_Options (buffer, NULL, &flags);

			if (arg_Add < -1)
			{
				exit(EXIT_FAILURE);
			}else if (arg_Add == -1)
			{
					find_Packages(packages_ar, buffer);
			}
			i += arg_Add;
		}
		sources(flags,packages_ar);
	}else
	{
		packager(argc,argv,&flags,packages_ar);
	}




	printf("Hello, World!\n");
	return EXIT_SUCCESS;
}

