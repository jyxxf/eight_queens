#include <stdio.h>

#define N 8

int board[N][N];
int num=0;
void put(int);
int judge(int,int);
int judge_column(void);
int judge_bias(int,int);

#define board_init(x,y) for (size_t i = x-1;i < y ;i++) {\
for (size_t j = 0;j < N;j++) {\
	board[i][j] = 0;\
}\
}