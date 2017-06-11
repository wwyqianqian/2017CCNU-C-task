/************************************************************************************************
                                      实 验 六

  编写一个程序，输入两个包含10个元素的数组，先将第一个数组采用冒泡法进行降序排列，第二个数组采用选择排序进行降序排列，然后将这两个数组合并成一个降序数组。

************************************************************************************************/
#include <stdio.h>

void bubble_sort(int arr[], int total);
void selection_sort(int a[], int total);
void Merge(int a[], int b[], int sorted[], int alen, int blen);


int main(void){
    int arr_1[10] = {0};
    int arr_2[10] = {0};
    int tmp1 = 0, tmp2 = 0;
    int sorted[20] = {0};
    int max = 0;

    printf("enter first array: \n");
    for(int i=0; i<10; i++){
        scanf("%d ", &arr_1[i]);
    }
    printf("enter another array: \n");
    for(int i=0; i<10; i++){
        scanf("%d ", &arr_2[i]);
    }

    bubble_sort(arr_1, 10);
    selection_sort(arr_2, 10);
    Merge(arr_1, arr_2, sorted, 10, 10);

    for(int j=0; j<20; j++){
        printf("%d ", &sorted[j]);
    }

    return 0;
}

void bubble_sort(int arr[], int total){
    int tmp = 0;
    for(int i=0; i<total-1; i++){
        for(int j=0; j<total-1-i; j++){
            if(arr[j+1]<arr[j]){
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void selection_sort(int a[], int total){
    int max_index = 0, tmp = 0;
    for(int i=0; i<total-1; i++){
        max_index = i;
        for(int j=i+1; j<total; j++){
            if(a[max_index]>a[j]) max_index = j;

            tmp = a[max_index];
            a[max_index] = a[i];
            a[i] = tmp; 
        }
    }
}

void Merge(int a[], int b[], int sorted[], int alen, int blen){
    int i = 0, j = 0;
    while(i<alen && j<blen){
        sorted[i+j] = a[i]>b[j]? a[i++] : b[j++];
    }

    while(i<alen){
        sorted[i+j] = a[i++];
    }

    while(j<blen){
        sorted[i+j] = b[j++];
    }
}
