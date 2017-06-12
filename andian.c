#include<stdio.h>
#define M 10
#define N 10

int main(){
  int a[M][N];
  int i, j;
  int temp = 1, temp1[M], temp2[N];


    for(i = 0;i < M; i++){
         for(j = 0;j < N;j++){
             printf("a[%d][%d]=", i, j);
             scanf("%d", &a[i][j]);
        }
    }

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
             printf("%d\t", a[i][j]);
           }
        printf("\n");
    }

    for(i = 0; i < M; i++){
         temp1[i] = a[i][0];    //给每行的最大值赋一个初始值
         temp2[i] = a[0][i];    //给每列的最小值赋一个初始值
         for(j = 0;j < N;j++){
            if(temp1[i] < a[i][j]){
                temp1[i] = a[i][j];
              }
            if(temp2[i] > a[j][i]){
                temp2[i] = a[j][i];
              }
         }
     }

     for(i = 0; i < M; i++){
         for (j = 0;j < N;j++){
             if (a[i][j] == temp1[i] && a[i][j] == temp2[j])
                 printf("haha,鞍点为%d\n", a[i][j]);
             else
                 temp = 0;

         }
     }
     if (temp == 0)
         printf("fxxk,没有鞍点.\n");
 }
