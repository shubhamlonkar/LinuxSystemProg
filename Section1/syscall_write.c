#include <stdio.h>

//for exit system call
#include <stdlib.h>

//for open system call
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//for displaying errors
#include <string.h>
#include <errno.h>

//for read and close systemcalls
#include <unistd.h>

#define BUFF_SIZE 1024

char buff[BUFF_SIZE];

int fd,fd2,file_read,file_write,file_close;

int main(void)
{
	fd = open("abcd.txt",O_APPEND | O_RDONLY,S_IRUSR | S_IRGRP |S_IROTH);
	if (fd == -1)
	{
		/* code */
		fprintf(stderr, "Open Failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
		exit(EXIT_FAILURE);		
	}
	else
		printf("Open Successfully fd:%d\n",fd);

	fd2 = open("write.txt",O_RDWR,S_IWUSR | S_IWGRP | S_IWOTH);
	if (fd2 == -1)
	{
		/* code */
		fprintf(stderr, "Open Failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
		exit(EXIT_FAILURE);
	}
	else
		printf("Open Successfully fd2:%d\n",fd2);

	printf("Reading contents of a file:\n");
	file_read = read(fd,buff,BUFF_SIZE);
	if (file_read == -1)
	{
		/* code */
		fprintf(stderr, "Read Failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
		exit(EXIT_FAILURE);
	}
	else
		printf("File Read successfully contents of a file:%s\n",buff);

	printf("Writing contents into an another file\n");
	file_write = file_read;

	file_write = write(fd2,buff,file_read);
	if (file_write == -1)
	{
		/* code */
		fprintf(stderr, "Write Failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
		exit(EXIT_FAILURE);
	}
	else
		printf("Write successfully in the file.\n");

	file_write = write(STDOUT_FILENO,buff,file_read);
	if (file_write == -1)
	{
		/* code */
		fprintf(stderr, "Write Failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
		exit(EXIT_FAILURE);
	}
	else
		printf("Write successfully on terminal\n");

	printf("Now closing\n");
	file_close = close(fd);
	if (file_close == -1)
	{
		/* code */
		fprintf(stderr, "Close Failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
		exit(EXIT_FAILURE);
	}
	else
		printf("File to be read is closed now\n");

	file_close = close(fd2);
	if (file_close == -1)
	{
		/* code */
		fprintf(stderr, "Close Failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__ );
		exit(EXIT_FAILURE);
	}
	else
		printf("File to be write is closed now\n");

	return 0;
}