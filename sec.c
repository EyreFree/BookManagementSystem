/********************************************************************************
**         ����:EyreFree	��19��	QQ:1795179491                          **
********************************************************************************/
#include"head.h"



openfire(int turn)																				//���Һ���
{																								//�ҳ��м������ϲ���Ҫ������ݼ�¼
	if(strlen(stu.time)!=10)
		return(turn);
	else
	{
		turn++;
		*p1=stu;																				//������Ҫ�����ݼ�¼д������
		p1=(struct infor*)malloc(LEN);															//��������
		p2->next=p1;
		p3=p2;
		p2=p1;
		return(turn);																			//���ؼ�¼����turn
	}
}




showresult(int turn)																			//��Ŀ���¼������������
{
	char c,Found;
	int len,time=0,Pages,Page=1,i;
	Pages=(turn/LINE+1);
	if(turn==1)																					//���޶�Ӧ��¼ʱ������
	{
		line(1);
		printf("\n\n");
		mid();printf("      ��¼��:\n\n");
		mid();printf("      ��  ��:\n\n");
		mid();printf("      ������:\n\n");
		mid();printf("      �����:\n\n");
		mid();printf("      ���浥λ:");
		printf("\n\n\n");mid();
		printf("      ����ʧ��!  �Ƿ����?\n\n");mid();
		printf("      (Yes[�س�] / No[Esc])");
		Found=getch();
		while(Found!='y'&&Found!='n'&&Found!='Y'&&Found!='N'&&Found!=13&&Found!=27)
			Found=getch();
		if(Found=='y'||Found=='Y'||Found==13)
			sec('1');
		else
			home('1');
	}
	if(turn==2)																					//������һ������Ҫ��ļ�¼ʱ�������һ��
	{
		line(1);
		printf("\n\n");
		mid();printf("      ��¼��:%s\n\n",Start->num);
		mid();printf("      ��  ��:%s\n\n",Start->name);
		mid();printf("      ������:%s\n\n",Start->writer);
		mid();printf("      �����:%s\n\n",Start->Class);
		mid();printf("      ���浥λ:%s\n\n",Start->publisher);
		mid();printf("      ����ʱ��:%s\n\n",Start->time);
		mid();printf("      �۸�:%s",Start->price);
		fclose(save);
		printf("\n\n\n");mid();
		printf("      �����ɹ�!  �Ƿ����?\n\n");mid();
		printf("      (Yes[�س�] / No[Esc])");
		Found=getch();
		while(Found!='y'&&Found!='n'&&Found!='Y'&&Found!='N'&&Found!=13&&Found!=27)
			Found=getch();
		if(Found=='y'||Found=='Y'||Found==13)
			sec('1');
		else
			home('1');
		}
	else																						//���ж������Ҫ��ļ�¼ʱ����ҳ��ӡ
	{
		while(1)
		{
			p1=Start;
			printf("   ");
			for(i=0;i<(LINE*(Page-1));i++)
			{	
				p1=p1->next;
			}
			system("cls");
			line(1);
			line(2);
			printf("\n   ");
			do																					//ѭ�������ҳ�������
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
					c=getch();																	//�����û��������Ƿ������½���
				if(c==27) home('1');
				if(c==77&&Page!=Pages&&p1->next!=NULL)											//�����û�����������Ӧ��Ļ����
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
}




found(int Sec)																					//������Ӧ�ļ�����
{
	char Found;
	int Pages,turn=1;
	Start=NULL;
	p1=p2=p3=(struct infor*)malloc(LEN);
	Start=p1;
	system("cls");
	switch(Sec)
	{
	case '1':	if((save=fopen("book.txt","r"))==NULL)											//��¼��Ų���
				{
					system("cls");
					line(1);
					printf("\n\n   ��ʧ��!\n\n   �ļ�������!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   �ļ���ȡʧ��!\n\n   ");
				}
				else
				{
					while(!feof(save))
					{
						fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",stu.num,stu.name,stu.writer,stu.Class,stu.publisher,stu.time,stu.price);
						if(!strcmp(stu.num,tem.num)&&(!feof(save)))
							turn=openfire(turn);
					}
					fclose(save);
					p3->next=NULL;
					showresult(turn);
				}
				break;
	case '2':	if((save=fopen("book.txt","r"))==NULL)											//����������
				{
					system("cls");
					line(1);
					printf("\n\n   ��ʧ��!\n\n   �ļ�������!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   �ļ���ȡʧ��!\n\n   ");
				}
				else
				{
					while(!feof(save))
					{
						fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",stu.num,stu.name,stu.writer,stu.Class,stu.publisher,stu.time,stu.price);
						if(!strcmp(stu.name,tem.name)&&(!feof(save)))
							turn=openfire(turn);
					}
					fclose(save);
					p3->next=NULL;
					showresult(turn);
				}
				break;
	case '3':	if((save=fopen("book.txt","r"))==NULL)											//�����߲���
				{
					system("cls");
					line(1);
					printf("\n\n   ��ʧ��!\n\n   �ļ�������!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   �ļ���ȡʧ��!\n\n   ");
				}
				else
				{
					while(!feof(save))
					{
						fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",stu.num,stu.name,stu.writer,stu.Class,stu.publisher,stu.time,stu.price);
						if(!strcmp(stu.writer,tem.writer)&&(!feof(save)))
							turn=openfire(turn);
					}
					fclose(save);
					p3->next=NULL;
					showresult(turn);
				}
				break;
	case '4':	if((save=fopen("book.txt","r"))==NULL)											//������Ų���
				{
					system("cls");
					line(1);
					printf("\n\n   ��ʧ��!\n\n   �ļ�������!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   �ļ���ȡʧ��!\n\n   ");
				}
				else
				{
					while(!feof(save))
					{
						fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",stu.num,stu.name,stu.writer,stu.Class,stu.publisher,stu.time,stu.price);
						if(!strcmp(stu.Class,tem.Class)&&(!feof(save)))
							turn=openfire(turn);
					}
					fclose(save);
					p3->next=NULL;
					showresult(turn);
				}
				break;
	case '5':	if((save=fopen("book.txt","r"))==NULL)											//�����浥λ����
				{
					system("cls");
					line(1);
					printf("\n\n   ��ʧ��!\n\n   �ļ�������!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   �ļ���ȡʧ��!\n\n   ");
				}
				else
				{
					while(!feof(save))
					{
						fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",stu.num,stu.name,stu.writer,stu.Class,stu.publisher,stu.time,stu.price);
						if(!strcmp(stu.publisher,tem.publisher)&&(!feof(save)))
							turn=openfire(turn);				
					}
					fclose(save);
					p3->next=NULL;
					showresult(turn);
				}
				break;
	}
}



resec(int Sec)																					//�����û��������Ӧ��������
{
	switch(Sec)
	{
	case '1':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("   >>>��¼��:\n\n");
				mid();printf("      ��  ��:\n\n");
				mid();printf("      ������:\n\n");
				mid();printf("      �����:\n\n");
				mid();printf("      ���浥λ:");
				printf("\n\n");mid();printf("      ������Ҫ���ҵĵ�¼�ţ�");
				while(1)
				{
					scanf("%s",tem.num);
					if(strlen(tem.num)==6) break;												//���������ݺϷ�������ѭ��
					else																		//���������ݷǷ�����������
					{
						printf("\n\n");mid();printf("      ������淶�ĵ�¼��(����Ϊ6λ����)~!\n\n");mid();
						printf("      ");
						system("pause");
						resec('1');
					}
					system("cls");
				}
				found('1');
	case '2':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:\n\n");
				mid();printf("   >>>��  ��:\n\n");
				mid();printf("      ������:\n\n");
				mid();printf("      �����:\n\n");
				mid();printf("      ���浥λ:");
				printf("\n\n");mid();printf("      ������Ҫ���ҵ�������");
				while(1)
				{
					scanf("%s",tem.name);
					if(!(strlen(tem.name)>20||strlen(tem.name)<=0)) break;						//���������ݺϷ�������ѭ��
					else																		//���������ݷǷ�����������
					{
						printf("\n\n");mid();printf("      ������淶������(10����������)~!\n\n");mid();
						printf("      ");
						system("pause");
						resec('2');
					}
					system("cls");
				}
				found('2');
	case '3':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:\n\n");
				mid();printf("      ��  ��:\n\n");
				mid();printf("   >>>������:\n\n");
				mid();printf("      �����:\n\n");
				mid();printf("      ���浥λ:");
				printf("\n\n");mid();printf("      ������Ҫ���ҵ���������");
				while(1)
				{
					scanf("%s",tem.writer);
					if(!(strlen(tem.writer)<=0||strlen(tem.writer)>8)) break;					//���������ݺϷ�������ѭ��
					else																		//���������ݷǷ�����������
					{
						printf("\n\n");mid();printf("      ������淶��������(4����������)~!\n\n");mid();
						printf("      ");
						system("pause");
						resec('3');
					}
					system("cls");
				}
				found('3');
	case '4':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:\n\n");
				mid();printf("      ��  ��:\n\n");
				mid();printf("      ������:\n\n");
				mid();printf("   >>>�����:\n\n");
				mid();printf("      ���浥λ:");
				printf("\n\n");mid();printf("      ������Ҫ���ҵķ���ţ�");
				while(1)
				{
					scanf("%s",tem.Class);
					if(!(strlen(tem.Class)<=0||strlen(tem.Class)>3)) break;						//���������ݺϷ�������ѭ��
					else																		//���������ݷǷ�����������
					{
						printf("\n\n");mid();printf("      ������淶�ķ����(3λ��������)~!\n\n");mid();
						printf("      ");
						system("pause");
						resec('4');
					}
					system("cls");
				}
				found('4');
	case '5':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:\n\n");
				mid();printf("      ��  ��:\n\n");
				mid();printf("      ������:\n\n");
				mid();printf("      �����:\n\n");
				mid();printf("   >>>���浥λ:");
				printf("\n\n");mid();printf("      ������Ҫ���ҵĳ��浥λ��");
				while(1)
				{
					scanf("%s",tem.publisher);
					if((strlen(tem.publisher)<=20)&&(strlen(tem.publisher)>0)) break;			//���������ݺϷ�������ѭ��
					else																		//���������ݷǷ�����������
					{
						printf("\n\n");mid();printf("      ������淶�ĳ��浥λ(����Ϊ10����������)~!\n\n");mid();
						printf("      ");
						system("pause");
						resec('5');
					}
					system("cls");
				}
				found('5');
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



sec(int Sec)																					//���û�ѡ���������
{
	char C1;
	int i;
	system("cls");
	line(1);
	switch(Sec)
	{
	case '1':	printf("\n\n");
				mid();printf("   >>>��¼��:\n\n");
				mid();printf("      ��  ��:\n\n");
				mid();printf("      ������:\n\n");
				mid();printf("      �����:\n\n");
				mid();printf("      ���浥λ:");break;
	case '2':	printf("\n\n");
				mid();printf("      ��¼��:\n\n");
				mid();printf("   >>>��  ��:\n\n");
				mid();printf("      ������:\n\n");
				mid();printf("      �����:\n\n");
				mid();printf("      ���浥λ:");break;
	case '3':	printf("\n\n");
				mid();printf("      ��¼��:\n\n");
				mid();printf("      ��  ��:\n\n");
				mid();printf("   >>>������:\n\n");
				mid();printf("      �����:\n\n");
				mid();printf("      ���浥λ:");break;
	case '4':	printf("\n\n");
				mid();printf("      ��¼��:\n\n");
				mid();printf("      ��  ��:\n\n");
				mid();printf("      ������:\n\n");
				mid();printf("   >>>�����:\n\n");
				mid();printf("      ���浥λ:");break;
	case '5':	printf("\n\n");
				mid();printf("      ��¼��:\n\n");
				mid();printf("      ��  ��:\n\n");
				mid();printf("      ������:\n\n");
				mid();printf("      �����:\n\n");
				mid();printf("   >>>���浥λ:");break;
	}
	printf("\n");
	line(6);
	C1=getch();
	while(C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=27&&C1!=13)
		C1=getch();																				//�����û�����������Ƿ������½���
	switch(C1)																					//�����û�����ִ����Ӧ��Ļ����
	{
	case 27:home('1');
	case 13:resec(Sec);
	case 72:
	case 75:if(Sec=='1') Sec='5';
			else Sec--; break;
	case 77:
	case 80:if(Sec=='5') Sec='1';
			else Sec++;break;
	}
	sec(Sec);																					//���ݲ���
}
