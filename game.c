#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印数组函数
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------扫雷游戏----------\n");
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row;i++)
	{
		//打印行号
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("----------扫雷游戏----------\n");
}

//布置雷函数
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = EASY_COUNT;
	while (count)
	{
		//生成随机的下标
		int x = rand()%row+1;      //rand()%9 =  0~8
		int y = rand()%col+1;      //rand函数需要在int main函数内声明srand函数
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//坐标周围雷的个数
//static   1.修饰局部变量，2.修饰全局变量，3.修饰函数
static int get_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';        //减去字符'0'，周围8个坐标加起来就是周围雷的总数。
}

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.输入排查的坐标
	//2.检查坐标处是不是雷
	    //2.1是雷，很遗憾炸死了，游戏结束
	    //2.2不是雷，统计坐标周围有几个雷，存储排查雷的信息到show数组，游戏继续
	int x = 0;
	int y = 0;
	int win = 0;
	
	while (win < row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标：>");
		scanf("%d %d", &x, &y);      //输入坐标，x--(1-9),y--(1-9)

		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷情况下，统计x,y坐标周围有几个雷
				int count = get_mine(mine, x, y);
				show[x][y] = count + '0';      //数字转换成字符，数字+48=字符数字，或者数字+'0'=字符数字
				//显示排查出的信息
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}