getopt函数

#include<unistd.h>
int getopt(int argc,char * const argv[],const char *optstring);

extern char *optarg;   //当前选项参数字串（如果有）
extern int optind;     //argv的当前索引值
各参数的意义:

argc:通常为main函数中的argc

argv:通常为main函数中的argv

optstring:用来指定选项的内容(如:"ab:c")，它由多个部分组成，表示的意义分别为：

1.单个字符，表示选项。

2 单个字符后接一个冒号：表示该选项后必须跟一个参数。参数紧跟在选项后或者以空格隔开。该参数的指针赋给optarg。

3 单个字符后跟两个冒号，表示该选项后可以跟一个参数，也可以不跟。如果跟一个参数，参数必须紧跟在选项后不能以空格隔开。该参数的指针赋给optarg。
(https://www.cnblogs.com/runnyu/p/4943704.html)
