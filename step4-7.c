#include <stdio.h>

#include "linkedlist.h"
#include "step.h"

void step4To7(Node* step2Result, Node* minterms, int row, int col) {
	Node** tables = (Node*)malloc(sizeof(Node) * row + 1);
	
	for (int y = 0; y < row + 1; y++) {
		tables[y] = LinkedList();
	}
	for (int x = 0; x < col + 1; x++) {
		addNode(tables[0], 0);
	}
	Node* current1 = step2Result->next;
	Node* current2 = minterms->next; 
	Node* tableX;
	Node* beforeXNode;
	Node* beforeYNode;
	int index = 1;
	while (current1 != NULL) {
		addNode(tables[index], 0);
		beforeYNode = tables[index - 1]->next;
		beforeXNode = tables[index]->next;
		current2 = minterms->next;
		while (current2 != NULL)
		{
			printf("test : %d %d\n", current1->data, current2->data);
			int data = checkX(current2->data, current1->data, current1->dashData);
			if (beforeYNode->data + data > beforeXNode->data) {
				addNode(tables[index], beforeYNode->data + data);
			}
			else {
				addNode(tables[index], beforeXNode->data + data);
			}
			current2 = current2->next;
			beforeXNode->next;
			beforeYNode->next;
		}
		
		index++;
		current1 = current1->next;
	}
	int pp = 1;
	current1 = step2Result->next;
	while (current1 != NULL) {
		printf("current1 : %d ", current1->data);
		printAllNode(tables[pp]);
		current1 = current1->next;
		pp++;
	}
 	
}

int checkX(int mintermData, int step2ResultData, int step2ResultDashData) {
	int equate = !(step2ResultDashData & mintermData);
	if (equate & step2ResultData == step2ResultData) {
		return 1;
	}
	return 0;
}