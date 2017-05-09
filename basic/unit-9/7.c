#include<stdio.h>
#include<string.h>
int totsubstrnum (char *str, char *substr);
int main(void){
  char str[100], substr[100];
  printf("input:");
  gets(str);
  printf("inupt:");
  gets(substr);
  printf("%d\n", totsubstrnum(str,substr));
}

int totsubstrnum (char *str, char *substr){
  int i = 0, count = 0, len1, len2;
  len1 = strlen(str);
  len2 = strlen(substr);

  while (i <= len1 - len2) {
    if(strncmp(str + i, substr, len2) == 0){
      count++;
      i += len2;
    }
    else i++;
  }
 return (count);
}
