# Tips
### 整理编写:007xiong
### 原 文:Hoyt 等
### 二次制作:AureoLEO MAIL:wangzihao[AT]gmail[DOT]com QQ:15959622 制作说明:本书版权归原文作者!2005-12-18

### #include <sys/stat.h>;
### #include <unistd.h>;
### int stat(const char *file_name,struct stat *buf);
### int fstat(int filedes,struct stat *buf);
### struct stat {
### dev_t st_dev; /* 设备 */
### ino_t st_ino; /* 节点 */
### mode_t st_mode; /* 模式 */
### nlink_t st_nlink; /* 硬连接 */
### uid_t st_uid; /* 用户 ID */
### gid_t st_gid; /* 组 ID */
### dev_t st_rdev; /* 设备类型 */
### off_t st_off; /* 文件字节数 */
### unsigned long st_blksize; /* 块大小 */
### unsigned long st_blocks; /* 块数 */
### time_t st_atime; /* 最后一次访问时间 */
### time_t st_mtime; /* 最后一次修改时间 */
### time_t st_ctime; /* 最后一次改变时间(指属性) */
### };
### stat 用来判断没有打开的文件,而 fstat 用来判断打开的文件.我们使用最多的属性是 st_ mode.通过着属性我们可以判断给定的文件是一个普通文件还是一个目录,连接等等.可以 使用下面几个宏来判断.
### S_ISLNK(st_mode):是否是一个连接.S_ISREG 是否是一个常规文件.S_ISDIR 是否是一个目 录 S_ISCHR 是否是一个字符设备.S_ISBLK 是否是一个块设备 S_ISFIFO 是否 是一个 FIFO 文
### 件.S_ISSOCK 是否是一个 SOCKET 文件