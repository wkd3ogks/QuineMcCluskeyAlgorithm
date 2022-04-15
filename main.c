#define _CRT_SECURE_NO_WARNINGS

// Int���� �̿��ؼ� �ִ� 30���� inputBitLength�� �����ϴ�.
// �ذ�å�� Node�� �����͸� �迭�� �޾Ƽ� �ذ��Ѵ�.

// Dash�� 0�� ǥ���ϰ� ������ ǥ���� �����ٶ� &����� �ڱ�� ���ų� ũ�� ������Ʈ Xǥ��.
// ���� ��Ʈ ����鼭 �ٿ� � �ִ� �� ���.


#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "step.h"

//�Է¹޴� ũ��(������ ù �Է�)�� ���� �޶�����.


int main(void) 
{
	int    inputBitLength;
	int rsltCol = 0;
	int rsltRow = 0;
	Node* minterms = LinkedList();
	Node** groups = step1(&inputBitLength, minterms);
	Node* step2Result;
	printf("[ QuineMcCluskeyAlgorithm Start ] \n\n");
	if (groups != NULL) {
		printf("============== Step 1 Succeed ==============\n\n");

		printf("=============== Step 2 Start ===============\n\n");
		step2Result = step2To3(inputBitLength, groups);
		Node* curr = step2Result->next;
		while (curr != NULL) {
			rsltRow += 1;
			curr = curr->next;
		}
		//printf("rsltRow : %d\n", rsltRow);
		curr = minterms->next;
		while (curr != NULL) {
			rsltCol += 1;
			curr = curr->next;
		}
		//printf("rsltCol : %d\n", rsltCol);
		
		printf("============== Step 2 Succeed ==============\n\n");
		printf("=============== Step 3 Start ===============\n\n");
		step4To7(step2Result, minterms, rsltRow, rsltCol, inputBitLength);
		printf("============== Step 3 Succeed ==============\n");
		
	}
	else {
		printf("============== Step 1 Failed. ==============\n\n");
	}
	printf("[ QuineMcCluskeyAlgorithm End ] ");
	return 0;
}
