/********************************************************************************
**         ����:EyreFree	��19��	QQ:1795179491                          **
********************************************************************************/
#include"head.h"


checker()																				//����¼�뺯��
{
	int checker=0;
	O=0;
	if((save=fopen("book.txt","r"))==NULL)
	{
		if((save=fopen("book.txt","w+"))==NULL)
		{
			system("cls");
			line(1);
			printf("\n\n   �ļ�����ʧ��!\n");
			system("pause");
			home('1');
		}
		O=1;
		jump();
	}
	while(!feof(save)&&(O!=1))															//������ݵ�¼���Ƿ��Ѵ���
	{
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",tem.num,tem.name,tem.writer,tem.Class,tem.publisher,tem.time,tem.price);
		if(!strcmp(stu.num,tem.num))
			checker++;	
	}
	fclose(save);
	return(checker);
}


jump()																					//��ת�����¼�����ݵ�¼���Ƿ��Ѵ���
{
	checker();
}


check()
{
	char Write;																			//ȷ���Ƿ�ʼ¼������
	system("cls");
	line(1);
	line(7);
	printf("\n\n   ������������¼�����!\n\n   �Ƿ����?\n\n   (Yes[�س�] / No[Esc])");
	Write=getch();
	while(Write!='y'&&Write!='n'&&Write!='Y'&&Write!='N'&&Write!=13&&Write!=27)
		Write=getch();
	if(Write=='y'||Write=='Y'||Write==13)
		scan();
	else
		home('1');
}




