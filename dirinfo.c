#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
  //declaring vars
  struct dirent *files;
  struct stat buffer;
  int size = 0;

  //getting dir info
  DIR *d = opendir(".");

  //printing dirs
  printf("directories in directory:\n");
  while(files = readdir(d)){
    if(files -> d_type == DT_DIR){
      printf("directory name: %s\n", files-> d_name);
    }
  }

  //printing files
  d = opendir(".");
  printf("files in directory:\n");
  while (files = readdir(d)) {
    if (files -> d_type == DT_REG) { //if regular file
      stat(files -> d_name, &buffer);
      size += buffer.st_size;
      printf("file name: %s\n", files -> d_name);
    }
    files = readdir(d);
  }
  closedir(d);
  printf("Size of files in directory: %d\n", size); 
  return 0;
}
