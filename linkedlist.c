#include <stdio.h>

#include "linkedlist.h"

// head 뒤에 계속 추가된다. ㅁ-new-ㅁ
Node* addNode(Node* target, int data) {
	Node* newNode;
	if ((newNode = (Node *)malloc(sizeof(Node))) != NULL) {
		newNode->next = target->next;
		newNode->data = data;
		newNode->dashData = 0;
		newNode->checked = false;
		target->next = newNode;
		return newNode;
	}
	else {
		printf("[ ERROR ] Can't Add new Element in LinkedList (malloc Function Return NULL)\n");
		return NULL;
	}
}
Node* copyNode(Node* target, Node* object) {
	Node* newNode;
	if ((newNode = (Node*)malloc(sizeof(Node))) != NULL) {
		newNode->next = target->next;
		newNode->data = object->data;
		newNode->checked = object->checked;
		target->next = newNode;
		return newNode;
	}
	else {
		printf("[ ERROR ] Can't Add new Element in LinkedList (malloc Function Return NULL)\n");
		return NULL;
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
 void printAllNodeWithDash(Node* head) {
	 printf("[ Node Data ]\n");
	 Node* current = head->next;
	 while (current != NULL) {
		 printf("Data : %d, DashData : %d\n", current->data, current->dashData);
		 current = current->next;
	 }
	 printf("\n");
 }

 void removeNode(Node* target)    // 기준 노드의 다음 노드를 삭제하는 함수
 {
	 Node* removeNode = target->next;    // 기준 노드의 다음 노드 주소를 저장
	 if (removeNode != NULL) {
		 target->next = removeNode->next;
	 }
	 else {
		 target->next = NULL;
	 }

	 free(removeNode);    // 노드 메모리 해제
 }

 
 void deleteLinkedList(Node* head) {
	 
	 Node* before = head;
	 Node* current = head->next;
	 while (current != NULL) {
		 before = current;
		 current = current->next;
		 free(before);
	 }
 }