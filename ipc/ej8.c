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

//lee de un mensaje en la cola ya existente

int main() {
 int fd;
 char buff[8192];
 int leido, confirma;
    
    fd = mq_open("/nombre_cola",O_RDONLY);
    if (fd < 0 ){ // en caso que no se pueda abrir
       printf("No se pudo abrir :( \n");
       return -1;
    }
   else{
     printf("Se pudo abrir!! :D \n");
    }
    confirma = mq_receive(fd,buff,sizeof(buff), NULL);
    if (confirma < 0){
      printf("No se pudo recibir el mensaje\n");
      return -1;
    }else{
       printf("si se pudo recibir\n");
    }
    write (1,buff, confirma);

  return 0;

} 
