#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>
#include <cmath>
#include <stdexcept>

#include "Vetor.hpp"

class Ordenacao{
    private:
        //Troca 2 valores de lugar
        template <typename T> 
        static void trocar(Item<T>& A, Item<T>& B) {
            Item<T> C = A;
            A = B;
            B = C;
        }

        //Junta duas seções previamente ordenadas, para o mergesort.
        template <typename T>
        static void mesclar(Vetor<T>& v,unsigned int i_comeco,unsigned int i_quebra,unsigned int i_fim){

            // PROGRAMAÇÃO DEFENSIVA
            if (i_comeco > i_quebra|| i_quebra > i_fim) throw std::invalid_argument("Índice de fim deve ser maior ou igual ao de quebra, que deve ser maior ou igual ao de começo.");
            if(i_fim >= v.getTamanho()) throw std::out_of_range("Fim do Vetor fora de alcance");
            unsigned int tamanho = i_fim - i_comeco + 1;
            if(tamanho <= 1) return;



            Vetor<T> aux(tamanho);

            unsigned int i = i_comeco;
            unsigned int j = i_quebra + 1;
            unsigned int k = 0;

            while (i <= i_quebra && j <= i_fim ){
        
                if (v[i].chave < v[j].chave) {
                    aux[k] = v[i];
                    ++i;
                }
                else {
                    aux[k] = v[j];
                    ++j;
                }
                ++k;
            }

            if(k < tamanho){
                while (i <= i_quebra){
                    aux[k] = v[i];
                    ++i;
                    ++k;
                }
                while (j <= i_fim) {
                    aux[k] = v[j];
                    ++j;
                    ++k;
                }    
            }

            for (unsigned int i = 0; i < tamanho ; ++i) {
                v[i_comeco + i] = aux[i];
            }
        }
    
        //Cria uma partição simples (pivô é o valor do meio) para o quicksort tradicional
        template <typename T>
        static void particao(Vetor<T>& v, unsigned int i_comeco,unsigned int i_fim, long int& i, long int& j) {
            i = i_comeco;
            j = i_fim;

            unsigned int pivo = v[(i_comeco+i_fim)/2].chave;

            do {
                while (v[i].chave < pivo) ++i;
                while (v[j].chave > pivo) --j;

                if (i <= j){
                    trocar(v[i],v[j]);
                    ++i; --j;
                }
            } while (i <= j);  
        }

        template <typename T>
        static void particaoRadix(Vetor<T>& v, long int i_comeco,long int i_fim, unsigned int k) {
            if (i_fim <= i_comeco || k >= 32) return;
            long int i = i_comeco;
            long int j = i_fim;

            while (i!=j) {
                while (getBit(v[i].chave,k) == 0 && i < j) ++i; 
                while (getBit(v[j].chave,k) == 1 && i < j) --j;
                trocar(v[i],v[j]);
            }
            if (getBit(v[i_fim].chave,k) == 0) ++j;

            particaoRadix(v,i_comeco,j-1,k+1);
            particaoRadix(v,j,i_fim,k+1);
        }

        //Retorna o valor (zero ou um) do enésimo bit de um unsigned int da esquerda para a direita (indice vai de 0 a 31) 
        static unsigned int getBit(unsigned int n,unsigned int indice){
            if (indice > sizeof(unsigned int)*8-1) throw std::logic_error("Unsigned int não tem mais de 32 bits!");

            return (n >> (31 - indice)) & 1U;
        }
    
        static void imprimirBinario(unsigned int n) {
            for (int i = 0; i < 32; ++i){
                std::cout<<getBit(n,i);
            }
            std::cout<<std::endl;
        }
        
    public:
        template <typename T>
        static void bubbleSort(Vetor<T>& V){
            unsigned int tamanho = V.getTamanho();
            bool trocou = false;

            for(unsigned int i = 0; i < tamanho-1; ++i){
                
                trocou = 0;
                for(unsigned int j = 1; j < tamanho-i; ++j){

                    if(V[j].chave < V[j-1].chave){

                        trocar(V[j-1],V[j]);
                        trocou = 1;
                    }
                }
                if(!trocou) break;
            }
        }

        template <typename T>
        static void selectionSort(Vetor<T>& V){

            unsigned int tamanho = V.getTamanho();
            unsigned int menor;

            for (unsigned int i = 0; i < tamanho - 1; i++){ 

                menor = i;

                for (unsigned int j = i + 1 ; j < tamanho; j++){

                    if (V[j].chave < V[menor].chave){
                        menor = j;
                    }   
                }
                trocar(V[i], V[menor]);
            }
        }

