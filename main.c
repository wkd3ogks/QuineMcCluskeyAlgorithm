#define _CRT_SECURE_NO_WARNINGS

// Int���� �̿��ؼ� �ִ� 31���� inputBitLength�� �����ϴ�.
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
	Node** groups = step1(&inputBitLength);

	printf("[ QuineMcCluskeyAlgorithm Start ] \n\n");
	if (groups != NULL) {
		printf("============== Step 1 Succeed ==============\n\n");
	}
	else {
		
		printf("============== Step 1 Failed. ==============\n\n");
	}
	printf("[ QuineMcCluskeyAlgorithm End ] ");
	return 0;
}


