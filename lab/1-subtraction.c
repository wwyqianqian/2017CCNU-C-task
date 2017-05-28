/************************************************************************************************
                                    实 验 一

  从键盘上输入四个短整型数，求这四个数中最大的无符号数和最小无符号数及其对应的输入值，并输出最大的无符号数与最小无符号数的差。

  提示：定义四个短整型变量，通过scanf函数输入值，利用if语句逐一比较，分别计算最大无符号数和最小无符号数，比较时要进行强制类型转换。

************************************************************************************************/
#include<stdio.h>
#include<string.h>

int main(void){
  short i, j, a[4], max = 0, min = 0;
  unsigned short int b[4], maxu, minu;

  for (i = 0; i < 4; i++){
    scanf("%hd", &a[i]);//short int
    b[i] = (unsigned short int)a[i];
  }
  maxu = b[0];
  minu = b[0];

  for (i = 1; i < 4; i++){
    if(maxu < b[i]){
      maxu = b[i];
      max = i;
    }
    if(maxu > b[i]){
      minu = b[i];
      min = i;
    }
  }

  printf("你输入的%hd， 最大无符号数%u \n", b[max], a[max]);
  printf("你输入的%hd， 最小无符号数%u \n", b[min], a[min]);
  printf("subtraction: %u", a[max]-a[min]);
  return 0;

}
