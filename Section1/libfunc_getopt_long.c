#include <stdio.h>
#include <getopt.h>

static struct option opt_arr[] = 
{
	/* data */
	{"help",no_argument,0,'h'},
	{"version",no_argument,0,'v'},
	{0,0,0,0}
};

int ret ,i = 0;

void print_help();
void print_version();

int main(int argc, char  *argv[])
{
	/* code */

	while((ret = getopt_long(argc,argv,"hv",opt_arr,&i)) != -1)
	{
		switch((char)ret)
		{
			case 'h':
						print_help();
						break;
			case 'v':
						print_version();
						break;
		}
	}
	return 0;
}


void print_help()
{
	printf("\nThis has --help -h --version -v option\n");
}

void print_version()
{
	printf("\nThis is version 1.1\n");
}