/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
#include"head.h"



openfire(int turn)																				//查找函数
{																								//找出有几个符合查找要求的数据记录
	if(strlen(stu.time)!=10)
		return(turn);
	else
	{
		turn++;
		*p1=stu;																				//将符合要求数据记录写入链表
		p1=(struct infor*)malloc(LEN);															//遍历链表
		p2->next=p1;
		p3=p2;
		p2=p1;
		return(turn);																			//返回记录条数turn
	}
}




showresult(int turn)																			//按目标记录的条数输出结果
{
	char c,Found;
	int len,time=0,Pages,Page=1,i;
	Pages=(turn/LINE+1);
	if(turn==1)																					//当无对应记录时，报错
	{
		line(1);
		printf("\n\n");
		mid();printf("      登录号:\n\n");
		mid();printf("      书  名:\n\n");
		mid();printf("      作者名:\n\n");
		mid();printf("      分类号:\n\n");
		mid();printf("      出版单位:");
		printf("\n\n\n");mid();
		printf("      查找失败!  是否继续?\n\n");mid();
		printf("      (Yes[回车] / No[Esc])");
		Found=getch();
		while(Found!='y'&&Found!='n'&&Found!='Y'&&Found!='N'&&Found!=13&&Found!=27)
			Found=getch();
		if(Found=='y'||Found=='Y'||Found==13)
			sec('1');
		else
			home('1');
	}
	if(turn==2)																					//当仅有一个符合要求的记录时，仅输出一个
	{
		line(1);
		printf("\n\n");
		mid();printf("      登录号:%s\n\n",Start->num);
		mid();printf("      书  名:%s\n\n",Start->name);
		mid();printf("      作者名:%s\n\n",Start->writer);
		mid();printf("      分类号:%s\n\n",Start->Class);
		mid();printf("      出版单位:%s\n\n",Start->publisher);
		mid();printf("      出版时间:%s\n\n",Start->time);
		mid();printf("      价格:%s",Start->price);
		fclose(save);
		printf("\n\n\n");mid();
		printf("      操作成功!  是否继续?\n\n");mid();
		printf("      (Yes[回车] / No[Esc])");
		Found=getch();
		while(Found!='y'&&Found!='n'&&Found!='Y'&&Found!='N'&&Found!=13&&Found!=27)
			Found=getch();
		if(Found=='y'||Found=='Y'||Found==13)
			sec('1');
		else
			home('1');
		}
	else																						//当有多个符合要求的记录时，按页打印
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
			do																					//循环输出按页输出数据
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
			printf("\n\n   ═══════════  [←] 上一页 第 %d/%d 页 下一页 [→]  ═══════════",Page,Pages);
			while(1)
			{
				c=getch();
				while(c!=75&&c!=77&&c!=27)
					c=getch();																	//接受用户输入若非法则重新接受
				if(c==27) home('1');
				if(c==77&&Page!=Pages&&p1->next!=NULL)											//根据用户操作进行相应屏幕操作
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




found(int Sec)																					//进行相应文件操作
{
	char Found;
	int Pages,turn=1;
	Start=NULL;
	p1=p2=p3=(struct infor*)malloc(LEN);
	Start=p1;
	system("cls");
	switch(Sec)
	{
	case '1':	if((save=fopen("book.txt","r"))==NULL)											//按录入号查找
				{
					system("cls");
					line(1);
					printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   文件读取失败!\n\n   ");
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
	case '2':	if((save=fopen("book.txt","r"))==NULL)											//按书名查找
				{
					system("cls");
					line(1);
					printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   文件读取失败!\n\n   ");
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
	case '3':	if((save=fopen("book.txt","r"))==NULL)											//按作者查找
				{
					system("cls");
					line(1);
					printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   文件读取失败!\n\n   ");
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
	case '4':	if((save=fopen("book.txt","r"))==NULL)											//按分类号查找
				{
					system("cls");
					line(1);
					printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   文件读取失败!\n\n   ");
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
	case '5':	if((save=fopen("book.txt","r"))==NULL)											//按出版单位查找
				{
					system("cls");
					line(1);
					printf("\n\n   打开失败!\n\n   文件不存在!\n\n   ");
					system("pause");
					home('1');
				}
				if(feof(save))	
				{
					system("cls");
					line(1);
					printf("\n\n   文件读取失败!\n\n   ");
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



resec(int Sec)																					//接受用户输入的相应查找条件
{
	switch(Sec)
	{
	case '1':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("   >>>登录号:\n\n");
				mid();printf("      书  名:\n\n");
				mid();printf("      作者名:\n\n");
				mid();printf("      分类号:\n\n");
				mid();printf("      出版单位:");
				printf("\n\n");mid();printf("      请输入要查找的登录号：");
				while(1)
				{
					scanf("%s",tem.num);
					if(strlen(tem.num)==6) break;												//若输入数据合法则跳出循环
					else																		//若输入数据非法则重新输入
					{
						printf("\n\n");mid();printf("      请输入规范的登录号(必须为6位数字)~!\n\n");mid();
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
				mid();printf("      登录号:\n\n");
				mid();printf("   >>>书  名:\n\n");
				mid();printf("      作者名:\n\n");
				mid();printf("      分类号:\n\n");
				mid();printf("      出版单位:");
				printf("\n\n");mid();printf("      请输入要查找的书名：");
				while(1)
				{
					scanf("%s",tem.name);
					if(!(strlen(tem.name)>20||strlen(tem.name)<=0)) break;						//若输入数据合法则跳出循环
					else																		//若输入数据非法则重新输入
					{
						printf("\n\n");mid();printf("      请输入规范的书名(10个汉字以内)~!\n\n");mid();
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
				mid();printf("      登录号:\n\n");
				mid();printf("      书  名:\n\n");
				mid();printf("   >>>作者名:\n\n");
				mid();printf("      分类号:\n\n");
				mid();printf("      出版单位:");
				printf("\n\n");mid();printf("      请输入要查找的作者名：");
				while(1)
				{
					scanf("%s",tem.writer);
					if(!(strlen(tem.writer)<=0||strlen(tem.writer)>8)) break;					//若输入数据合法则跳出循环
					else																		//若输入数据非法则重新输入
					{
						printf("\n\n");mid();printf("      请输入规范的作者名(4个汉字以内)~!\n\n");mid();
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
				mid();printf("      登录号:\n\n");
				mid();printf("      书  名:\n\n");
				mid();printf("      作者名:\n\n");
				mid();printf("   >>>分类号:\n\n");
				mid();printf("      出版单位:");
				printf("\n\n");mid();printf("      请输入要查找的分类号：");
				while(1)
				{
					scanf("%s",tem.Class);
					if(!(strlen(tem.Class)<=0||strlen(tem.Class)>3)) break;						//若输入数据合法则跳出循环
					else																		//若输入数据非法则重新输入
					{
						printf("\n\n");mid();printf("      请输入规范的分类号(3位数字以内)~!\n\n");mid();
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
				mid();printf("      登录号:\n\n");
				mid();printf("      书  名:\n\n");
				mid();printf("      作者名:\n\n");
				mid();printf("      分类号:\n\n");
				mid();printf("   >>>出版单位:");
				printf("\n\n");mid();printf("      请输入要查找的出版单位：");
				while(1)
				{
					scanf("%s",tem.publisher);
					if((strlen(tem.publisher)<=20)&&(strlen(tem.publisher)>0)) break;			//若输入数据合法则跳出循环
					else																		//若输入数据非法则重新输入
					{
						printf("\n\n");mid();printf("      请输入规范的出版单位(必须为10个汉字以内)~!\n\n");mid();
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



sec(int Sec)																					//让用户选择查找条件
{
	char C1;
	int i;
	system("cls");
	line(1);
	switch(Sec)
	{
	case '1':	printf("\n\n");
				mid();printf("   >>>登录号:\n\n");
				mid();printf("      书  名:\n\n");
				mid();printf("      作者名:\n\n");
				mid();printf("      分类号:\n\n");
				mid();printf("      出版单位:");break;
	case '2':	printf("\n\n");
				mid();printf("      登录号:\n\n");
				mid();printf("   >>>书  名:\n\n");
				mid();printf("      作者名:\n\n");
				mid();printf("      分类号:\n\n");
				mid();printf("      出版单位:");break;
	case '3':	printf("\n\n");
				mid();printf("      登录号:\n\n");
				mid();printf("      书  名:\n\n");
				mid();printf("   >>>作者名:\n\n");
				mid();printf("      分类号:\n\n");
				mid();printf("      出版单位:");break;
	case '4':	printf("\n\n");
				mid();printf("      登录号:\n\n");
				mid();printf("      书  名:\n\n");
				mid();printf("      作者名:\n\n");
				mid();printf("   >>>分类号:\n\n");
				mid();printf("      出版单位:");break;
	case '5':	printf("\n\n");
				mid();printf("      登录号:\n\n");
				mid();printf("      书  名:\n\n");
				mid();printf("      作者名:\n\n");
				mid();printf("      分类号:\n\n");
				mid();printf("   >>>出版单位:");break;
	}
	printf("\n");
	line(6);
	C1=getch();
	while(C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=27&&C1!=13)
		C1=getch();																				//接受用户输入若输入非法则重新接受
	switch(C1)																					//根据用户输入执行相应屏幕操作
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
	sec(Sec);																					//传递参数
}
