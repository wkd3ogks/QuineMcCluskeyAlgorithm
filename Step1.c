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
			// 배열로 반복문을 파일에서 데이터 받아오는 반복문과 합칠 수 있다.
			for (int i = 0; i <= *inputBitLength; i++) {
				// 그룹 배열 링크드 리스트 제작
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
	// 의미상 가장 최상위 비트는 모드를 의미한다.(1이면 Don't Care) ex. InputBitLength = 4 -> 2^5에서 모드를 결정함.

	int mode = inputData[0];
	int i, oneCnt = 0, decimal = 0, squareOf2 = 1;

	// 이진수를 십진수로 변환
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
	TODO : 그룹에 추가
	링크드 리스트를 이용하고 각 시작노드를 기억하고 있기

	링크드 리스트 사용 장점..
	1. 주항 차트를 만들어갈때 복사과정 필요 X.(헤드의 주소만 마지막에 바꾸면 되므로)
	2. 파일의 총 길이를 몰라도 된다.(불필요한 반복문 제거)
	3. 데이터 추가가 자유로워 값을 이동할 일이 없다.
	-> 배열보다 링크드 리스트를 이용하는 것이 더 효율적이다. (주항 차트를 구할때)
	4. 접근도 순차적으로 이루어진다.
	*/
	assignToGroup(groups, oneCnt, decimal);

	return decimal;
}

void assignToGroup(Node** groups, int oneCnt, int data) {
	addNode(groups[oneCnt], data);
	// printf("Groups %d : %d", oneCnt, groups[oneCnt]->next->data);
}

// 패트릭 매서드 그냥 없는 비트는 0 취급하고 있으면 1취급해준다음에 &연산하면 끝인거 같은데?? 아니네