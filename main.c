#define _CRT_SECURE_NO_WARNINGS

// Int���� �̿��ؼ� �ִ� 30���� inputBitLength�� �����ϴ�.
// �ذ�å�� Node�� �����͸� �迭�� �޾Ƽ� �ذ��Ѵ�.

// Dash�� 0�� ǥ���ϰ� ������ ǥ���� �����ٶ� &����� �ڱ�� ���ų� ũ�� ������Ʈ Xǥ��.
// ���� ��Ʈ ����鼭 �ٿ� � �ִ� �� ���.

//�̸� ���̺� ��ȣ ���̰� ��ȣ�� �°� ��� ���� ����, 0�� ����

//Cost ���ϴ� �κ��� �׸���� Ǯ �� ������ �׸���� �׷��� ���ϸ� DP��  


#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "step.h"

//�Է¹޴� ũ��(������ ù �Է�)�� ���� �޶�����.


int main(void) 
{
	int    inputBitLength;
	Node* minterms = LinkedList();
	Node** groups = step1(&inputBitLength, minterms);
	Node* step2Result;
	printf("[ QuineMcCluskeyAlgorithm Start ] \n\n");
	if (groups != NULL) {
		printf("============== Step 1 Succeed ==============\n\n");

		printf("=============== Step 2 Start ===============\n\n");
		step2Result = step2To3(4, groups, inputBitLength);
		printf("============== Step 2 Succeed ==============\n\n");
		printf("=============== Step 3 Start ===============\n\n");
		step4To7(step2Result, minterms);
		printf("============== Step 3 Succeed ==============\n");
		
	}
	else {
		printf("============== Step 1 Failed. ==============\n\n");
	}
	printf("[ QuineMcCluskeyAlgorithm End ] ");
	return 0;
}
