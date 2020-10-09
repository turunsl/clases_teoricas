#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

//escribe un mensaje en la cola ya existente

int main() {
 int fd;
 char buffer[20];
 int leido, confirma;
    
    fd = mq_open("/nombre_cola",O_WRONLY);
    if (fd < 0 ){ // en caso que no se pueda abrir
       printf("No se pudo crear :( \n");
       return -1;
    }
   else{
     printf("Se pudo crear!! :D \n");
    }
    confirma = mq_send(fd,"primer mensaje\n",15,40);
    if (confirma == 0){
      printf("Se pudo enviar el mensaje\n");
    }else{
       printf("No se pudo escribir\n");
    }

  return 0;

} 
