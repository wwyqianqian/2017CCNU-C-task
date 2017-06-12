#include<stdio.h>
#include<conio.h>
#include<string.h>

#define N 20

void beep();
void GetNumberStr (char *s);
void SubNumberStr (char *a, char *b, char *c);
char SubChar (char ch1, char ch2);
void LeftTrim (char *str, char sign);

int tag = 0;

void main(){
  char a[N + 1] = {0}, b[N + 1] = {0}, c[N + 2];
  printf("a = ");
  while(strlen(a) == 0)
    GetNumberStr(a);
  printf("\n b = ");
  while(strlen(b) == 0)
    GetNumberStr(b);

  SubNumberStr(a, b, c);
  printf("\n a - b = %s \n", c);

}

void GetNumberStr(char *s){
  int i = 0;
  char ch;

  while(1){
    ch = getch();
    if(ch == '\r')
      break;
    if(ch == '\b'){
      if(i > 0){
        printf("%c %c", ch, ch);
        i--;
      }
      else
        beep();
      continue;
    }
    if(ch < '0' || ch > '9'){
      beep();
      continue;
    }
    if(i < N){
      printf("%c", ch);
      s[i++] = ch;
    }
    else
      beep();
  }
  s[i] = '\0';
}

void beep() {
  printf("\07");
}

void SubNumberStr(char *a, char *b, char *c){
  int i, j, k;
  char t[N + 1], sign = ' ';

  if(strlen(a) < strlen(b) || strlen(a) == strlen(b) && strcmp(a, b) < 0){
    sign = '-';
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
  }
  memset(c, ' ', N + 2);
    i = strlen(a) - 1;
    j = strlen(b) - 1;
    k = N;
  while(i >= 0 && j >= 0)
    c[k--] = SubChar(a[i--], b[j--]);
  while(i >= 0)
    c[k--] = SubChar(a[i--], '0');
  c[N + 1] = '\0';
  LeftTrim(c, sign);
}

char SubChar (char ch1, char ch2){
  char ch;

  ch = ch1 - ch2 - tag;
  if(ch >= 0){
    tag = 0;
    return (ch + 0x30);
  }
  else{
    tag = 1;
    return (ch + 10 + 0x30);
  }
}

void LeftTrim (char *str, char sign){
  int i = 1;
  for (i = 0; str[i] == '' || str[i] == '0'; i++);
    if(str[i] == '\0')
      i--;
    if(sign == '-')
      str[--i] = sign;
  strcpy(str, str + i);
}












}
