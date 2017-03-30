#include <stdio.h>
#include <getopt.h> /*or you can include<unistd.h> . This is for 
 only library function getopt(). For getopt_long include <getopt.h>
 see man page of getopt 'function'(not command).
 command to see man page of getopt function
 'man 3 getopt' (3 is for library function while 2 is for system call
 and 1 or empty arg is for command)
 'man getopt' is for command (here noarg is given so it is considered as 1).  */ 

int ret;

void print_help();
void print_version();

int main(int argc, char *argv[])
{
	/* code */
	while((ret = getopt(argc,argv,"hv"))!= -1)
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

void print_help(){

	printf("\nHello,this is help, options are -h and -v\n");
}

void print_version(){
	printf("\nThis is version 1.1\n");

}