#include <chrono>
#include "auxiliares.h"

Node* constroi_txt(double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return nullptr;
}

Node* constroi_input(double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return nullptr;
}

void altura(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();

  int iAltura = height(ptrHead);

  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  cout << "Altura da sua árvore: " << iAltura << endl;
}

void tamanho(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  int iSize = calculateTreeSize(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  std::cout << "O tamanho da árvore é: " << iSize << std::endl;
}

Node* inserir(Node* ptrHead, double &dbTempo)
{
  int inputValue;

  std::cout << "Ensira um valor inteiro para entrar na �rvore: ";
  std::cin >> inputValue;

  auto start = chrono::high_resolution_clock::now();
  
  ptrHead = insertNode(ptrHead, inputValue);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  std::cout << inputValue << " inserido com sucesso na �rvore!" << std::endl;
  return ptrHead;
}

Node* remover(Node* ptrHead, double &dbTempo)
{
  int inputValue;

  std::cout << "Qual valor voc� gostaria de deletar da �rvore: ";
  std::cin >> inputValue;

  auto start = chrono::high_resolution_clock::now();
  
  ptrHead = deleteNode(ptrHead, inputValue);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  std::cout << inputValue << " Valor deletado com sucesso da �rvore!" << std::endl;
  return ptrHead;
}

Node* buscar(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return nullptr;
}

bool completa(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return 0;
}

bool perfeita(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return 0;
}

void exebe_BFS(Node* ptrHead, double &dbTempo)
{
  cout << "A sua árvore: " << endl;
  
  auto start = chrono::high_resolution_clock::now();
  
  traverseBFS(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
}

void converte(Node* ptrRoot, Node** ptrHead)
{
  if (ptrRoot == nullptr) return;
  // Nó visitado anteriormente
  static Node* ptrPrev = nullptr;
 
  //Converte a sub árvore a esquerda
  converte(ptrRoot->ptrLeft, ptrHead);
 
  if (ptrPrev == nullptr) *ptrHead = ptrRoot;
  else
  {
    ptrRoot->ptrLeft = ptrPrev;
    ptrPrev->ptrRight = ptrRoot;
  }
  ptrPrev = ptrRoot;
 
  //Converte a sub árvore a direita
  converte(ptrRoot->ptrRight, ptrHead);
}

void BubbleSort(Node** ptrHead, double &dbTempo) 
{
  auto start = chrono::high_resolution_clock::now();

  if (*ptrHead == nullptr || (*ptrHead)->ptrRight == nullptr) return;

  Node* ptrLast = nullptr;
    
  while (ptrLast != (*ptrHead)->ptrRight) 
  {
    Node* ptrCurrent = *ptrHead;
        
    while (ptrCurrent->ptrRight != ptrLast) 
    {
      if (ptrCurrent->iPayload > ptrCurrent->ptrRight->iPayload) swapNodes(ptrCurrent, ptrCurrent->ptrRight);
      ptrCurrent = ptrCurrent->ptrRight;
    } 
    ptrLast = ptrCurrent;
  }
  printList(*ptrHead);

  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
}

void InsertionSort(Node** ptrHead, double &dbTempo) 
{
  auto start = chrono::high_resolution_clock::now();

  if (*ptrHead == nullptr || (*ptrHead)->ptrRight == nullptr) return;

  Node* ptrList_sorted = nullptr;
  Node* ptrCurrent = *ptrHead;
    
  while (ptrCurrent != nullptr) 
  {
    Node* ptrNext_node = ptrCurrent->ptrRight;
        
    if (ptrList_sorted == nullptr || ptrCurrent->iPayload < ptrList_sorted->iPayload) 
    {
      // Insere o nó no início da lista ordenada
      ptrCurrent->ptrLeft = nullptr;
      ptrCurrent->ptrRight = ptrList_sorted;
      if (ptrList_sorted != nullptr) ptrList_sorted->ptrLeft = ptrCurrent;
      ptrList_sorted = ptrCurrent;
    } 
    else 
    {
      // Procura a posição correta para inserir o nó na lista ordenada
      Node* ptrSearch = ptrList_sorted;
            
      while (ptrSearch->ptrRight != nullptr && ptrCurrent->iPayload >= ptrSearch->ptrRight->iPayload) ptrSearch = ptrSearch->ptrRight;
            
      ptrCurrent->ptrLeft = ptrSearch;
      ptrCurrent->ptrRight = ptrSearch->ptrRight;
      if (ptrSearch->ptrRight != nullptr) ptrSearch->ptrRight->ptrLeft = ptrCurrent;
      ptrSearch->ptrRight = ptrCurrent;
    }
    ptrCurrent = ptrNext_node;
  }
  *ptrHead = ptrList_sorted;
  printList(*ptrHead);

  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
}

void SelectionSort(Node** ptrHead, double &dbTempo) 
{
  auto start = chrono::high_resolution_clock::now();

  if (*ptrHead == nullptr || (*ptrHead)->ptrRight == nullptr) return;

  Node* ptrCurrent = *ptrHead;
  while (ptrCurrent != nullptr) 
  {
    Node* ptrMin_node = ptrCurrent;
    Node* ptrSearch = ptrCurrent->ptrRight;
        
    while (ptrSearch != nullptr) 
    {
      if (ptrSearch->iPayload < ptrMin_node->iPayload) ptrMin_node = ptrSearch;
      ptrSearch = ptrSearch->ptrRight;
    }
    swapNodes(ptrCurrent, ptrMin_node);
    ptrCurrent = ptrCurrent->ptrRight;
  }
  printList(*ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
}

void MergeSort(Node** ptrHead) 
{
    auto start = chrono::high_resolution_clock::now();

    if (*ptrHead == nullptr || (*ptrHead)->ptrRight == nullptr) return;
    
    Node* ptrFront = nullptr;
    Node* ptrBack = nullptr;
    // Divide a lista em duas partes
    splitList(*ptrHead, &ptrFront, &ptrBack);
    
    // Ordena as duas partes da lista recursivamente
    MergeSort(&ptrFront);
    MergeSort(&ptrBack);
    
    // Mescla as duas partes ordenadas
    *ptrHead = mergeSortedList(ptrFront, ptrBack);
    if (*ptrHead != nullptr) (*ptrHead)->ptrLeft = nullptr;
}