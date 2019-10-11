#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	int fd;
	//fd = open("archivo.txt",O_RDWR|O_APPEND|O_CREAT,0640);
	fd = open("archivo.txt",O_RDWR|O_CREAT,0640);
	if (fd < 0){
		perror("open");
	}
	//lseek(fd, 20 , SEEK_CUR); //me adelanto 20 bytes del offset actual
	lseek(fd, 1024 , SEEK_END); //me adelanto 20 bytes del final
	write(fd, "donde estoy?\n",13);	
	close(fd);
	return 0;
}
