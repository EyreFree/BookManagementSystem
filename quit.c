/********************************************************************************
**         ����:EyreFree	��19��	QQ:1795179491                          **
********************************************************************************/
quit(int Quit)														//�˳�����
{
	char C1;
	int i;
	system("cls");
	if(Quit==1)
	{
		for(i=0;i<=7;i++)printf("\n");
		mid();printf("   �X�T�T�T�T�T�T�T�T�T�T�T�[\n");
		mid();printf("   �Uȷ �� �� �� (Y / N) ���U\n");
		mid();printf("   �U������������          �U\n");
		mid();printf("   �U���˳� (Y)������ (N)  �U\n");
		mid();printf("   �U������������          �U\n");
		mid();printf("   �^�T�T�T�T�T�T�T�T�T�T�T�a");
	}
	else
	{
		for(i=0;i<=7;i++)printf("\n");
		mid();printf("   �X�T�T�T�T�T�T�T�T�T�T�T�[\n");
		mid();printf("   �Uȷ �� �� �� (Y / N) ���U\n");
		mid();printf("   �U          �������������U\n");
		mid();printf("   �U  �˳� (Y)������ (N)���U\n");
		mid();printf("   �U          �������������U\n");
		mid();printf("   �^�T�T�T�T�T�T�T�T�T�T�T�a");
	}
	C1=getch();
	while(C1!=89&&C1!=78&&C1!=121&&C1!=110&&C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=13&&C1!=27)
		C1=getch();													//�����벻Ϊ���ܼ������»�ȡ
	switch(C1)
	{
	case 27:home('1');
	case 89:
	case 121:Quit=1;break;
	case 78:
	case 110:Quit=2;break;
	case 13:if(Quit==1) exit(0);
			else home('1');
	default:if(Quit==1) Quit=2;
			else Quit=1;break;
	}
	quit(Quit);														//���ݲ����ƶ����ο�
}