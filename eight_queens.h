#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 8

int board[N][N];
int num=0;
void put(int);
int judge(int,int);
int judge_column(int);
int judge_bias(int,int);
int*** result = NULL;
void copy(int);
void print(int);

#define board_init(x,y) for (size_t i = x;i <= y ;i++) {\
for (size_t j = 0;j < N;j++) {\
	board[i][j] = 0;\
}\
}