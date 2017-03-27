#include<stdio.h>
int main(void){
  long term = 0, sum = 0;
  int a, i, n;

  printf("input a, n:  ");
  scanf("%d %d", &a ,&n);

  for(i = 1; i <= n; i++){
    term = term * 10 + a;
    sum = sum + term;
  }
  printf("%ld", sum);
}
