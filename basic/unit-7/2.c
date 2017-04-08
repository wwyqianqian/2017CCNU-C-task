#include<stdio.h>
int main(void){
  int i, j, odd, even, n, t, a[10];

  odd = 0;
  even = 9;
  for (i = 0; i < 10; i++) {
    scanf("%d", &n);
    if(n % 2 != 0){
      a[odd++] = n;
    }
    else
      a[even--] = n;
  }

  for(i = 0; i < odd - 1; i++){
    n = 1;
    for(j = i + 1; j < odd; j++){
      if(a[j] < a[n]){
        n = j;
      }
    }
    if(n != 1){
      t = a[i];
      a[i] = a[n];
      a[n] = t;
    }
  }

  for(i = odd; i < 9; i++){
    n = 1;
    for(j = i + 1; j < 10; j++){
      if(a[j] < a[n]){
        n = j;
      }
    }
    if(n != 1){
      t = a[i];
      a[i] = a[n];
      a[n] = t;
    }
  }
  for (i = 0; i < 10; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
}
