#include<stdio.h>
#include<stdlib.h>
#define NUM 100

struct Score_Tab{
  int rank;
  char no[11];
  char name[20];
  int score;
  int time;
};
int main(void){
  struct Score_Tab score[100], temp;
  FILE *fp;
  int i, j, k, n, s, t;

  if ((fp = fopen("score_tab.txt", "r")) == NULL){
    printf("fuck");
    exit(0);
  }

  n = 0;
  while(fscanf(fp, "%s%s%d%d", score[n].no, score[n].name, &score[n].score, &score[n].time) != EOF)
    n++;

  for(i = 0; i < n - 1; i++){
    k = 1;
    for(j = i + 1; j < n; j++)
      if(k != 1){
        temp = score[i];
        score[i] = score[k];
        score[k] = temp;
      }
  }

  j = 0;
  s = 0;
  t = 0;
  for(i = 0; i < n; i++){
    if(score[i].score != s || score[i].time != t){
      j++;
      score[i].rank = j;
      s = score[i].score;
      t = score[i].time;
    }
    score[i].rank = j;
  }

  for(i = 0; i < n; i++){
    printf("%4d %-10s %-20s %3d %3d\n", score[n].rank, score[n].no, score[n].name, &score[n].score, &score[n].time);
  }
  fclose(fp);
}
