#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define TRUE  0
#define FALSE 1

typedef int flag_t;

void print_help(void);
void print_version(void);
void print_recursive(void);
void copy(char *src_file_name,char *dest_file_name);

static struct option opts_arr[] = 
{
	/* data */
	{"help",no_argument,0,'h'},
	{"version",no_argument,0,'v'},
	{"recursive",no_argument,0,'R'},
	{"src",required_argument,0,'s'},
	{"dest",required_argument,0,'d'},
	{0,0,0,0}
};

int val,i = 0;
char *src,*dest;

flag_t s_used = FALSE,d_used = FALSE;

int main(int argc,char *argv[])
{
		while((val = getopt_long(argc,argv,"hvRs:d:",opts_arr,&i))!= -1)
		{
			switch((char)val)
			{
				case 0:

				case 'h':	print_help();
							break;		

				case 'v':
							print_version();
							break;
				case 'R':
							print_recursive();
							break;
				case 's':
							s_used = TRUE;
							src = optarg;	
							break;
				case 'd':
							d_used = TRUE;
							dest = optarg;
							copy(src,dest);
							break;
				default:
							printf("\nINVALID\n");
							exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
}						

void copy(char *src_file_name,char *dest_file_name)
{
	if(s_used ^ d_used)
	{
		printf("Problem with argument passing\n");
	}
	else
	{
		printf("\nSrc=%s",src_file_name);
		printf("\ndest=%s",dest_file_name);
	}
}

void print_recursive(void)
{
	printf("\nThe Recursive option is used\n");
}


void print_help(void)
{
	static const char helpstr[] = "\n This is help, \
	use h/help,v/version,R/recursive s/src: d/dest:\nThank you!\n";

	printf(helpstr);
}

void print_version(void)
{
	printf("\nThis is version 1.0\n");
}