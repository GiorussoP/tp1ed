#include <iostream>
#include <fstream>
#include <string>

#include "TestesAlg.hpp"

int main(){
    unsigned int n_max;
    unsigned int max_bytes;
    unsigned int intervalo = 0;
    std::cout<<"Numero maximo de elementos:"<<std::endl;
    std::cin>>n_max;

    std::cout<<"Numero maximo de bytes:"<<std::endl;
    std::cin>>max_bytes;

    while (intervalo ==0) {
        std::cout<<"Intervalo dos testes:"<<std::endl;
        std::cin>>intervalo;
    }


    /* BUBBLE */

    Testes::variarTamanhoVetor(Algoritmo::bubble,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::bubble,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::linear);
    Testes::variarTamanhoVetor(Algoritmo::bubble,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::bubble,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::quadratica);
    
    Testes::variarTamanhoItem(Algoritmo::bubble,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::quadratica);

    /* SELECTION */

    Testes::variarTamanhoVetor(Algoritmo::selection,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::selection,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::selection,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::selection,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::quadratica);

    Testes::variarTamanhoItem(Algoritmo::selection,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::quadratica);

    /* INSERTION */

    Testes::variarTamanhoVetor(Algoritmo::insertion,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::insertion,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::linear);
    Testes::variarTamanhoVetor(Algoritmo::insertion,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::insertion,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::quadratica);

    Testes::variarTamanhoItem(Algoritmo::insertion,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::quadratica);

    /* MERGE */

    Testes::variarTamanhoVetor(Algoritmo::merge,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::nlogn);
    Testes::variarTamanhoVetor(Algoritmo::merge,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::nlogn);
    Testes::variarTamanhoVetor(Algoritmo::merge,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::nlogn);
    Testes::variarTamanhoVetor(Algoritmo::merge,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::nlogn);

    Testes::variarTamanhoItem(Algoritmo::merge,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::linear);

    /* QUICK */

    Testes::variarTamanhoVetor(Algoritmo::quick,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::nlogn);
    Testes::variarTamanhoVetor(Algoritmo::quick,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::nlogn);
    Testes::variarTamanhoVetor(Algoritmo::quick,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::nlogn);
    Testes::variarTamanhoVetor(Algoritmo::quick,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::nlogn);

    Testes::variarTamanhoItem(Algoritmo::quick,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::linear);

    /* SHELL */

    Testes::variarTamanhoVetor(Algoritmo::shell,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::shell,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::shell,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::quadratica);
    Testes::variarTamanhoVetor(Algoritmo::shell,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::quadratica);

    
    Testes::variarTamanhoItem(Algoritmo::shell,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::linear);

    /* COUNTING */

    Testes::variarTamanhoVetor(Algoritmo::counting,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::linear);
    Testes::variarTamanhoVetor(Algoritmo::counting,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::linear);
    Testes::variarTamanhoVetor(Algoritmo::counting,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::linear);
    Testes::variarTamanhoVetor(Algoritmo::counting,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::linear);
   

    Testes::variarTamanhoItem(Algoritmo::counting,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::linear);

    /* BUCKET - Baldes de tamanho raiz de n */ 

    Testes::variarTamanhoVetor(Algoritmo::bucket,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::n_15);
    Testes::variarTamanhoVetor(Algoritmo::bucket,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::n_15);
    Testes::variarTamanhoVetor(Algoritmo::bucket,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::n_15);
    Testes::variarTamanhoVetor(Algoritmo::bucket,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::n_15);

    Testes::variarTamanhoItem(Algoritmo::bucket,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::linear);

    /* RADIX - considerando o número total de bits sempre 32 */

    Testes::variarTamanhoVetor(Algoritmo::radix,ConfiguracaoInicial::aleatorio,n_max,intervalo,TipoFuncao::linear);
    Testes::variarTamanhoVetor(Algoritmo::radix,ConfiguracaoInicial::ordenado,n_max,intervalo,TipoFuncao::linear);
    Testes::variarTamanhoVetor(Algoritmo::radix,ConfiguracaoInicial::inversamenteOrdenado,n_max,intervalo,TipoFuncao::linear);
    Testes::variarTamanhoVetor(Algoritmo::radix,ConfiguracaoInicial::repeticaoDeChaves,n_max,intervalo,TipoFuncao::linear);
   
    Testes::variarTamanhoItem(Algoritmo::radix,ConfiguracaoInicial::inversamenteOrdenado,max_bytes,intervalo,TipoFuncao::linear);

    return 0;
}
