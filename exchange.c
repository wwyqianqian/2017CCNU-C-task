#include <stdio.h>

int main(void){
  int a[10], i, min, max, b, c;
  min = 0;
  max = 0;

  printf("输入几个正整数：");

  for(i = 0; i < 10; i++){
    scanf("%d",&a[i]);
  }

  for(i = 1; i < 10; i++){
    if(a[i] < a[min])
      min = i;
  }

  b = a[min];
  a[min] = a[9];
  a[9] = b; //exchange min and the last one : a[9]


  for(i = 1; i < 10; i++){
   if(a[i]>a[max])
     max=i;
  }

  c = a[max];
  a[max] = a[0];
  a[0] = c; //exchange max and the first one : a[0]


  for(i = 0; i < 10; i++)
    printf("%d ", a[i]); //print the array which is after exchanged
  return 0;
}
