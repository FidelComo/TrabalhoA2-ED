#include <iostream>
using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

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

// Função para calcular o tamanho da árvore
int calculateTreeSize(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int ptrLeftSize = calculateTreeSize(root->ptrLeft);
        int ptrRightSize = calculateTreeSize(root->ptrRight);

        return ptrLeftSize + ptrRightSize + 1;
    }
}
