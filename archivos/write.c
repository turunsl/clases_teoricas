#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int fd;
	//fd = open("archivo.txt",O_RDWR|O_APPEND|O_CREAT,0640);
	fd = open("archivo.txt",O_RDWR|O_TRUNC|O_CREAT,0640);
	if (fd < 0){
		perror("open");
	}
	write(fd, "a ver ahora?\n",13);	
	close(fd);
	return 0;
}
