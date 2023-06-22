#include <iostream>
#include <stdlib.h>
#include "items.h"

using namespace std;

void printMenu()
{
  cout << "Opções de uso: " << endl;
  int i = 1;
  cout << " " << i++ << ". Árvore a partir de um arquivo texto" << endl;
  cout << " " << i++ << ". Árvore a partir de dados digitados" << endl;
  cout << " " << i++ << ". Altura da árvore" << endl;
  cout << " " << i++ << ". Tamanho da árvore" << endl;
  cout << " " << i++ << ". Inserção de um elemento" << endl;
  cout << " " << i++ << ". Remoção de um elemento" << endl;
  cout << " " << i++ << ". Busca de um elemento" << endl;
  cout << " " << i++ << ". Verificar se a árvore é completa" << endl;
  cout << " " << i++ << ". Verificar se a árvore é perfeita" << endl;
  cout << i++ << ". Exibir a árvore" << endl;
  cout << i++ << ". Ordenar com Bubble Sort" << endl;
  cout << " 0. Sair" << endl;
}

void limparConsola()
{
  #if defined(__linux__) // Or #if __linux__
    system("clear");
  #elif _WIN32
    system("cls");
  #endif
}

void aguardarInput()
{
  #if defined(__linux__) // Or #if __linux__
    system("read -p 'Press Enter to continue...' var");
  #elif _WIN32
    system("pause");
  #endif
}

int main()
{
  Node* ptrHead = nullptr;
  int iOption = 0;
  
  while (true)
    {
      printMenu();
      cin >> iOption;
      limparConsola();
      
      switch(iOption) 
      {
        case 0:
          return 0;
        case 1:
          ptrHead = constroi_txt();
          break;
        case 2:
          ptrHead = constroi_input();
          break;
        case 3:
          cout << altura(ptrHead) << endl;
          break;
        case 4:
          cout << tamanho(ptrHead) << endl;
          break;
        case 5:
          ptrHead = inserir(ptrHead);
          break;
        case 6:
          ptrHead = remover(ptrHead);
          break;
        case 7:
          cout << buscar(ptrHead) << endl;
          break;
        case 8:
           cout << "A arvore " << ((completa(ptrHead)) ? "":"não ") << "é completa" << endl;
          break;
        case 9:
          cout << ((perfeita(ptrHead)) ? "A arvore é perfeita" : "A arvore não é perfeita") << endl;
          break;
        case 10:
          exebe_BFS(ptrHead);
          break;
        case 11:
          ptrHead = ordenar_Bubble(ptrHead);
          break;
      }
      aguardarInput();
      limparConsola();
    }
  
  return 0;
}