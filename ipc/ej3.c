#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
//este programa solo crea una tuberia
int main() {
 int valor;
	
	valor=mkfifo("/tmp/tuberia", 0666);
  if (valor < 0 ){ // en caso que no se pueda crear
   printf("No se pudo crear :( \n");
   return -1;
   }
  else{
     printf("Se pudo crear!! :D \n");
   }

  return 0;

}
