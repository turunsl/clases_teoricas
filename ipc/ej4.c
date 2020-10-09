#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//programa que escribe en una tubería
int main() {
 int fd;
    // con O_NONBLOCK el operativo no deja durmiendo a este proceso, a la espera que otro lea la tuberia	
	fd = open ("/tmp/tuberia",O_NONBLOCK | O_WRONLY );
  if (fd < 0 ){ // en caso que no se pueda abrir
   printf("No se pudo abrir :( \n");
   return -1;
   }
  else{
     printf("Se pudo abrir!! :D \n");
     
   }
  write(fd,"Hola Mundosss\n",14);
  
  return 0;

}
