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

 /*
Node* a = LinkedList();
printf("%d", a->data);
addNode(a, 2);
addNode(a, 3);
addNode(a, 4);
Node* curr = a->next;
while (curr != NULL) {
	printf("%d ", curr->data);
	curr = curr->next;
}*/