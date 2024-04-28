#include "TestesAlg.hpp"

#include <fstream>

#include "Timer.hpp"
#include "gnuplot.h"

void Testes::variarTamanhoVetor(Algoritmo alg,ConfiguracaoInicial conf, unsigned int tam_max,unsigned int intervalo,TipoFuncao f){
    if(intervalo == 0) return;
    //Nome do arquivo de saida
    std::string nome_saida;
    switch (alg) {
        case Algoritmo::bubble:
                nome_saida = "bubble";
            break;
        case Algoritmo::insertion:
                nome_saida = "insertion";
            break;
        case Algoritmo::selection:
                nome_saida = "selection";
            break;
        case Algoritmo::merge:
                nome_saida = "merge";
            break;
        case Algoritmo::quick:
                nome_saida = "quick";
            break;
        case Algoritmo::counting:
                nome_saida = "counting";
            break;
        case Algoritmo::bucket:
                nome_saida = "bucket";
            break;
        case Algoritmo::shell:
                nome_saida = "shell";
            break;
        case Algoritmo::radix:
                nome_saida = "radix";
            break;
        default:
            break;
    }
    switch (conf) {
        case ConfiguracaoInicial::aleatorio:
                nome_saida+="_A";
            break;
        case ConfiguracaoInicial::ordenado:
                nome_saida+="_O";
            break;
        case ConfiguracaoInicial::inversamenteOrdenado:
                nome_saida+="_IO";
            break;
        case ConfiguracaoInicial::repeticaoDeChaves:
                nome_saida+="_RC";
            break;
        default:
            break;
    }
    nome_saida+=".tamvetor";

    // Abertura do arquivo de saida
    std::ofstream saida;
    saida.open(nome_saida);

    switch (alg) {
        case Algoritmo::bubble:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::bubbleSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::insertion:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;
                    timer::iniciarTimer();
                    Ordenacao::insertionSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::selection:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::selectionSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::merge:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;
                    unsigned int tamanho = v.getTamanho()-1;

                    timer::iniciarTimer();
                    Ordenacao::mergeSort(v,0,tamanho);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::quick:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;
                    unsigned int tamanho = v.getTamanho()-1;

                    timer::iniciarTimer();
                    Ordenacao::quickSort(v,0,tamanho);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::counting:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;
                    double maior_chave = v.getMaiorChave();

                    timer::iniciarTimer();
                    Ordenacao::countingSort(v,maior_chave);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::bucket:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;
                    unsigned int k_buckets = sqrt(v.getTamanho());

                    timer::iniciarTimer();
                    Ordenacao::bucketSort(v,k_buckets);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::shell:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::shellSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::radix:
                for(unsigned int  i = 1; i <= tam_max; i += intervalo) {
                    Vetor<int> v(i);
                    prepararVetor(v,conf);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::radixSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        default:
            break;
    }
    saida.close();

    fazerGraficoN(alg,conf,nome_saida,f);

}
void Testes::variarTamanhoItem(Algoritmo alg, ConfiguracaoInicial conf, unsigned int max_bytes,unsigned int intervalo,TipoFuncao f){
    if(intervalo == 0) return;

    std::string nome_saida;
    switch (alg) {
        case Algoritmo::bubble:
                nome_saida = "bubble";
            break;
        case Algoritmo::insertion:
                nome_saida = "insertion";
            break;
        case Algoritmo::selection:
                nome_saida = "selection";
            break;
        case Algoritmo::merge:
                nome_saida = "merge";
            break;
        case Algoritmo::quick:
                nome_saida = "quick";
            break;
        case Algoritmo::counting:
                nome_saida = "counting";
            break;
        case Algoritmo::bucket:
                nome_saida = "bucket";
            break;
        case Algoritmo::shell:
                nome_saida = "shell";
            break;
        case Algoritmo::radix:
                nome_saida = "radix";
            break;
        default:
            break;
    }
    switch (conf) {
        case ConfiguracaoInicial::aleatorio:
                nome_saida+="_A";
            break;
        case ConfiguracaoInicial::ordenado:
                nome_saida+="_O";
            break;
        case ConfiguracaoInicial::inversamenteOrdenado:
                nome_saida+="_IO";
            break;
        case ConfiguracaoInicial::repeticaoDeChaves:
                nome_saida+="_RC";
            break;
        default:
            break;
    }
    nome_saida+=".nbytes";

    // Abertura do arquivo de saida
    std::ofstream saida;
    saida.open(nome_saida);


    std::string valor = "";
    switch (alg) {
        case Algoritmo::bubble:
                for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::bubbleSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::insertion:
            for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::insertionSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::selection:
            for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::selectionSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::merge:
                for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);

                    double tempo;
                    unsigned int n = v.getTamanho() -1;

                    timer::iniciarTimer();
                    Ordenacao::mergeSort(v,0,n);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::quick:
                for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);

                    double tempo;
                    unsigned int n = v.getTamanho() -1;

                    timer::iniciarTimer();
                    Ordenacao::quickSort(v,0,n);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
                
            break;
        case Algoritmo::counting:
                for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);
                  

                    double tempo;
                    unsigned int maior_chave =   v.getMaiorChave();

                    timer::iniciarTimer();
                    Ordenacao::countingSort(v,maior_chave);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::bucket:
                for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);

                    double tempo;
                    unsigned int k_buckets = sqrt(v.getTamanho());

                    timer::iniciarTimer();
                    Ordenacao::bucketSort(v,k_buckets);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::shell:
                for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::shellSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
            break;
        case Algoritmo::radix:
                for(unsigned int  i = 1; i <= max_bytes; i += intervalo) {
                    Vetor<std::string> v(QUANTIDADE_CHAVES_REPETICAO);
                    valor+= 'a';
                    prepararVetorBytes(v,conf,valor);

                    double tempo;

                    timer::iniciarTimer();
                    Ordenacao::radixSort(v);
                    tempo = timer::pararTimer();

                    saida<<i<<"\t"<<tempo<<std::endl;
                    std::cout<<nome_saida<<"\t"<<i<<std::endl;
                }
                
            break;
        default:
            break;
    }



    saida.close();

    fazerGraficoT(alg,conf,nome_saida,f);
}
void Testes::fazerGraficoN(Algoritmo alg,ConfiguracaoInicial conf,std::string nome_arquivo, TipoFuncao f){

    std::string cor;
    std::string nome;
    std::string modo;
    switch (alg) {
        case Algoritmo::bubble:
                nome = "Bubble";
            break;
        case Algoritmo::insertion:
                nome = "Insertion";
            break;
        case Algoritmo::selection:
                nome = "Selection";
            break;
        case Algoritmo::merge:
                nome = "Merge";
            break;
        case Algoritmo::quick:
                nome = "Quick";
            break;
        case Algoritmo::counting:
                nome = "Counting";
            break;
        case Algoritmo::bucket:          //////COLOCAR SWITCH CASES E REVISAR OS CASOS
                nome = "Bucket";
            break;
        case Algoritmo::shell:
                nome = "Shell";
            break;
        case Algoritmo::radix:
                nome = "Radix";
            break;

        default:
            break;
    } 
    switch (conf) {
        case ConfiguracaoInicial::aleatorio:
                cor = "purple";
                modo = "aleatório";
            break;
        case ConfiguracaoInicial::ordenado:
                cor = "blue";
                modo = "ordenado";
            break;
        case ConfiguracaoInicial::inversamenteOrdenado:
                cor = "dark-turquoise";
                modo = "inversamente ordenado";
            break;
        case ConfiguracaoInicial::repeticaoDeChaves:
                cor = "green"; 
                modo = "repetição de chaves";
            break;
        default:
            break;
    }
    std::string fx, params;
    switch (f) {
        case TipoFuncao::linear:
            fx = "a*x+b";
            params = "a,b";
            break;
        case TipoFuncao::nlogn:
            fx = "a*x*log(b*x)";
            params = "a,b";
            break;
        case TipoFuncao::quadratica:
            fx = "a*x**2 + b*x + c";
            params = "a,b,c";
    }
    
    /// CONFIGURAÇÕES DO GNUPLOT
    GnuplotPipe gp;
    gp.sendLine("set term pngcairo");
    gp.sendLine("set output '" + nome_arquivo + ".png'");

    //regressão
    gp.sendLine("f(x) = "+ fx);
    gp.sendLine("set fit logfile '"+nome_arquivo+".log'");
    gp.sendLine("fit f(x) './"+nome_arquivo + "' via " + params);

    gp.sendLine("set terminal png size 1280,720");
    gp.sendLine("set xlabel 'n'");
    gp.sendLine("set ylabel 's'");
    gp.sendLine("set title 'Algoritmo: "+ nome+", Configuração inicial do vetor: "+modo+", f(x) = "+ fx +"' offset 0,0");

    //plotagem
    gp.sendLine("plot './"+nome_arquivo+"' notitle lc rgb '" + cor+"', f(x) lw 3 lc rgb 'red'");
}

