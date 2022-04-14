#define _CRT_SECURE_NO_WARNINGS

// Int형을 이용해서 최대 30개의 inputBitLength가 가능하다.
// 해결책은 Node의 데이터를 배열로 받아서 해결한다.

// Dash는 0로 표현하고 마지막 표에서 비교해줄때 &연산시 자기랑 같거나 크면 주항차트 X표시.
// 주항 차트 만들면서 줄에 몇개 있는 지 기록.


#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "step.h"

//입력받는 크기(파일의 첫 입력)에 따라 달라진다.


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
		step2Result = step2To3(4, groups);
		printf("============== Step 2 Succeed ==============\n\n");
		printf("=============== Step 3 Start ===============\n\n");
		step4To7(step2Result, minterms, 7, 5);
		printf("============== Step 3 Succeed ==============\n");
		
	}
	else {
		printf("============== Step 1 Failed. ==============\n\n");
	}
	printf("[ QuineMcCluskeyAlgorithm End ] ");
	return 0;
}
