/********************************************************************************
**         ����:EyreFree	��19��	QQ:1795179491                          **
********************************************************************************/
#include"head.h"


repchoose(int Quit,int page,int RRLINE_B)									//�޸���ɾ������
{
	char C1;
	int i;
	system("cls");
	if(Quit==1)
	{
		for(i=0;i<=7;i++)printf("\n");
		mid();printf("  �X�T�T�T�T�T�T�T�T�T�T�T�[\n");
		mid();printf("  �Uȷ��ɾ������ (Y / N)���U\n");
		mid();printf("  �U������������          �U\n");
		mid();printf("  �U��ȷ�� (Y)��ȡ�� (N)  �U\n");
		mid();printf("  �U������������          �U\n");
		mid();printf("  �^�T�T�T�T�T�T�T�T�T�T�T�a");
	}
	else
	{
		for(i=0;i<=7;i++)printf("\n");
		mid();printf("  �X�T�T�T�T�T�T�T�T�T�T�T�[\n");
		mid();printf("  �Uȷ��ɾ������ (Y / N)���U\n");
		mid();printf("  �U          �������������U\n");
		mid();printf("  �U  ȷ�� (Y)��ȡ�� (N)���U\n");
		mid();printf("  �U          �������������U\n");
		mid();printf("  �^�T�T�T�T�T�T�T�T�T�T�T�a");
	}
	C1=getch();
	while(C1!=89&&C1!=78&&C1!=121&&C1!=110&&C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=13&&C1!=27)
		C1=getch();															//��ȡ�û����������벻�Ϸ������»�ȡ
	switch(C1)
	{																		//�����û����������Ӧ����
	case 27:rep(page,RRLINE_B);
	case 89:
	case 121:Quit=1;break;
	case 78:
	case 110:Quit=2;break;
	case 13:if(Quit==1)
			{
				if(page==1&&TIME==1)										//�����������������һ������ִ��ɾ������ʱ����
				{
					line(1);
					if((save=fopen("book.txt","w+"))==NULL)
					{
						system("cls");
						line(1);
						printf("\n\n\n   �ļ��޸�ʧ��!\n\n   ���ܾ̾�����!\n   ");
						system("pause");
						rep(1);
					}
					else
						fclose(save);
					system("cls");
					line(1);
					printf("\n\n\n   Դ�ļ����Ѳ���������!\n\n   ");
					system("pause");
					home('1');
				}
				if(TIME==1)
				{
					repdel(page-1,RRLINE_B);
				}
				else
					repdel(page,RRLINE_B);
			}
			else rep(page,RRLINE_B);
	default:if(Quit==1) Quit=2;
			else Quit=1;break;
	}
	repchoose(Quit,page,RRLINE_B);											//�����ϼ��˵�
}





repdel(int Page,int RRLINE_B)												//ɾ�������еĴ�ɾ�ڵ�
{
	int i;
	p1=Start;
	if(Page==1&&RRLINE_B==0)
	{
		Start=p1->next;
	}
	else
	{
		for(i=0;i<(RLINE*(Page-1)+RRLINE_B-1);i++)	
		p1=p1->next;
		p2=p1->next;
		if(p2->next!=NULL)
			p1->next=p2->next;
		else
			p1->next=NULL;
	}
	if(Page==(PAGE)) RRLINE_B=0;
	repwrite(Page,RRLINE_B);												//����д���ļ�����
}





