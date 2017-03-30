#include <stdio.h>

//header file for open syscall
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


//std unix libs
#include <unistd.h>
#include <stdlib.h>

//error handling
#include <errno.h>	
#include <string.h>

int err;	//for catching errors

#define BUF_SIZE 1024
char buff[BUF_SIZE];

int main()
{
	int fd;
	fd = open("abcd.txt",O_APPEND,S_IRUSR);
		if(fd == -1)
		{
			fprintf(stderr, "\nOpen failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
			exit(EXIT_FAILURE);
		}
	printf("\nSystem call success:fd=%d\n",fd);	

	err = read(fd,buff,BUF_SIZE);
		if(err == -1)
		{
			fprintf(stderr, "\nRead failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
			exit(EXIT_FAILURE);
		}
	printf("FILE READ:%s\n",buff);	
 
	printf("NOW closing\n");

	err = close(fd);
		if(err == -1)
		{
			fprintf(stderr, "\nclose failed:%s:%s:%s:%d\n",strerror(errno),__FILE__ ,__FUNCTION__,__LINE__);
			exit(EXIT_FAILURE);
		}

	return 0;
}

