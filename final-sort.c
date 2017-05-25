#include<stdio.h>
#include<string.h>

int main(void){
  FILE *fi, *fo;
  int i = 0, j = 0;
  int score[5];

  fi = fopen("./input.data", "r");
  fo = fopen("./input.data", "w+");

  for( ; i < 5; ++i){
    fscanf(fi ,"%d", &score[i]);
  }
  for(i = 0; i < 5; ++i){
    int index = i;

    for(j = i + 1; j < 5; ++j){
      if(score[j] > score[index])
        index = j;
    }
    score[index] ^= score[i];
    score[i] ^= score[index];
    score[index] ^= score[i];
  }

  for(i = 0; i < 4; ++i){
    fprintf(fo, "%d\n", score[i]);
  }

}