void Testes::fazerGraficoT(Algoritmo alg,ConfiguracaoInicial conf,std::string nome_arquivo,TipoFuncao f){
     std::string nome;
    std::string modo;
    switch (alg) {
        case Algoritmo::bubble:
                nome = "Bubble";
            break;
        case Algoritmo::insertion:
                nome = "Insertion";
            break;
        case Algoritmo::selection:
                nome = "Selection";
            break;
        case Algoritmo::merge:
                nome = "Merge";
            break;
        case Algoritmo::quick:
                nome = "Quick";
            break;
        case Algoritmo::counting:
                nome = "Counting";
            break;
        case Algoritmo::bucket:          //////COLOCAR SWITCH CASES E REVISAR OS CASOS
                nome = "Bucket";
            break;
        case Algoritmo::shell:
                nome = "Shell";
            break;
        case Algoritmo::radix:
                nome = "Radix";
            break;

        default:
            break;
    } 
    switch (conf) {
        case ConfiguracaoInicial::aleatorio:
                modo = "aleatório";
            break;
        case ConfiguracaoInicial::ordenado:
                modo = "ordenado";
            break;
        case ConfiguracaoInicial::inversamenteOrdenado:
                modo = "inversamente ordenado";
            break;
        case ConfiguracaoInicial::repeticaoDeChaves:
                modo = "repetição de chaves";
            break;
        default:
            break;
    }
    
    std::string fx, params;
    switch (f) {
        case TipoFuncao::linear:
            fx = "a*x+b";
            params = "a,b";
            break;
        case TipoFuncao::nlogn:
            fx = "a*x*log(b*x)";
            params = "a,b";
            break;
        case TipoFuncao::quadratica:
            fx = "a*x**2 + b*x + c";
            params = "a,b,c";
    }
    
    GnuplotPipe gp;
    gp.sendLine("set term pngcairo");
    gp.sendLine("set output '" + nome_arquivo + ".png'");

    //regressão
    gp.sendLine("f(x) = "+ fx);
    gp.sendLine("set fit logfile '"+nome_arquivo+".log'");
    gp.sendLine("fit f(x) './"+nome_arquivo + "' via " + params);

    gp.sendLine("set terminal png size 1280,720");
    gp.sendLine("set xlabel 'bytes'");
    gp.sendLine("set ylabel 's'");
    gp.sendLine("set title 'Algoritmo: "+ nome+", Configuração inicial do vetor: "+modo+", f(x) = "+ fx +"' offset 0,0");

    //plotagem
    gp.sendLine("plot './"+nome_arquivo+"' notitle lc rgb 'slategrey', f(x) lw 3 lc rgb 'orange'");
}

