#include"stdio.h"
int main(void){

int a[100] = {0}, i, j;
char c;
c = getchar();

while(c != '\n'){         //not space

  for(i = 65; i <= 90; i++){
    if(c == i || c == i+32){
      a[i]++;
    }

    for(j = 65; j <= 90; j++){
      if(a[j]>0){
      printf("%c : %-3d  \n", j, a[j]);
    }
  }
}
}
getch();
}