repwrite(int page,int RRLINE_B)												//��д�����Ǿɵ������ļ�
{
	int len=0;
	p2=p1=Start;
	if((save=fopen("book.txt","w+"))==NULL)
	{
		system("cls");
		printf("\n\n\n   �ļ��޸�ʧ��!\n\n   ���ܾ̾�����!\n   ");
		system("pause");
		rep(1);
	}
	else
	{
		while(p1!=NULL&&p2!=NULL&&p2->next!=NULL&&p1->next!=NULL)			//������������д���ļ�
		{
			fprintf(save,"%s ",p1->num);
/////////////////////////////////////////////////////////////
			fprintf(save,"%s ",p1->name);
			len=20;
			while((len-strlen(p1->name))>0)
			{
				fprintf(save," ");
				len--;
			}
/////////////////////////////////////////////////////////////
			fprintf(save,"%s ",p1->writer);
			len=8;
			while((len-strlen(p1->writer))>0)
			{
				fprintf(save," ");
				len--;
			}
/////////////////////////////////////////////////////////////
			fprintf(save,"%s ",p1->Class);
			len=3;
			while((len-strlen(p1->Class))>0)
			{
				fprintf(save," ");
				len--;
			}
/////////////////////////////////////////////////////////////
			fprintf(save,"%s ",p1->publisher);
			len=20;
			while((len-strlen(p1->publisher))>0)
			{
				fprintf(save," ");
				len--;
			}
/////////////////////////////////////////////////////////////
			fprintf(save,"%s ",p1->time);
			len=10;
			while((len-strlen(p1->time))>0)
			{
				fprintf(save," ");
				len--;
			}
/////////////////////////////////////////////////////////////
			fprintf(save,"%s ",p1->price);
			len=6;
			while((len-strlen(p1->price))>0)
			{
				fprintf(save," ");
				len--;
			}
/////////////////////////////////////////////////////////////
			fprintf(save,"\n");
			p2=p1;
			if(p1!=NULL&&p2!=NULL&&p2->next!=NULL&&p1->next!=NULL)
				p1=p2->next;
			else
				break;
		}
		fclose(save);
	}
	rep(page,RRLINE_B);														//д�ļ���Ϸ����ϼ��˵�
}


jumper()																	//��ת�����¼�⡾2��
{
	checker2();
}


checker2()																	//����¼���Ƿ��Ѵ���
{
	int checker=0;
	if((save=fopen("book.txt","r"))==NULL)
	{
		if((save=fopen("book.txt","w+"))==NULL)
		{
			printf("\n   �ļ�����ʧ��!\n");
			system("pause");
			home('1');
		}
		O=1;
		jumper();															//��ת�����¼�⡾1��
	}
	while(!feof(save)&&(O!=1))												//���û�����ĵ�¼���Ѵ�����checker����
	{
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",stu.num,stu.name,stu.writer,stu.Class,stu.publisher,stu.time,stu.price);
		if(!strcmp(stu.num,tem.num))
		{
			checker++;	
		}
	}
	fclose(save);
	return(checker);														//����checkerֵ
}



