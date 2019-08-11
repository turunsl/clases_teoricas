#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
	printf("hola mundo\n");
	int ret = fork();
	if ( ret == 0 ){ //hijo
		printf("chau soy el hijo\n");
 		return 0;
	} //ejecutar ps -fea y top ... para ver el zombie ... por que es zombie ? y hasta cuando ???
	sleep(10);
	printf("pid %d ppid %d retorno %d\n", getpid(), getppid(),ret);

 return 0;
}
