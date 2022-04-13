#include <stdio.h>
#include "linkedlist.h"
#include "step.h"

// 비교 완성

void step2To3(int GroupCnt, Node** groups) {
	printf("=============== Step 2 Start ===============\n");
	Node** newGroups = malloc(sizeof(Node *) * GroupCnt);

	for (int i = 0; i <= GroupCnt; i++) {
		newGroups[i] = LinkedList();
	}

	for (int i = 4; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			printf("Before Compare ");
			printAllNode(groups[j - 1]);
			CompareGroups(groups[j - 1], groups[j], newGroups[j]);
			printf("Compared Original ");
			printAllNode(groups[j - 1]);
			printf("New ");
			printAllNode(newGroups[3]);
		}
	}

}


// Return N Group
void CompareGroups(Node* Group1, Node* Group2, Node* newGroup) {
	int n;
	Node* current1;
	Node* current2;
	Node* addedNode;
	Node* beforeNode; // 삭제를 위해서
	bool isChecked = false;
	current1 = Group1->next;
	beforeNode = Group1;
	while (current1 != NULL) {
		// printf("current1 : %d\n", current1->data);
		current2 = Group2->next;
		while (current2 != NULL) {
			// printf("  current2 : %d\n", current2->data);
			n = abs(current1->data - current2->data);
			if ((n & (n - 1)) == 0) {
				addedNode = addNode(newGroup, current1->data);
				addedNode->dashData = n;
				isChecked = true;
			}
			current2 = current2->next;
		}
		
		if (isChecked == true) {
			removeNode(beforeNode);
			isChecked = false;
			current1 = beforeNode->next;
		}
		else {
			beforeNode = current1;
			current1 = current1->next;
		}
	}
}