#include<stdio.h>
int main(void){
  float term, result = 1;
  int n;
  for(n = 2; n <= 100; n += 2){
    term = (float)(n * n) / ((n - 1) * (n + 1));
    result *= term;
  }
  printf("result = %f\n", 2 * result);
}
