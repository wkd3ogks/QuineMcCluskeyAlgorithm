#define _CRT_SECURE_NO_WARNINGS

// Int형을 이용해서 최대 30개의 inputBitLength가 가능하다.
// 해결책은 Node의 데이터를 배열로 받아서 해결한다.

// Dash는 0로 표현하고 마지막 표에서 비교해줄때 &연산시 자기랑 같거나 크면 주항차트 X표시.
// 주항 차트 만들면서 줄에 몇개 있는 지 기록.

//미리 테이블에 번호 붙이고 번호에 맞게 출력 형식 제작, 0의 개수

//Cost 구하는 부분은 그리디로 풀 수 있으면 그리디로 그렇지 못하면 DP로  


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
