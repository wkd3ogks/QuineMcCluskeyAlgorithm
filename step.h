Node** step1(int* inputBitLength, Node* minterms);
int parseBinaryData(Node** groups, char* inputData, int inputBitLength, Node* minterms);
void assignToGroup(Node** groups, int oneCnt, int data);

Node* step2To3(int GroupCnt, Node** groups);
void addStep2Result(Node* Group, Node* step2Result);
void CompareGroups(Node* Group1, Node* Group2, int stdIndex, Node** newGroups, Node* step2Result);


void step4To7(Node* step2Result, Node* minterms);