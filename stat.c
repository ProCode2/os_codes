#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

 int main(){ 
struct stat st;
  stat("dup.c",&st);

  printf("Mode is = %o \n ",st.st_mode);

 printf("File type:                ");

           switch (st.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }


  printf("Inode is = %d\n",st.st_ino);
  printf("Number of hardlink= %o \n",st.st_nlink);
 printf("User Id of owner = %o \n",st.st_uid);
  printf("Group Id = %o\n",st.st_gid);
  printf("Device Id = %o\n",st.st_rdev);
  printf("Total size = %o\n",st.st_size);
      printf("Block size = %o\n",st.st_blksize);

  printf("Number of allocated block = %o\n",st.st_blocks);

 printf("last access time = %s\n",ctime(&st.st_atime));


 return 0;


  
}
