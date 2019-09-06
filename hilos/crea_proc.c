#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  int pid;
  int i;
  for(i=0;i<1001;i++){
	pid = fork();
  if(pid==0){
	i = i ++;
  return 0;
  }}
return 0;
}

