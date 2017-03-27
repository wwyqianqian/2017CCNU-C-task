#include<stdio.h>
#include<math.h>
int main(void){
  int n = 1, count = 0;
  float x;
  double sum, term;

  printf("input x: "); scanf("%f", &x);
  sum = x;
  term = x;

  do{
    term = -term * x * x / ((n + 1) * (n + 2));
    sum = sum + term;
    n += 2;
    count++;
  }while(fabs(term) >= 1e-5);

  printf("sin(x) = %f\n  count = %d", sum ,count);
}
