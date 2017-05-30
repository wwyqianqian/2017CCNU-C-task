#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#ifndef SCORE_H
#define SCORE_H

#define TRUE	1
#define FALSE	0
#define MAXNUM	100


enum SEX { man, female };
struct Student_Info
{
	char	no[9];			//学号
	char	name[20];		//姓名
	enum	SEX sex;		//性别
	int		age;			//年龄
	int		classno;		//班级
	float	Math;			//数学
	float	C_Language;		//C语言
	float	English;		//英语
};

typedef struct Student_Info STUDENT;

STUDENT *GetStuInfo(int i);
void SortStuInfo(STUDENT **pstu, int num);
void FreeMemory(STUDENT **pstu, int num);

extern int  EditFlag;
extern char WorkingFileName[31];
extern int  DataNum;

void DoOpen(STUDENT **, int);
void DoSave(STUDENT **, int);
void Doinput(STUDENT **, int);
void DoSearch(STUDENT **, int);
void DoEdit(STUDENT **, int); 
void DoShow(STUDENT **, int); 
void DoSort(STUDENT **, int);
void Dotongji(STUDENT **, int);

void ShowMessage( char *msg, char *str );
void ShowMenu( char *title, char menuitem[][31], int cc );
int  ShowIsSave(void);

void ShowSelectError( int cc );
void ShowBye( void );
void ShowQuit( STUDENT **pstu );
void IsSave( STUDENT **pstu );

void DoMainMenu( STUDENT **pstu );

int  OpenData( STUDENT **pstu, int num );
int  SaveData( STUDENT **pstu, int num );

STUDENT *InputItem(void);
void ShowOneItem( STUDENT **pstu, int i );
void InputOneData( STUDENT **pstu, int i );

int  SearchData(STUDENT **pstu, int num, int item, char *name, float score, int dd );
int  SearchNo(STUDENT **pstu, int num, char *name );

void SortStuInfo( STUDENT **pstu, int max, int cc );

void tongjiall( STUDENT **pstu, int num );

void FreeMemory(STUDENT **pstu, int num);
void Destory( STUDENT **pstu, int num );
void InitList(STUDENT **pstu, int num );

#endif
