#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int fd;
	//fd = open("archivo.txt",O_RDWR|O_CREAT, 0640);
	fd = open("archivo.txt",O_RDWR|O_CREAT, S_IRUSR | S_IWUSR |S_IRGRP);
	if (fd < 0){
		perror("open");
	}
	
	close(fd);
	return 0;
}
