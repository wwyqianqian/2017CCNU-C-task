#include<stdio.h>
#include<stdlib.h>

void main(int a, char *argv[]){
  FILE *fp;
  char string[256];
  int i;


  if((fp = fopen("4.c","r")) == NULL){
    printf("fuck can not open\n");
    exit(0);
  }

  i = 1;
  while(fgets(string,256,fp) != NULL){
    printf("%d, %s", i++, string);
  }
  fclose(fp);
}
