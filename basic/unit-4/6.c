#include<stdio.h>

void main()
{
  unsigned long t, r;
  int d, h, m, s;

  printf("second = ");
  scanf("%d", &t);

  d = t / (24 * 3600);    //days
  r = t % (24 * 3600);    //total seconds
  h = r / 3600;           //hours
  m = (r % 3600) / 60;    //minutes
  s = (r % 3600) % 60;    //seconds

  printf("Have passed %d days, current time is %02d:%02d:%02d\n", d, h, m, s);
  
}
