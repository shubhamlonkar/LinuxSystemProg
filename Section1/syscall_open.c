#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
int err;

int main(void)
{
	int fd,crd;

	fd = open("pqr.txt",O_APPEND,S_IRUSR);
	if (fd == -1)
	{
		/* code */
		crd = creat("pqr.txt",S_IRUSR);
		if (crd == -1)
		{
			/* code */
			fprintf(stderr,"\nOpen failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
		}

		
	}
	if(fd == -1)
		printf("\nSystem call success:fd = %d \n",crd);
	else
		printf("\nSystem call success:fd = %d \n",fd);
	printf("\nNow closing\n");

	err = close(fd);
	if (fd == -1)
	{
		/* code */
		fprintf(stderr, "\nclose failed:%s:%s:%s:%d\n",strerror(errno),__FILE__,__FUNCTION__,__LINE__);
	}
	return 0;
}