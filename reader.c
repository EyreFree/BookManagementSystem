/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
#include"head.h"
reader()																				//查看全部函数
{
	char c;
	int len,time=0,turn=0,Pages,Page=1,i;
	Start=NULL;
	p1=p2=(struct infor*)malloc(LEN);													//创建链表
	Start=p1;
	if((save=fopen("book.txt","r"))==NULL)												//若文件打开失败则报错
	{
		system("cls");
		line(1);
		printf("\n\n   打开失败!文件不存在!\n\n   ");
		system("pause");
		home('1');
	}
	if(feof(save))																		//若文件为空则报错
	{
		system("cls");
		line(1);
		printf("\n\n   读取失败!数据不存在!\n\n   ");
		system("pause");
		home('1');
	}
	else																				//若数据存在则读入链表
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
		Pages=(turn/LINE);																//记录总页数
	else
		Pages=(turn/LINE+1);
	if(strlen(Start->num)!=6)
	{																					//若链表首节点登录号数据错误则返回主页
		system("cls");
		line(1);
		printf("\n   读取失败!数据不存在!\n\n   ");
		system("pause");
		home('1');
	}
	while(1)
	{
		p1=Start;
		printf("   ");
		for(i=0;i<(LINE*(Page-1));i++)													//按页移动指针到相应页数
			p1=p1->next;
		system("cls");
		line(1);
		line(2);
		printf("\n   ");
		do																				//输出当前页所有数据
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
				c=getch();																//获取用户输入
			if(c==27) home('1');
			if(c==77&&Page!=Pages&&p1->next!=NULL)										//响应用户操作
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