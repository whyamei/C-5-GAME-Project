#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"game1.h"//包含小游戏1的头文件
#include"game2.h"//包含小游戏2的头文件
#include"game3.h"//包含小游戏3的头文件
#include"game4.h"//包含小游戏4的头文件
#include"game5.h"//包含小游戏5的头文件
#include<time.h>
#define ROW 3  //行
#define COL 3  //列

void menu()
{
	printf("*****************************\n");
	printf("*****1.猜数字   2.三子棋*****\n");
	printf("*****3.扫  雷   4.五子棋*****\n");
	printf("*****5.飞行棋   0.退  出*****\n");
	printf("*****************************\n");
}
void game1();
void game2();
void game3();
void game4();
void game5();
//#include"game1.h"
static void menu1()
{
	printf("*****************************\n");
	printf("*****      猜数字       *****\n");
	printf("***** 1.Start the game ******\n");
	printf("***** 0.Exit the game  ******\n");
	printf("*****************************\n");
}
static void game_1()
{
	int num = rand() % 100 + 1;//创建一个变量，用来存放随机数。
	int guess = 0;//创建一个变量，用来存放所猜的数字。	
	//rand函数是用来生成随机数的，我们用rand函数生成的随机数对100取模并加1，可以产生1~100的随机数
	while(1)
	{
		printf("请输入你猜测的数字：");
		scanf("%d", &guess);
		if (guess == num)
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
		else if (guess > num)
		{
			printf("你猜的数字过大，请重新猜测吧！\n");
		}
		else if (guess < num)
		{
			printf("你猜的数字过小，请重新猜测吧！\n");
		}
	}
	return;
}
void game1()
{
	int optional = 0;//创建一个接收选择的变量
	do
	{
		optional = 0;
		menu1();
		printf("请输入你的选项：\n");
		scanf("%d", &optional);
		switch (optional)
		{
		case 1:
			game_1();
			break;
		case 0:
			printf("猜数字小游戏已退出。\n");
			break;
		default:
			printf("你的选项输入有误，请重新输入：\n");
			break;
		}
	} while (optional);
}
static void menu2()
{
	printf("*****************************\n");
	printf("*****      三子棋       *****\n");
	printf("***** 1.Start the game ******\n");
	printf("***** 0.Exit the game  ******\n");
	printf("*****************************\n");
}
static void ptintinitialization(char arr[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
			{
				printf(" %c |", arr[i][j]);//打印棋盘，如果为列中的最后一个元素，则不打印|
			}
			else
			{
				printf(" %c ", arr[i][j]);
			}
		}
		printf("\n");
		if(i < row-1)//打印棋盘，如果为行中的最后一个元素，则不打印---
		{
			for (j = 0; j < col; j++)
			{
				if (j < col)
				{
					printf("--- ");
				}
			}
		}
		printf("\n");
	}
}

static void initialization(char arr[ROW][COL],int row,int col)//初始化数组
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';//把数组中的每个元素赋值为空格
		}
	}
}
static void Player(char arr[ROW][COL], int row, int col, char ch)//玩家下棋函数
{
	int x = 0;
	int y = 0;
	while(1)
	{
		printf("请输入你要下棋的坐标：");
		scanf("%d %d", &x, &y);
		if (x<1 || x>row || y<1 || y>col)//判断坐标是否合法
		{
			printf("你输入的坐标不合法，请重新输入。\n");
		}
		else if (arr[x - 1][y - 1] != ' ')//判断输入坐标是否被占用
		{
			printf("你输入的坐标已被占用，请重新输入。\n");
		}
		else
		{
			arr[x - 1][y - 1] = ch;//数组下标从0开始，所以玩家的真实坐标要进行减1
			break;
		}
	}
}
static void Computer(char arr[ROW][COL], int row, int col, char ch)
{
	while (1)
	{
		int x = rand() % 3;//产生0~2的数字
		int y = rand() % 3;
		if (arr[x][y] == ' ')//如果坐标未被占用，则电脑下棋，否则产生新的坐标进行判断
		{
			arr[x][y] = ch;//电脑的坐标的下标和数组下标对应，不需要进行减1操作
			break;
		}
	}
}
static char Iswin(char arr[ROW][COL], int row, int col)//判断是否获胜
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//判断每一排中是否有人获胜
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
			return arr[i][1];
		}
	}
	for (i = 0; i < col; i++)//判断每一列中是否有人获胜
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			return arr[1][i];
		}
	}
	if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ') || 
		(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' '))//判断对角线上是否有人获胜
	{
		return arr[1][1];
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; i < col; i++)
		{
			if (arr[i][j] == ' ');//判断是否还有空位
			{
				return 'C';
			}
		}
	}
	return 'D';
}

