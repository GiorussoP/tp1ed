#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H


template <typename T>
struct Celula {
    T elemento;
    Celula<T>* proximo = nullptr;
};

template <typename T>
class Lista {
    private:
        Celula<T>* comeco;
        Celula<T>* ultimo;

        unsigned int tamanho;

        //percorre a lista até a posicao desejada
        void percorrerAte(Celula<T>*& p,unsigned int posicao){
            if (posicao == 0 || posicao > tamanho) throw stderr::logic_error("Posicao fora da lista");

            p = primeiro;
            while (posicao > 1){
                p = p->proximo;
                --posicao;
            }
            
        }

    public:
        Lista() : tamanho(0) {
            primeiro = new Celula<T>;
            ultimo = primeiro;
        }

        T getMeio(unsigned int posicao) {

        }

        bool taVazia() {
            if (primeiro->proximo == nullptr) return true;
        }
        void inserirFinal(T elemento) {
            Celula<T>* nova = new Celula<T>;
            nova->elemento = elemento;
            ultimo->proximo = nova;
            ultimo = nova;

            ++tamanho;
        }
        void inserirComeco(T elemento) {
            Celula<T>* nova = new Celula<T>;
            nova->elemento = elemento;
            nova->proximo = primeiro;
            primeiro = nova;

            ++tamanho;
        }
        void inserirMeio(T elemento, unsigned int posicao) {
            
        };

        ~Lista() {
            Celula<T>* del = primeiro;
            while (del->proximo != nullptr){
                 Celula<T>* anterior = del;
                 del = del->proximo;
                 delete anterior;
            }
            delete del;
        }

};




#endif