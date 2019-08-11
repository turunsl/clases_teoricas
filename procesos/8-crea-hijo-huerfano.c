#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
	printf("pid %d ppid %d \n", getpid(), getppid());
	int ret = fork();
	if ( ret == 0 ){ //hijo
		sleep(1);
		printf("soy el hijo %d ... y mi padre es %d ...what ???? \n", getpid(), getppid()); // que proceso es padre ? por que ?
 		return 0;
	} 

 return 0;
}
