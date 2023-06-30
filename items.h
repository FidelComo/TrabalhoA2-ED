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

Node* sort_Bubble(Node* ptrHead, double dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  //Operação
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return ptrHead;
}

Node* sort_Insertion(Node* ptrHead, double dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  //Operação
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return ptrHead;
}

Node* sort_Selection(Node* ptrHead, double dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  //Operação
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return ptrHead;
}

Node* sort_Merge(Node* ptrHead, double dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  
  //Operação
  
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();

  return ptrHead;
}