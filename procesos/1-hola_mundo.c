#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("hola mundo, soy el proceso %d, y mi padre es %d\n",getpid(),getppid());
	// verificar que proceso es el padre del programa hola_mundo, usando ps -fea
return 0; //revisar exit status con echo $?
}
