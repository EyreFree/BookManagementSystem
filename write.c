/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
#include"head.h"
write()																	//将数据写入文件
{
	char Write;
	int len=0;
	if((save=fopen("book.txt","a"))==NULL)								//尝试追加方式打开文件
	{
		if((save=fopen("book.txt","w"))==NULL)							//若追加方式失败则尝试创建文件
		{
			system("cls");
			line(1);
			printf("\n\n   文件创建失败!\n");							//若创建文件失败则报错并返回主页
			system("pause");
			home('1');
		}
		write();
	}
	else
	{
		fseek(save,0L,2);												//将文件指针指向文件结尾处
		fprintf(save,"%s ",stu.num);
		fprintf(save,"%s ",stu.name);
		len=20;
		while((len-strlen(stu.name))>0)
		{
			fprintf(save," ");
			len--;
		}
		fprintf(save,"%s ",stu.writer);
		len=8;
		while((len-strlen(stu.writer))>0)
		{
			fprintf(save," ");
			len--;
		}
		fprintf(save,"%s ",stu.Class);
		len=3;
		while((len-strlen(stu.Class))>0)
		{
			fprintf(save," ");
			len--;
		}
		fprintf(save,"%s ",stu.publisher);
		len=20;
		while((len-strlen(stu.publisher))>0)
		{
			fprintf(save," ");
			len--;
		}
		fprintf(save,"%s ",stu.time);
		len=10;
		while((len-strlen(stu.time))>0)
		{
			fprintf(save," ");
			len--;
		}
		fprintf(save,"%s ",stu.price);
		len=6;
		while((len-strlen(stu.price))>0)
		{
			fprintf(save," ");
			len--;
		}
	}
	fprintf(save,"\n");
	fclose(save);
	printf("\n\n   操作成功!\n\n   是否继续?\n\n   (Yes[回车] / No[Esc])");
	Write=getch();														//接受用户输入若输入非法则重新接受
	while(Write!='y'&&Write!='n'&&Write!='Y'&&Write!='N'&&Write!=13&&Write!=27)
		Write=getch();
	if(Write=='y'||Write=='Y'||Write==13)								//根据用户输入执行相关操作
		scan();
	else
		home('1');														//若选择'N'则返回主页
}