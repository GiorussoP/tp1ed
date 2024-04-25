#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>

class timer{
    private:
        static timeval hora_inicio;

    public:
        static void iniciarTimer();
        static double pararTimer();
};

#endif