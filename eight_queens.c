#include "eight_queens.h"

int main(void) {
	board_init(0,7);
	put(0);
	printf("%d\n", num);
	return 0;
}

void put(int row) {
	if (row == N) {
		num++;
		result = (int***)realloc(result,num*sizeof(int));
		result[num-1] = (int**)malloc(sizeof(int)*N);
		for (size_t i = 0;i < N;i++) {
			result[num - 1][i] = (int*)malloc(sizeof(int) * N);
		}
		copy(num);
		return;
	}
	for (size_t column = 0;column < N;column++) {
		if (!judge(row, column)) {
			put(row+1);
			board_init(row, row);
		}
	}
}

int judge(int row,int column) {
	board[row][column] = 1;
	if (judge_column(column) + judge_bias(row, column)) {
		board[row][column] = 0;
		return 1;
	}
	return 0;
}

int judge_column(int column) {
	int sum = 0;
	for (size_t i = 0;i < N;i++) {
			sum += board[i][column];
	}
	if (sum > 1)return 1;
	return 0;
}

int judge_bias(int row,int column) {
	int sum = 0;
	int row_init = row;int column_int = column;
	while (row!=7&&column!=0) {
		row++;column--;
	}
	do {
		sum += board[row][column];
		row--;column++;
	} while (row>=0&&column<8);
	row = row_init;column = column_int;
	while (row != 0 && column != 0) {
		row--;column--;
	}
	do {
		sum += board[row][column];
		row++;column++;
	} while (row < 8 && column < 8);
	if (sum > 2)return 1;
	return 0;
}

void copy(int num) {
	for (size_t i = 0;i < N;i++) {
		for (size_t j = 0;j < N;j++) {
			result[num - 1][i][j] = board[i][j];
		}
	}
}

void print(int num) {
	for (size_t i = 0;i < N;i++) {
		for (size_t j = 0;j < N;j++) {
			printf("%d ", result[num - 1][i][j]);
		}
		printf("\n");
	}
	printf("\n");
}