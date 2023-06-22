#include "auxiliares.h"

Node* constroi_txt()
{
  return nullptr;
}

Node* constroi_input()
{
  return nullptr;
}

int altura(Node* ptrHead)
{
  return 0;
}

int tamanho(Node* ptrHead)
{
  return 0;
}

Node* inserir(Node* ptrHead)
{
    int inputValue;

    std::cout << "Ensira um valor inteiro para entrar na árvore: ";
    std::cin >> inputValue;

    ptrHead = insertNode(ptrHead, inputValue);

    std::cout << inputValue << " inserido com sucesso na árvore!" << std::endl;

  return nullptr;
}

Node* remover(Node* ptrHead)
{
    int inputValue;

    std::cout << "Qual valor você gostaria de deletar da árvore: ";
    std::cin >> inputValue;

    ptrHead = deleteNode(ptrHead, inputValue);

    std::cout << inputValue << " Valor deletado com sucesso da árvore!" << std::endl;

  return nullptr;
}

Node* buscar(Node* ptrHead)
{
  return nullptr;
}

bool completa(Node* ptrHead)
{
  return 0;
}

bool perfeita(Node* ptrHead)
{
  return 0;
}

void exebe_BFS(Node* ptrHead)
{

}

Node* ordenar_Bubble(Node* ptrHead)
{
  return nullptr;
}

