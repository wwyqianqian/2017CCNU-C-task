#include "score.h"

void ShowMessage( char *msg, char *str )
{
	printf( "\n\n%s%s\n", str, msg );
}

void ShowMenu( char *title, char menuitem[][31], int cc )
{
	int i;
	printf( "\n\n**" );
	printf( "%s", title );
	printf( "**\n" );
	printf( "��������������������������\n" );
	for( i=0; i<cc; i++ )
		printf( "      %s \n", menuitem[i] );
	printf( "��������������������������\n" );
	printf( "��ѡ��һ�0--%d���� ", cc-1 );
}

int ShowIsSave(void)
{
	int dd;
	char TitleName[30] = "����������"; 
	char showitem[2][31] = {	"1   ��������", 
								"0   ����������" };
	while ( 1 )
	{
		ShowMenu( TitleName, showitem, 2 );
		scanf( "%d", &dd );
		if ( dd==1 )  return TRUE;
		else if ( dd==0 ) return FALSE;
	}
}

void IsSave( STUDENT **pstu )
{
	if ( EditFlag )	
	{
		if (ShowIsSave()) DoSave(pstu,DataNum);
	}
}

void ShowSelectError( int cc )
{
	printf( "\nѡ�����!!\n" );
	printf( "��ʾ��ֻ��ѡ��0��%d����, ������ѡ��\n\n", cc );
}

void ShowBye( void )
{
	printf( "\nллʹ�ñ����!\n" );
	printf( "��ӭ�´���ʹ�ã�\n" );
	printf( "�ټ�����\n" );
}

void ShowQuit( STUDENT **pstu )
{
	IsSave(pstu);
	ShowBye();	
}

int OpenData( STUDENT **pstu, int num )
{
	int i=0, pos=0, pend, rc;
	FILE *fp;
	fp = fopen( WorkingFileName, "rb+" );
	if (!fp) 
	{
		ShowMessage( "\n�ļ����д�", WorkingFileName );
		return 0;
	}
	rc = sizeof(STUDENT);
	fseek( fp, 0L, SEEK_END );
	pend = ftell(fp);
	fseek( fp, 0L, SEEK_SET );
	while( pend && pend-pos>=rc )
	{
		pstu[i] = (STUDENT *)malloc (sizeof(STUDENT));
		if (!pstu[i]) 
		{
			ShowMessage( "\n�ڴ�����д�", WorkingFileName );
			return 0;
		}
		fread( pstu[i], sizeof(STUDENT), 1, fp );
		pos = ftell(fp); 
		i++;
	}
	DataNum = i;
	fclose(fp);	
	return 1;
}

int SaveData( STUDENT **pstu, int num )
{
	int i;
	FILE *fp;
	fp = fopen( WorkingFileName, "wb+" );
	if (!fp) 
	{
		ShowMessage( "\n�ļ������д�", WorkingFileName );
		return 0;
	}
	
	fseek( fp, 0L, SEEK_SET );
	for( i=0; i<DataNum; i++)
	{
		if ( pstu[i] )
			fwrite( pstu[i], sizeof(STUDENT), 1, fp );
	}
	fclose(fp);
	EditFlag = 0;
	return 1;
}

STUDENT *InputItem(void)
{
    STUDENT *p;
    char sex;
    p = (STUDENT *)malloc (sizeof(STUDENT));
    if (p==NULL) return NULL;
    printf("\n==������ѧ����Ϣ== \n" );
    printf("ѧ��: ");
    scanf( "%s", p->no);
    fflush(stdin);
	printf("����: ");
    scanf( "%s", p->name);
    fflush(stdin);  
    while(1)
    {
        printf("�Ա�(M,F): ");
        scanf("%c", &sex);
		fflush(stdin);
        if(sex=='M' || sex=='F') break;        
	}
	p->sex = (sex=='M')?man:female;
	printf("����: ");
    scanf("%d", &p->age);
    fflush(stdin);
	printf("�༶: ");
    scanf("%d", &p->classno);
    fflush(stdin);
	printf("��ѧ: ");
    scanf("%f", &p->Math);
	fflush(stdin);
	printf("Ӣ��: ");
    scanf("%f", &p->English);
	fflush(stdin);
    printf("C����: ");
    scanf("%f", &p->C_Language);
	fflush(stdin);
	return(p);
}

void ShowOneItem( STUDENT **pstu, int i ) 
{
    printf( "%10s%12s%4s%3d%6d%6.1f%6.1f%6.1f\n", 
			pstu[i]->no, pstu[i]->name, 
			(pstu[i]->sex==man)?"��":"Ů", 
			pstu[i]->age,  
			pstu[i]->classno, 
			pstu[i]->English, 
			pstu[i]->Math, 
			pstu[i]->C_Language );
}

int SearchData(STUDENT **pstu, int num, int item, char *name, float score, int dd )
{
	int flag=0, i, ii=-1;
	printf( "\n_____________________���ҵ����������£�____________________________\n" );
	for (i=0; i<num; i++ )
	{
		if (!pstu[i]) continue; 
		if ( item==1 && !strcmp(pstu[i]->no,name)	|| 
			 item==2 && !strcmp(pstu[i]->name,name) || 
			 item==3 && pstu[i]->sex==dd			|| 
			 item==4 && pstu[i]->age==dd			||
			 item==5 && pstu[i]->classno==dd		||
			 item==6 && pstu[i]->English==score		||
			 item==7 && pstu[i]->Math==score		||
			 item==8 && pstu[i]->C_Language==score		) 
		{
			ii = i;
			ShowOneItem(pstu,ii);
			flag = 1;
		}
	}
	printf( "___________________________________________________________________\n" );
	if ( flag ) return TRUE;
	else return FALSE;
}

