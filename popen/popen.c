#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char buf[100];
	FILE *fp = NULL;
	fp = popen("ls", "r");
	if(!fp) {
		perror("popen");
		exit(-1);
	}
	while(memset(buf, 0, sizeof(buf)), fgets(buf, sizeof(buf) - 1, fp) != 0 ) 
	{
		printf("%s",buf);
	}
	pclose(fp);
}

