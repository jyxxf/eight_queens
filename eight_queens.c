#include "eight_queens.h"

int main(void) {
	board_init(1,8);
	for (size_t row = 0;row < N;row++) {
		put(row);
	}
	printf("%d\n", num);
	return 0;
}

void put(int row) {
	if (row == N) {
		num++;
		board_init(8, 8);
		return;
	}
	for (size_t column = 0;column < N;column++) {
		if (!judge(row, column))
			put(row++);
		if (column == N - 1)return;
	}
}

int judge(int row,int column) {
	board[row][column] = 1;
	if (judge_column() + judge_bias(row, column)) {
		board[row][column] = 0;
		return 1;
	}
	return 0;
}

int judge_column(void) {
	for (size_t i = 0;i < N;i++) {
		int sum = 0;
		for (size_t j = 0;j < N;j++) {
			sum += board[i][j];
		}
		if (sum > 1)return 1;
	}
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
