#include<stdio.h>
int main(void){
  int a;
  long b, count = 0;

  for(a = 1; a <= 99; a += 2){
    b = a * (a + 1) * (a + 2);
    count += b;
  }
  printf("%ld\n", count);
}
