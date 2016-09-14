/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
#include"head.h"


checker()																				//数据录入函数
{
	int checker=0;
	O=0;
	if((save=fopen("book.txt","r"))==NULL)
	{
		if((save=fopen("book.txt","w+"))==NULL)
		{
			system("cls");
			line(1);
			printf("\n\n   文件创建失败!\n");
			system("pause");
			home('1');
		}
		O=1;
		jump();
	}
	while(!feof(save)&&(O!=1))															//检测数据登录号是否已存在
	{
		fscanf(save,"%s\t%s\t%s\t%s\t%s\t%s\t%s",tem.num,tem.name,tem.writer,tem.Class,tem.publisher,tem.time,tem.price);
		if(!strcmp(stu.num,tem.num))
			checker++;	
	}
	fclose(save);
	return(checker);
}


jump()																					//跳转并重新检测数据登录号是否已存在
{
	checker();
}


check()
{
	char Write;																			//确认是否开始录入数据
	system("cls");
	line(1);
	line(7);
	printf("\n\n   即将进行数据录入操作!\n\n   是否继续?\n\n   (Yes[回车] / No[Esc])");
	Write=getch();
	while(Write!='y'&&Write!='n'&&Write!='Y'&&Write!='N'&&Write!=13&&Write!=27)
		Write=getch();
	if(Write=='y'||Write=='Y'||Write==13)
		scan();
	else
		home('1');
}




scan()																						//录入数据
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
			if(checker()>=1)																//若登录号已存在则强制重新输入
			{	
				printf("\n   该登录号已存在,请重新输入新的登录号~!\n\n   ");
				system("pause");
			}
			else break;																		//若数据合法且未存在则终止循环
		}
		else
		{
			printf("\n   请输入规范的登录号(必须为6位数字)~!\n\n   ");						//若登录号不合法则强制重新输入
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
		if(!(strlen(stu.name)>20||strlen(stu.name)<=0)) break;								//若数据合法则终止循环
		else																				//若数据不合法则强制重新输入
		{
			printf("\n   请输入规范的书名(10个汉字以内)~!\n\n   ");
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
		if(!(strlen(stu.writer)<=0||strlen(stu.writer)>8)) break;							//若数据合法则终止循环
		else																				//若数据不合法则强制重新输入
		{
			printf("\n   请输入规范的作者名(4个汉字以内)~!\n\n   ");
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
		if(!(strlen(stu.Class)<=0||strlen(stu.Class)>3)) break;								//若数据合法则终止循环
		else																				//若数据不合法则强制重新输入
		{
			printf("\n   请输入规范的分类号(3位数字以内)~!\n\n   ");
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
		if((strlen(stu.publisher)<=20)&&(strlen(stu.publisher)>0)) break;					//若数据合法则终止循环
		else																				//若数据不合法则强制重新输入
		{
			printf("\n   请输入规范的出版单位(必须为10个汉字以内)~!\n\n   ");
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
		if(strlen(stu.time)==10) break;														//若数据合法则终止循环
		else
		{
			printf("\n   请输入规范的日期(必须为2011/01/01格式)~!\n\n   ");					//若数据不合法则强制重新输入
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
		if((0<strlen(stu.price))&&(strlen(stu.price)<=6)) break;							//若数据合法则终止循环
		else
		{
			printf("\n   请输入规范的价格(必须为6位数字以内)~!\n\n   ");					//若数据不合法则强制重新输入
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
	write();																				//调用写文件函数写入文件内
}