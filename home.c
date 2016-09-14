/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
home(int Home)
{
	char C1;
	system("cls");
	printf("\n   ════════════════ 图书信息管理系统 ════════════════\n\n\n\n\n");
	switch(Home)
	{
	case '1':	mid();printf("┏━━━━━┓\n");
				mid();printf("┃1:输入信息┃      2:排序处理\n");
				mid();printf("┗━━━━━┛\n");
				mid();printf("  3:查找信息        4:删改信息\n\n");
				mid();printf("  5:浏览全部        6:使用说明\n\n");
				mid();printf("  7:关于作者        8:退出程序\n\n"); break;
	case '2':	mid();printf("                  ┏━━━━━┓\n");
				mid();printf("  1:输入信息      ┃2:排序处理┃\n");
				mid();printf("                  ┗━━━━━┛\n");
				mid();printf("  3:查找信息        4:删改信息\n\n");
				mid();printf("  5:浏览全部        6:使用说明\n\n");
				mid();printf("  7:关于作者        8:退出程序\n\n"); break;
	case '3':	printf("\n");
				mid();printf("  1:输入信息        2:排序处理\n");
				mid();printf("┏━━━━━┓\n");
				mid();printf("┃3:查找信息┃      4:删改信息\n");
				mid();printf("┗━━━━━┛\n");
				mid();printf("  5:浏览全部        6:使用说明\n\n");
				mid();printf("  7:关于作者        8:退出程序\n\n");	break;
	case '4':	printf("\n");
				mid();printf("  1:输入信息        2:排序处理\n");
				mid();printf("                  ┏━━━━━┓\n");
				mid();printf("  3:查找信息      ┃4:删改信息┃\n");
				mid();printf("                  ┗━━━━━┛\n");
				mid();printf("  5:浏览全部        6:使用说明\n\n");
				mid();printf("  7:关于作者        8:退出程序\n\n");	break;
	case '5':	printf("\n");
				mid();printf("  1:输入信息        2:排序处理\n\n");
				mid();printf("  3:查找信息        4:删改信息\n");
				mid();printf("┏━━━━━┓\n");
				mid();printf("┃5:浏览全部┃      6:使用说明\n");
				mid();printf("┗━━━━━┛\n");
				mid();printf("  7:关于作者        8:退出程序\n\n");	break;
	case '6':	printf("\n");
				mid();printf("  1:输入信息        2:排序处理\n\n");
				mid();printf("  3:查找信息        4:删改信息\n");
				mid();printf("                  ┏━━━━━┓\n");
				mid();printf("  5:浏览全部      ┃6:使用说明┃\n");
				mid();printf("                  ┗━━━━━┛\n");
				mid();printf("  7:关于作者        8:退出程序\n\n"); break;
	case '7':	printf("\n");
				mid();printf("  1:输入信息        2:排序处理\n\n");
				mid();printf("  3:查找信息        4:删改信息\n\n");
				mid();printf("  5:浏览全部        6:使用说明\n");
				mid();printf("┏━━━━━┓\n");
				mid();printf("┃7:关于作者┃      8:退出程序\n");
				mid();printf("┗━━━━━┛\n");				break;
	case '8':	printf("\n");
				mid();printf("  1:输入信息        2:排序处理\n\n");
				mid();printf("  3:查找信息        4:删改信息\n\n");
				mid();printf("  5:浏览全部        6:使用说明\n");
				mid();printf("                  ┏━━━━━┓\n");
				mid();printf("  7:关于作者      ┃8:退出程序┃\n");
				mid();printf("                  ┗━━━━━┛\n"); break;
	}
	printf("\n\n\n\n\n   [  提示 : 请按 <方向键> 选中选项后再按 <回车键> 实现对应功能     按 <Esc> 键退出 ]\n\n");
	printf("   ═══════════════  软工 19班  EyreFree  ═══════════════");
	C1=getch();																				//获取用户输入
	while((C1<49||C1>56)&&C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=27&&C1!=13)					//若输入不为功能键则重新获取
		C1=getch();
	switch(C1)
	{
	case 13:switch(Home)																	//若为回车则执行相应操作
			{
			case 49:check();
			case 50:sortscreen(1,1,1,1,1);
			case 51:sec('1');
			case 52:rep(1,0);
			case 53:reader();
			case 54:readme();
			case 55:about();
			case 56:quit(2);
			}
	case 27:quit(2);
	case 49:
	case 50:
	case 51:
	case 52:
	case 53:
	case 54:
	case 55:
	case 56:Home=(int)C1;break;																//若为选择键则按规则移动矩形框
	case 72:if(Home=='1') Home='7';
			else if(Home=='2') Home='8';
				else Home=Home-2; break;
	case 75:if(Home=='1') Home='8';
			else Home--; break;
	case 77:if(Home=='8') Home='1';
			else Home++; break;
	case 80:if(Home=='8') Home='2';
			else if(Home=='7') Home='1';
				else Home=Home+2;break;
	}
	home(Home);																				//根据参数返回主页
}