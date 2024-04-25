#include "Timer.hpp"

#include <cstddef>

//CLASSE TIMER

timeval timer::hora_inicio;

void timer::iniciarTimer(){
    gettimeofday(&hora_inicio,NULL);
}

double timer::pararTimer(){
    timeval hora_fim;
    gettimeofday(&hora_fim,NULL);

    double tempo_total = (hora_fim.tv_sec - hora_inicio.tv_sec) + 
              ((hora_fim.tv_usec - hora_inicio.tv_usec)/1000000.0);
    return tempo_total;
}
