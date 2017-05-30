#include "score.h"

void DoMainMenu( STUDENT **pstu )
{
	char TitleName[30] = "ѧ���γ�ѧϰ���˵�ѡ��"; 
	char showitem[9][31]={	"1   ���ļ�", 
							"2   �����ļ�", 
							"3   ��¼����", 
							"4   ��������", 
							"5   �޸�����", 
							"6   ��ʾ����", 
							"7   �������", 
							"8   ͳ������",
							"0   �˳�ϵͳ" }; 
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
	char TitleName[30] = "��ѡ��һ���ļ�"; 
	char showitem[8][31] = {	"1  01��ѧϰ�ɼ��ļ�", 
								"2  02��ѧϰ�ɼ��ļ�", 
								"3  03��ѧϰ�ɼ��ļ�", 
								"4  04��ѧϰ�ɼ��ļ�", 
								"5  05��ѧϰ�ɼ��ļ�", 
								"6  06��ѧϰ�ɼ��ļ�", 
								"7  07��ѧϰ�ɼ��ļ�", 
								"0  ������һ��" }; 
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
				ShowMessage( "\n�ļ������ڣ�������ѡ��", WorkingFileName );	
				strcpy( WorkingFileName , "" );
				continue;
			}
			ShowMessage( "\n�ļ��Ѿ��򿪣�", WorkingFileName );
			break;
		}
	}
}

void DoSave( STUDENT **pstu, int num )
{
	char TitleName[30] = "��ѡ��һ���ļ�"; 
	char showitem[8][31] = {	"1  01��ѧϰ�ɼ��ļ�", 
								"2  02��ѧϰ�ɼ��ļ�", 
								"3  03��ѧϰ�ɼ��ļ�", 
								"4  04��ѧϰ�ɼ��ļ�", 
								"5  05��ѧϰ�ɼ��ļ�", 
								"6  06��ѧϰ�ɼ��ļ�", 
								"7  07��ѧϰ�ɼ��ļ�", 
								"0  ������һ��" }; 
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
	ShowMessage( "�ļ��Ѿ����棡", WorkingFileName );
}


void Doinput( STUDENT **pstu, int num )
{
	int i,cc;
	printf( "\n\n���ݵ�¼������\n" );
	while(1)
    {
     	printf( "\n�����뱾�ε�½ѧ������: " );
		scanf( "%d", &cc );
		fflush(stdin);
		if (cc>0 && cc<MAXNUM-num) break;
	}
	printf( "\n��������������ѧ������:\n" );
    for ( i=0; i<cc; i++ )					
    {
        pstu[num+i] = InputItem();
        if (pstu[num+i]==NULL)				
        {
            printf("\n�ڴ�����д�!\n");
            FreeMemory (pstu, i);		
            return;
        }
		DataNum++;
    }
	EditFlag = 1;
}


void DoSearch( STUDENT **pstu, int num )
{
	char  TitleName[30] = "��ѡ����Ҫ���ҵ�������"; 
	char  showitem[9][31] = {	"1   ѧ��", 
								"2   ����", 
								"3   �Ա�", 
								"4   ����", 
								"5   �༶", 
								"6   Ӣ��", 
								"7   ��ѧ", 
								"8   C����", 
								"0   ������һ��" }; 
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
 				printf("\n������Ҫ���ҵ�ѧ�ţ�");
				scanf( "%s", name );
				fflush(stdin);
			}
			else if ( dd==2 ) 
			{
 				printf("\n������Ҫ���ҵ�������");
				scanf( "%s", name );
				fflush(stdin);
			}
			else if ( dd==3 )
			{
				while(1)
				{
					printf("\n������Ҫ���ҵ��Ա�(M,F): ");
					fflush(stdin);
					scanf("%c", &sex);
					fflush(stdin);
					if ( sex=='M' || sex=='F') break;     
					else ShowMessage( "���������д����������룡", "" ); 
				}
				if ( sex=='M' ) item = 0;
				else item = 1;
			}
			else if ( dd==4 )
			{
				while(1)
				{
					printf("\n������Ҫ���ҵ�����: ");
					scanf("%d", &item);
					fflush(stdin);
					if ( item>15 && item<32 ) break;  
					else ShowMessage( "���������д����������룡", "" ); 
				}
			}
			else if ( dd==5 )
			{
				printf("\n������Ҫ���ҵİ༶: ");
				scanf("%d", &item);
				fflush(stdin);
			}
			else if ( dd==6 )
			{
				while(1)
				{
					printf("\n������Ҫ���ҵ�Ӣ��ɼ�: ");
					scanf("%f", &score);
					fflush(stdin);
					if ( score>=0 && score<=100 ) break;        
					else ShowMessage( "���������д����������룡", "" ); 
				}
			}
			else if ( dd==7 )
			{
				while(1)
				{
					printf("\n������Ҫ���ҵ���ѧ�ɼ�: ");
					scanf("%f", &score);
					fflush(stdin);
					if ( score>=0 && score<=100 ) break;
					else ShowMessage( "���������д����������룡", "" ); 
				}
			}
			else if ( dd==8 )
			{
				while(1)
				{
					printf("\n������Ҫ���ҵ�C���Գɼ�: ");
					scanf("%f", &score);
					fflush(stdin);
					if ( score>=0 && score<=100 ) break;        
					else ShowMessage( "���������д����������룡", "" ); 
				}
			}

			if ( !SearchData(pstu,num,dd,name,score,item) ) 
				ShowMessage( "�ļ���û���ҵ�Ҫ���ҵ����ݣ�", WorkingFileName );
			else
				ShowMessage( "�ļ��е����ݲ�����ϣ�", WorkingFileName );
			break;
		}
	}		
}


void DoEdit( STUDENT **pstu, int num ) 
{
	int  dd;
	char no[31];

	printf( "\n���������������������������������޸ģ�����������������������������\n" );
	printf( "\n������Ҫ�޸ĵ�ѧ����ѧ�ţ�" );
	scanf( "%s", no );
	dd = SearchNo( pstu, num, no );
	if ( dd<0 ) { 
		printf( "\nû�ҵ���Ҫ�޸ĵ�ѧ����\n" );
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
    printf ("\n==========================�༶���ݱ�===========================\n");
    for (i=0; i<num; i++)			
    {
		if(pstu[i])
			printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n", 
					pstu[i]->no, pstu[i]->name, 
					(pstu[i]->sex==man)?"��":"Ů", 
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
	char TitleName[30] = "��ѡ��һ���ֶν�������"; 
	char showitem[8][31] = {	"1   ѧ��", 
								"2   ����", 
								"3   Ӣ��", 
								"4   ��ѧ", 
								"5   C����", 
								"0   ������һ��" }; 
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
			ShowMessage( "�ļ��Ѿ����򱣴棡", WorkingFileName );
			break;
		}
	}	
}

void Dotongji( STUDENT **pstu, int num )
{
	tongjiall( pstu, num );
	ShowMessage( "\nͳ�ƽ�����", WorkingFileName );
}