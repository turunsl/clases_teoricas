#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

int main (){
    int pipe1[2];
    int pid;
    int pipe2[2];
    char buff[20];
    printf("voy a crear un pipe\n");
    pipe(pipe1);
    pipe(pipe2);
    pid = fork();
    if ( pid == 0 ){ //hijo
        // escribo algo en el canal 
        sleep(3);
        write(pipe1[1],"hola pipe\n",10);
        printf("Estoy esperando para leer.\n");
        read(pipe2[0], buff, 10);
        write (1, buff, 10);
        return 0;
        }
    // padre    
    //espera hasta que puede leer algo del pipe
    read(pipe1[0], buff, 10);
    sleep(3);
    buff[0] = toupper(buff [0]);
    write(pipe2[1], buff, 10);
    wait(NULL);
    // escribo por pantalla lo leido en el canal
    //write (1, buff, 10);
    return 0;

}
