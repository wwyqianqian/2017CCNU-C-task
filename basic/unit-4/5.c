#include<stdio.h>
#include<math.h>

void main()
{
  float a, b, c;
  float d;
  float x1, x2;

  printf("input a, b, c:   ");
  scanf("%f%f%f", &a, &b, &c);
  d = sqrt(b * b - 4 * a * c);

  x1 = (-b + d)/(2 * a);
  x2 = (-b - d)/(2 * a);
  printf("x1 = %.2f x2 = %.2f\n", x1, x2);

}