scan()																						//¼������
{
	int len=0;
	system("cls");
	line(1);
	line(7);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		scanf("%s",stu.num);
		if(strlen(stu.num)==6) 
		{	
			if(checker()>=1)																//����¼���Ѵ�����ǿ����������
			{	
				printf("\n   �õ�¼���Ѵ���,�����������µĵ�¼��~!\n\n   ");
				system("pause");
			}
			else break;																		//�����ݺϷ���δ��������ֹѭ��
		}
		else
		{
			printf("\n   ������淶�ĵ�¼��(����Ϊ6λ����)~!\n\n   ");						//����¼�Ų��Ϸ���ǿ����������
			system("pause");
		}
		system("cls");
		line(1);
		line(7);
	}
	system("cls");
	line(1);
	line(7);
	printf("%s ",stu.num);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		scanf("%s",stu.name);
		if(!(strlen(stu.name)>20||strlen(stu.name)<=0)) break;								//�����ݺϷ�����ֹѭ��
		else																				//�����ݲ��Ϸ���ǿ����������
		{
			printf("\n   ������淶������(10����������)~!\n\n   ");
			system("pause");
		}
		system("cls");
		line(1);
		line(7);
		printf("%s ",stu.num);
	}
	system("cls");
	line(1);
	line(7);
	printf("%s ",stu.num);
	printf("%s ",stu.name);
	len=20;
	while((len-strlen(stu.name))>0)
	{
		printf(" ");
		len--;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		scanf("%s",stu.writer);
		if(!(strlen(stu.writer)<=0||strlen(stu.writer)>8)) break;							//�����ݺϷ�����ֹѭ��
		else																				//�����ݲ��Ϸ���ǿ����������
		{
			printf("\n   ������淶��������(4����������)~!\n\n   ");
			system("pause");
		}
		system("cls");
		line(1);
		line(7);
		printf("%s %s",stu.num,stu.name);
		len=20;
		while((len-strlen(stu.name))>0)
		{
			printf(" ");
			len--;
		}
	}
	system("cls");
	line(1);
	line(7);
	printf("%s ",stu.num);
	printf("%s ",stu.name);
	len=20;
	while((len-strlen(stu.name))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.writer);
	len=8;
	while((len-strlen(stu.writer))>0)
	{
		printf(" ");
		len--;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		scanf("%s",stu.Class);
		if(!(strlen(stu.Class)<=0||strlen(stu.Class)>3)) break;								//�����ݺϷ�����ֹѭ��
		else																				//�����ݲ��Ϸ���ǿ����������
		{
			printf("\n   ������淶�ķ����(3λ��������)~!\n\n   ");
			system("pause");
		}
		system("cls");
		line(1);
		line(7);
		printf("%s %s",stu.num,stu.name);
		len=20;
		while((len-strlen(stu.name))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.writer);
		len=8;
		while((len-strlen(stu.writer))>0)
		{
			printf(" ");
			len--;
		}
	}
	system("cls");
	line(1);
	line(7);
	printf("%s ",stu.num);
	printf("%s ",stu.name);
	len=20;
	while((len-strlen(stu.name))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.writer);
	len=8;
	while((len-strlen(stu.writer))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.Class);
	len=3;
	while((len-strlen(stu.Class))>0)
	{
		printf(" ");
		len--;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		scanf("%s",stu.publisher);
		if((strlen(stu.publisher)<=20)&&(strlen(stu.publisher)>0)) break;					//�����ݺϷ�����ֹѭ��
		else																				//�����ݲ��Ϸ���ǿ����������
		{
			printf("\n   ������淶�ĳ��浥λ(����Ϊ10����������)~!\n\n   ");
			system("pause");
		}
		system("cls");
		line(1);
		line(7);
		printf("%s ",stu.num);
		printf("%s ",stu.name);
		len=20;
		while((len-strlen(stu.name))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.writer);
		len=8;
		while((len-strlen(stu.writer))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.Class);
		len=3;
		while((len-strlen(stu.Class))>0)
		{
			printf(" ");
			len--;
		}
	}
	system("cls");
	line(1);
	line(7);
	printf("%s ",stu.num);
	printf("%s ",stu.name);
	len=20;
	while((len-strlen(stu.name))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.writer);
	len=8;
	while((len-strlen(stu.writer))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.Class);
	len=3;
	while((len-strlen(stu.Class))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.publisher);
	len=20;
	while((len-strlen(stu.publisher))>0)
	{
		printf(" ");
		len--;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		scanf("%s",stu.time);
		if(strlen(stu.time)==10) break;														//�����ݺϷ�����ֹѭ��
		else
		{
			printf("\n   ������淶������(����Ϊ2011/01/01��ʽ)~!\n\n   ");					//�����ݲ��Ϸ���ǿ����������
			system("pause");
		}
		system("cls");
		line(1);
		line(7);
		printf("%s ",stu.num);
		printf("%s ",stu.name);
		len=20;
		while((len-strlen(stu.name))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.writer);
		len=8;
		while((len-strlen(stu.writer))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.Class);
		len=3;
		while((len-strlen(stu.Class))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.publisher);
		len=20;
		while((len-strlen(stu.publisher))>0)
		{
			printf(" ");
			len--;
		}
	}
	system("cls");
	line(1);
	line(7);
	printf("%s ",stu.num);
	printf("%s ",stu.name);
	len=20;
	while((len-strlen(stu.name))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.writer);
	len=8;
	while((len-strlen(stu.writer))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.Class);
	len=3;
	while((len-strlen(stu.Class))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.publisher);
	len=20;
	while((len-strlen(stu.publisher))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.time);
	len=10;
	while((len-strlen(stu.time))>0)
	{
		printf(" ");
		len--;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		scanf("%s",stu.price);
		if((0<strlen(stu.price))&&(strlen(stu.price)<=6)) break;							//�����ݺϷ�����ֹѭ��
		else
		{
			printf("\n   ������淶�ļ۸�(����Ϊ6λ��������)~!\n\n   ");					//�����ݲ��Ϸ���ǿ����������
			system("pause");
		}
		system("cls");
		line(1);
		line(7);
		printf("%s ",stu.num);
		printf("%s ",stu.name);
		len=20;
		while((len-strlen(stu.name))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.writer);
		len=8;
		while((len-strlen(stu.writer))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.Class);
		len=3;
		while((len-strlen(stu.Class))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.publisher);
		len=20;
		while((len-strlen(stu.publisher))>0)
		{
			printf(" ");
			len--;
		}
		printf("%s ",stu.time);
		len=10;
		while((len-strlen(stu.time))>0)
		{
			printf(" ");
			len--;
		}
	}
	system("cls");
	line(1);
	line(7);
	printf("%s ",stu.num);
	printf("%s ",stu.name);
	len=20;
	while((len-strlen(stu.name))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.writer);
	len=8;
	while((len-strlen(stu.writer))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.Class);
	len=3;
	while((len-strlen(stu.Class))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.publisher);
	len=20;
	while((len-strlen(stu.publisher))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.time);
	len=10;
	while((len-strlen(stu.time))>0)
	{
		printf(" ");
		len--;
	}
	printf("%s ",stu.price);
	len=6;
	while((len-strlen(stu.price))>0)
	{
		printf(" ");
		len--;
	}
	write();																				//����д�ļ�����д���ļ���
}