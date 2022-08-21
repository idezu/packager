#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <options.h>

int allocator (char **pack_Ar)
{
  	int status = EXIT_FAILURE;

	if ((pack_Ar = malloc(sizeof(char)*256000000 * pow(8,2))) == NULL)
		{
			fprintf(stderr,"can't assigned memory with malloc");
			goto Alloc_Failure;
		}


	status = EXIT_SUCCESS;
Alloc_Failure:

  	return status;
}

void deallocator(char **pack_Ar)
{
	free(pack_Ar);
}

/* update the options_Sheet accordingly
 * return how much
 * return a negative value if an error occurred
*/
int search_Through_Options(char *arg, char *Maybedata, options *op_Sheet)
{
	if (*arg != '-')
  	{
		return -1;
  	}else
	{
    	op_Sheet = malloc(OPTS_NUM);
    	for (size_t i = 0; i < OPTS_NUM; i++)
    	{
      		op_Sheet[i] = 0;
    	}
    	char *two_First_Char = NULL;
    	two_First_Char[0] = arg[0];
    	two_First_Char[1] = arg[1];
    	/*check if arg start with "--" for some optimisations*/
    	if (!strcmp (two_First_Char,"--"))
    	{
      		if (strcmp (arg, "--help"))
      		{
        		op_Sheet[HELP_OPTS]++;
        		if (!op_Sheet[HELP_OPTS])
        		{
          			fprintf (stderr, "multiple %s given", arg);
          			return -2;
        		}else
        		{
          			fprintf (stderr, "didn't recognized %s",arg);
          			return sizeof(int)-1;
				}
    		}
			else if (strcmp(arg, "--version"))
			{
				return -3;
			}
    	}else
    	{
      		if (strcmp(arg,"-h"))
      		{
        		op_Sheet[HELP_OPTS]++;
        		if (!op_Sheet[HELP_OPTS])
        		{
          			fprintf (stderr, "multiple %s given", arg);
          			return -2;
        		}else
        		{
          			fprintf (stderr, "didn't recognized %s",arg);
          			return sizeof(int)-1;
        		}
	  		}
		}
	}
}
