#include<stdio.h>
#include<string.h>

void JsSort(char str[]);

main (void){
  char str[80];

  printf("input: ");  gets(str);  JsSort(str);
  printf("after: %s\n", str);
}

void JsSort(char str[]){
  int i, j, k, len;
  char ch;

  len = strlen(str);
  for(i = 1; i <= len - 1; i += 2){
    k = i;
    for(j = i + 2; j < len; j += 2){
      if(str[j] > str[k])
        k = j;
    }
    if(k != i){
      ch = str[i];
      str[i] = str[k];
      str[k] = ch;
    }
  }
}
