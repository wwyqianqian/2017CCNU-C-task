//失败了的坑，暑假填。-2017.5.25

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct student{
  char num[10];
  char nane[20];
  char class[20];
  float score;

  struct student *next;

}student;

int main(void){
  FILE *fi, *fo;
  fi = fopen("./input.data", "r");
  fo = fopen("./input.data", "w+");

  student *head = (student*)malloc(sizeof student);

  if(head = NULL){
    printf("none");
    return;
  }


  strcpy(head->name," ");

  //next
  current->next = (student*)malloc(sizeof student);
  current = current->next;


  printf("After sorted: \n" );
  fi = head->next;
  while (fi != NULL) {
    printf("%d", p->score);
    p = p->next;
  }
}


void cpscore(student **stu){
  student *current = NULL;
  student *big = NULL;
  student *next = NULL;

  current = *stu;
  big = *stu;
  next = *sru;

  while (current != NULL && current->next != NULL) {
    while (next != NULL) {
      if (next->score > big->score) {
        big = next;
      }
      //exchange
    }
  }
    *current ^= *big;
    *big ^= *current;
    *current ^= *big;
}
