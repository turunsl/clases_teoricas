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

//crear cola de mensajes

int main() {
 int fd;
 char buffer[20];
 int leido;
    
    fd = mq_open("/nombre_cola",O_CREAT,0666,NULL);
    if (fd < 0 ){ // en caso que no se pueda abrir
       printf("No se pudo crear :( \n");
       return -1;
    }
   else{
     printf("Se pudo crear!! :D \n");
    }
  return 0;

} 
