#include <iostream>
#include "teatro.h"

using namespace std;


int main(){
    Teatro t(5, 10);
    short int menu;
    unsigned int linha, coluna;

    do{
        cout << "1 - Inserir" << endl;
        cout << "2 - Remover" << endl;
        cout << "3 - Exibir" << endl;
        cout << "4 - Redimensionar" << endl;
        cout << "5 - Sair" << endl;
        cin >> menu;

        switch(menu){
            case 1:
                cout << "Insere - Linha Coluna ex(0 5): ";
                cin >> linha >> coluna;
                t.insere(linha, coluna);
                break;
            case 2:
                cout << "Remove - Linha Coluna ex(0 5): ";
                cin >> linha >> coluna;
                t.remover(linha, coluna);
                break;
            case 3:
                t.exibir();
                break;
            case 4:
                cout << "Redimensionar - Linha Coluna ex(0 5): ";
                cin >> linha >> coluna;
                t.resize(linha, coluna);
                break;
        }

    }while(menu != 5);
    return 0;
}
