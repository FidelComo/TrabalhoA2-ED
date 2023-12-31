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
  cout << i++ << ". Converter e ordenar com Bubble Sort" << endl;
  cout << i++ << ". Converter e ordenar com Insertion Sort" << endl;
  cout << i++ << ". Converter e ordenar com Selection Sort" << endl;
  cout << i++ << ". Converter e ordenar com Merge Sort" << endl;
  cout << i++ << ". Converter e ordenar com Shell Sort" << endl;
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
  bool bValida = 1;
  double dbTempo = 0;
  
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
          ptrHead = constroi_txt(ptrHead, dbTempo);
          break;
        case 2:
          ptrHead = constroi_input(ptrHead, dbTempo);
          break;
        case 3:
          altura(ptrHead, dbTempo);
          break;
        case 4:
          tamanho(ptrHead, dbTempo);
          break;
        case 5:
          ptrHead = inserir(ptrHead, dbTempo);
          break;
        case 6:
          ptrHead = remover(ptrHead, dbTempo);
          break;
        case 7:
          buscar(ptrHead, dbTempo);
          break;
        case 8:
          completa(ptrHead, dbTempo);
          break;
        case 9:
          perfeita(ptrHead, dbTempo);
          break;
        case 10:
          exibe_BFS(ptrHead, dbTempo);
          break;
        case 11:
          ptrHead = sort_Bubble(ptrHead, dbTempo);
          break;
        case 12:
          ptrHead = sort_Insertion(ptrHead, dbTempo);
          break;
        case 13:
          ptrHead = sort_Selection(ptrHead, dbTempo);
          break;
        case 14:
          ptrHead = sort_Merge(ptrHead, dbTempo);
          break;
        case 15:
          ptrHead = sort_Shell(ptrHead, dbTempo);
          break;
        default:
          bValida = 0;
      }
      if (bValida)
      {
        dbTempo *= 1e-09;
        cout << "Tempo de execução: " << dbTempo << "s" << endl;
        aguardarInput();
        limparConsola();
      }
      bValida = 1;
    }

  ptrHead = deleteTree(ptrHead);
  
  return 0;
}