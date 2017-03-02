#include<stdio.h>

void main()
{
  unsigned short a, b;

  scanf("%4X", &a);
  b = (a & 0x000F)<<12;
  b += (a & 0x00F0)<<4;
  b += (a & 0x0F00)>>4;
  b += (a & 0xF000)>>12;
  printf("%4X\n", b);
  
}
