/********************************************************************************
**         ����:EyreFree	��19��	QQ:1795179491                          **
********************************************************************************/
home(int Home)
{
	char C1;
	system("cls");
	printf("\n   �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T ͼ����Ϣ����ϵͳ �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n\n\n\n\n");
	switch(Home)
	{
	case '1':	mid();printf("��������������\n");
				mid();printf("��1:������Ϣ��      2:������\n");
				mid();printf("��������������\n");
				mid();printf("  3:������Ϣ        4:ɾ����Ϣ\n\n");
				mid();printf("  5:���ȫ��        6:ʹ��˵��\n\n");
				mid();printf("  7:��������        8:�˳�����\n\n"); break;
	case '2':	mid();printf("                  ��������������\n");
				mid();printf("  1:������Ϣ      ��2:������\n");
				mid();printf("                  ��������������\n");
				mid();printf("  3:������Ϣ        4:ɾ����Ϣ\n\n");
				mid();printf("  5:���ȫ��        6:ʹ��˵��\n\n");
				mid();printf("  7:��������        8:�˳�����\n\n"); break;
	case '3':	printf("\n");
				mid();printf("  1:������Ϣ        2:������\n");
				mid();printf("��������������\n");
				mid();printf("��3:������Ϣ��      4:ɾ����Ϣ\n");
				mid();printf("��������������\n");
				mid();printf("  5:���ȫ��        6:ʹ��˵��\n\n");
				mid();printf("  7:��������        8:�˳�����\n\n");	break;
	case '4':	printf("\n");
				mid();printf("  1:������Ϣ        2:������\n");
				mid();printf("                  ��������������\n");
				mid();printf("  3:������Ϣ      ��4:ɾ����Ϣ��\n");
				mid();printf("                  ��������������\n");
				mid();printf("  5:���ȫ��        6:ʹ��˵��\n\n");
				mid();printf("  7:��������        8:�˳�����\n\n");	break;
	case '5':	printf("\n");
				mid();printf("  1:������Ϣ        2:������\n\n");
				mid();printf("  3:������Ϣ        4:ɾ����Ϣ\n");
				mid();printf("��������������\n");
				mid();printf("��5:���ȫ����      6:ʹ��˵��\n");
				mid();printf("��������������\n");
				mid();printf("  7:��������        8:�˳�����\n\n");	break;
	case '6':	printf("\n");
				mid();printf("  1:������Ϣ        2:������\n\n");
				mid();printf("  3:������Ϣ        4:ɾ����Ϣ\n");
				mid();printf("                  ��������������\n");
				mid();printf("  5:���ȫ��      ��6:ʹ��˵����\n");
				mid();printf("                  ��������������\n");
				mid();printf("  7:��������        8:�˳�����\n\n"); break;
	case '7':	printf("\n");
				mid();printf("  1:������Ϣ        2:������\n\n");
				mid();printf("  3:������Ϣ        4:ɾ����Ϣ\n\n");
				mid();printf("  5:���ȫ��        6:ʹ��˵��\n");
				mid();printf("��������������\n");
				mid();printf("��7:�������ߩ�      8:�˳�����\n");
				mid();printf("��������������\n");				break;
	case '8':	printf("\n");
				mid();printf("  1:������Ϣ        2:������\n\n");
				mid();printf("  3:������Ϣ        4:ɾ����Ϣ\n\n");
				mid();printf("  5:���ȫ��        6:ʹ��˵��\n");
				mid();printf("                  ��������������\n");
				mid();printf("  7:��������      ��8:�˳�����\n");
				mid();printf("                  ��������������\n"); break;
	}
	printf("\n\n\n\n\n   [  ��ʾ : �밴 <�����> ѡ��ѡ����ٰ� <�س���> ʵ�ֶ�Ӧ����     �� <Esc> ���˳� ]\n\n");
	printf("   �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T  �� 19��  EyreFree  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T");
	C1=getch();																				//��ȡ�û�����
	while((C1<49||C1>56)&&C1!=72&&C1!=75&&C1!=77&&C1!=80&&C1!=27&&C1!=13)					//�����벻Ϊ���ܼ������»�ȡ
		C1=getch();
	switch(C1)
	{
	case 13:switch(Home)																	//��Ϊ�س���ִ����Ӧ����
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
	case 56:Home=(int)C1;break;																//��Ϊѡ����򰴹����ƶ����ο�
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
	home(Home);																				//���ݲ���������ҳ
}