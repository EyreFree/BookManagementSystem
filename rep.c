/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
#include"head.h"


repchoose(int Quit,int page,int RRLINE_B)									//修改与删除函数
{
	char C1;
	int i;
	system("cls");
	if(Quit==1)
	{
		for(i=0;i<=7;i++)printf("\n");
		mid();printf("  ╔═══════════╗\n");
		mid();printf("  ║确认删除该项 (Y / N)？║\n");
		mid();printf("  ║┏━━━━┓          ║\n");
		mid();printf("  ║┃确认 (Y)┃取消 (N)  ║\n");
		mid();printf("  ║┗━━━━┛          ║\n");
		mid();printf("  ╚═══════════╝");
	}
	else
	{
		for(i=0;i<=7;i++)printf("\n");
		mid();printf("  ╔═══════════╗\n");
		mid();printf("  ║确认删除该项 (Y / N)？║\n");
		mid();printf("  ║          ┏━━━━┓║\n");
		mid();printf("  ║  确认 (Y)┃取消 (N)┃║\n");
		mid();printf("  ║          ┗━━━━┛║\n");
		mid();printf("  ╚═══════════╝");
	}
	C1=getch();
	while(C1!=89&&C1!=78&&C1!=121&&C1!=110&&C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=13&&C1!=27)
		C1=getch();															//获取用户输入若输入不合法则重新获取
	switch(C1)
	{																		//根据用户输入进行相应操作
	case 27:rep(page,RRLINE_B);
	case 89:
	case 121:Quit=1;break;
	case 78:
	case 110:Quit=2;break;
	case 13:if(Quit==1)
			{
				if(page==1&&TIME==1)										//【特殊情况】当仅有一个数据执行删除操作时警告
				{
					line(1);
					if((save=fopen("book.txt","w+"))==NULL)
					{
						system("cls");
						line(1);
						printf("\n\n\n   文件修改失败!\n\n   磁盘拒绝访问!\n   ");
						system("pause");
						rep(1);
					}
					else
						fclose(save);
					system("cls");
					line(1);
					printf("\n\n\n   源文件内已不存在数据!\n\n   ");
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
	repchoose(Quit,page,RRLINE_B);											//返回上级菜单
}





repdel(int Page,int RRLINE_B)												//删除链表中的待删节点
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
	repwrite(Page,RRLINE_B);												//调用写入文件函数
}





repwrite(int page,int RRLINE_B)												//重写并覆盖旧的数据文件
{
	int len=0;
	p2=p1=Start;
	if((save=fopen("book.txt","w+"))==NULL)
	{
		system("cls");
		printf("\n\n\n   文件修改失败!\n\n   磁盘拒绝访问!\n   ");
		system("pause");
		rep(1);
	}
	else
	{
		while(p1!=NULL&&p2!=NULL&&p2->next!=NULL&&p1->next!=NULL)			//将链表中数据写入文件
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
	rep(page,RRLINE_B);														//写文件完毕返回上级菜单
}


jumper()																	//跳转并重新检测【2】
{
	checker2();
}


checker2()																	//检测登录号是否已存在
{
	int checker=0;
	if((save=fopen("book.txt","r"))==NULL)
	{
		if((save=fopen("book.txt","w+"))==NULL)
		{
			printf("\n   文件创建失败!\n");
			system("pause");
			home('1');
		}
		O=1;
		jumper();															//跳转并重新检测【1】
	}
	while(!feof(save)&&(O!=1))												//若用户输入的登录号已存在则checker自增
	{
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",stu.num,stu.name,stu.writer,stu.Class,stu.publisher,stu.time,stu.price);
		if(!strcmp(stu.num,tem.num))
		{
			checker++;	
		}
	}
	fclose(save);
	return(checker);														//返回checker值
}



represec(int Sec,int page,int RRLINE_B)
{
	switch(Sec)																//打印选择菜单
	{
	case '1':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("   >>>登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);
				printf("\n\n");mid();printf("      请输入新的登录号：");
				while(1)
				{
					scanf("%s",tem.num);
					if(strlen(tem.num)==6)									//检测输入数据是否合法
					{
						if(checker2()>=1)									//调用检测函数检测登录号是否已存在
						{	
							printf("\n\n");  
							mid();printf("      该登录号已存在,请重新输入新的登录号~!\n\n");mid();
							printf("      ");
							system("pause");
							represec('1',page,RRLINE_B);					//根据参数重新打印菜单
						}
						else break;
					}
					else
					{
						printf("\n");mid();printf("      请输入规范的登录号(必须为6位数字)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('1',page,RRLINE_B);						//根据参数重新打印菜单
					}
					system("cls");
				}
				strcpy(p1->num,tem.num);									//若数据合法则复制到链表中相应节点处
				break;
	case '2':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("   >>>书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);
				printf("\n\n");mid();printf("      请输入新的书名：");
				while(1)
				{
					scanf("%s",tem.name);
					if(!(strlen(tem.name)>20||strlen(tem.name)<=0)) break;	//检测输入数据是否合法
					else
					{
						printf("\n");mid();printf("      请输入规范的书名(10个汉字以内)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('2',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->name,tem.name);									//若数据合法则复制到链表中相应节点处
				break;
	case '3':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("   >>>作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);
				printf("\n\n");mid();printf("      请输入新的作者名：");
				while(1)
				{
					scanf("%s",tem.writer);
					if(!(strlen(tem.writer)<=0||strlen(tem.writer)>8)) break;//检测输入数据是否合法
					else
					{
						printf("\n");mid();printf("      请输入规范的作者名(4个汉字以内)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('3',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->writer,tem.writer);								//若数据合法则复制到链表中相应节点处
				break;
	case '4':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("   >>>分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);
				printf("\n\n");mid();printf("      请输入新的分类号：");
				while(1)
				{
					scanf("%s",tem.Class);
					if(!(strlen(tem.Class)<=0||strlen(tem.Class)>3)) break;//检测输入数据是否合法
					else
					{
						printf("\n");mid();printf("      请输入规范的分类号(3位数字以内)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('4',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->Class,tem.Class);								//若数据合法则复制到链表中相应节点处
				break;
	case '5':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("   >>>出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);
				printf("\n\n");mid();printf("      请输入新的出版单位：");
				while(1)
				{
					scanf("%s",tem.publisher);
					if((strlen(tem.publisher)<=20)&&(strlen(tem.publisher)>0)) break;//检测输入数据是否合法
					else
					{
						printf("\n");mid();printf("      请输入规范的出版单位(必须为10个汉字以内)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('5',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->publisher,tem.publisher);						//若数据合法则复制到链表中相应节点处
				break;
	case '6':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("   >>>出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);
				printf("\n\n");mid();printf("      请输入新的出版单位：");
				while(1)
				{
					scanf("%s",tem.time);
					if(strlen(tem.publisher)==20) break;					//检测输入数据是否合法
					else
					{
						printf("\n");mid();printf("      请输入规范的日期(必须为2011/01/01格式)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('5',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->time,tem.time);									//若数据合法则复制到链表中相应节点处
				break;
	case '7':	system("cls");
				line(1);
				printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("    >>>价格:%s",p1->price);
				printf("\n\n");mid();printf("      请输入新的出版单位：");
				while(1)
				{
					scanf("%s",tem.price);
					if((strlen(tem.price)<=6)&&(strlen(tem.price)>0)) break;//检测输入数据是否合法
					else
					{
						printf("\n");mid();printf("      请输入规范的价格(必须为6位数字以内)~!\n\n");mid();
						printf("      ");
						system("pause");
						represec('5',page,RRLINE_B);
					}
					system("cls");
				}
				strcpy(p1->price,tem.price);								//若数据合法则复制到链表中相应节点处
				break;
	}
	repwrite(page,RRLINE_B);
}






repsec(int Sec,int Page,int RRLINE_B)
{
	char C1;
	int i;
	p1=Start;
	for(i=0;i<(RLINE*(Page-1)+RRLINE_B);i++)								//在链表中找到相应节点处的数据并使指针指向该处
		p1=p1->next;
	system("cls");
	line(1);
	switch(Sec)																//根据参数打印菜单
	{
	case '1':	printf("\n\n");
				mid();printf("   >>>登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);break;
	case '2':	printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("   >>>书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);break;
	case '3':	printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("   >>>作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);break;
	case '4':	printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("   >>>分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);break;
	case '5':	printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("   >>>出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);break;
	case '6':	printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("   >>>出版时间:%s\n\n",p1->time);
				mid();printf("      价格:%s",p1->price);break;
	case '7':	printf("\n\n");
				mid();printf("      登录号:%s\n\n",p1->num);
				mid();printf("      书  名:%s\n\n",p1->name);
				mid();printf("      作者名:%s\n\n",p1->writer);
				mid();printf("      分类号:%s\n\n",p1->Class);
				mid();printf("      出版单位:%s\n\n",p1->publisher);
				mid();printf("      出版时间:%s\n\n",p1->time);
				mid();printf("   >>>价格:%s",p1->price);break;
	}
	C1=getch();
	while(C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=27&&C1!=13)
		C1=getch();															//获取用户输入若不合法则重新获取
	switch(C1)																//根据用户输入执行相应屏幕操作
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
	repsec(Sec,Page,RRLINE_B);												//根据参数重新打印屏幕
}





rep(int Page,int RRLINE_B)
{
	char c;
	int len,time=0,turn=0,Pages,i,RRLINE=0;
	Start=NULL;
	p1=p2=(struct infor*)malloc(LEN);										//创建链表
	Start=p1;
	if((save=fopen("book.txt","r"))==NULL)									//若打开文件失败则报错并返回主页
	{
		system("cls");
		line(1);
		printf("\n   打开失败!文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	if(feof(save))															//若文件为空则报错并返回主页
	{
		system("cls");
		line(1);
		printf("\n   读取失败!数据不存在!\n\n   ");
		system("pause");
		home('1');
	}
	else
	{																		//若数据存在则将数据读入链表
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		while(!feof(save))
		{
			p1=(struct infor*)malloc(LEN);
			turn++;															//记录数据条数
			p2->next=p1;
			p2=p1;
			fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		}
		p2->next=NULL;														//令链表末尾节点指向NULL
		fclose(save);
	}
	if(turn%RLINE==0)
		Pages=(turn/RLINE);													//记录总页数
	else
		Pages=(turn/RLINE+1);
	PAGE=Pages;
	if(strlen(Start->num)!=6)												//若首节点数据登录号不合法则报错并返回主页
	{
		system("cls");
		line(1);
		printf("\n   读取失败!数据不存在!\n\n   ");
		system("pause");
		home('1');
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while(1)
	{
		p1=Start;
		printf("   ");
		for(i=0;i<(RLINE*(Page-1));i++)										//使指针指向链表相应节点处
			p1=p1->next;
		RRLINE=0;
		if(Page==(Pages)&&(c==77||c==75))									//若为最后一页则使光标到达顶部
			RRLINE_B=0;
		if(RRLINE_B<0) RRLINE_B=0;
		system("cls");
		line(1);
		printf("     登录号 书名\t         作者  分类号 出版单位\t\t   出版时间   价格\n   ");
		do
		{																	//打印该页所有数据	
			if(RRLINE_B==time)
				line(5);
			else
				printf("\n   ");
			if(RRLINE_B==time)
				printf("┃");												//若为指定行则打印光标
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
			if(RRLINE_B==time)												//若为指定行则打印光标
				printf("┃");
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
		printf("\n\n   [提示:按 <方向键> 选中选项后按 <回车键> 修改；按 <Delete> 键删除；按 <Esc> 键退出]\n");
		//printf("\n   ════════════  [←] 上一页 第 %d 页 下一页 [→] ════════════",Page);
		printf("\n   ═══════════  [←] 上一页 第 %d/%d 页 下一页 [→]  ═══════════",Page,Pages);
		while(1)
		{
			len=0;
			c=getch();
			while(c!=75&&c!=77&&c!=27&&c!=72&&c!=80&&c!=13&&c!=83)
				c=getch();													//获取用户输入若不合法则重新接收输入
			switch(c)														//根据输入执行相应操作
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
			case 13:repsec('1',Page,RRLINE_B);								//调用repsec查找函数并传递相关参数
			}
			if(len==1)
				break;
		}
	}
}