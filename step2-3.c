#include <stdio.h>

#include "linkedlist.h"
#include "step.h"



// 중복 제거 문제, 반복문 중단 위치 문제

Node* step2To3(int GroupCnt, Node** groups) {
	// 변수명은 같아도 내용물이 다르다~ 
	//printf("=============== Step 2 Start ===============\n");
	Node** newGroups = malloc(sizeof(Node*) * (GroupCnt+1));	
	Node* step2Result = LinkedList();
	//무조건 group의 개수가 2 될때까지 반복하는데 더 빠르게 할 방법 없을까?
	// 더 빠르게 할 방법은? 동적할당 해제 빠진건 없나?
	for (int decrease = 0; decrease < GroupCnt; decrease++) {
		for (int i = 0; i <= GroupCnt; i++) {
			newGroups[i] = LinkedList();
		}
		for (int i = 0; i < GroupCnt - decrease; i++) {
			CompareGroups(groups[i], groups[i+1], i, newGroups, step2Result);
			deleteLinkedList(groups[i]);
			groups[i]->next = newGroups[i]->next;
			if (i + 1 == GroupCnt - decrease) {
				addStep2Result(groups[i+1], step2Result);
			}
		}
		for (int i = 0; i <= GroupCnt; i++) {
			free(newGroups[i]);
		}
	}
	if (groups[0]->next != NULL) {
		addStep2Result(groups[0]->next, step2Result);
	}
	printAllNodeWithDash(step2Result);
	return step2Result;
}

// dash를 빼주면 처리 가능

void CompareGroups(Node* Group1, Node* Group2, int stdIndex, Node** newGroups, Node* step2Result) {
	//printf("Compare Group1 "); printAllNode(Group1);
	//printf("Compare Group2 "); printAllNode(Group2);
	int n = 0;
	Node* current1;
	Node* current2;
	Node* addedNode;
	current1 = Group1->next;
	while (current1 != NULL) {
		// printf("current1 : %d\n", current1->data);
		current2 = Group2->next;
		while (current2 != NULL) {
			// printf("  current2 : %d\n", current2->data);
			if ((current1->dashData == current2->dashData) && ((current1->data | current2->data) == current1->data || (current1->data | current2->data) == current2->data)) {
				n = current1->data - current2->data;
				if (n < 0) {
					n = -n;
				}
				if ((n & (n - 1)) == 0) {
					// printf("  Groups Index %d, ", stdIndex);
					//Current1->data 이기에 기본적으로 Dash는 0 값을 가진다.
					addedNode = addNode(newGroups[stdIndex], current1->data);
					//문제! 2의n승(중복 X)로 다른 조합의 덧셈으로 같은 값이 나오게 할 수 있을까? 정답!! 몰라~ 다른 값이 나오면 아래 +n 성립 X
					addedNode->dashData = current1->dashData + n;
					// printf("Dash Data : %i\n", n);
					current1->checked = true;
					current2->checked = true;
				}
			}
			current2 = current2->next;
		}
		current1 = current1->next;
	}
	addStep2Result(Group1, step2Result);
}

void addStep2Result(Node* Group, Node* step2Result) {
	Node* tmpCurrent = Group->next;
	Node* copy;
	while (tmpCurrent != NULL) {
		if ((tmpCurrent->checked) == false) {
			// printf("test : %d %d\n", tmpCurrent->data, tmpCurrent->dashData);
			copy = addNode(step2Result, tmpCurrent->data);
			copy->dashData = tmpCurrent->dashData;
			copy->checked = tmpCurrent->checked;
		}
		tmpCurrent = tmpCurrent->next;
	}
}