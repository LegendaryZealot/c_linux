#include <stdio.h>
#include <string.h>

//union关键字，定义union下面的成员变量共享一块内存，每一个成员在任一时刻有且只有一个成员使用此块内存。
//老师和学生有相同的一部分信息，但是老师有课程数目，学生有得分，想用一个数据结构描述，结构体可以，但是造成空间浪费，Union可以减少浪费

typedef union{
    int i;
    char str[20];
}Union;

int main(int argc, char const *argv[])
{
    Union data;
    data.i=100;
    printf("size:%ld int:%d str:%s\n",sizeof(data),data.i,data.str);
    strcpy(data.str,"hello word!");
    printf("size:%ld int:%d str:%s\n",sizeof(data),data.i,data.str);
    return 0;
}
