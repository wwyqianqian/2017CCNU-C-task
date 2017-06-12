#include<stdio.h>
#include<string.h>
void multiplication(char a[], char b[], int c[]);
int main(){
    char a[200], b[200];
    int c[200];
    scanf("%s%s", a, b);
    memset(c, 0, 200*sizeof(int));
}
void multiplication(char a[] , char b[] , int c[] ){
    int longa = strlen(a) ;
    int longb = strlen(b) ;
    for(int i = 0; i < longa; i++ ){
       for(int j = 0; j < longb; j++){
           c[i + j + 1] += (a[i] - '0') * (b[j] - '0');
       }
    }
    for(int i = longa + longb + 2; i >= 0; i--){
        if(c[i] >= 10) {
          c[i-1] += c[i] / 10 ;
          c[i] %= 10 ;
        }
    }
    int con = 0 ;
    printf("%s * %s =    " , a, b);
    for(int i = 0; i < longa + longb; i++){
      if(c[i] != 0 ){
        con = 1;
      }
      if(con){
        printf("%d",c[i]);
        }
    }
}
