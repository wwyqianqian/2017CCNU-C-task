#include<stdio.h>
int main(void){
  long a = 1, count = 0;
  int i;

  for(i = 1; i <= 10; i += 1){
    a *= i;
    count += a;
  }
  printf("%ld\n", count);
}

/*
#include<stdio.h>
int main(void){
long term, sum;
int i, j;

for(i = 1; i <=10; i += 1){
  term = 1;
  for(j = 1; j <= 1; j++){
    term *= j;
}
  sum += term;

}
 printf("%ld", sum);
}

*/
