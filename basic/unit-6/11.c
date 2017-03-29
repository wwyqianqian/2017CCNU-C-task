#include<stdio.h>
int main(void){
  int k = 0, sum = 0, g = 0;
  char this = ' ';

  for(k = 0; k <= 3; k++){
    this = 'A' + k; //？喵

    sum = (this != 'A') + (this == 'C') + (this == 'D') + (this != 'D');
    if(sum == 3){
      printf("This is %c\n", this);
      g = 1;
    }
  }
  if(g != 1){
    printf("Cannot found.\n");
  }
}
