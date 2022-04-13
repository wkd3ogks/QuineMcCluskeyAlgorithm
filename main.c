#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

//�Է¹޴� ũ��(������ ù �Է�)�� ���� �޶�����.
#define BUFFERSIZE 200

void getDataFromFile(int* inputBitLength);
void assignToGroup(Node** groups, int OneCnt);

int main(void) 
{
	int inputBitLength;

	getDataFromFile(&inputBitLength);



	return 0;
}


/* ��ũ�� ����Ʈ�� �̿�� �ʿ����.
int getFileLineLength() {
	FILE* fp;
	char buffer[BUFFERSIZE];
	int FileLineLength = 0;
	fp = fopen("input_minterm.txt", "r");
	if (fp != NULL) {
		printf("[ input_minterm.txt Open for Line Count Succeed ]\n");
		while (fgets(buffer, BUFFERSIZE, fp) != NULL) FileLineLength++;
		fclose(fp);
		printf("File Line Length : %i\n\n", FileLineLength);
		return FileLineLength;
	}
	else {
		printf("[ input_minterm.txt Open for Line Count Failed ]\n\n");
		return -1;
	}
}
*/


// �Ƹ� �׷��� ���� ������ �Լ��� �� �� ����.
void getDataFromFile(int* inputBitLength) {

	FILE* fp;
	char buffer[BUFFERSIZE];
	Node** groups;

	// TODO : binary ���� �����غ��� �͵� �����غ���.
	// ���� ����� ���� : https://robodream.tistory.com/158
	fp = fopen("input_minterm.txt", "r");
	int parsedData;
	if (fp != NULL) {
		printf("[ input_minterm.txt Open Succeed ]\n");
		if (fscanf(fp, "%d\n", inputBitLength) != 0) {
			printf("Input Bit Length : %i\n", *inputBitLength);

			groups = malloc(sizeof(Node* ) * (*inputBitLength + 1));
			for (int i = 0; i <= *inputBitLength; i++) {
				// �׷� �迭 ��ũ�� ����Ʈ ����
				groups[i] = LinkedList();
				// groups[i]->data = i + 1;
				//printf("Groups %d : %d\n", i, groups[i]->data);
			}

			while (fgets(buffer, BUFFERSIZE, fp) != NULL) {
				parsedData = parseBinaryData(groups, buffer, *inputBitLength);
				printf(">>> [Parse Data] : % d, [Original Data] %s\n", parsedData, buffer);
			}
			for (int i = 0; i <= *inputBitLength; i++) {
				printf("Groups[%i] ", i);
				printAllNode(groups[i]);
			}
		}
		else {
			printf("Error! No inputData about Bit Length");
		}
		fclose(fp);
	}
	else {
		printf("input_minterm.txt Open Failed\n");
	}
}


int parseBinaryData(Node** groups,char *inputData, int inputBitLength) {
	// �ǹ̻� ���� �ֻ��� ��Ʈ�� ��带 �ǹ��Ѵ�.(1�̸� Don't Care) ex. InputBitLength = 4 -> 2^5���� ��带 ������.

	int mode = inputData[0];
	int i, oneCnt = 0, decimal = 0, squareOf2 = 1;

	// �������� �������� ��ȯ
	for (i = inputBitLength + 1; i > 1; i--) {
		decimal += squareOf2 * (oneCnt += inputData[i] - 48);
		squareOf2 *= 2;
	}

	decimal = decimal | (squareOf2 * 2 * (mode == 'd' ? 1 : 0));

	/*
	TODO : �׷쿡 �߰�
	��ũ�� ����Ʈ�� �̿��ϰ� �� ���۳�带 ����ϰ� �ֱ�

	��ũ�� ����Ʈ ��� ����..
	1. ���� ��Ʈ�� ������ ������� �ʿ� X.(����� �ּҸ� �������� �ٲٸ� �ǹǷ�)
	2. ������ �� ���̸� ���� �ȴ�.(���ʿ��� �ݺ��� ����)
	3. ������ �߰��� �����ο� ���� �̵��� ���� ����.
	-> �迭���� ��ũ�� ����Ʈ�� �̿��ϴ� ���� �� ȿ�����̴�. (���� ��Ʈ�� ���Ҷ�)
	*/
	assignToGroup(groups, oneCnt, decimal);

	return decimal;
}

void assignToGroup(Node** groups, int oneCnt, int data) {
	addNode(groups[oneCnt], data);
	// printf("Groups %d : %d", oneCnt, groups[oneCnt]->next->data);
}

// ��Ʈ�� �ż��� �׳� ���� ��Ʈ�� 0 ����ϰ� ������ 1������ش����� &�����ϸ� ���ΰ� ������?? �ƴϳ�
