#ifndef TESTES_ALG_H
#define TESTES_ALG_H

#define TAMANHO_VETOR_TESTE_BYTES 1000

#define QUANTIDADE_CHAVES_REPETICAO 10

#include "Ordenacao.hpp"

enum class ConfiguracaoInicial {
    aleatorio,
    ordenado,
    inversamenteOrdenado,
    repeticaoDeChaves
};

enum class TipoFuncao {
    linear,
    quadratica,
    nlogn
};

enum class Algoritmo {
    bubble,
    insertion,
    selection,  
    merge,
    quick,
    shell,
    counting,
    bucket,
    radix
};

class Testes {
    public:

        static void variarTamanhoVetor(Algoritmo alg,ConfiguracaoInicial conf, unsigned int tam_max,unsigned int intervalo,TipoFuncao f);
        static void variarTamanhoItem(Algoritmo alg, ConfiguracaoInicial conf, unsigned int max_bytes, unsigned int intervalo,TipoFuncao f);

        static void fazerGraficoN(Algoritmo alg,ConfiguracaoInicial conf,std::string nome_arquivo,TipoFuncao f);
        static void fazerGraficoT(Algoritmo alg,ConfiguracaoInicial conf,std::string nome_arquivo,TipoFuncao f);

    private:
        template<typename T>
        static void prepararVetor(Vetor<T>& v,ConfiguracaoInicial conf);

        static void prepararVetorBytes(Vetor<std::string>& v,ConfiguracaoInicial conf,std::string n);
};



#endif
