#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char **argv){
	int opt=0;
   while(-1!=(opt=getopt(argc,argv,"ab:"))){
      printf("option:%c,value:%s\n",opt,optarg);
   }
   return 0;
}

//https://www.cnblogs.com/runnyu/p/4943704.html
//app -a -b 1212
