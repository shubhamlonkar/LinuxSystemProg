#include <stdio.h>
#include <getopt.h>
int ret;

void print_help();

void print_version();

int main(int argc, char *argv[])
{
	while((ret = getopt(argc,argv,"hv")) != -1)	
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
	printf("\nHello, this is help, options are -h and -v\n");
}

void print_version()
{
	printf("\nThis is version 1.1\n");
}