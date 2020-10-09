#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//programa que lee de una tuberia y escribe en la pantalla
int main() {
 int fd;
 char buffer[20];
 int leido;
    
    fd = open ("/tmp/tuberia",O_RDONLY );
  if (fd < 0 ){ // en caso que no se pueda abrir
   printf("No se pudo abrir :( \n");
   return -1;
   }
  else{
     printf("Se pudo abrir!! :D \n");
     
   }
   leido = read(fd,buffer,20);
  
  write(1,buffer,leido);
  return 0;

}
