#include <stdio.h>
#include <stdlib.h>

char code[10000];
int codeIndex=0;
int stack[10000];
int stackIndex=0;
char arr[20000]={0};

int main(int argc, char const *argv[])
{
    FILE *f;
    f=fopen(argv[1],"r");
    while(fread(&code[++codeIndex],1,1,f));
    fclose(f);
    char* p=arr;
    for(int i=0;i<codeIndex;i++){
        switch(code[i]){
            case '+':(*p)++;break;
            case '-':(*p)--;break;
            case '>':p++;break;
            case '<':p--;break;
            case '.':putchar((int)(*p));break;
            case ',':*p=getchar();break;
            case '[':
                if(*p) {
                    stack[stackIndex++]=i;
                } else {
                    for(int k=i,j=0;k<codeIndex;k++) {
                        code[k]=='['&&j++;
                        code[k]==']'&&j--;
                        if(j==0){
                            i=k;
                            break;
                        }
                    }
                }
                break;
            case ']':i=stack[stackIndex-- - 1]-1;break;
            default:break;
        }
    }
    return 0;
}