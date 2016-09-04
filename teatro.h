#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED

#include <iostream>

struct Teatro{
    bool *cadeiras = nullptr;
    int contador;

    unsigned maxLinha, maxColuna, totalCadeiras;

    Teatro(int linha, int coluna);
    void resize(int linha, int coluna);
    void insere(int linha, int coluna);
    void remover(int linha, int coluna);
    bool buscar(int linha, int coluna);
    void exibir();
};

Teatro::Teatro(int linha, int coluna){
    resize(linha, coluna);
}

void Teatro::resize(int linha, int coluna){
    if(cadeiras != nullptr){
        std::cout << "Old ptr cadeiras deleted" << std::endl;
        delete cadeiras;
    }

    contador = 0;
    maxLinha = linha;
    maxColuna = coluna;
    totalCadeiras = linha*coluna;

    cadeiras = new bool[linha*coluna];
    for(int i = 0; i < maxLinha; i++){
        for(int j = 0; j < maxColuna; j++){
                cadeiras[i*maxColuna+j] = false;
        }
    }
}

void Teatro::insere(int linha, int coluna){
    if(linha >= maxLinha || coluna >= maxColuna || linha < 0 || coluna < 0){
        std::cout << "Invalid position" << std::endl;
        return;
    }

    if(!cadeiras[linha*maxColuna+coluna]){
        cadeiras[linha*maxColuna+coluna] = true;
        contador++;
    }
}

void Teatro::remover(int linha, int coluna){
    if(linha >= maxLinha || coluna >= maxColuna || linha < 0 || coluna < 0){
        std::cout << "Invalid position" << std::endl;
        return;
    }

    if(cadeiras[linha*maxColuna+coluna]){
        cadeiras[linha*maxColuna+coluna] = false;
        contador--;
    }
}

bool Teatro::buscar(int linha, int coluna){
    if(linha >= maxLinha || coluna >= maxColuna || linha < 0 || coluna < 0){
        std::cout << "Invalid position" << std::endl;
        return false;
    }
    return cadeiras[linha*maxColuna+coluna];
}

void Teatro::exibir(){
    std::cout << "Total: " << contador << std::endl;
    for(int i = 0; i < maxLinha; i++){
        for(int j = 0; j < maxColuna; j++){
            std::cout << cadeiras[i*maxColuna+j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif // TEATRO_H_INCLUDED
