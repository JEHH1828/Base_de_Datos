#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Nodo{
    int dato;
    Nodo *sig;
    public:
    Nodo(int);
    int damedato();
    void modificarnodos();
    Nodo *dametusig();
    void modificatusig (Nodo*);
};