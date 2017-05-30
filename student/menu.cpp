#include "score.h"

void DoMainMenu( STUDENT **pstu )
{
	char TitleName[30] = "学生课程学习主菜单选择"; 
	char showitem[9][31]={	"1   打开文件", 
							"2   保存文件", 
							"3   登录数据", 
							"4   查找数据", 
							"5   修改数据", 
							"6   显示数据", 
							"7   结果排序", 
							"8   统计数据",
							"0   退出系统" }; 
	void (*func[])(STUDENT **, int) = { DoOpen, DoSave, Doinput, DoSearch, DoEdit, DoShow, DoSort, Dotongji };
	
	int dd;

	while ( 1 )
	{
		ShowMenu( TitleName, showitem, 9 );
		scanf( "%d", &dd );
		if ( dd==0 ) 
		{ 
			ShowQuit(pstu);  
			break; 
		}
		if ( dd<0 || dd>=9 ) 
		{
			ShowSelectError(9);
			continue;
		}
		func[dd-1](pstu,DataNum);
	}
}

void DoOpen( STUDENT **pstu, int num )
{
	char TitleName[30] = "请选择一个文件"; 
	char showitem[8][31] = {	"1  01班学习成绩文件", 
								"2  02班学习成绩文件", 
								"3  03班学习成绩文件", 
								"4  04班学习成绩文件", 
								"5  05班学习成绩文件", 
								"6  06班学习成绩文件", 
								"7  07班学习成绩文件", 
								"0  返回上一级" }; 
	char FileName[][21]  = { "class01.dat", "class02.dat", "class03.dat", "class04.dat", "class05.dat", "class06.dat", "class07.dat" };
	int  dd;

	while ( 1 )
	{
		ShowMenu( TitleName, showitem, 8 );
		scanf( "%d", &dd );
		if ( dd==0 ) break;  
		if ( dd<0 || dd>=8 ) ShowSelectError(8);
		else 
		{ 
			strcpy( WorkingFileName, FileName[dd-1] );
			if ( !OpenData( pstu, num ) )
			{
				ShowMessage( "\n文件不存在，请重新选择！", WorkingFileName );	
				strcpy( WorkingFileName , "" );
				continue;
			}
			ShowMessage( "\n文件已经打开！", WorkingFileName );
			break;
		}
	}
}

void DoSave( STUDENT **pstu, int num )
{
	char TitleName[30] = "请选择一个文件"; 
	char showitem[8][31] = {	"1  01班学习成绩文件", 
								"2  02班学习成绩文件", 
								"3  03班学习成绩文件", 
								"4  04班学习成绩文件", 
								"5  05班学习成绩文件", 
								"6  06班学习成绩文件", 
								"7  07班学习成绩文件", 
								"0  返回上一级" }; 
	char FileName[7][21] = { "class01.dat", "class02.dat", "class03.dat", "class04.dat", "class05.dat", "class06.dat", "class07.dat" };
	int  dd;
	if (!strcmp(WorkingFileName,""))
	{
		while ( 1 )
		{
			ShowMenu( TitleName, showitem, 8 );
			scanf( "%d", &dd );
			if ( dd==0 ) break;  
			if ( dd<0 || dd>=8 ) ShowSelectError(8);
			else 
			{ 
				strcpy( WorkingFileName, FileName[dd-1] );
				break;
			}
		}
	}
	SaveData( pstu, num );
	ShowMessage( "文件已经保存！", WorkingFileName );
}


void Doinput( STUDENT **pstu, int num )
{
	int i,cc;
	printf( "\n\n数据登录操作！\n" );
	while(1)
    {
     	printf( "\n请输入本次登陆学生人数: " );
		scanf( "%d", &cc );
		fflush(stdin);
		if (cc>0 && cc<MAXNUM-num) break;
	}
	printf( "\n请依次输入下列学生数据:\n" );
    for ( i=0; i<cc; i++ )					
    {
        pstu[num+i] = InputItem();
        if (pstu[num+i]==NULL)				
        {
            printf("\n内存分配有错!\n");
            FreeMemory (pstu, i);		
            return;
        }
		DataNum++;
    }
	EditFlag = 1;
}


