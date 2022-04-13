#include <stdio.h>

#include "linkedlist.h"

// head 뒤에 계속 추가된다. ㅁ-new-ㅁ
void addNode(Node* target, int data) {
	Node* newNode;;
	if ((newNode = (Node *)malloc(sizeof(Node))) != NULL) {
		newNode->next = target->next;
		newNode->data = data;
		target->next = newNode;
	}
	else {
		printf("[ ERROR ] Can't Add new Element in LinkedList (malloc Function Return NULL)\n");
	}

}

 Node* LinkedList() {
	 Node* head;
	 if ((head = (Node*)malloc(sizeof(Node))) != NULL) {
		 head->next = NULL;
		 head->data = 0;
		 return head;
	 }
	 else {
		 printf("[ ERROR ] Can't make LinkedList (malloc Function Return NULL)\n");
		 return NULL;
	 }

 }

 void printAllNode(Node* head) {
	 printf("Node Data : ");
	 Node* current = head->next;
	 while (current != NULL) {
		 printf("%d ", current->data);
		 current = current->next;
	 }
	 printf("\n");
 }

 /*

}*/