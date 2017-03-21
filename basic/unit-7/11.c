#include<stdio.h>

int main(void) {
  int a[10] = {1, 3, 5, 7, 9}, num = 5, i, n;
  printf("Before: " );
  for ( i = 0; i < num; i++)
    printf("%d", a[i]);
  printf("\n");

  printf("input:");
  scanf("%d", &n);

  for (i = num - 1; i >= 0; i--)
    if(a[i] > n)
      a[i+1] = a[i];
    else
      break;
  a[i+1] = n;

  printf("After:");
  for ( i = 0; i < num + 1; i++)
    printf("%d", a[i]);
  printf("\n");
}
