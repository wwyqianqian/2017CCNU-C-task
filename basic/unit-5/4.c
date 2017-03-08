#include<stdio.h>

int main(void){
  char c;

  printf("*****Time*****\n");
  printf("1  morning\n");
  printf("2  afternoon\n");
  printf("3  night\n");

  c = getchar();
  switch (c) {
    case'1': printf("Good morning\n");  break;
    case'2': printf("Good afternoon\n");  break;
    case'3': printf("Good night\n");  break;
    default: printf("Selection Error!!!\n");
  }
}
