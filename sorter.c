/********************************************************************************
**         ����:EyreFree	��19��	QQ:1795179491                          **
********************************************************************************/
#include"head.h"

																								//������
sortscreen(int way,int Way1,int Way2)															//��������ѡ��˵�
{
	char C1,W1[]="����",W2[]="����",W[5],F1[]="��¼��  ",F2[]="����    ",F3[]="������  ",F4[]="�����  ",F5[]="���浥λ",F[9];
	int i;
	switch(Way1)
	{
	case 1:	strcpy(F,F1);break;																	//Ϊ������Ŀ��Ӧѡ�ֵ
	case 2:	strcpy(F,F2);break;
	case 3:	strcpy(F,F3);break;
	case 4:	strcpy(F,F4);break;
	case 5:	strcpy(F,F5);break;
	}
	if(Way2==1)																					//Ϊ����ʽ��Ӧѡ�ֵ
		strcpy(W,W1);
	else
		strcpy(W,W2);
	system("cls");
	printf("\n   �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T ͼ����Ϣ����ϵͳ �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T");
	switch(way)
	{
	case 1:
		for(i=0;i<=3;i++)printf("\n");
		mid();printf("    �X�T�T�T�T�T�T�T�T�T�T�T�[\n");
		mid();printf("    �U  ѡ �� �� �� �� ��   �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U������������          �U\n");
		mid();printf("    �U��������Ŀ��: %s�U\n",F);
		mid();printf("    �U������������          �U\n");
		mid();printf("    �U  ����ʽ  : %s    �U\n",W);
		mid();printf("    �U                      �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U  ȷ  ��      ȡ  ��  �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �^�T�T�T�T�T�T�T�T�T�T�T�a");break;
	case 2:
		for(i=0;i<=3;i++)printf("\n");
		mid();printf("    �X�T�T�T�T�T�T�T�T�T�T�T�[\n");
		mid();printf("    �U  ѡ �� �� �� �� ��   �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U  ������Ŀ  : %s�U\n",F);
		mid();printf("    �U������������          �U\n");
		mid();printf("    �U������ʽ��: %s    �U\n",W);
		mid();printf("    �U������������          �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U  ȷ  ��      ȡ  ��  �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �^�T�T�T�T�T�T�T�T�T�T�T�a");break;
	case 3:
		for(i=0;i<=3;i++)printf("\n");
		mid();printf("    �X�T�T�T�T�T�T�T�T�T�T�T�[\n");
		mid();printf("    �U  ѡ �� �� �� �� ��   �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U  ������Ŀ  : %s�U\n",F);
		mid();printf("    �U                      �U\n");
		mid();printf("    �U  ����ʽ  : %s    �U\n",W);
		mid();printf("    �U                      �U\n");
		mid();printf("    �U����������            �U\n");
		mid();printf("    �U��ȷ  �ϩ�    ȡ  ��  �U\n");
		mid();printf("    �U����������            �U\n");
		mid();printf("    �^�T�T�T�T�T�T�T�T�T�T�T�a");break;
	case 4:
		for(i=0;i<=3;i++)printf("\n");
		mid();printf("    �X�T�T�T�T�T�T�T�T�T�T�T�[\n");
		mid();printf("    �U  ѡ �� �� �� �� ��   �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U                      �U\n");
		mid();printf("    �U  ������Ŀ  : %s�U\n",F);
		mid();printf("    �U                      �U\n");
		mid();printf("    �U  ����ʽ  : %s    �U\n",W);
		mid();printf("    �U                      �U\n");
		mid();printf("    �U            �����������U\n");
		mid();printf("    �U  ȷ  ��    ��ȡ  �����U\n");
		mid();printf("    �U            �����������U\n");
		mid();printf("    �^�T�T�T�T�T�T�T�T�T�T�T�a");break;
	}
	printf("\n\n\n\n   [  ��ʾ : �� �� Ҫ �� �� �� �� Ӧ �� Ŀ �� Ϣ �� ��  <�س���Enter>  �� ��  ~o_0~ ]\n\n");
	printf("   �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T  �� 19��  EyreFree  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T");
	C1=getch();
	while(C1!=89&&C1!=78&&C1!=121&&C1!=110&&C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=13&&C1!=27)
		C1=getch();																				//�����û�����
	switch(C1)
	{																							//�����û��������Ӧ���ܼ�������Ӧ����
	case 27:home('1');
	case 89:
	case 121:way=3;break;
	case 78:
	case 110:way=4;break;
	case 13:switch(way)
			{
			case 1:	if(Way1==5)
					   Way1=1;
					else
					   Way1++;break;
			case 2:	if(Way2==1) Way2=2;
					else Way2=1;break;
			case 3:sort(Way2,Way1);
			case 4:home('1');break;
			}break;
	case 72:if(way==1) way=4;
			else way--;break;
	case 75:if(way==1||way==2) 
			{
				if(way==1)
				{
					if(Way1==1) Way1=5;
					else Way1--;
				}
				else
				{
					if(Way2==1) Way2=2;
					else Way2=1;
				}
			}
			else
			{
				if(way==1) way=4;
				else way--;
			}
			break;
	case 80:if(way==4) way=1;
			else way++;break;
	case 77:if(way==1||way==2)
			{
				if(way==1)
				{
					if(Way1==5) Way1=1;
					else Way1++;
				}
				else
				{
					if(Way2==2) Way2=1;
					else Way2=2;
				}

			}
			else
			{
				if(way==4) way=1;
				else way++;
			}
			break;
	}
	sortscreen(way,Way1,Way2);																	//������Ӧ�������´�ӡ����ѡ��˵�
}



