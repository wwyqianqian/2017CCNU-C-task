#include<stdio.h>

int main(void){
  double m = 2, n = 1, sum = 0;

  for(int x = 1; x <= 20; x++){
        sum += m / n;

        m = m + n;
        n = m - n;
    }
    printf("%d\n", sum);
    return 0;
}

/*m = 2, n = 1;
  m = 3, n = 3 - 1 = 2;
  m = 5, n = 5 - 2 = 3;
  m = 8, n = 8 - 3 = 5;
  ...
  ...

*/
