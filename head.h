/********************************************************************************
**         ×÷Õß:EyreFree	Èí¹¤19°à	QQ:1795179491                          **
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define LEN sizeof(struct infor)
#define LINE 15
#define RLINE 7
/*#define up 72
#define down 80
#define left 75
#define right 77*/

typedef struct infor
{
	char num[7];
	char name[21];
	char writer[9];
	char Class[4];
	char publisher[21];
	char time[11];
	char price[7];
	struct infor* next;
}S;
S stu,tem,temper;

FILE * save,middle;
struct infor * p1,* p2,* p3,* Start,* Stafter;
int TIME,PAGE,PAGES,O;


