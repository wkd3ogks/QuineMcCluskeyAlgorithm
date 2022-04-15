#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "linkedlist.h"
#include "step.h"

int checkLoop(int* arr, int col);
int MakeOutput(int Data, int dashData, int inputBitLength, FILE* fp, int* notGate, int* andGate);
//1. String1[n], String2[k]가 같다면 : [n, k] == [n-1, k-1] + 1
//2. String1[n], String2[k]가 다르면 : [n, k] == [n - 1, k]와[n, k - 1] 중 큰 값

typedef struct _record {
	int data;
	int dashData;
} record;


void step4To7(Node* step2Result, Node* minterms, int row, int col) {
	FILE* fp = fopen("result.txt", "w");
	Node* result = malloc(sizeof(Node) * row);
	int orGate = 0, AndGate = 0, NotGate = 0;
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
		orGate += MakeOutput(max.data, max.dashData, 4, fp, &NotGate, &AndGate);
		for (int q = 0; q < col; q++) {
			if (tables[maxY][q] == 1) {
				checkedminterm[q] = 1;
			}
		}
	}
	if (orGate > 1) {
		orGate = orGate * 2 + 2;
	}
	else {
		orGate = 0;
	}
	fprintf(fp, "\nCost (# of transistors): %d", orGate + NotGate + AndGate);
	fclose(fp);
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
int MakeOutput(int Data, int dashData, int inputBitLength, FILE* fp, int* notGate, int* andGate) {
	char* output = (char*)malloc(sizeof(char) * inputBitLength);
	int dashCnt = 0;
	for (int i = 0; i < inputBitLength; i++) {
		output[i] = 0;
	}
	for (int i = 0; i < inputBitLength; i++) {
		output[inputBitLength - i - 1] = (Data % 2) + 48;
		Data = Data / 2;
	}
	for (int i = 0; i < inputBitLength; i++) {
		if (dashData % 2 == 1) {
			output[inputBitLength - i - 1] = '_';
			dashCnt += 1;
		}
		dashData = dashData / 2;
		 
	}
	for (int i = 0; i < inputBitLength; i++) {
		if (output[i] == '0') {
			*notGate += 2;
		}
		fprintf(fp, "%c", output[i]);
	}
	*andGate += (inputBitLength - dashCnt) * 2 + 2;
	fprintf(fp, "\n");
	return 1;
}