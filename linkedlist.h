#include <stdlib.h>

typedef struct _Node {
	struct _Node* next;
	int data;
} Node;

void addNode(Node* target, int data);
Node* LinkedList();
void printAllNode(Node*);
