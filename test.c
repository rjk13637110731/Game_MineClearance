#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("********* 1.play  *********\n");
	printf("********* 0.exit  *********\n");
	printf("***************************\n");
}

void game()
{
	char mine[ROWS][COLS] = {0};      //���úõ��׵���Ϣ
	char show[ROWS][COLS] = {0};      //����Ų�����׵���Ϣ
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');      //'0'
	InitBoard(show, ROWS, COLS, '*');      //'*'

	//��ӡһ������
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine,ROW,COL);
	//DisplayBoard(mine, ROW, COL);

	//�Ų���
	FindMine(mine,show,ROW,COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));      //rand������srand������ͷ�ļ��ǣ�<stdlib.h>��<time.h>
	do                                    //(unsigned int)Ϊ��time��������ֵǿ������ת��Ϊ�޷��ŵ�����
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();      //ɨ����Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}