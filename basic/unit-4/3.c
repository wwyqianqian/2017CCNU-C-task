#include<stdio.h>

#define PI 3.14159

void main()
{
  float r, c, s;
  scanf("%f", &r);
  c = 2 * r * PI;
  s = PI * r * r;
  printf("c = %f s = %f\n", c, s);
}
