#include <stdio.h>

int main(){
	#ifdef MACRO
		printf("Hello,defined macro\n");
	#else
		printf("oops,no macro \n");
	#endif
	return 0;
}