void DoSearch( STUDENT **pstu, int num )
{
	char  TitleName[30] = "请选择需要查找的数据项"; 
	char  showitem[9][31] = {	"1   学号", 
								"2   姓名", 
								"3   性别", 
								"4   年龄", 
								"5   班级", 
								"6   英语", 
								"7   数学", 
								"8   C语言", 
								"0   返回上一级" }; 
	char  sex = 0;
	int   item;
	int   dd;
	float score = 0.0;
	char  name[31] = "";

	while ( 1 )
	{
		ShowMenu( TitleName, showitem, 9 );
		scanf( "%d", &dd );
		if ( dd==0 ) break;  
		if ( dd<0 || dd>=9 ) ShowSelectError(9);
		else 
		{ 
			if ( dd==1 ) 
			{
 				printf("\n请输入要查找的学号：");
				scanf( "%s", name );
				fflush(stdin);
			}
			else if ( dd==2 ) 
			{
 				printf("\n请输入要查找的姓名：");
				scanf( "%s", name );
				fflush(stdin);
			}
			else if ( dd==3 )
			{
				while(1)
				{
					printf("\n请输入要查找的性别(M,F): ");
					fflush(stdin);
					scanf("%c", &sex);
					fflush(stdin);
					if ( sex=='M' || sex=='F') break;     
					else ShowMessage( "数据输入有错，请重新输入！", "" ); 
				}
				if ( sex=='M' ) item = 0;
				else item = 1;
			}
			else if ( dd==4 )
			{
				while(1)
				{
					printf("\n请输入要查找的年龄: ");
					scanf("%d", &item);
					fflush(stdin);
					if ( item>15 && item<32 ) break;  
					else ShowMessage( "数据输入有错，请重新输入！", "" ); 
				}
			}
			else if ( dd==5 )
			{
				printf("\n请输入要查找的班级: ");
				scanf("%d", &item);
				fflush(stdin);
			}
			else if ( dd==6 )
			{
				while(1)
				{
					printf("\n请输入要查找的英语成绩: ");
					scanf("%f", &score);
					fflush(stdin);
					if ( score>=0 && score<=100 ) break;        
					else ShowMessage( "数据输入有错，请重新输入！", "" ); 
				}
			}
			else if ( dd==7 )
			{
				while(1)
				{
					printf("\n请输入要查找的数学成绩: ");
					scanf("%f", &score);
					fflush(stdin);
					if ( score>=0 && score<=100 ) break;
					else ShowMessage( "数据输入有错，请重新输入！", "" ); 
				}
			}
			else if ( dd==8 )
			{
				while(1)
				{
					printf("\n请输入要查找的C语言成绩: ");
					scanf("%f", &score);
					fflush(stdin);
					if ( score>=0 && score<=100 ) break;        
					else ShowMessage( "数据输入有错，请重新输入！", "" ); 
				}
			}

			if ( !SearchData(pstu,num,dd,name,score,item) ) 
				ShowMessage( "文件中没有找到要查找的数据！", WorkingFileName );
			else
				ShowMessage( "文件中的数据查找完毕！", WorkingFileName );
			break;
		}
	}		
}


void DoEdit( STUDENT **pstu, int num ) 
{
	int  dd;
	char no[31];

	printf( "\n——————————————数据修改！——————————————\n" );
	printf( "\n请输入要修改的学生的学号：" );
	scanf( "%s", no );
	dd = SearchNo( pstu, num, no );
	if ( dd<0 ) { 
		printf( "\n没找到需要修改的学生！\n" );
		return;
	}
	printf( "\n" );
	ShowOneItem( pstu, dd );
	InputOneData( pstu, dd );
	EditFlag = 1;
}


void DoShow( STUDENT **pstu, int num ) 
{
	int i;
    printf ("\n==========================班级数据表===========================\n");
    for (i=0; i<num; i++)			
    {
		if(pstu[i])
			printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n", 
					pstu[i]->no, pstu[i]->name, 
					(pstu[i]->sex==man)?"男":"女", 
					pstu[i]->age,  
					pstu[i]->classno, 
					pstu[i]->English, 
					pstu[i]->Math, 
					pstu[i]->C_Language );
	}
	printf ("===============================================================\n");
}


void DoSort( STUDENT **pstu, int num )
{
	char TitleName[30] = "请选择一个字段进行排序"; 
	char showitem[8][31] = {	"1   学号", 
								"2   姓名", 
								"3   英语", 
								"4   数学", 
								"5   C语言", 
								"0   返回上一级" }; 
	int  dd;

	while ( 1 )
	{
		ShowMenu( TitleName, showitem, 6 );
		scanf( "%d", &dd );
		if ( dd==0 ) break;  
		if ( dd<0 || dd>=6 ) ShowSelectError(6);
		else 
		{ 
			SortStuInfo( pstu, num, dd );
			ShowMessage( "文件已经排序保存！", WorkingFileName );
			break;
		}
	}	
}

void Dotongji( STUDENT **pstu, int num )
{
	tongjiall( pstu, num );
	ShowMessage( "\n统计结束！", WorkingFileName );
}