template<typename T>
void Testes::prepararVetor(Vetor<T>& v,ConfiguracaoInicial conf){

    switch (conf) {
        case ConfiguracaoInicial::aleatorio:
                v.preencherChavesAleatoriamente();
            break;
        case ConfiguracaoInicial::ordenado:
                v.preencherChavesSequencialmente();
            break;
        case ConfiguracaoInicial::inversamenteOrdenado:
                v.preencherChavesInversamente();
            break;
        case ConfiguracaoInicial::repeticaoDeChaves:
                v.preencherChavesComRepeticao(QUANTIDADE_CHAVES_REPETICAO);
            break;
        default:
            break;
    }
    v.preencherValoresAleatoriamente();
}

void Testes::prepararVetorBytes(Vetor<std::string>& v,ConfiguracaoInicial conf,std::string n) {
     switch (conf) {
        case ConfiguracaoInicial::aleatorio:
                v.preencherChavesAleatoriamente();
            break;
        case ConfiguracaoInicial::ordenado:
                v.preencherChavesSequencialmente();
            break;
        case ConfiguracaoInicial::inversamenteOrdenado:
                v.preencherChavesInversamente();
            break;
        case ConfiguracaoInicial::repeticaoDeChaves:
                v.preencherChavesComRepeticao(QUANTIDADE_CHAVES_REPETICAO);
            break;
        default:
            break;
    }
    v.preencherValoresComString(n);
}