        template <typename T>
        static void insertionSort(Vetor<T>& v){

                unsigned int tamanho = v.getTamanho();

                for(unsigned int i = 1; i<tamanho;++i){

                    Item<T> item_retirado = v[i];

                    for (int j = i-1; j >=0; --j){

                        if (v[j].chave>item_retirado.chave){

                            trocar(v[j],v[j+1]);
                        }
                        else {
                            v[j+1] = item_retirado;
                            break;
                        }
                    }
                }
        }

        template <typename T>
        static void mergeSort(Vetor<T>& v,unsigned int i_comeco,unsigned int i_fim){
                if(i_comeco < i_fim){

                    unsigned int meio = (i_fim + i_comeco)/2;


                    mergeSort(v,i_comeco,meio);

                    mergeSort(v,meio+1,i_fim);

                    mesclar(v,i_comeco,meio,i_fim);

                }   
        }

        template <typename T>
        static void quickSort(Vetor<T>& v, unsigned int i_comeco, unsigned int i_fim) {
            if (i_comeco >= i_fim) return;
            long int i, j;
            particao(v,i_comeco,i_fim,i,j);

            if((long int) i_comeco < j) quickSort(v,i_comeco,j);
            if (i < (long int) i_fim) quickSort(v, i, i_fim);
        }

        template <typename T>
        static void shellSort(Vetor<T>& v) {
            unsigned int n = v.getTamanho();

            for (unsigned int h = n / 2; h > 0; h /= 2) {

                for (unsigned int i = h; i < n; ++i) {

                    Item<T> aux = v[i];
                    
                    unsigned int j;

                    for (j = i; (j >= h) && (v[j-h].chave > aux.chave); j -= h) {

                        v[j] = v[j - h];

                    }

                    v[j] = aux;
                }
            }

        }

        template <typename T>
        static void countingSort(Vetor<T>& v, unsigned int maior_chave) {

            unsigned int tam_v = v.getTamanho();
            unsigned int n_max_chaves = maior_chave + 1;

            //alocação do vetor de itens
            T * aux = new T[n_max_chaves*tam_v];
            //alocação do vetor de chaves
            unsigned int * v_chaves = new unsigned int[n_max_chaves] {0};

            //organização do vetor auxiliar e do vetor de chaves (CONSOME BASTANTE MEMÓRIA)
            for (unsigned int i = 0; i < tam_v; ++i) {

                unsigned int chave = v[i].chave;

                aux[tam_v*chave + v_chaves[chave]] = v[i].valor;

                ++v_chaves[chave];
            }



            //remontagem do vetor
            unsigned int k = 0;

            for (unsigned int i = 0; i < n_max_chaves; ++i) {

                unsigned int n_chave = v_chaves[i];

                if(n_chave > 0) {

                    for (unsigned int j = 0; j < n_chave; ++j) {

                        v[k].chave = i;
                        v[k].valor = aux[tam_v*i +j];

                        ++k;
                    }
                }
                
            }


            // desalocação de memória
            delete[] aux;
            delete[] v_chaves;
        }

        template <typename T>
        static void bucketSort(Vetor<T>& v, unsigned int k_buckets) {
            if(k_buckets == 0) throw std::logic_error("Não podem existir zero baldes");

            unsigned int tamanho = v.getTamanho();
            unsigned int max = v.getMaiorChave();
            unsigned int tamanho_baldes = max / k_buckets + 1;

            //criação do vetor auxiliar que representa os baldes
            Vetor<T> aux(tamanho*k_buckets);

            //alocação do vetor de chaves
            unsigned int * q_itens_balde = new unsigned int[k_buckets] {0};

            //colocando elementos nos baldes
            for (unsigned int i = 0; i < tamanho; ++ i){
                unsigned int qual = v[i].chave/tamanho_baldes;

                aux[qual * tamanho + q_itens_balde[qual]] = v[i];
                ++q_itens_balde[qual];
            }

            //ordenando elementos de cada balde
            for (unsigned int i = 0; i < k_buckets; ++ i) {
                if(q_itens_balde[i] > 0){
                    quickSort(aux,i*tamanho,i*tamanho + q_itens_balde[i]-1);
                }
            }

            //copiando valores pro vetor original
            unsigned int k = 0;
            for (unsigned int i = 0; i < k_buckets; ++i) {
                unsigned int valores_balde =  q_itens_balde[i];
                if (valores_balde > 0) {
                    for(unsigned int j = 0; j < valores_balde; ++ j) {
                         v[k] = aux[i*tamanho + j];
                         ++k;
                    }
                }
            }

            delete[] q_itens_balde;
        }

        template <typename T>
        static void radixSort(Vetor<T>& v) {
            particaoRadix(v,0,v.getTamanho()-1,0);
        }
        //Radix Sort
        
};

#endif