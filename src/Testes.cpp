#include "Testes.hpp"


//Teste de função  de ordenação que recebe apenas o vetor
void Testes::testarAlgoritmoOrdenacao(void (*func)(Vetor<int>&),std::string nome_alg,unsigned int tamanho_max,unsigned int intervalo){
    
            if(intervalo == 0) throw std::invalid_argument("O intervalo entre os vetores testados precisa ser de pelo menos 1");

            std::ofstream saida;
            std::string nome_saida = nome_alg + ".tempoexec"; 

            saida.open(nome_saida);

            for(unsigned int i = 1; i <= tamanho_max; i+=intervalo){
                Vetor<int> v(i);
                v.preencherValoresAleatoriamente();
                v.preencherChavesAleatoriamente();

                timer::iniciarTimer();
                func(v);
                double tempo = timer::pararTimer();

                saida<<i<<"\t"<<tempo<<std::endl;
                std::cout<<"Testado tempo de ordenacao de "<<i<<" itens por "<<nome_alg<<std::endl;
            }

            saida.close();


            //CRIANDO IMAGEM
            GnuplotPipe gp;
            gp.sendLine("set term png");
            gp.sendLine("set output '" +nome_alg + ".png'");
            gp.sendLine("set terminal png size 1280,720");

            gp.sendLine("set xlabel 'n'");
            gp.sendLine("set ylabel 's'");


            gp.sendLine("plot './" + nome_saida +"' notitle");
        }
//Teste de função  de ordenação que recebe: o vetor, primeiro índice, último índice.
void Testes::testarAlgoritmoOrdenacao(void (*func)(Vetor<int>&,unsigned int, unsigned int), std::string nome_alg,unsigned int tamanho_max, unsigned int intervalo){

    if(intervalo == 0) throw std::invalid_argument("O intervalo entre os vetores testados precisa ser de pelo menos 1");

            std::ofstream saida;
            std::string nome_saida = nome_alg + ".tempoexec"; 

            saida.open(nome_saida);

            for(unsigned int i = 1; i <= tamanho_max; i+=intervalo){
                Vetor<int> v(i);
                v.preencherValoresAleatoriamente();
                v.preencherChavesAleatoriamente();

                timer::iniciarTimer();
                func(v,0,v.getTamanho()-1);
                double tempo = timer::pararTimer();

                saida<<i<<"\t"<<tempo<<std::endl;
                std::cout<<"Testado tempo de ordenacao de "<<i<<" itens por "<<nome_alg<<std::endl;
            }

            saida.close();


            //CRIANDO IMAGEM
            GnuplotPipe gp;
            gp.sendLine("set term png");
            gp.sendLine("set output '" +nome_alg + ".png'");
            gp.sendLine("set terminal png size 1280,720");

            gp.sendLine("set xlabel 'n'");
            gp.sendLine("set ylabel 's'");


            gp.sendLine("plot './" + nome_saida +"' notitle");

}