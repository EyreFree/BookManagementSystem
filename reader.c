/********************************************************************************
**         ����:EyreFree	��19��	QQ:1795179491                          **
********************************************************************************/
#include"head.h"
reader()																				//�鿴ȫ������
{
	char c;
	int len,time=0,turn=0,Pages,Page=1,i;
	Start=NULL;
	p1=p2=(struct infor*)malloc(LEN);													//��������
	Start=p1;
	if((save=fopen("book.txt","r"))==NULL)												//���ļ���ʧ���򱨴�
	{
		system("cls");
		line(1);
		printf("\n\n   ��ʧ��!�ļ�������!\n\n   ");
		system("pause");
		home('1');
	}
	if(feof(save))																		//���ļ�Ϊ���򱨴�
	{
		system("cls");
		line(1);
		printf("\n\n   ��ȡʧ��!���ݲ�����!\n\n   ");
		system("pause");
		home('1');
	}
	else																				//�����ݴ������������
	{
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		while(!feof(save))
		{
			p1=(struct infor*)malloc(LEN);
			turn++;
			p2->next=p1;
			p2=p1;
			fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		}
		p2->next=NULL;
	}
	if(turn%LINE==0)
		Pages=(turn/LINE);																//��¼��ҳ��
	else
		Pages=(turn/LINE+1);
	if(strlen(Start->num)!=6)
	{																					//�������׽ڵ��¼�����ݴ����򷵻���ҳ
		system("cls");
		line(1);
		printf("\n   ��ȡʧ��!���ݲ�����!\n\n   ");
		system("pause");
		home('1');
	}
	while(1)
	{
		p1=Start;
		printf("   ");
		for(i=0;i<(LINE*(Page-1));i++)													//��ҳ�ƶ�ָ�뵽��Ӧҳ��
			p1=p1->next;
		system("cls");
		line(1);
		line(2);
		printf("\n   ");
		do																				//�����ǰҳ��������
		{	
			printf("%s ",p1->num);
			printf("%s ",p1->name);
			len=20;
			while((len-strlen(p1->name))>0)
			{
				printf(" ");
				len--;
			}
			printf("%s ",p1->writer);
			len=8;
			while((len-strlen(p1->writer))>0)
			{
				printf(" ");
				len--;
			}
			printf("%s ",p1->Class);
			len=3;
			while((len-strlen(p1->Class))>0)
			{
				printf(" ");
				len--;
			}
			printf("%s ",p1->publisher);
			len=20;
			while((len-strlen(p1->publisher))>0)
			{
				printf(" ");
				len--;
			}
			printf("%s ",p1->time);
			len=10;
			while((len-strlen(p1->time))>0)
			{
				printf(" ");
				len--;
			}
			printf("%s ",p1->price);
			len=6;
			while((len-strlen(p1->price))>0)
			{
				printf(" ");
				len--;
			}
			printf("\n   ");
			p1=p1->next;
			time++;
		}while(p1->next!=NULL&&time<LINE);
		while(time<LINE)
		{
			printf("\n");
			time++;
		}
		printf("\n\n   �T�T�T�T�T�T�T�T�T�T�T  [��] ��һҳ �� %d/%d ҳ ��һҳ [��]  �T�T�T�T�T�T�T�T�T�T�T",Page,Pages);
		while(1)
		{
			c=getch();
			while(c!=75&&c!=77&&c!=27)
				c=getch();																//��ȡ�û�����
			if(c==27) home('1');
			if(c==77&&Page!=Pages&&p1->next!=NULL)										//��Ӧ�û�����
			{
				system("cls");
				time=0;
				Page++;
				break;
			}
			if(c==75&&Page!=1)
			{
				system("cls");
				time=0;
				Page--;
				break;
			}
		}
	}
}