#include<stdio.h>
int main(void){
  int i, j, t, a[6];

  printf("input 6:");
  for(i = 0; i < 6; i++){
    scanf("%d", &a[i]);
  }
  printf("\n");
  for(i = 0; i < 6; i++){
    for(j = 0; j < 6; j++){
      printf("%d", a[j]);
    }
    printf("\n");
    t = a[5];
    for(j = 5; j > 0; j--){
      a[j] = a[j-1];
    }
    a[0] = t;
  }
}
