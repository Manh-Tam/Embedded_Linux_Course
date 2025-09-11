#include <stdio.h>
#include <stdlib.h>   //exit()
#include <sys/stat.h> //lstat(), S_ISREG, S_ISDIR, S_ISLNK
#include <time.h>     //ctime, strftime
#include <string.h>

typedef struct
{
  char type[10];
  int size;
  char permission;
  char users[3][50];
  int timestamp;
}data;

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <file_path>\n", argv[0]);
    return 1;
  }
  struct stat fileStat;
  if (lstat(argv[1], &fileStat) == -1)
  {
    perror("lstat");
    return 1;
  }

  if (S_ISREG(fileStat.st_mode))
    printf("File Type: Regular File\n");
  else if (S_ISDIR(fileStat.st_mode))
      printf("File Type: Directory\n");
  else if (S_ISLNK(fileStat.st_mode))
      printf("File Type: Symbolic Link\n");
  else
      printf("File Type: Other\n");
  
  printf("Size: %ld bytes\n", fileStat.st_size);

  char timeBuf[100];
  struct tm *timeinfo = localtime(&fileStat.st_mtime);
  strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", timeinfo);
  printf("Last Modified: %s\n", timeBuf);
  return 0;
}