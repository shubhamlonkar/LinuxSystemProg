#include <stdio.h>

//for error handling or error showing
#include <string.h>
#include <errno.h>

// for read() and close() system calls 
#include <unistd.h>

//for open() system call
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

char buff[BUF_SIZE];

int err;			//err -> variable for a file descriptor of read

int main(int argc, char const *argv[])
{
	int fd,cl;			//fd -> variable for a file descriptor of open
						// cl -> variable for a file descriptor of close

	fd = open("pqr.txt",O_APPEND,S_IRUSR |S_IRGRP | S_IROTH);
	if (fd == -1)
	{
		/* code */
		fprintf(stderr, "\nOpen Failed%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
	}
	printf("\nSystem call success:fd=%d \n",fd);

	err = read(fd,buff,BUF_SIZE);
	if (err == -1)
	{
		/* code */
		fprintf(stderr, "\n read failed %s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
	}
	printf("FILE READ::%s\n",buff);

	printf("Now Closing.\n");

	cl = close(fd);
	if (cl == -1)
	{
		/* code */
		fprintf(stderr, "\nclose failed %s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
	}
	printf("File Closed.\n");


	return 0;
}