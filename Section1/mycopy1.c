#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TRUE	0
#define FALSE 	1

char *src_file_name = NULL;
char *out_file_name = NULL;
int ret;
	
typedef int flag_t;

flag_t s_used = FALSE;
flag_t o_used = FALSE;

void print_help();
void print_version();
void copy(char *,char *);

int main(int argc,char *argv[])
{
	while((ret = getopt(argc,argv,"s:o:hv"))!= -1)	
	{
		switch((char)ret)
		{
			case 'h':
						print_help();
						break;
			case 'v':
						print_version();
						break;
			case 's':	
						src_file_name = optarg;
						if(strcmp("-h",optarg) == 0 || strcmp("-v",optarg) == 0)
							s_used = FALSE;
						else
							s_used = TRUE;		
						break;
			case 'o':	
						out_file_name = optarg;
						if(strcmp("-h",optarg) == 0 || strcmp("-v",optarg) == 0)
							o_used = FALSE;
						else
							o_used = TRUE;
						break;										
		}
	}

	if(s_used == TRUE && o_used == TRUE)
	{
		copy(src_file_name,out_file_name);
	}
	else 
	{
		printf("Invalid Input\n");
		printf("after -s and -o,file name is expected.\n");
		
	}
	return 0;
	exit(EXIT_SUCCESS);
}

void copy(char *src_file_name,char *out_file_name)
{
	printf("\nWe will copy from here\n");
	printf("\nsrc name=%s out_file_name=%s\n",src_file_name,out_file_name);
}

void print_help()
{
	printf("\nThis has -s: -o: -h -v option\n");
}

void print_version()
{
	printf("\nThis is version 1.0\n");
}