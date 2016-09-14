/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
#include"head.h"

																								//排序函数
sortscreen(int way,int Way1,int Way2)															//定义排序选择菜单
{
	char C1,W1[]="升序",W2[]="降序",W[5],F1[]="登录号  ",F2[]="书名    ",F3[]="作者名  ",F4[]="分类号  ",F5[]="出版单位",F[9];
	int i;
	switch(Way1)
	{
	case 1:	strcpy(F,F1);break;																	//为排序项目相应选项赋值
	case 2:	strcpy(F,F2);break;
	case 3:	strcpy(F,F3);break;
	case 4:	strcpy(F,F4);break;
	case 5:	strcpy(F,F5);break;
	}
	if(Way2==1)																					//为排序方式相应选项赋值
		strcpy(W,W1);
	else
		strcpy(W,W2);
	system("cls");
	printf("\n   ════════════════ 图书信息管理系统 ════════════════");
	switch(way)
	{
	case 1:
		for(i=0;i<=3;i++)printf("\n");
		mid();printf("    ╔═══════════╗\n");
		mid();printf("    ║  选 择 排 序 规 则   ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║┏━━━━┓          ║\n");
		mid();printf("    ║┃排序项目┃: %s║\n",F);
		mid();printf("    ║┗━━━━┛          ║\n");
		mid();printf("    ║  排序方式  : %s    ║\n",W);
		mid();printf("    ║                      ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║  确  认      取  消  ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ╚═══════════╝");break;
	case 2:
		for(i=0;i<=3;i++)printf("\n");
		mid();printf("    ╔═══════════╗\n");
		mid();printf("    ║  选 择 排 序 规 则   ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║  排序项目  : %s║\n",F);
		mid();printf("    ║┏━━━━┓          ║\n");
		mid();printf("    ║┃排序方式┃: %s    ║\n",W);
		mid();printf("    ║┗━━━━┛          ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║  确  认      取  消  ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ╚═══════════╝");break;
	case 3:
		for(i=0;i<=3;i++)printf("\n");
		mid();printf("    ╔═══════════╗\n");
		mid();printf("    ║  选 择 排 序 规 则   ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║  排序项目  : %s║\n",F);
		mid();printf("    ║                      ║\n");
		mid();printf("    ║  排序方式  : %s    ║\n",W);
		mid();printf("    ║                      ║\n");
		mid();printf("    ║┏━━━┓            ║\n");
		mid();printf("    ║┃确  认┃    取  消  ║\n");
		mid();printf("    ║┗━━━┛            ║\n");
		mid();printf("    ╚═══════════╝");break;
	case 4:
		for(i=0;i<=3;i++)printf("\n");
		mid();printf("    ╔═══════════╗\n");
		mid();printf("    ║  选 择 排 序 规 则   ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║                      ║\n");
		mid();printf("    ║  排序项目  : %s║\n",F);
		mid();printf("    ║                      ║\n");
		mid();printf("    ║  排序方式  : %s    ║\n",W);
		mid();printf("    ║                      ║\n");
		mid();printf("    ║            ┏━━━┓║\n");
		mid();printf("    ║  确  认    ┃取  消┃║\n");
		mid();printf("    ║            ┗━━━┛║\n");
		mid();printf("    ╚═══════════╝");break;
	}
	printf("\n\n\n\n   [  提示 : 请 按 要 求 输 入 相 应 项 目 信 息 并 按  <回车键Enter>  结 束  ~o_0~ ]\n\n");
	printf("   ═══════════════  软工 19班  EyreFree  ═══════════════");
	C1=getch();
	while(C1!=89&&C1!=78&&C1!=121&&C1!=110&&C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=13&&C1!=27)
		C1=getch();																				//接受用户输入
	switch(C1)
	{																							//根据用户输入的相应功能键进行相应操作
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
	sortscreen(way,Way1,Way2);																	//根据相应参数重新打印排序选择菜单
}



sort(int action,int obj)																		//排序预处理函数
{
	char c;
	int len,time=0,turn=1,Pages,Page=1,i;
	Start=NULL;
	p1=p2=(struct infor*)malloc(LEN);
	Start=p1;
	if((save=fopen("book.txt","r"))==NULL)														//若文件打开失败则报错
	{
		system("cls");
		line(1);
		printf("\n\n   打开失败!文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	if(feof(save))																				//若数据读取失败则报错
	{
		system("cls");
		line(1);
		printf("\n\n   读取失败!数据不存在!\n\n   ");
		system("pause");
		home('1');
	}
	else																						//若数据读取成功则将数据读入链表为排序做准备
	{
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		while(!feof(save))
		{
			p1=(struct infor*)malloc(LEN);
			turn++;																				//记录数据条数
			p2->next=p1;
			p2=p1;
			fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",p1->num,p1->name,p1->writer,p1->Class,p1->publisher,p1->time,p1->price);
		}
		p2->next=NULL;																			//令尾节点指向NULL
	}
	Pages=(turn/LINE+1);																		//根据turn计算数据页数为分页显示做准备
	if(strlen(Start->num)!=6)
	{																							//若链表头结点数据录入号非法则报错并返回主页
		system("cls");
		line(1);
		printf("\n\n   读取失败!数据不存在!\n\n   ");
		system("pause");
		home('1');
	}
	sorter(action,turn,obj);																	//调用链表排序函数对链表进行排序处理
	sortwrite();																				//调用文件写入函数将链表内所有数据写入文件
	if(strlen(Start->num)!=6)
	{																							//若链表头结点数据录入号非法则报错并返回主页
		system("cls");
		line(1);
		printf("\n\n   排序失败!数据消失!\n\n   ");
		system("pause");
		home('1');
	}
	while(1)
	{
		p1=Start;
		printf("   ");
		for(i=0;i<(LINE*(Page-1));i++)															//根据当前页数使指针移动到链表相应位置
		{	
			p1=p1->next;
		}
		system("cls");
		line(1);
		line(2);																				//打印当前页所有数据
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
			time++;																				//若数据不足一页则用换行补齐
		}
		printf("\n\n   ═══════════  [←] 上一页 第 %d/%d 页 下一页 [→]  ═══════════",Page,Pages);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		while(1)
		{
			c=getch();
			while(c!=75&&c!=77&&c!=27)
				c=getch();																		//等待用户输入并响应操作
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


sorter(int action,int turn,int obj)																//链表冒泡排序核心函数
{
	int i,j,Act1,Act2;
	Stafter=Start->next;
	for(i=0;i<turn;i++)
	{
		Stafter=Start->next;
		switch(obj)																				//根据参数选择响应排序规则
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
		if(Act1)																				//【特殊】对链表头的特殊处理
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
			switch(obj)																			//根据参数选择响应排序规则
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
			if(Act2)																			//冒泡排序
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


sortwrite()																						//文件写入函数
{
	int len=0;
	p2=p1=Start;
	if((save=fopen("book.txt","w+"))==NULL)														//文件打开失败则报错并返回首页
	{
		system("cls");
		line(1);
		printf("\n\n\n   文件修改失败!\n\n   磁盘拒绝访问!\n   ");
		system("pause");
		rep(1);
	}
	else
	{
		while(p1!=NULL&&p2!=NULL&&p2->next!=NULL&&p1->next!=NULL)								//将链表内所有数据写入文件
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
		fclose(save);																			//数据写入完成关闭文件
	}
}