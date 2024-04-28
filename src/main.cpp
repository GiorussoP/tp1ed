#include <iostream>
#include <fstream>
#include <string>

#include "TestesAlg.hpp"

int main(){

    
    Testes::variarTamanhoItem(Algoritmo::bubble,ConfiguracaoInicial::inversamenteOrdenado,5000000,100,TipoFuncao::quadratica);


    /*
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 4; ++j) {
            Testes::variarTamanhoItem((Algoritmo)i,(ConfiguracaoInicial) j,5000000,100,TipoFuncao::linear);
        }
    }
    */

    

     /*
    int n_maximo;
    std::cout<<"Digite numero de testes que se quer realizar para cada algoritmo:"<<std::endl;
    std::cin>>n_maximo;

    Testes::testarAlgoritmoOrdenacao(Ordenacao::bubbleSort,"BubbleA",n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::bubbleSort,"BubbleO",n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::bubbleSort,"BubbleI",n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::bubbleSort,"BubbleR",n_maximo,ConfiguracaoInicial::repeticaoDeChaves);
   
    Testes::testarAlgoritmoOrdenacao(Ordenacao::insertionSort,"InsertionA",n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::insertionSort,"InsertionO",n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::insertionSort,"InsertionI",n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::insertionSort,"InsertionR",n_maximo,ConfiguracaoInicial::repeticaoDeChaves);

    Testes::testarAlgoritmoOrdenacao(Ordenacao::selectionSort,"SelectionA",n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::selectionSort,"SelectionO",n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::selectionSort,"SelectionI",n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::selectionSort,"SelectionR",n_maximo,ConfiguracaoInicial::repeticaoDeChaves);

    Testes::testarAlgoritmoOrdenacao(Ordenacao::shellSort,"ShellA",n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::shellSort,"ShellO",n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::shellSort,"ShellI",n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::shellSort,"ShellR",n_maximo,ConfiguracaoInicial::repeticaoDeChaves);

    Testes::testarAlgoritmoOrdenacao(Ordenacao::mergeSort,"MergeA",n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::mergeSort,"MergeO",n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::mergeSort,"MergeI",n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::mergeSort,"MergeR",n_maximo,ConfiguracaoInicial::repeticaoDeChaves);

    Testes::testarAlgoritmoOrdenacao(Ordenacao::quickSort,"QuickA",n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::quickSort,"QuickO",n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::quickSort,"QuickI",n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::quickSort,"QuickR",n_maximo,ConfiguracaoInicial::repeticaoDeChaves);

    Testes::testarCounting(Ordenacao::countingSort,n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarCounting(Ordenacao::countingSort,n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarCounting(Ordenacao::countingSort,n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarCounting(Ordenacao::countingSort,n_maximo,ConfiguracaoInicial::repeticaoDeChaves);
    
    Testes::testarBucket(Ordenacao::bucketSort,n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarBucket(Ordenacao::bucketSort,n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarBucket(Ordenacao::bucketSort,n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarBucket(Ordenacao::bucketSort,n_maximo,ConfiguracaoInicial::repeticaoDeChaves);

    Testes::testarAlgoritmoOrdenacao(Ordenacao::radixSort,"RadixA",n_maximo,ConfiguracaoInicial::aleatorio);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::radixSort,"RadixO",n_maximo,ConfiguracaoInicial::ordenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::radixSort,"RadixI",n_maximo,ConfiguracaoInicial::inversamenteOrdenado);
    Testes::testarAlgoritmoOrdenacao(Ordenacao::radixSort,"RadixR",n_maximo,ConfiguracaoInicial::repeticaoDeChaves);

    */
    return 0;
}
