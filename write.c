/********************************************************************************
**         ����:EyreFree	��19��	QQ:1795179491                          **
********************************************************************************/
#include"head.h"
write()																	//������д���ļ�
{
	char Write;
	int len=0;
	if((save=fopen("book.txt","a"))==NULL)								//����׷�ӷ�ʽ���ļ�
	{
		if((save=fopen("book.txt","w"))==NULL)							//��׷�ӷ�ʽʧ�����Դ����ļ�
		{
			system("cls");
			line(1);
			printf("\n\n   �ļ�����ʧ��!\n");							//�������ļ�ʧ���򱨴�������ҳ
			system("pause");
			home('1');
		}
		write();
	}
	else
	{
		fseek(save,0L,2);												//���ļ�ָ��ָ���ļ���β��
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
	printf("\n\n   �����ɹ�!\n\n   �Ƿ����?\n\n   (Yes[�س�] / No[Esc])");
	Write=getch();														//�����û�����������Ƿ������½���
	while(Write!='y'&&Write!='n'&&Write!='Y'&&Write!='N'&&Write!=13&&Write!=27)
		Write=getch();
	if(Write=='y'||Write=='Y'||Write==13)								//�����û�����ִ����ز���
		scan();
	else
		home('1');														//��ѡ��'N'�򷵻���ҳ
}