#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "linkedlist.h"
#include "step.h"

#define BUFFERSIZE 200

Node** step1(int* inputBitLength, Node* minterms) {
	printf("=============== Step 1 Start ===============\n");
	FILE* fp;
	char buffer[BUFFERSIZE];
	Node** groups;

	fp = fopen("input_minterm.txt", "r");
	int parsedData;
	if (fp != NULL) {
		printf("[ input_minterm.txt Open Succeed ]\n");
		if (fscanf(fp, "%d\n", inputBitLength) != 0) {
			printf("Input Bit Length : %i\n", *inputBitLength);

			groups = malloc(sizeof(Node*) * (*inputBitLength + 1));
			// �迭�� �ݺ����� ���Ͽ��� ������ �޾ƿ��� �ݺ����� ��ĥ �� �ִ�.
			for (int i = 0; i <= *inputBitLength; i++) {
				// �׷� �迭 ��ũ�� ����Ʈ ����
				groups[i] = LinkedList();
				// groups[i]->data = i + 1;
				//printf("Groups %d : %d\n", i, groups[i]->data);
			}

			while (fgets(buffer, BUFFERSIZE, fp) != NULL) {
				parsedData = parseBinaryData(groups, buffer, *inputBitLength, minterms);
				printf(">>> [Parse Data] : % d, [Original Data] %s\n", parsedData, buffer);
			}
			for (int i = 0; i <= *inputBitLength; i++) {
				printf("Groups[%i] ", i);
				printAllNode(groups[i]);
			}
			return groups;
		}
		else {
			printf("Error! No inputData about Bit Length");
		}
		fclose(fp);
	}
	else {
		printf("input_minterm.txt Open Failed\n");
	}
	return NULL;
}


int parseBinaryData(Node** groups, char* inputData, int inputBitLength, Node* minterms) {
	// �ǹ̻� ���� �ֻ��� ��Ʈ�� ��带 �ǹ��Ѵ�.(1�̸� Don't Care) ex. InputBitLength = 4 -> 2^5���� ��带 ������.

	int mode = inputData[0];
	int i, oneCnt = 0, decimal = 0, squareOf2 = 1;

	// �������� �������� ��ȯ
	for (i = inputBitLength + 1; i > 1; i--) { 
		oneCnt += inputData[i] - 48;
		decimal += squareOf2 * (inputData[i] - 48);
		squareOf2 *= 2;
	}
	if (mode == 'm') {
		addNode(minterms, decimal);
	}
	//decimal = decimal | (squareOf2 * (mode == 'd' ? 1 : 0));
	
	/*
	TODO : �׷쿡 �߰�
	��ũ�� ����Ʈ�� �̿��ϰ� �� ���۳�带 ����ϰ� �ֱ�

	��ũ�� ����Ʈ ��� ����..
	1. ���� ��Ʈ�� ������ ������� �ʿ� X.(����� �ּҸ� �������� �ٲٸ� �ǹǷ�)
	2. ������ �� ���̸� ���� �ȴ�.(���ʿ��� �ݺ��� ����)
	3. ������ �߰��� �����ο� ���� �̵��� ���� ����.
	-> �迭���� ��ũ�� ����Ʈ�� �̿��ϴ� ���� �� ȿ�����̴�. (���� ��Ʈ�� ���Ҷ�)
	4. ���ٵ� ���������� �̷������.
	*/
	assignToGroup(groups, oneCnt, decimal);

	return decimal;
}

void assignToGroup(Node** groups, int oneCnt, int data) {
	addNode(groups[oneCnt], data);
	// printf("Groups %d : %d", oneCnt, groups[oneCnt]->next->data);
}

// ��Ʈ�� �ż��� �׳� ���� ��Ʈ�� 0 ����ϰ� ������ 1������ش����� &�����ϸ� ���ΰ� ������?? �ƴϳ