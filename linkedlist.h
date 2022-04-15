#include <stdbool.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node* next;
	int data;
	int dashData;
	bool checked;
} Node;

typedef struct _ENode {
	struct _Node* next;
	struct _Node* data;
	int dashData;
	bool checked;
} extendsNode;

Node* LinkedList();

Node* addNode(Node* target, int data);
extendsNode* addExtendsNode(Node* target, extendsNode* data);

Node* copyNode(Node* target, Node* object);

void printAllNode(Node* head);
void removeNode(Node* target);
void printAllNodeWithDash(Node* head);

void deleteLinkedList(Node* head);
//head 다음 요소들 삭제