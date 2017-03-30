#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>


#define TRUE  		 1
#define FALSE 		 0


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

int ret,i = 0;

void print_help(void);
void print_version(void);
void print_recursive(void);
void copy(char *,char *);
typedef int flag_t;

flag_t s_used = FALSE,d_used = FALSE;

char *src,*dest;

int main(int argc, char *argv[])
{
	/* code */
	while((ret = getopt_long(argc,argv,"hvRs:d:",opts_arr,&i)) != -1)
	{
		switch((char)ret)
		{
			case 'h':
						print_help();
						break;
			case 'v':
						print_version();
						break;
			case 'R':
						print_recursive();		
						break;
			case 's':	
						
						src = optarg;
						if(strcmp("-h",src) == 0 || strcmp("-v",src) == 0)
							s_used = FALSE;
						else
							s_used = TRUE;	
						break;
			case 'd':
						
						dest = optarg;
						if(strcmp("-h",dest) == 0 || strcmp("-v",dest) == 0)
							d_used = FALSE;
						else
							d_used = TRUE;	
						
						break;
			default:
					printf("\nInvalid\n");
					exit(EXIT_FAILURE);			

		}
	}
	if(s_used == TRUE && d_used == TRUE)
	{
		copy(src,dest);
	}
	else if(s_used == FALSE && d_used == FALSE)
	{
		printf("Invalid Input");
		printf("\tOptions are not accepted as a filename\t use valid filename with extension\n");
	}
	else
	{
		printf("Invalid Input.\tUse option -s src_filename -d dest_filename\n");
	}
    

	
	return 0;
}

void copy(char *src_file_name,char *dest_file_name){

	if(s_used ^ d_used)
	{
		printf("\nProblem with argument passing\n");
	}
	else
	{
		printf("We Will copy from here\n");
		printf("\nSrc=%s\t",src_file_name);
		printf("\nDest=%s\t",dest_file_name);
	}
}

void print_recursive(void)
{
	printf("\n The Recursive option is used\n");
}

void print_help(void){

	printf("\nThis is help.\n");
	printf("1.use -h for help\n");
	printf("2.use -v for version\n");
	printf("3.use -R for recursive\n");
	printf("4.use -s for source\n");
	printf("5.use -d for destination.\n");

}

void print_version(void)
{
	printf("\nThis is version 1.1\n");
}