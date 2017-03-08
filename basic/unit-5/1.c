#include<stdio.h>

void main(){
  int a ;

  scanf("%d", &a);

  if(a >= 0)
    printf("非负数\n");
  else
    printf("负数\n");

  if(a % 2 == 0)
      printf("偶数\n");
  else
      printf("奇数\n");

}
