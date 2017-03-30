#include <stdio.h>

//for open system call
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//for exit syscall and open,read syscall
#include <stdlib.h>
#include <unistd.h>

//for errno var and for string 
#include <errno.h>
#include <string.h>

int err,fd;	

#define BUF_SIZE 1024
char buff[BUF_SIZE];

int main(void)
{
	int nb_read;		//file descriptor

	fd = open("abcd.txt",O_APPEND| O_CREAT | O_RDWR,S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
	{
		fprintf(stderr, "Open failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		exit(EXIT_FAILURE);
	}
	printf("Open System Call Success: fd:%d\n",fd);

	nb_read = read(fd,buff,BUF_SIZE);
	err = nb_read;
	if (err == -1)
	{
		/* code */
		fprintf(stderr, "Read failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		exit(EXIT_FAILURE);
	}
	printf("File Read:%s\n",buff);

	printf("Writing into a file\n");

	err = write(STDIN_FILENO,buff,nb_read);
	if (err == -1)
	{
		/* code */
		fprintf(stderr, "Write failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		exit(EXIT_FAILURE);
	}

	printf("Writing into a terminal\n");

	err = write(STDOUT_FILENO,buff,nb_read);
	if (err == -1)
	{
		/* code */
		fprintf(stderr, "Write failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		exit(EXIT_FAILURE);
	}
	printf("Write Successful\n");

	printf("Now Closing\n");

	err = close(fd);
	if (err == -1)
	{
		/* code */
		fprintf(stderr, "Close Failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		exit(EXIT_FAILURE);
	}
	printf("File Closed\n");

	return 0;
}