#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"game1.h"//包含小游戏1的头文件
#include"game2.h"//包含小游戏2的头文件
#include"game3.h"//包含小游戏3的头文件
#include"game4.h"//包含小游戏4的头文件
#include"game5.h"//包含小游戏5的头文件
#include<time.h>
#include<stdbool.h>//包含bool
#define ROW 9  //显示的行
#define COL 9  //显示的列
#define ROWS ROW+2  //真实数组的行
#define COLS COL+2  //真实数组的列
#define MINENUM 10  //地雷的个数

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
static void Initialization_3(char minemap[ROWS][COLS], char showmap[ROWS][COLS], int rows, int cols)
{
	int count = MINENUM;//创建一个变量，用来计算放置的雷的数量
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)//把地雷地图全部赋值为字符0
	{
		for (j = 0; j < cols; j++)
		{
			minemap[i][j] = '0';
		}
	}
	while (count)//把雷分布随机分布在地雷地图中
	//我们把0代表安全，1代表雷区
	{
		int x = rand() % ROW + 1;//创建随机变量范围在1~9
		int y = rand() % COL + 1;//创建随机变量范围在1~9
		if (minemap[x][y] == '0')//判断该位置是否已有雷
		{
			minemap[x][y] = '1';//放置地雷
			count--;
		}
	}
	for (i = 0; i < rows; i++)//把展示地图全部赋值为字符*
	{
		for (j = 0; j < cols; j++)
		{
			showmap[i][j] = '*';
		}
	}
}
static void Ptintinitialization_3(char showmap[ROWS][COLS], int row, int col)//打印地图
{
	int i = 1;
	int j = 1;
	for (i = 1; i <= row; i++)
	{
		if (i == 1)//当i为1时，需要多一个空格，目的为了和地图对齐
		{
			printf(" ");
		}
		printf(" %d", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//打印我们所需要的地图
	{
		printf("%d", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c", showmap[i][j]);
		}
		printf("\n");
	}
}
static bool Determine(char minemap[ROWS][COLS],int x,int y)
{
	if (minemap[x][y] == '1')
	{
		printf("排雷失败，你已死亡！\n");
		return false;
	}
	else
	{
		return true;
	}
}
static void Renewmap(char minemap[ROWS][COLS], char showmap[ROWS][COLS], int x, int y)
{
	showmap[x][y] = (minemap[x - 1][y - 1] + minemap[x - 1][y] + minemap[x - 1][y + 1]
				  + minemap[x][y - 1] + minemap[x][y + 1]
				  + minemap[x + 1][y - 1] + minemap[x + 1][y] + minemap[x + 1][y + 1]) - 8*'0' + '0';
}

static void game_3()
{
	int winnum = ROW * COL - MINENUM;//设置一个变量，用来存放还有多少个安全的地方
	char minemap[ROWS][COLS] = { 0 };//雷分布的地图
	char showmap[ROWS][COLS] = { 0 };//向玩家展示的地图
	Initialization_3(minemap, showmap, ROWS, COLS);//初始化数组,把雷分布随机分布在地图中，并且把向玩家展示的地图全部替换为 * 
	//Ptintinitialization(minemap, ROW, COL);//测试代码，用来打印地图
	while (winnum)
	{
		int x = 0;
		int y = 0;
		Ptintinitialization_3(showmap, ROW, COL);//打印展示地图
		printf("请输入排雷坐标：");
		scanf("%d %d", &x, &y);
		if (x<1 || x>ROW || y<1 || y>COL)//判断坐标是否合法
		{
			printf("你输入的坐标不合法，请重新输入。\n");
		}
		else if (showmap[x][y] != '*')//判断坐标是否已被排查过
		{
			printf("你输入的坐标已被排过雷了，请重新输入。\n");
		}
		else 
		{
			if (!Determine(minemap, x, y))//!Determine(minemap, x, y)用来判断是否踩到雷
			{
				Ptintinitialization_3(minemap, ROW, COL);//打印地雷地图，让玩家知道地雷在哪里。
				break;
			}
			Renewmap(minemap, showmap, x, y);//用来更新向玩家展示的地图
			winnum--;//对安全的地方进行减1
		}
	}
	if(winnum == 0)//当安全地方为0时，证明排雷成功
	{
		printf("恭喜你排雷成功！\n");
		Ptintinitialization_3(showmap, ROW, COL);//打印展示地图，让玩家知道自己获胜地图
	}
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
			game_3();
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

