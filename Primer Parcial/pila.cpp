#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Nodo
{ private:
	 int   dato;
	 Nodo* siguiente;
  public:
	 Nodo(int v=0, Nodo* s=NULL);
	 int   dameTuDato(void);
	 Nodo* dameTuSiguiente(void);
	 void  modificaTuDato(int);
	 void  modificaTuSiguiente(Nodo*);
};

	Nodo::Nodo(int v, Nodo* s)
	{ dato = v;
	  siguiente = s;
	}

	int   Nodo::dameTuDato(void)
	{  return dato;
	}

	Nodo* Nodo::dameTuSiguiente(void)
	{     return siguiente;
	}

	void  Nodo::modificaTuDato(int v)
	{  dato = v;
	}

	void  Nodo::modificaTuSiguiente(Nodo* s)
	{  siguiente = s;
	}

class Pila{
   private:
     Nodo* tope;
   public:
     Pila();
     ~Pila();
    bool laPilaEstaVacia();
    void push(int v);
    int  pop(void);
    int  tamanio(void);
};

	Pila::Pila()
	{ tope = NULL;
	}

	void Pila::push(int d)
	{ tope = new Nodo(d, tope);
	}

	int Pila::pop(void)
	{  Nodo* aux;
		int d;
		if(!laPilaEstaVacia())
		{ aux = tope;
			d = aux->dameTuDato();
            tope = aux->dameTuSiguiente();
			delete aux;
		} else{ cout<<"Pila vacia"<<endl;
			exit(-1);
			}
	return d;
	}

	bool Pila::laPilaEstaVacia()
	{  return tope == NULL;
	}

	Pila::~Pila()
	{ while(!laPilaEstaVacia())
		cout << pop()<<endl;
	  system("pause");
	}

int Pila::tamanio(void)
{  
}

int main(void)
{   int num, i;
    srand(time(NULL));
    i =num = 10 + rand() % (20-1);
    num = 10 + rand() % (i-1);
    Pila P;
    for(int j = 0; j < num; j++)
    {
        P.push(j);
    }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%  Prueba del ejercicio 4   %%%%%%%%%%%%%%%%%%%%%%

    cout << "Tamanio de la Pila: "<< P.tamanio()<<endl;
    cout << "num: " << num <<endl;
    return 0;
}
