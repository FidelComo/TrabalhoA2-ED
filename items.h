#include <chrono>
#include <fstream>
#include "auxiliares.h"

Node* constroi_txt(Node* ptrRoot, double &dbTempo)
{
  ifstream file;
  string strFileName = "";
  int iElement = 0;
  
  cout << "Digite o nome do arquivo: (0 Para sair)" << endl;

  // Pedir para o usuário o nome do arquivo até ele fornecer um nome válido
  while (!file.is_open())
  {
    cin >> strFileName;
    if (strFileName == "0") return ptrRoot;
    file.open(strFileName);
  }

  // Se já existir uma árvore, ela será deletada
  if (ptrRoot != nullptr) ptrRoot = deleteTree(ptrRoot);
    
  auto start = chrono::high_resolution_clock::now();
  
  while (file >> iElement) ptrRoot = insertNode(ptrRoot, iElement);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
  
  file.close();
  
  return ptrRoot;
}

Node* constroi_input(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  if (ptrHead != nullptr) ptrHead = deleteTree(ptrHead);
  ptrHead = buildTreeImput(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return ptrHead;
}

void altura(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();

  int iAltura = height(ptrHead);

  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  cout << "A altura da sua árvore é: " << iAltura << endl;
}

void tamanho(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  int iSize = calculateTreeSize(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  std::cout << "O tamanho da sua árvore é: " << iSize << std::endl;
}

Node* inserir(Node* ptrHead, double &dbTempo)
{
  int iInputValue;

  std::cout << "Insira um valor inteiro para entrar na árvore: ";
  std::cin >> iInputValue;

  auto start = chrono::high_resolution_clock::now();
  
  ptrHead = insertNode(ptrHead, iInputValue);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  std::cout << iInputValue << " inserido com sucesso na árvore!" << std::endl;
  return ptrHead;
}

Node* remover(Node* ptrHead, double &dbTempo)
{
  int iInputValue;

  std::cout << "Qual valor você gostaria de deletar da árvore? ";
  std::cin >> iInputValue;

  auto start = chrono::high_resolution_clock::now();
  
  ptrHead = deleteNode(ptrHead, iInputValue);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  std::cout << iInputValue << " Valor deletado com sucesso da árvore!" << std::endl;
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

void completa(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  int iAltura = height(ptrHead);
  bool bCompleta = isLevelFull(ptrHead, iAltura - 1);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
  
  cout << "A sua árvore " << ((!bCompleta) ? "não " : "") << "é completa" << endl;
}

void perfeita(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  int iAltura = height(ptrHead);
  bool bPerfeita = isLevelFull(ptrHead, iAltura);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
  
  cout << "A sua árvore " << ((!bPerfeita) ? "não " : "") << "é perfeita" << endl;
}

void exibe_BFS(Node* ptrHead, double &dbTempo)
{
  cout << "A sua árvore: " << endl;
  
  auto start = chrono::high_resolution_clock::now();
  
  traverseBFS(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
}

Node* sort_Bubble(Node* ptrHead, double dbTempo)
{
  Node** ptrHead2 = &ptrHead;
  auto start = chrono::high_resolution_clock::now();

  convertTree(ptrHead, ptrHead2);
  MergeSort(ptrHead2);
  convertList(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  cout << "Árvore ordenada: " << endl;
  printList(ptrHead);

  return ptrHead;
}

Node* sort_Insertion(Node* ptrHead, double dbTempo)
{ 
  auto start = chrono::high_resolution_clock::now();

  convertTree(ptrHead, &ptrHead);
  InsertionSort(&ptrHead);
  convertList(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  cout << "Árvore ordenada: " << endl;
  printList(ptrHead);

  return ptrHead;
}

Node* sort_Selection(Node* ptrHead, double dbTempo)
{
  Node** ptrHead2 = &ptrHead;
  auto start = chrono::high_resolution_clock::now();

  convertTree(ptrHead, ptrHead2);
  SelectionSort(ptrHead2);
  convertList(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  cout << "Árvore ordenada: " << endl;
  printList(ptrHead);

  return ptrHead;
}

Node* sort_Merge(Node* ptrHead, double dbTempo)
{
  Node** ptrHead2 = &ptrHead;
  auto start = chrono::high_resolution_clock::now();

  convertTree(ptrHead, ptrHead2);
  MergeSort(ptrHead2);
  convertList(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  cout << "Árvore ordenada: " << endl;
  printList(ptrHead);

  return ptrHead;
}

Node* sort_Shell(Node* ptrHead, double dbTempo)
{
  auto start = chrono::high_resolution_clock::now();

  int iTamanho = calculateTreeSize(ptrHead);
  convertTree(ptrHead, &ptrHead);
  ptrHead = shellSort(ptrHead, iTamanho);
  convertList(ptrHead);
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  cout << "Árvore ordenada: " << endl;
  printList(ptrHead);

  return ptrHead;
}