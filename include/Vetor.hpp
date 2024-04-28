#ifndef MEU_Vetor_H
#define MEU_Vetor_H

template <typename T>
struct Item{
    unsigned int chave = 0U;
    T valor;
};

template <typename T>
class Vetor{
    private:
        const unsigned int tamanho;
        Item<T>* valores;

    public:
        Vetor(unsigned int n) : tamanho(n){
            if (n==0) throw std::invalid_argument("Vetor não pode ter zero elementos");
            valores = new Item<T>[n];
        }
        ~Vetor(){
            if (valores!= nullptr) delete[] valores;
        }

        Item<T>& operator[](unsigned int n){
            if (n<tamanho){
                return valores[n];
            }
            else throw std::out_of_range("Índice fora do alcance");
        }

        unsigned int getTamanho(){
            return tamanho;
        }

        unsigned int getMaiorChave() {
            unsigned int chave_max = valores[0].chave;

            for(unsigned int i = 1; i < tamanho; ++i){

                if (valores[i].chave > chave_max) chave_max = valores[i].chave;

            }
            return chave_max;
        }

        void preencherValoresAleatoriamente(){
            for(unsigned int i = 0; i < tamanho; ++i){
                valores[i].valor = (T) std::rand();
            }
        }
        void preencherValoresComString(std::string str) {
            for(unsigned int i = 0; i < tamanho; ++i){
                valores[i].valor = (T) str;
            }
        }

        void preencherChavesAleatoriamente(){
            for(unsigned int i = 0; i < tamanho; ++i){
                valores[i].chave = (unsigned int) std::rand();
            }
        }

         void preencherChavesComRepeticao(unsigned int valores_possiveis){
            if(valores_possiveis == 0) throw std::logic_error("Chave não pode assumir 0 valores possíveis");

            for(unsigned int i = 0; i < tamanho; ++i){
                valores[i].chave = (unsigned int) std::rand()%valores_possiveis;
            }
        }
        void preencherChavesSequencialmente(){
            for(unsigned int i = 0; i < tamanho; ++i){
                valores[i].chave = i;
            }
        }
        void preencherChavesInversamente(){
            for(unsigned int i = 1; i <= tamanho; ++i){
                valores[i-1].chave = tamanho-i;
            }
        }

        void  imprimir(){
            std::cout<<"Vetor: "<<std::endl;
            for(unsigned int i = 0; i < tamanho; ++i){
                std::cout<<valores[i].chave<<":\t'"<<valores[i].valor<<"'"<<std::endl;
        }
    std::cout<<std::endl;
}
};



#endif