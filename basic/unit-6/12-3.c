//下三角形
#include<stdio.h>
int main(void){
    int i, j;
    for(i = 1; i <= 5; i++){
      for(j = 1; j <= 2 * (i - 1) + 1; j++){
        printf("*");
      }
      printf("\n");
    }
}
