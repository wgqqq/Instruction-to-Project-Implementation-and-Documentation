
#define ROW 3
#define LINE 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Initbord(char board[ROW][LINE], int row,int line);//初始化键盘
void Displayborad(char board[ROW][LINE], int row, int line);//打印键盘
void Player_move(char board[ROW][LINE], int row, int line);//玩家下棋
void Computer_move(char board[ROW][LINE], int row, int line);//电脑下棋
char is_win(char board[ROW][LINE], int row, int line);//判断
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
	printf("玩家输入:>\n");
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
				printf("该坐标已被占用，请重新输入\n");
			}
		}
		else {
			printf("该数字无效，请重新输入有效数字\n");
		}
	}
}
 
void Computer_move(char board[ROW][LINE], int row, int line)
{
	printf("电脑输入:>\n");
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
	//判断平局
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
			printf("恭喜你 成功拿捏！\n");
			break;
		}
		if (ret == '#') {
			printf("很遗憾，你输了\n");
			break;
		}
		if (ret == 'q') {
			printf("技术很不错，平局哦！\n");
			break;
		}
	}
		Computer_move(board, ROW, LINE);
		Displayborad(board, ROW, LINE);
		ret = is_win(board, ROW, LINE);
 
		if (ret != 'c') {
			if (ret == '*') {
				printf("恭喜你 成功拿捏！\n");
				break;
			}
			if (ret == '#') {
				printf("很遗憾，你输了\n");
				break;
			}
			if (ret == 'q') {
				printf("技术很不错，平局哦！\n");
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
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input) {
		case 1:game();
			break;
		case 2:printf("游戏结束！\n");
			break;
		default:printf("请重新选择:>\n");
			break;
		}
	} while (input);
	return 0;
}
