//그냥 머리 텅~ 한 척하고 구현만 완성하자... 귀찮아!
// 대쉬 데이터부분을 같은 값으로 조작하자.(& 연산과
// 대쉬데이터로 민텀을 조작 -> 그 데쉬 데이터만 0 나머지는 1인 값이 있을 때 1111(inputBitLength) - 대쉬 데이터(ex. 8) -> 0111 --> 민텀
#include <stdio.h>

#include "linkedlist.h"
#include "step.h"

void step4To7(Node* step2Result, Node* minterms) {
	printAllNode(step2Result);
	printAllNode(minterms);
}