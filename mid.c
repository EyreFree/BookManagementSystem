/********************************************************************************
**         作者:EyreFree	软工19班	QQ:1795179491                          **
********************************************************************************/
mid()																//居中函数
{	
	int i;
	for(i=0;i<=27;i++)
		printf(" ");
}

line(int i)
{
	switch(i)
	{
	case 1:	printf("\n   ════════════════ 图书信息管理系统 ════════════════\n\n");break;
	case 2:	printf("   登录号 书名\t\t       作者  分类号 出版单位\t\t 出版时间   价格\n   ");break;
	case 3:	printf("\n\n   ═══════════════  软工 19班  EyreFree  ═══════════════\n   ");break;
	case 4:	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");break;
	case 5:	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n   ");break;
	case 6:	printf("\n\n\n\n\n\n   [  提示 : 请按 <方向键> 选中选项后再按 <回车键> 实现对应功能     按 <Esc> 键退出 ]\n\n");
			printf("   ═══════════════  软工 19班  EyreFree  ═══════════════");break;
	case 7:	printf("   [  提示 : 请 按 要 求 输 入 相 应 项 目 信 息 并 按  <回车键Enter>  结 束  ~o_0~ ]\n\n");
			printf("   登录号 书名\t\t       作者  分类号 出版单位\t\t 出版时间   价格\n   ");break;
	case 8:break;
	case 9:break;
	case 10:break;
	}
}