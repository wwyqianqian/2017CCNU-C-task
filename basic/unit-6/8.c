#include<stdio.h>
#include<math.h>
int main(void){
  int a, b, c, d, k , n;
  printf("input it :"); scanf("%d", &n);

  k = abs(n);
  a = k /1000;
  b = (k - a * 1000) / 100;
  c = (k - a * 1000 - b * 100) / 10;
  d = k % 10;

  printf("%d\n", a + b + c + d);
}
