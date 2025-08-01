#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"game1.h"//包含小游戏1的头文件
#include"game2.h"//包含小游戏2的头文件
#include"game3.h"//包含小游戏3的头文件
#include"game4.h"//包含小游戏4的头文件
#include"game5.h"//包含小游戏5的头文件
#include<time.h>
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
			//game();
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
			//game();
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
