//对调max min的位置

#include<stdio.h>
int main(void){
  int i, max, min, a[10];

  printf("input 10 integer number: ");
  for(i = 0; i < 10; i++){
    scanf("%d", &a[i]);
  }
  max = 0;
  min = 0;
  for(i = 1; i < 10; i++){
    if(a[i] > a[max]){
      max = i;
    }
    if(a[i] < a[max]){
      min = i;
    }
  }
  i = a[max];
  a[max] = a[min];
  a[min] = i;
  for(i = 0; i < 10; i++){
    printf("%d", a[i]);
  }
  printf("\n");
}
