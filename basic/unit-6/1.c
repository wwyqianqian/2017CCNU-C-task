#include<stdio.h>
int main(void){
  int a, b;
  b = 0;
  for(a = 2; a <= 100; a += 2){
    b += a;
  }
  printf("%d", b);
}
