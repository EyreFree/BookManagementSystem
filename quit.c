/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
quit(int Quit)														//退出函数
{
	char C1;
	int i;
	system("cls");
	if(Quit==1)
	{
		for(i=0;i<=7;i++)printf("\n");
		mid();printf("   ╔═══════════╗\n");
		mid();printf("   ║确 认 退 出 (Y / N) ？║\n");
		mid();printf("   ║┏━━━━┓          ║\n");
		mid();printf("   ║┃退出 (Y)┃返回 (N)  ║\n");
		mid();printf("   ║┗━━━━┛          ║\n");
		mid();printf("   ╚═══════════╝");
	}
	else
	{
		for(i=0;i<=7;i++)printf("\n");
		mid();printf("   ╔═══════════╗\n");
		mid();printf("   ║确 认 退 出 (Y / N) ？║\n");
		mid();printf("   ║          ┏━━━━┓║\n");
		mid();printf("   ║  退出 (Y)┃返回 (N)┃║\n");
		mid();printf("   ║          ┗━━━━┛║\n");
		mid();printf("   ╚═══════════╝");
	}
	C1=getch();
	while(C1!=89&&C1!=78&&C1!=121&&C1!=110&&C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=13&&C1!=27)
		C1=getch();													//若输入不为功能键则重新获取
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
	quit(Quit);														//根据参数移动矩形框
}