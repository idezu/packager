#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int find_Packages(char **package_Selected,char *package_Name)
{
	struct dirent ** package_List;
	scandir(package_Name, &package_List, NULL, NULL);
	if (sizeof(package_List) > sizeof(struct dirent))
	{

	}
	return EXIT_SUCCESS;
}