static void game_2()
{
	char win;//创建一个变量,存放判段获胜条件的字符。
	//我们把C代表继续，D代表平局，*代表玩家获胜，#代表电脑获胜
	char checkerboard[ROW][COL] = { 0 };//创建一个数组，用来存放棋盘信息
	initialization(checkerboard,ROW,COL);//初始化数组,把数组中的每个元素初始化为空格
	ptintinitialization(checkerboard, ROW, COL);//打印棋盘
	while(1)
	{
		Player(checkerboard, ROW, COL, '*');//玩家下棋，玩家的标志为 *
		win = Iswin(checkerboard, ROW, COL);//判断是否获胜
		if (win != 'C')
		{
			break;
		}
		ptintinitialization(checkerboard, ROW, COL);//打印棋盘
		Computer(checkerboard, ROW, COL, '#');//电脑下棋，电脑的标志为 #
		win = Iswin(checkerboard, ROW, COL);
		if (win != 'C')
		{
			break;
		}
		ptintinitialization(checkerboard, ROW, COL);//打印棋盘
	}
	if (win == 'D')
	{
		printf("平局\n");
		ptintinitialization(checkerboard, ROW, COL);
	}
	else if (win == '*')
	{
		printf("恭喜你获得胜利\n");
		ptintinitialization(checkerboard, ROW, COL);
	}
	else
	{
		printf("很遗憾，你输掉了比赛\n");
		ptintinitialization(checkerboard, ROW, COL);
	}
}


void game2()
{
	int optional = 0;//创建一个接收选择的变量
	do
	{
		optional = 0;
		menu2();
		printf("请输入你的选项：\n");
		scanf("%d", &optional);
		switch (optional)
		{
		case 1:
			game_2();
			break;
		case 0:
			printf("三子棋小游戏已退出。\n");
			break;
		default:
			printf("你的选项输入有误，请重新输入：\n");
			break;
		}
	} while (optional);
}
static void menu3()
{
	printf("*****************************\n");
	printf("*****      扫雷       *****\n");
	printf("***** 1.Start the game ******\n");
	printf("***** 0.Exit the game  ******\n");
	printf("*****************************\n");
}
void game3()
{
	int optional = 0;//创建一个接收选择的变量
	do
	{
		optional = 0;
		menu3();
		printf("请输入你的选项：\n");
		scanf("%d", &optional);
		switch (optional)
		{
		case 1:
			//game();
			break;
		case 0:
			printf("扫雷小游戏已退出。\n");
			break;
		default:
			printf("你的选项输入有误，请重新输入：\n");
			break;
		}
	} while (optional);
}
static void menu4()
{
	printf("*****************************\n");
	printf("*****      五子棋       *****\n");
	printf("***** 1.Start the game ******\n");
	printf("***** 0.Exit the game  ******\n");
	printf("*****************************\n");
}
void game4()
{
	int optional = 0;//创建一个接收选择的变量
	do
	{
		optional = 0;
		menu4();
		printf("请输入你的选项：\n");
		scanf("%d", &optional);
		switch (optional)
		{
		case 1:
			//game();
			break;
		case 0:
			printf("五子棋小游戏已退出。\n");
			break;
		default:
			printf("你的选项输入有误，请重新输入：\n");
			break;
		}
	} while (optional);
}
static void menu5()
{
	printf("*****************************\n");
	printf("*****      飞行棋       *****\n");
	printf("***** 1.Start the game ******\n");
	printf("***** 0.Exit the game  ******\n");
	printf("*****************************\n");
}
void game5()
{
	int optional = 0;//创建一个接收选择的变量
	do
	{
		optional = 0;
		menu5();
		printf("请输入你的选项：\n");
		scanf("%d", &optional);
		switch (optional)
		{
		case 1:
			//game();
			break;
		case 0:
			printf("飞行棋小游戏已退出。\n");
			break;
		default:
			printf("你的选项输入有误，请重新输入：\n");
			break;
		}
	} while (optional);
}
int main()
{
	srand((unsigned int)time(NULL));//用来生成随机数
	do
	{
		int optional = 0;//创建一个接收选择的变量
		menu();
		printf("请输入你的选项：\n");
		scanf("%d", &optional);
		switch (optional)
		{
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 3:
			game3();
			break;
		case 4:
			game4();
			break;
		case 5:
			game5();
			break;
		case 0:
			printf("感谢你的游玩，欢迎下次使用。\n");
			exit(0);
		default:
			printf("你的选项输入有误，请重新输入：\n");
			break;
		}
	} while (1);
}

