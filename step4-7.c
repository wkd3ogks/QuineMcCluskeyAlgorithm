#include <stdio.h>

#include "linkedlist.h"
#include "step.h"


//1. String1[n], String2[k]가 같다면 : [n, k] == [n-1, k-1] + 1
//2. String1[n], String2[k]가 다르면 : [n, k] == [n - 1, k]와[n, k - 1] 중 큰 값


void step4To7(Node* step2Result, Node* minterms, int row, int col) {
	Node** tables = (Node*)malloc(sizeof(Node) * row + 1);
	Node*** primeTables = (Node**)malloc(sizeof(Node *) * row + 1);

	for (int y = 0; y < row + 1; y++) {
		tables[y] = LinkedList();
		primeTables[y] = (Node* )malloc(sizeof(Node) * col + 1);
		for (int x = 0; x < col + 1; x++) {
			primeTables[y][x] = LinkedList();
		}
	}
	
	for (int x = 0; x < col + 1; x++) {
		addNode(tables[0], 0);
	}
	Node* current1 = step2Result->next;
	Node* current2 = minterms->next; 
	Node* beforeXNode;
	Node* beforeYNode;
	int indexY = 1;
	int indexX;
	while (current1 != NULL) {
		addNode(tables[indexY], 0);
		beforeYNode = tables[indexY - 1]->next;
		beforeXNode = tables[indexY]->next;
		current2 = minterms->next;
		indexX = 1;
		while (current2 != NULL)
		{
			printf("test : %d %d\n", current1->data, current2->data);
			int data = checkX(current2->data, current1->data, current1->dashData);
			if(data == 1) {
				printf("addNumber\tbeforeYNode data : %d\t\n", beforeYNode->data);
				addNode(tables[indexY], beforeYNode->data + 1);
				Node* curr = primeTables[indexY - 1][indexX - 1]->next;
				while (curr != NULL) {
					Node* more;
					more = addNode(primeTables[indexY][indexX], curr->data);
					more->dashData = curr->dashData;
					curr = curr->next;
				}
				Node* more;
				more = addNode(primeTables[indexY][indexX], current1->data);
				more->dashData = current1->dashData;
			}
			else {
				addNode(tables[indexY], beforeXNode->data > beforeYNode->data ? beforeXNode->data : beforeYNode->data);
				if (beforeXNode->data > beforeYNode->data) {
					Node* curr = primeTables[indexY][indexX - 1]->next;
					while (curr != NULL) {
						Node* more;
						more = addNode(primeTables[indexY][indexX], curr->data);
						more->dashData = curr->dashData;
						curr = curr->next;
					}
				}
				else {
					Node* curr = primeTables[indexY - 1][indexX - 1]->next;
					while (curr != NULL) {
						Node* more;
						more = addNode(primeTables[indexY][indexX], curr->data);
						more->dashData = curr->dashData;
						curr = curr->next;
					}
				}
			}
			current2 = current2->next;
			beforeXNode->next;
			beforeYNode->next;
			indexX++;
		}
		
		indexY++;
		current1 = current1->next;
	}
	int pp = 0;
	current1 = step2Result;
	while (current1 != NULL) {
		printf("current1 : %d ", current1->data);
		printAllNode(tables[pp]);
		current1 = current1->next;
		pp++;
	}
 	
}

int checkX(int mintermData, int step2ResultData, int step2ResultDashData) {
	unsigned int equate = (~step2ResultDashData) & mintermData;
	if (equate == step2ResultData) {
		return 1;
	}
	return 0;
}