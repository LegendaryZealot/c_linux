#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "progress.h"

#define PROGRESSBUFSIZE 101

char buf[PROGRESSBUFSIZE];
const char sta[]="-\\|/";

void PrintProgress(int progress)
{
  PrintProgressWithColor(progress,"\033[m");
}

void PrintProgressWithColor(int progress,char* color)
{
    memset(buf,'#',PROGRESSBUFSIZE);
    buf[progress]='\0';
    printf("%s[%c][%-100s][%%%d]\r",color,sta[progress%4],buf,progress);
    fflush(stdout);
}