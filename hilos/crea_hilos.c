#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int x= 0;
void * fun(){
	x = x ++;
	pthread_exit(NULL);
}
int main(){
  pthread_t tid;
  int i;
  for(i=0;i<1001;i++){
	pthread_create(&tid, NULL, fun, NULL);
  }
	pthread_exit(NULL);
return 0;
}

