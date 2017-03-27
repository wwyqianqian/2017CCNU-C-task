#include<stdio.h>
int main(void){
  int n, m = 0, r, s;
  printf("input: "); scanf("%d", &n);

  s = n;
  while (s != 0) {
    r = s % 10;
    m = m * 10 + r;
    s = s / 10;
  }
  if(m == n)
    printf("yep");
  else
    printf("nope");
}
