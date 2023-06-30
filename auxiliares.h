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
//Funções para Queues

struct qNode* newQNode(Node* ptrData)
{
    struct qNode* ptrNewNode = (struct qNode*) malloc(sizeof(struct qNode));
    ptrNewNode->ptrPayload = ptrData;
    ptrNewNode->ptrNext = nullptr;
    ptrNewNode->ptrPrev = nullptr;

    return ptrNewNode;
}

void Push(struct Queue &queue, struct Node* ptrData)
{
    qNode* ptrNewNode = newQNode(ptrData);
  
    if (queue.ptrFirst != nullptr) 
    {
        queue.ptrFirst->ptrPrev = ptrNewNode;
        ptrNewNode->ptrNext = queue.ptrFirst;
    } 
    else queue.ptrLast = ptrNewNode;
  
    queue.ptrFirst = ptrNewNode;
}

void Pop(struct Queue &queue)
{
    if (queue.ptrFirst == nullptr) return;
  
    qNode* ptrOldNode = queue.ptrLast;
    
    queue.ptrLast = queue.ptrLast->ptrPrev;
    if (queue.ptrLast != nullptr) queue.ptrLast->ptrNext = nullptr;
    else queue.ptrFirst = nullptr;

    free(ptrOldNode);
}

/*===================================================================*/
//Funções para Trees

struct Node* newNode(int iData)
{
    struct Node* ptrNewNode = (struct Node*) malloc(sizeof(struct Node));
    ptrNewNode->iPayload = iData;
    ptrNewNode->ptrLeft = nullptr;
    ptrNewNode->ptrRight = nullptr;

    return ptrNewNode;
}

struct Node* insertNode(struct Node* ptrRoot, int iData)
{
    if (ptrRoot == nullptr) return newNode(iData);

    if (iData < ptrRoot->iPayload) ptrRoot->ptrLeft = insertNode(ptrRoot->ptrLeft, iData);
    else ptrRoot->ptrRight = insertNode(ptrRoot->ptrRight, iData);

    return ptrRoot;
}

void traverseInOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) return;

    traverseInOrder(ptrStartingNode->ptrLeft);
    cout << " " << ptrStartingNode->iPayload;
    traverseInOrder(ptrStartingNode->ptrRight);
}

struct Node* lesserLeaf(struct Node* ptrNode)
{
    struct Node* ptrCurrent = ptrNode;

    while(ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;

    return ptrCurrent;
}

void swapNodes(Node* &ptrNode1, Node* &ptrNode2)
{
    Node* ptrTemp = ptrNode1->ptrRight;
    ptrNode1->ptrRight = ptrNode2->ptrRight;
    if (ptrTemp != ptrNode2 or ptrTemp == nullptr) ptrNode2->ptrRight = ptrTemp;
    else ptrNode2->ptrRight = ptrNode1;

    ptrTemp = ptrNode1->ptrLeft;
    ptrNode1->ptrLeft = ptrNode2->ptrLeft;
    if (ptrTemp != ptrNode2 or ptrTemp == nullptr) ptrNode2->ptrLeft = ptrTemp;
    else ptrNode2->ptrLeft = ptrNode1;

    ptrTemp = ptrNode1;
    ptrNode1 = ptrNode2;
    ptrNode2 = ptrTemp;

    ptrTemp = ptrNode1->ptrRight;
    while (ptrTemp->ptrLeft != ptrNode1 and ptrTemp->ptrLeft != nullptr) ptrTemp = ptrTemp->ptrLeft;
    if (ptrTemp->ptrLeft != nullptr) ptrTemp->ptrLeft = ptrNode2;

    return;
}

struct Node* deleteNode(struct Node* ptrRoot, int iData)
{
    if (ptrRoot == nullptr) return ptrRoot;

    if (iData < ptrRoot->iPayload) ptrRoot->ptrLeft = deleteNode(ptrRoot->ptrLeft, iData);
    else if (iData > ptrRoot->iPayload) ptrRoot->ptrRight = deleteNode(ptrRoot->ptrRight, iData);
    else
    {
        struct Node* ptrTemp = nullptr;

        if (ptrRoot->ptrLeft == nullptr)
        {
            ptrTemp = ptrRoot->ptrRight;
            free(ptrRoot);

            return ptrTemp;
        }
        else if (ptrRoot->ptrRight == nullptr)
        {
            ptrTemp = ptrRoot->ptrLeft;
            free(ptrRoot);

            return ptrTemp;
        }

        ptrTemp = lesserLeaf(ptrRoot->ptrRight);

        swapNodes(ptrRoot, ptrTemp);

        ptrRoot->ptrRight = deleteNode(ptrRoot->ptrRight, ptrTemp->iPayload);
    }
    return ptrRoot;
}

struct Node* searchNode(struct Node* ptrNode, int iData)
{
    if (ptrNode == nullptr) return nullptr;

    else if (ptrNode->iPayload == iData) return ptrNode;

    else if (iData < ptrNode->iPayload) return searchNode(ptrNode->ptrLeft, iData);
    return searchNode(ptrNode->ptrRight, iData);
}

int height(struct Node* ptrStartingNode)
{
  if (ptrStartingNode == nullptr) return 0;

  int iLeft = height(ptrStartingNode->ptrLeft);
  int iRight = height(ptrStartingNode->ptrRight);

  return max(iLeft, iRight) + 1;
}

// Função para calcular o tamanho da árvore
int calculateTreeSize(Node* ptrRoot) 
{
    if (ptrRoot == nullptr) return 0;
    else 
    {
        int ptrLeftSize = calculateTreeSize(ptrRoot->ptrLeft);
        int ptrRightSize = calculateTreeSize(ptrRoot->ptrRight);

        return ptrLeftSize + ptrRightSize + 1;
    }
}

void traverseBFS(Node* ptrRoot)
{
  if (ptrRoot == nullptr) return;
  
  Node* ptrLastNode = nullptr;
  Queue queue = {
  nullptr,
  nullptr
  };
  Push(queue, ptrRoot);

  int iLevelNodes = 1;
  int iPrintedNodes = 0;

  while (queue.ptrFirst != nullptr)
  {
    ptrLastNode = queue.ptrLast->ptrPayload;

    // O último nó guardado na queue é exibido e os seus galhos são guardados da esquerda para a direita na queue mantendo a ordem desejada
    if (ptrLastNode != nullptr) 
    {
      cout << ptrLastNode->iPayload << " ";
      Push(queue, ptrLastNode->ptrLeft);
      Push(queue, ptrLastNode->ptrRight);
      iPrintedNodes++;
    } 
    else iLevelNodes--;
    
    Pop(queue);

    // Quando o número de nós exibidos iguala o número de nós no nível, um novo nível é atingido
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