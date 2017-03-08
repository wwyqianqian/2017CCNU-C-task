#include<stdio.h>

void main(){
  int num1, num2, num3;
  scanf("%d%d%d\n", &num1, &num2, &num3);

  if(num1 >= num2)
    if(num2 >= num3)
      printf("%d %d %d\n", num3, num2, num1);
    else if(num1 <= num3)
      printf("%d %d %d\n", num2, num1, num3);
        else
          printf("%d %d %d\n", num2, num3, num1);

  else
    if(num2 <= num3)
      printf("%d %d %d\n", num1, num2, num3);
    else if(num1 <= num3)
      printf("%d %d %d\n", num1, num3, num2);
        else
          printf("%d %d %d\n", num3, num1, num2);

}
