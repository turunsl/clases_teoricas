#include <stdio.h>
#include <unistd.h>

int main (){
    int pd[2];
    int pid;
    char buff[20];
    printf("voy a crear un pipe\n");
    pipe(pd);
    pid = fork();
    if ( pid == 0 ){ //hijo
        // escribo algo en el canal 
        sleep(3);
        write(pd[1],"hola pipe\n",10);
        return 0;
        }
    // padre    
    //espera hasta que puede leer algo del pipe
    read(pd[0], buff, 10);
    // escribo por pantalla lo leido en el canal
    write (1, buff, 10);
    return 0;

}

