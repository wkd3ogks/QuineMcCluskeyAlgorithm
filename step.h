Node** step1(int* inputBitLength);
int parseBinaryData(Node** groups, char* inputData, int inputBitLength);
void assignToGroup(Node** groups, int OneCnt);

Node* step2To3(int GroupCnt, Node** groups);
void addStep2Result(Node* Group, Node* step2Result);
void CompareGroups(Node* Group1, Node* Group2, int stdIndex, Node** newGroups, Node* step2Result);