represec(int Sec,int page,int RRLINE_B)
{
	switch(Sec)																//��ӡѡ��˵�
	{
	case '1':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("   >>>��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);
				printf("\n\n");mid();printf("      �������µĵ�¼�ţ�");
				while(1)
				{
					scanf("%s",tem.num);
					if(strlen(tem.num)==6)									//������������Ƿ�Ϸ�
					{
						if(checker2()>=1)									//���ü�⺯������¼���Ƿ��Ѵ���
						{	
							printf("\n\n");  
							mid();printf("      �õ�¼���Ѵ���,�����������µĵ�¼��~!\n\n");mid();
							printf("      ");
							system("pause");
							represec('1',page,RRLINE_B);					//���ݲ������´�ӡ�˵�
						}
						else break;
					}
					else
					{
						printf("\n");mid();printf("      ������淶�ĵ�¼��(����Ϊ6λ����)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('1',page,RRLINE_B);						//���ݲ������´�ӡ�˵�
					}
					system("cls");
				}
				strcpy(p1->num,tem.num);									//�����ݺϷ����Ƶ���������Ӧ�ڵ㴦
				break;
	case '2':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("   >>>��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);
				printf("\n\n");mid();printf("      �������µ�������");
				while(1)
				{
					scanf("%s",tem.name);
					if(!(strlen(tem.name)>20||strlen(tem.name)<=0)) break;	//������������Ƿ�Ϸ�
					else
					{
						printf("\n");mid();printf("      ������淶������(10����������)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('2',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->name,tem.name);									//�����ݺϷ����Ƶ���������Ӧ�ڵ㴦
				break;
	case '3':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("   >>>������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);
				printf("\n\n");mid();printf("      �������µ���������");
				while(1)
				{
					scanf("%s",tem.writer);
					if(!(strlen(tem.writer)<=0||strlen(tem.writer)>8)) break;//������������Ƿ�Ϸ�
					else
					{
						printf("\n");mid();printf("      ������淶��������(4����������)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('3',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->writer,tem.writer);								//�����ݺϷ����Ƶ���������Ӧ�ڵ㴦
				break;
	case '4':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("   >>>�����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);
				printf("\n\n");mid();printf("      �������µķ���ţ�");
				while(1)
				{
					scanf("%s",tem.Class);
					if(!(strlen(tem.Class)<=0||strlen(tem.Class)>3)) break;//������������Ƿ�Ϸ�
					else
					{
						printf("\n");mid();printf("      ������淶�ķ����(3λ��������)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('4',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->Class,tem.Class);								//�����ݺϷ����Ƶ���������Ӧ�ڵ㴦
				break;
	case '5':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("   >>>���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);
				printf("\n\n");mid();printf("      �������µĳ��浥λ��");
				while(1)
				{
					scanf("%s",tem.publisher);
					if((strlen(tem.publisher)<=20)&&(strlen(tem.publisher)>0)) break;//������������Ƿ�Ϸ�
					else
					{
						printf("\n");mid();printf("      ������淶�ĳ��浥λ(����Ϊ10����������)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('5',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->publisher,tem.publisher);						//�����ݺϷ����Ƶ���������Ӧ�ڵ㴦
				break;
	case '6':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("   >>>����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);
				printf("\n\n");mid();printf("      �������µĳ��浥λ��");
				while(1)
				{
					scanf("%s",tem.time);
					if(strlen(tem.publisher)==20) break;					//������������Ƿ�Ϸ�
					else
					{
						printf("\n");mid();printf("      ������淶������(����Ϊ2011/01/01��ʽ)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('5',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->time,tem.time);									//�����ݺϷ����Ƶ���������Ӧ�ڵ㴦
				break;
	case '7':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("    >>>�۸�:%s",p1->price);
				printf("\n\n");mid();printf("      �������µĳ��浥λ��");
				while(1)
				{
					scanf("%s",tem.price);
					if((strlen(tem.price)<=6)&&(strlen(tem.price)>0)) break;//������������Ƿ�Ϸ�
					else
					{
						printf("\n");mid();printf("      ������淶�ļ۸�(����Ϊ6λ��������)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('5',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->price,tem.price);								//�����ݺϷ����Ƶ���������Ӧ�ڵ㴦
				break;
	}
	repwrite(page,RRLINE_B);
}






repsec(int Sec,int Page,int RRLINE_B)
{
	char C1;
	int i;
	p1=Start;
	for(i=0;i<(RLINE*(Page-1)+RRLINE_B);i++)								//���������ҵ���Ӧ�ڵ㴦�����ݲ�ʹָ��ָ��ô�
		p1=p1->next;
	system("cls");
	line(1);
	switch(Sec)																//���ݲ�����ӡ�˵�
	{
	case '1':	printf("\n\n");
				mid();printf("   >>>��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);break;
	case '2':	printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("   >>>��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);break;
	case '3':	printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("   >>>������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);break;
	case '4':	printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("   >>>�����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);break;
	case '5':	printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("   >>>���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);break;
	case '6':	printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("   >>>����ʱ��:%s\n\n",p1->time);
				mid();printf("      �۸�:%s",p1->price);break;
	case '7':	printf("\n\n");
				mid();printf("      ��¼��:%s\n\n",p1->num);
				mid();printf("      ��  ��:%s\n\n",p1->name);
				mid();printf("      ������:%s\n\n",p1->writer);
				mid();printf("      �����:%s\n\n",p1->Class);
				mid();printf("      ���浥λ:%s\n\n",p1->publisher);
				mid();printf("      ����ʱ��:%s\n\n",p1->time);
				mid();printf("   >>>�۸�:%s",p1->price);break;
	}
	C1=getch();
	while(C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=27&&C1!=13)
		C1=getch();															//��ȡ�û����������Ϸ������»�ȡ
	switch(C1)																//�����û�����ִ����Ӧ��Ļ����
	{
	case 27:rep(Page,RRLINE_B);
	case 13:represec(Sec,Page,RRLINE_B);
	case 72:
	case 75:if(Sec=='1') Sec='7';
			else Sec--; break;
	case 77:
	case 80:if(Sec=='7') Sec='1';
			else Sec++;break;
	}
	repsec(Sec,Page,RRLINE_B);												//���ݲ������´�ӡ��Ļ
}





rep(int Page,int RRLINE_B)
{
	char c;
	int len,time=0,turn=0,Pages,i,RRLINE=0;
	Start=NULL;
	p1=p2=(struct infor*)malloc(LEN);										//��������
	Start=p1;
	if((save=fopen("book.txt","r"))==NULL)									//�����ļ�ʧ���򱨴�������ҳ
	{
		system("cls");
		line(1);
		printf("\n   ��ʧ��!�ļ�������!\n\n   ");
		system("pause");
		home('1');
	}
	if(feof(save))															//���ļ�Ϊ���򱨴�������ҳ
	{
		system("cls");
		line(1);
		printf("\n   ��ȡʧ��!���ݲ�����!\n\n   ");
		system("pause");
		home('1');
	}
	else
	{																		//�����ݴ��������ݶ�������
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		while(!feof(save))
		{
			p1=(struct infor*)malloc(LEN);
			turn++;															//��¼��������
			p2->next=p1;
			p2=p1;
			fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		}
		p2->next=NULL;														//������ĩβ�ڵ�ָ��NULL
		fclose(save);
	}
	if(turn%RLINE==0)
		Pages=(turn/RLINE);													//��¼��ҳ��
	else
		Pages=(turn/RLINE+1);
	PAGE=Pages;
	if(strlen(Start->num)!=6)												//���׽ڵ����ݵ�¼�Ų��Ϸ��򱨴�������ҳ
	{
		system("cls");
		line(1);
		printf("\n   ��ȡʧ��!���ݲ�����!\n\n   ");
		system("pause");
		home('1');
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		p1=Start;
		printf("   ");
		for(i=0;i<(RLINE*(Page-1));i++)										//ʹָ��ָ��������Ӧ�ڵ㴦
			p1=p1->next;
		RRLINE=0;
		if(Page==(Pages)&&(c==77||c==75))									//��Ϊ���һҳ��ʹ��굽�ﶥ��
			RRLINE_B=0;
		if(RRLINE_B<0) RRLINE_B=0;
		system("cls");
		line(1);
		printf("     ��¼�� ����\t         ����  ����� ���浥λ\t\t   ����ʱ��   �۸�\n   ");
		do
		{																	//��ӡ��ҳ��������	
			if(RRLINE_B==time)
				line(5);
			else
				printf("\n   ");
			if(RRLINE_B==time)
				printf("��");												//��Ϊָ�������ӡ���
			else
				printf("  ");
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
			if(RRLINE_B==time)												//��Ϊָ�������ӡ���
				printf("��");
			else
				printf("  ");
			printf("\n   ");
			if(RRLINE_B==time)
				line(4);
			p1=p1->next;
			time++;
			RRLINE++;
		}
		while(p1->next!=NULL&&time<RLINE);
		TIME=time;
		while(time<RLINE)
		{
			printf("\n\n");
			time++;
		}
		printf("\n\n   [��ʾ:�� <�����> ѡ��ѡ��� <�س���> �޸ģ��� <Delete> ��ɾ������ <Esc> ���˳�]\n");
		//printf("\n   �T�T�T�T�T�T�T�T�T�T�T�T  [��] ��һҳ �� %d ҳ ��һҳ [��] �T�T�T�T�T�T�T�T�T�T�T�T",Page);
		printf("\n   �T�T�T�T�T�T�T�T�T�T�T  [��] ��һҳ �� %d/%d ҳ ��һҳ [��]  �T�T�T�T�T�T�T�T�T�T�T",Page,Pages);
		while(1)
		{
			len=0;
			c=getch();
			while(c!=75&&c!=77&&c!=27&&c!=72&&c!=80&&c!=13&&c!=83)
				c=getch();													//��ȡ�û����������Ϸ������½�������
			switch(c)														//��������ִ����Ӧ����
			{
			case 83: repchoose(2,Page,RRLINE_B);
			case 27: home('1');
			case 77:if(Page!=Pages&&p1->next!=NULL)
					{
						system("cls");
						time=0;
					//	RRLINE_B=0;
						Page++;
						len=1;
					}
					break;
			case 75:if(Page!=1)
					{
						system("cls");
						time=0;
					//	RRLINE_B=0;
						Page--;
						len=1;
					}
					break;
			case 72:time=0;
					if(RRLINE_B!=0)
					{
						RRLINE_B--;
						len=1;
					}
					break;
			case 80:time=0;
					if(RRLINE_B!=(RLINE-1)&&RRLINE_B<(RRLINE-1))
					{
						RRLINE_B++;
						len=1;
					}
					break;
			case 13:repsec('1',Page,RRLINE_B);								//����repsec���Һ�����������ز���
			}
			if(len==1)
				break;
		}
	}
}