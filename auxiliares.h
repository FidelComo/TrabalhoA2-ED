#include <iostream>
using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

struct qNode
{
  struct Node* ptrPayload;
  struct qNode* ptrNext;
  struct qNode* ptrPrev;
};

struct Queue
{
  struct qNode* ptrFirst;
  struct qNode* ptrLast;
};

/*===================================================================*/
//Funçoes para Queues

struct qNode* newQNode(Node* ptrData)
{
    struct qNode* newNodePtr = (struct qNode*) malloc(sizeof(struct qNode));
    newNodePtr->ptrPayload = ptrData;
    newNodePtr->ptrNext = nullptr;
    newNodePtr->ptrPrev = nullptr;

    return newNodePtr;
}

void Push(struct Queue &queue, struct Node* ptrData)
{
    qNode* newNode = newQNode(ptrData);
  
    if (queue.ptrFirst != nullptr) 
    {
        queue.ptrFirst->ptrPrev = newNode;
        newNode->ptrNext = queue.ptrFirst;
    } else queue.ptrLast = newNode;
  
    queue.ptrFirst = newNode;
}

void Pop(struct Queue &queue)
{
    if (queue.ptrFirst == nullptr) return;
  
    qNode* oldNode = queue.ptrLast;
    
    queue.ptrLast = queue.ptrLast->ptrPrev;
    if (queue.ptrLast != nullptr) queue.ptrLast->ptrNext = nullptr;
    else queue.ptrFirst = nullptr;

    free(oldNode);
}

/*===================================================================*/
//Funçoes para Trees

struct Node* newNode(int iData)
{
    struct Node* newNodePtr = (struct Node*) malloc(sizeof(struct Node));
    newNodePtr->iPayload = iData;
    newNodePtr->ptrLeft = nullptr;
    newNodePtr->ptrRight = nullptr;

    return newNodePtr;
}

struct Node* insertNode(struct Node* root, int iData)
{
    if (root == nullptr) return newNode(iData);

    if (iData < root->iPayload) root->ptrLeft = insertNode(root->ptrLeft, iData);
    else root->ptrRight = insertNode(root->ptrRight, iData);

    return root;
}

void traverseInOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) return;

    traverseInOrder(ptrStartingNode->ptrLeft);
    cout << " " << ptrStartingNode->iPayload;
    traverseInOrder(ptrStartingNode->ptrRight);
}

struct Node* lesserLeaf(struct Node* node)
{
    struct Node* ptrCurrent = node;

    while(ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;

    return ptrCurrent;
}

void swapNodes(Node* &node1, Node* &node2)
{
    Node* temp = node1->ptrRight;
    node1->ptrRight = node2->ptrRight;
    if (temp != node2 or temp == nullptr) node2->ptrRight = temp;
    else node2->ptrRight = node1;

    temp = node1->ptrLeft;
    node1->ptrLeft = node2->ptrLeft;
    if (temp != node2 or temp == nullptr) node2->ptrLeft = temp;
    else node2->ptrLeft = node1;

    temp = node1;
    node1 = node2;
    node2 = temp;

    temp = node1->ptrRight;
    while (temp->ptrLeft != node1 and temp->ptrLeft != nullptr) temp = temp->ptrLeft;
    if (temp->ptrLeft != nullptr) temp->ptrLeft = node2;

    return;
}

struct Node* deleteNode(struct Node* root, int iData)
{
    if (root == nullptr) return root;

    if (iData < root->iPayload) root->ptrLeft = deleteNode(root->ptrLeft, iData);
    else if (iData > root->iPayload) root->ptrRight = deleteNode(root->ptrRight, iData);

    else
    {
        struct Node* temp = nullptr;

        if (root->ptrLeft == nullptr)
        {
            temp = root->ptrRight;
            free(root);

            return temp;
        }
        else if (root->ptrRight == nullptr)
        {
            temp = root->ptrLeft;
            free(root);

            return temp;
        }

        temp = lesserLeaf(root->ptrRight);

        swapNodes(root, temp);

        root->ptrRight = deleteNode(root->ptrRight, temp->iPayload);
    }
    return root;
}

struct Node* searchNode(struct Node* node, int iData)
{
    if (node == nullptr) return nullptr;

