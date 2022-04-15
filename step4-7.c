#include <stdio.h>

#include "linkedlist.h"
#include "step.h"

int checkLoop(int* arr, int col);
//1. String1[n], String2[k]가 같다면 : [n, k] == [n-1, k-1] + 1
//2. String1[n], String2[k]가 다르면 : [n, k] == [n - 1, k]와[n, k - 1] 중 큰 값

typedef struct _record {
	int data;
	int dashData;
} record;


void step4To7(Node* step2Result, Node* minterms, int row, int col) {
	Node* result = malloc(sizeof(Node) * row);
	int orGate, AndGate, NotGate;
	int* checkedminterm = (int* )malloc(sizeof(int) * col);
	Node* curr = minterms->next;
	for (int i = 0; i < col; i++) {
		checkedminterm[i] = 0;
	}
	int** tables = (int** )malloc(sizeof(int* ) * row);
	for (int i = 0; i < row + 1; i++) {
		tables[i] = (int*)malloc(sizeof(int) * col);
		for (int j = 0; j < col + 1; j++) {
			tables[i][j] = 0;
		}
	}
	Node* current1 = step2Result->next;
	Node* current2;
	int x = 0, y = 0;
	while (current1 != NULL) {
		current2 = minterms->next;
		x = 0;
		while (current2 != NULL)
		{
			printf("test : %d %d\n", current1->data, current2->data);
			int data = checkX(current2->data, current1->data, current1->dashData);
			if(data == 1) {
				tables[y][x] = 1;
			}
			current2 = current2->next;
			x++;
		}
		current1 = current1->next;
		y++;
	}
	curr = checkedminterm;

	while (checkLoop(checkedminterm, col)) {
		Node max;
		//printf("Test");
		int maxCnt = 0;
		int maxY = 0;
		int changeCnt;
		current1 = step2Result->next;
		x = 0, y = 0;
		while (current1 != NULL) {
			changeCnt = 0;
			current2 = minterms->next;
			x = 0;
			while (current2 != NULL)
			{
				if (checkedminterm[x] == 0) {
					if (tables[y][x] == 1) {
						changeCnt += 1;
					}
				}
				current2 = current2->next;
				x++;
			}
			if (maxCnt < changeCnt) {
				maxCnt = changeCnt;
				maxY = y;
				max.data = current1->data;
				max.dashData = current1->dashData;
			}
			current1 = current1->next;
			y++;
		}
		printf("maxCnt : %d, max.Data : %d, max.dashData : %d \n", maxCnt, max.data, max.dashData);
		for (int q = 0; q < col; q++) {
			if (tables[maxY][q] == 1) {
				checkedminterm[q] = 1;
			}
		}
	}
}

int checkX(int mintermData, int step2ResultData, int step2ResultDashData) {
	unsigned int equate = (~step2ResultDashData) & mintermData;
	if (equate == step2ResultData) {
		return 1;
	}
	return 0;
}

int checkLoop(int* arr, int col) {
	for (int i = 0; i < col; i++) {
		if (arr[i] == 0) {
			return 1;
		}
	}
	return 0;
}
 

// 이진수로 데이터가 들어있다.
void MakeOutput(int Data, int hashData, int inputBitLength) {
	char* output = (char*)malloc(sizeof(char) * inputBitLength);
	for (int i = 0; i < inputBitLength; i++) {
		output[i] = Data + 48;
	}
}