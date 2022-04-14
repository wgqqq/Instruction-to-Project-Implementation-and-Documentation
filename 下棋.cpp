
#define ROW 3
#define LINE 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Initbord(char board[ROW][LINE], int row,int line);//��ʼ������
void Displayborad(char board[ROW][LINE], int row, int line);//��ӡ����
void Player_move(char board[ROW][LINE], int row, int line);//�������
void Computer_move(char board[ROW][LINE], int row, int line);//��������
char is_win(char board[ROW][LINE], int row, int line);//�ж�
#define _CRT_SECURE_NO_WARNINGS 1
void Initbord(char board[ROW][LINE], int row, int line)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++) {
		for (j = 0;j < line;j++) {
			board[i][j] = ' ';
		}
	}
}
void Displayborad(char board[ROW][LINE], int row, int line) 
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++) {
		for (j = 0;j < line;j++) {
			if (j < line - 1) {
				printf(" %c |",board[i][j]);
			}
			else
			{
				printf(" %c ", board[i][j]);
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0;j < line;j++) {
				if (j < line - 1) {
					printf("---|");
				}
				else
				{
					printf("---");
				}
			}
			printf("\n");
		}
	}
}
 
void Player_move(char board[ROW][LINE], int row, int line)
{
	printf("�������:>\n");
	int x = 0;
	int y = 0;
	while (1) {
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= line) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("�������ѱ�ռ�ã�����������\n");
			}
		}
		else {
			printf("��������Ч��������������Ч����\n");
		}
	}
}
 
void Computer_move(char board[ROW][LINE], int row, int line)
{
	printf("��������:>\n");
	while (1) {
		int x = rand() % row + 1;
		int y = rand() % line + 1;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}
int is_full(char board[ROW][LINE], int row, int line)
{
	int i = 0;
	int j = 0;
	int count = 1;
	for (i = 0;i < row;i++) {
		for (j = 0;j < line;j++) {
			if (board[i][j] == ' ') {
				count = count + 1;
			}
	 }
	}
	if (count == 1) {
		return 1;
	}
	else { return 0; }
}
 
char is_win(char board[ROW][LINE], int row, int line) 
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++) {
		for (j = 0;j < line;j++) {
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&board[i][1]!=' ')
			{
				return board[i][1];
			}
		}
	}
	for (i = 0;i < line;i++) {
		for (j = 0;j < row;j++) {
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			{
				return board[i][1];
			}
		}
	}
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж�ƽ��
	if (1 == is_full(board, ROW, LINE)) {
		return 'q';
}
	else {
		return 'c';
	}
 
	
     
}
 
 
 
#define _CRT_SECURE_NO_WARNINGS 1
void menu() {
	printf("***********************\n");
	printf("*******1.play**********\n");
	printf("*******0.exit**********\n");
	printf("***********************\n");
}
void game( )
{
	char board[ROW][LINE] = {0};
	char ret = 0;
	Initbord(board, ROW, LINE);
	Displayborad(board,ROW,LINE);
	while (1) {
		Player_move(board, ROW, LINE);
		Displayborad(board, ROW, LINE);
	ret =	is_win(board, ROW, LINE);
	if (ret != 'c') {
		if (ret == '*') {
			printf("��ϲ�� �ɹ�����\n");
			break;
		}
		if (ret == '#') {
			printf("���ź���������\n");
			break;
		}
		if (ret == 'q') {
			printf("�����ܲ���ƽ��Ŷ��\n");
			break;
		}
	}
		Computer_move(board, ROW, LINE);
		Displayborad(board, ROW, LINE);
		ret = is_win(board, ROW, LINE);
 
		if (ret != 'c') {
			if (ret == '*') {
				printf("��ϲ�� �ɹ�����\n");
				break;
			}
			if (ret == '#') {
				printf("���ź���������\n");
				break;
			}
			if (ret == 'q') {
				printf("�����ܲ���ƽ��Ŷ��\n");
				break;
			}
		}
 
	}
 
}
int main() {
	int input = 0;
	do
	{
		srand((unsigned)time(NULL));
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input) {
		case 1:game();
			break;
		case 2:printf("��Ϸ������\n");
			break;
		default:printf("������ѡ��:>\n");
			break;
		}
	} while (input);
	return 0;
}