    else if (node->iPayload == iData) return node;

    else if (iData < node->iPayload) return searchNode(node->ptrLeft, iData);
    return searchNode(node->ptrRight, iData);
}

int height(struct Node* ptrStartingNode)
{
  if (ptrStartingNode == nullptr) return 0;

  int iLeft = height(ptrStartingNode->ptrLeft);
  int iRight = height(ptrStartingNode->ptrRight);

  return max(iLeft, iRight) + 1;
}

// Fun�o para calcular o tamanho da �rvore
int calculateTreeSize(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int ptrLeftSize = calculateTreeSize(root->ptrLeft);
        int ptrRightSize = calculateTreeSize(root->ptrRight);

        return ptrLeftSize + ptrRightSize + 1;
    }
}

void traverseBFS(Node* root)
{
  if (root == nullptr) return;
  
  Node* lastNode = nullptr;
  Queue queue = {
  nullptr,
  nullptr
  };
  Push(queue, root);

  int iLevelNodes = 1;
  int iPrintedNodes = 0;

  while (queue.ptrFirst != nullptr)
  {
    lastNode = queue.ptrLast->ptrPayload;

    // O ultimo no guardado na queue é exibido e os seus galhos sao guardados de ezquera a dereita na queue mantendo a ordem desejada
    if (lastNode != nullptr) 
    {
      cout << lastNode->iPayload << " ";
      Push(queue, lastNode->ptrLeft);
      Push(queue, lastNode->ptrRight);
      iPrintedNodes++;
    } else iLevelNodes--;
    
    Pop(queue);

    // Quando o numero de nos exibidos iguala o numero de nos no nivel, um novo nivel é atingido
    if (iPrintedNodes == iLevelNodes)
    {
      cout << endl;
      iLevelNodes = iPrintedNodes * 2;
      iPrintedNodes = 0;
    }
  }
}

void printList(Node* ptrHead) 
{
    Node* ptrCurrent = ptrHead;
    while (ptrCurrent != nullptr) 
    {
        cout << ptrCurrent->iPayload << " ";
        ptrCurrent = ptrCurrent->ptrRight;
    } cout << endl;
}

Node* mergeSortedList(Node* ptrHead1, Node* ptrHead2) 
{
    if (ptrHead1 == nullptr) return ptrHead2;
    if (ptrHead2 == nullptr) return ptrHead1;

    Node* ptrMerged_list = nullptr;
    
    if (ptrHead1->iPayload <= ptrHead2->iPayload) 
    {
        ptrMerged_list = ptrHead1;
        ptrMerged_list->ptrRight = mergeSortedList(ptrHead1->ptrRight, ptrHead2);
    } 
    else 
    {
        ptrMerged_list = ptrHead2;
        ptrMerged_list->ptrRight = mergeSortedList(ptrHead1, ptrHead2->ptrRight);
    }
    if (ptrMerged_list->ptrRight != nullptr) ptrMerged_list->ptrRight->ptrLeft = ptrMerged_list;
    
    return ptrMerged_list;
}

void splitList(Node* ptrSource, Node** ptrFront, Node** ptrBack) 
{
    if (ptrSource == nullptr || ptrSource->ptrRight == nullptr) 
    {
        *ptrFront = ptrSource;
        *ptrBack = nullptr;
        return;
    }

    Node* ptrSlow = ptrSource;
    Node* ptrFast = ptrSource->ptrRight;

    while (ptrFast != nullptr) 
    {
        ptrFast = ptrFast->ptrRight;
        if (ptrFast != nullptr) 
        {
            ptrSlow = ptrSlow->ptrRight;
            ptrFast = ptrFast->ptrRight;
        }
    }

    *ptrFront = ptrSource;
    *ptrBack = ptrSlow->ptrRight;
    ptrSlow->ptrRight = nullptr;
    if (*ptrBack != nullptr) (*ptrBack)->ptrLeft = nullptr;
}