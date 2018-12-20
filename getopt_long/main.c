#include <stdio.h>
#include <getopt.h>

enum{
   LONGOPT_VAL_TIMEOUT=257,
   LONGOPT_VAL_MPORT
};

static const char *short_options='c:vh';

static const struct option long _options[]={
   {"port",required_argument,NULL,'p'},
   {"timeout",required_argument,NULL,LONGOPT_VAL_TIMEOUT},
   {"config",required_argument,NULL,'c'},
   {"verbose",required_argument,NULL,'v'},
   {"help",required_argument,NULL,'h'},
   {NULL,0,NULL,0},
}
 
int main(int argc,char **argv){
   char *config_file=NULL;
   char *port=NULL:
   float timeout=0f;
   int verbose=0;

   int opt=0;
   while(-1!=(opt=getopt_long(argc, argv, short_options, long_options, NULL))){
              switch (opt){
            case 'h':
            case '?': //如果是不能识别的选项，则opt返回'?'
                fprintf(stdout, "Usage: %s -p <port>  [-v|--v <=verbose_level>] [-h]\n", argv[0]);
                return 0;
            case 'c':
                config_file = optarg;
                break;
           case 'p': // 'p'是个短选项，但是长选项port的值也是'p'，所以这里同时处理了port
                port = optarg;
                break;
           case LONGOPT_VAL_TIMEOUT: //长选项timeout的值
                timeout = atof(optarg);
                break;
           case 'v': // verbose有可选参数，所以这儿判断是否有参数
                if(optarg == NULL){
                     verbose = 1;
                }
                else {
                     verbose = atoi(optarg);
                }
                break;
        }
   }

   return 0;
}
