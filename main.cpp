#include <iostream>
#include "items.h"

using namespace std;

void printMenu()
{
  cout << "Opções de uso: " << endl;
  int i = 1;
  cout << " " << i++ << ". " << endl;
  cout << " " << i++ << ". " << endl;
  cout << " " << i++ << ". " << endl;
  cout << " " << i++ << ". " << endl;
  cout << " " << i++ << ". " << endl;
  cout << " " << i++ << ". " << endl;
  cout << " " << i++ << ". " << endl;
  cout << " " << i++ << ". " << endl;
  cout << " " << i++ << ". " << endl;
  cout << i++ << ". " << endl;
  cout << i++ << ". " << endl;
  cout << " 0. Sair" << endl;
}

int main()
{
  Node* ptrHead = nullptr;

  bool bExit = 0;
  int iOption = 0;
  
  while (!bExit)
    {
      printMenu();
      cin >> iOption;

      switch(iOption) 
      {
        case 0:
          bExit = 1;
          break;
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
          cout << ((completa(ptrHead)) ? "A arvore é completa" : "A arvore não é completa") << endl;
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
    }
  
  return 0;
}