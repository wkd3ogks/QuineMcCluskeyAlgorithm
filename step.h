Node** step1(int* inputBitLength);
int parseBinaryData(Node** groups, char* inputData, int inputBitLength);
void assignToGroup(Node** groups, int OneCnt);

void step2To3(int GroupCnt, Node** groups);
void CompareGroups(Node* Group1, Node* Group2, int stdIndex, Node** newGroups);
