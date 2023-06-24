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

int altura(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
  
  return 0;
}

int tamanho(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
  
  return 0;
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
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
}

Node* ordenar_Bubble(Node* ptrHead, double &dbTempo)
{
  auto start = chrono::high_resolution_clock::now();
  //Inserir operação
  auto end = chrono::high_resolution_clock::now();
  dbTempo = chrono::duration_cast < chrono::nanoseconds > (end - start).count();
  
  return nullptr;
}

