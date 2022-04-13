#include <stdio.h>

#include "linkedlist.h"
#include "step.h"

// 비교 완성

void step2To3(int GroupCnt, Node** groups) {
	printf("=============== Step 2 Start ===============\n");
	Node** newGroups = malloc(sizeof(Node*) * 5);
	for (int i = 0; i <= 4; i++) {
		newGroups[i] = LinkedList();
	}
	CompareGroups(groups[2], groups[3], 2, newGroups);
	printAllNode(groups[2]);
	printAllNodeWithDash(newGroups[2]);
}


void CompareGroups(Node* Group1, Node* Group2, int stdIndex, Node** newGroups) {
	int n = 0;
	Node* current1;
	Node* current2;
	Node* addedNode;
	current1 = Group1->next;
	while (current1 != NULL) {
		printf("current1 : %d\n", current1->data);
		current2 = Group2->next;
		while (current2 != NULL) {
			printf("  current2 : %d\n", current2->data);
			n = current1->data - current2->data;
			if (n < 0) {
				n = -n;
			}
				if ((n & (n - 1)) == 0) {
					printf("  Okay %d, ", stdIndex);
					addedNode = addNode(newGroups[stdIndex], current1->data);
					addedNode->dashData = n;
					printf("Dash Data : %i\n", n);
					current1->checked = true;
					current2->checked = true;
				}
				current2 = current2->next;
		}
		current1 = current1->next;
	}
}