#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
	int fd, leido;
	char buff[10]; 
	//fd = open("archivo.txt",O_RDWR|O_APPEND|O_CREAT,0640);
	fd = open("archivo.txt",O_RDWR|O_CREAT,0640);
	if (fd < 0){
		perror("open:");
		return -1;
	}
	while ( (leido = read(fd, buff, sizeof buff)) > 0 ){
		printf (" %d bytes: %s \n",leido,buff);
		memset(buff,0,10);
	}
	close(fd);
	return 0;
}
