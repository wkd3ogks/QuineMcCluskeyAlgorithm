#include <stdbool.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node* next;
	int data;
	int dashData;
	bool checked;
} Node;

Node* LinkedList();

Node* addNode(Node* target, int data);
void printAllNode(Node* head);
void removeNode(Node* target);
void swapLinkedListArr(Node** head1, Node** head2);
void printAllNodeWithDash(Node* head);