int SearchNo(STUDENT **pstu, int num, char *name )
{
	int i;
	for (i=0; i<num; i++ )
	{
		if (!pstu[i]) continue; 
		if ( !strcmp(pstu[i]->no,name) ) return i;		
	}
	return -1;
}

void InputOneData( STUDENT **pstu, int i )
{
	STUDENT *p, *q;
	char sex;
	
	q = pstu[i];
    p = (STUDENT *)malloc (sizeof(STUDENT));
    if (p==NULL) return;
    printf("\n==������ѧ��Ϊ%s��ѧ����Ϣ== \n", pstu[i]->no );
    printf("����: ");
    scanf( "%s", p->name);
    fflush(stdin);  
    while(1)
    {
        printf("�Ա�(M,F): ");
        scanf("%c", &sex);
		fflush(stdin);
        if(sex=='M' || sex=='F') break;        
	}
	p->sex = (sex=='M')?man:female;
	printf("����: ");
    scanf("%d", &p->age);
    fflush(stdin);
	printf("�༶: ");
    scanf("%d", &p->classno);
    fflush(stdin);
	printf("��ѧ: ");
    scanf("%f", &p->Math);
	fflush(stdin);
	printf("Ӣ��: ");
    scanf("%f", &p->English);
	fflush(stdin);
    printf("C����: ");
    scanf("%f", &p->C_Language);
	fflush(stdin);
	strcpy(p->no, pstu[i]->no);
	pstu[i] = p;
	free(q);
}

void SortStuInfo( STUDENT **pstu, int max, int cc )
{
    STUDENT *p;
    int i, j, k;
	int num=0;

	for (i=0; i<max; i++ )
		if (!pstu[i]) break;
	num = i;

	for (i=0; i<num-1; i++)
	{
		k = i;
		for (j=i+1; j<num; j++)
			switch( cc )
			{
				case 1: if ( strcmp(pstu[j]->no, pstu[k]->no)>0 )		k = j;	break;
				case 2: if ( strcmp(pstu[j]->name, pstu[k]->name)>0 )	k = j;	break;
				case 3: if ( pstu[j]->English>pstu[k]->English )		k = j;	break;
				case 4: if ( pstu[j]->Math>pstu[k]->Math )				k = j;	break;
				case 5: if ( pstu[j]->C_Language>pstu[k]->C_Language )	k = j;	break;
			}		
		if (k!=i)
		{
			p = pstu[i];
			pstu[i] = pstu[k];
			pstu[k] = p;
		}
			
	}
}

void tongjiall( STUDENT **pstu, int num )
{
	int i,cc=0;
	float max=0, min=0, avr=0;
	float maxalle=0, minalle=100, avralle=0;
	float maxallm=0, minallm=100, avrallm=0;
	float maxallc=0, minallc=100, avrallc=0;

	printf( "\n---------------------ѧ���ɼ�ͳ�ƽ��--------------------\n" );
	printf( "%10s%12s%8s%8s%8s\n", "ѧ��", "����", "��߷�", "��ͷ�", "ƽ����" );
	
	for ( i=0; i<num; i++ )
	{
		if ( pstu[i] )
		{
			avr = (pstu[i]->English+pstu[i]->Math+pstu[i]->C_Language)/(float)3.0;
			max = pstu[i]->English>pstu[i]->Math ? pstu[i]->English : pstu[i]->Math; 
			max = max>pstu[i]->C_Language ? max : pstu[i]->C_Language;
			min = pstu[i]->English<pstu[i]->Math ? pstu[i]->English : pstu[i]->Math; 
			min = min<pstu[i]->C_Language ? min : pstu[i]->C_Language;
			if ( maxalle<pstu[i]->English) maxalle = pstu[i]->English;
			if ( minalle>pstu[i]->English) minalle = pstu[i]->English;
			avralle += pstu[i]->English;
			if ( maxallm<pstu[i]->Math) maxallm = pstu[i]->Math;
			if ( minallm>pstu[i]->Math) minallm = pstu[i]->Math;
			avrallm += pstu[i]->Math;
			if ( maxallc<pstu[i]->C_Language) maxallc = pstu[i]->C_Language;
			if ( minallc>pstu[i]->C_Language) minallc = pstu[i]->C_Language;
			avrallc += pstu[i]->C_Language;
			printf( "%10s%12s%8.1f%8.1f%8.1f\n", pstu[i]->no, pstu[i]->name, max, min, avr );
			cc++;
		}
	}
	avralle = avralle/cc;
	avrallm = avrallm/cc;
	avrallc = avrallc/cc;
	printf( "---------------------------------------------------------\n\n" );
	
	printf( "%10s%10s%10s%10s%\n", "ȫ��", "Ӣ��", "��ѧ", "C����" );
	printf( "---------------------------------------------------------\n" );
	printf( "%10s%10.1f%10.1f%10.1f\n", "��߷�", maxalle, maxallm, maxallc );
	printf( "%10s%10.1f%10.1f%10.1f\n", "��ͷ�", minalle, minallm, minallc );
	printf( "%10s%10.1f%10.1f%10.1f\n", "ƽ����", avralle, avrallm, avrallc );
	printf( "---------------------------------------------------------\n\n" );
}


void FreeMemory(STUDENT **pstu, int num)
{
    int i;
    for (i=0; i<num; i++) 
		if (pstu[i]) 
			free(pstu[i]);
    free(pstu); 
}

void Destory( STUDENT **pstu, int num )
{
	FreeMemory( pstu, num);
}

void InitList(STUDENT **pstu, int num )
{
	int i;
	for (i=0;i<num;i++) 
		pstu[i]=NULL;
}