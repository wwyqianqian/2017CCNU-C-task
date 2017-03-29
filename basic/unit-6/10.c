#include<stdio.h>
int main(void){
  int x, y, z, count = 0;
  for(x = 1; x <= 28; x++){
    for(y = 1; y <= 73; y++){
      z =  100 - x - y;
      if(5 * x + 2 * y + z == 150){
        count++;
        printf("%02d, %02d, %02d   ", x, y, z);
        if(count % 6 == 0){        //layout
          printf("\n");
        }
      }
    }
  }
  printf("count = %d\n", count);
}
