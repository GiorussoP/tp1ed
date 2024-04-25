#include <iostream>
#include <fstream>
#include <string>

#include "Testes.hpp"

int main(){

    /*
    Vetor<int> v(10);
    v.preencherChavesAleatoriamente();
    v.preencherValoresAleatoriamente();
    v.imprimir();
    */
    Testes::testarAlgoritmoOrdenacao(Ordenacao::quickSort,"Quick",10000);
    //Ordenacao::countingSort(v,v.getMaiorChave());
    //v.imprimir();

    //std::cout<<v.getMaiorChave()<<std::endl;
    return 0;
}