sort(int action,int obj)																		//����Ԥ������
{
	char c;
	int len,time=0,turn=1,Pages,Page=1,i;
	Start=NULL;
	p1=p2=(struct infor*)malloc(LEN);
	Start=p1;
	if((save=fopen("book.txt","r"))==NULL)														//���ļ���ʧ���򱨴�
	{
		system("cls");
		line(1);
		printf("\n\n   ��ʧ��!�ļ�������!\n\n   ");
		system("pause");
		home('1');
	}
	if(feof(save))																				//�����ݶ�ȡʧ���򱨴�
	{
		system("cls");
		line(1);
		printf("\n\n   ��ȡʧ��!���ݲ�����!\n\n   ");
		system("pause");
		home('1');
	}
	else																						//�����ݶ�ȡ�ɹ������ݶ�������Ϊ������׼��
	{
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		while(!feof(save))
		{
			p1=(struct infor*)malloc(LEN);
			turn++;																				//��¼��������
			p2->next=p1;
			p2=p1;
			fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		}
		p2->next=NULL;																			//��β�ڵ�ָ��NULL
	}
	Pages=(turn/LINE+1);																		//����turn��������ҳ��Ϊ��ҳ��ʾ��׼��
	if(strlen(Start->num)!=6)
	{																							//������ͷ�������¼��ŷǷ��򱨴�������ҳ
		system("cls");
		line(1);
		printf("\n\n   ��ȡʧ��!���ݲ�����!\n\n   ");
		system("pause");
		home('1');
	}
	sorter(action,turn,obj);																	//�����������������������������
	sortwrite();																				//�����ļ�д�뺯������������������д���ļ�
	if(strlen(Start->num)!=6)
	{																							//������ͷ�������¼��ŷǷ��򱨴�������ҳ
		system("cls");
		line(1);
		printf("\n\n   ����ʧ��!������ʧ!\n\n   ");
		system("pause");
		home('1');
	}
	while(1)
	{
		p1=Start;
		printf("   ");
		for(i=0;i<(LINE*(Page-1));i++)															//���ݵ�ǰҳ��ʹָ���ƶ���������Ӧλ��
		{	
			p1=p1->next;
		}
		system("cls");
		line(1);
		line(2);																				//��ӡ��ǰҳ��������
		printf("\n   ");
		do
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
			time++;																				//�����ݲ���һҳ���û��в���
		}
		printf("\n\n   �T�T�T�T�T�T�T�T�T�T�T  [��] ��һҳ �� %d/%d ҳ ��һҳ [��]  �T�T�T�T�T�T�T�T�T�T�T",Page,Pages);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while(1)
		{
			c=getch();
			while(c!=75&&c!=77&&c!=27)
				c=getch();																		//�ȴ��û����벢��Ӧ����
			if(c==27) home('1');
			if(c==77&&Page!=Pages&&p1->next!=NULL)
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


sorter(int action,int turn,int obj)																//����ð��������ĺ���
{
	int i,j,Act1,Act2;
	Stafter=Start->next;
	for(i=0;i<turn;i++)
	{
		Stafter=Start->next;
		switch(obj)																				//���ݲ���ѡ����Ӧ�������
		{
		case 1:	if(action==1)
					Act1=(strcmp(Start->num,Stafter->num)>0);
				else
					Act1=(strcmp(Stafter->num,Start->num)>0);break;
		case 2:	if(action==1)
					Act1=(strcmp(Start->name,Stafter->name)>0);
				else
					Act1=(strcmp(Stafter->name,Start->name)>0);break;
		case 3:	if(action==1)
					Act1=(strcmp(Start->writer,Stafter->writer)>0);
				else
					Act1=(strcmp(Stafter->writer,Start->writer)>0);break;
		case 4:	if(action==1)
					Act1=(strcmp(Start->Class,Stafter->Class)>0);
				else
					Act1=(strcmp(Stafter->Class,Start->Class)>0);break;
		case 5:	if(action==1)
					Act1=(strcmp(Start->publisher,Stafter->publisher)>0);
				else
					Act1=(strcmp(Stafter->publisher,Start->publisher)>0);break;
		}
		if(Act1)																				//�����⡿������ͷ�����⴦��
		{
			Start->next=Stafter->next;
			Stafter->next=Start;
			Start=Stafter;
			Stafter=Stafter->next;
		}
		p3=Start;
		p2=p3->next;
		p1=p2->next;
		Stafter=Start->next;
		for(j=0;j<turn-2;j++)
		{
			switch(obj)																			//���ݲ���ѡ����Ӧ�������
			{
			case 1:	if(action==1)
						Act2=(strcmp(p2->num,p1->num)>0);
					else
						Act2=(strcmp(p1->num,p2->num)>0);break;
			case 2:	if(action==1)
						Act2=(strcmp(p2->name,p1->name)>0);
					else
						Act2=(strcmp(p1->name,p2->name)>0);break;
			case 3:	if(action==1)
						Act2=(strcmp(p2->writer,p1->writer)>0);
					else
						Act2=(strcmp(p1->writer,p2->writer)>0);break;
			case 4:	if(action==1)
						Act2=(strcmp(p2->Class,p1->Class)>0);
					else
						Act2=(strcmp(p1->Class,p2->Class)>0);break;
			case 5:	if(action==1)
						Act2=(strcmp(p2->publisher,p1->publisher)>0);
					else
						Act2=(strcmp(p1->publisher,p2->publisher)>0);break;
			}
			if(Act2)																			//ð������
			{
				p3->next=p1;
				p2->next=p1->next;
				p1->next=p2;
				p2=p1;
				p1=p2->next;
			}
			p3=p2;
			p2=p1;
			p1=p1->next;
			if(p1->next==NULL)
				break;
		}
	}
}


sortwrite()																						//�ļ�д�뺯��
{
	int len=0;
	p2=p1=Start;
	if((save=fopen("book.txt","w+"))==NULL)														//�ļ���ʧ���򱨴�������ҳ
	{
		system("cls");
		line(1);
		printf("\n\n\n   �ļ��޸�ʧ��!\n\n   ���ܾ̾�����!\n   ");
		system("pause");
		rep(1);
	}
	else
	{
		while(p1!=NULL&&p2!=NULL&&p2->next!=NULL&&p1->next!=NULL)								//����������������д���ļ�
		{
			fprintf(save,"%s ",p1->num);
			fprintf(save,"%s ",p1->name);
			len=20;
			while((len-strlen(p1->name))>0)
			{
				fprintf(save," ");
				len--;
			}
			fprintf(save,"%s ",p1->writer);
			len=8;
			while((len-strlen(p1->writer))>0)
			{
				fprintf(save," ");
				len--;
			}
			fprintf(save,"%s ",p1->Class);
			len=3;
			while((len-strlen(p1->Class))>0)
			{
				fprintf(save," ");
				len--;
			}
			fprintf(save,"%s ",p1->publisher);
			len=20;
			while((len-strlen(p1->publisher))>0)
			{
				fprintf(save," ");
				len--;
			}
			fprintf(save,"%s ",p1->time);
			len=10;
			while((len-strlen(p1->time))>0)
			{
				fprintf(save," ");
				len--;
			}
			fprintf(save,"%s ",p1->price);
			len=6;
			while((len-strlen(p1->price))>0)
			{
				fprintf(save," ");
				len--;
			}
			fprintf(save,"\n");
			p2=p1;
			if(p1!=NULL&&p2!=NULL&&p2->next!=NULL&&p1->next!=NULL)
				p1=p2->next;
			else
				break;
		}
		fclose(save);																			//����д����ɹر��ļ�
	}
}