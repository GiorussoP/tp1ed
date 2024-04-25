#ifndef TESTES_H
#define TESTES_H

#include <fstream>
#include "Timer.hpp"
#include "Ordenacao.hpp"
#include "gnuplot.h"

class Testes {
    public:
        static void testarAlgoritmoOrdenacao(
                                                void (*func)(Vetor<int>&),
                                                std::string nome_alg,
                                                unsigned int tamanho_max,
                                                unsigned int intervalo = 1
                                            );
        static void testarAlgoritmoOrdenacao(
                                                void (*func)(Vetor<int>&,unsigned int, unsigned int),
                                                std::string nome_alg,
                                                unsigned int tamanho_max,
                                                unsigned int intervalo = 1
                                            );

};

#endif