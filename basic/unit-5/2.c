#include<stdio.h>

void main(){
  int x, sign;

  scanf("%d", &x);

  if(x > 0)
    sign = 1;
  else if(x == 0)
    sign = 0;
    else
      sign = -1;

  printf("%d\n", sign);

}
