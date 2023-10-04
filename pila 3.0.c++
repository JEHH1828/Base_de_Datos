#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
    void MostrarIndicePar(void);
    int  tamanio(void);
	void Verpila(void);
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
	Nodo *Aux=tope; int Cont=0;
	while(Aux){
		Cont++;
		Aux=Aux-> dameTuSiguiente();
	}
	return Cont;
}
void Pila::Verpila(void){
	Nodo *Aux=tope;
	while(Aux){
		cout<<"\n"<<Aux->dameTuDato();
		Aux=Aux-> dameTuSiguiente();
	}
}
void Pila::MostrarIndicePar(void)
{ Nodo *Aux=tope; int Cont=0;
   while(Aux){
    Cont++;
   	if((Cont%2==0))
	cout<<"\n "<<Aux->dameTuDato();
	Aux=Aux->dameTuSiguiente();
	}		
}
/*
{ Nodo *Aux=tope;
  while(Aux)
  {
      Aux=Aux ->dameTuSiguiente();
  }
}
*/
/*
este es el caso 5
void Pila::MostrarContenidoPar(void)
{ Nodo *Aux=tope;
   while(Aux){
   	if(Aux->dameTuDato()%2==0)
	cout<<"\n "<<Aux->dameTuDato();
	Aux=Aux->dameTuSiguiente();
	   }		
}*/


/********************************************************************************/
int main(void)
{ char resp; int i;
  do{ Pila pilon1, pilon2; bool bandera=1;
  char palabra[30];
  system("cls");
  	cout <<"Teclea una palabra: "<<endl;
  	cin.getline(palabra,30);
	fflush(stdin);

	for(i=0;i<strlen(palabra);i++)
	{pilon1.push(palabra[i]);

	}
	for(i=strlen(palabra)-1;i>=0;i--){
		pilon2.push(palabra[i]);
	}
	for(i=strlen(palabra)-1;i>=0;i--){
		if (pilon1.pop()!=pilon2.pop()){
			bandera=0;
		}
	}
	if (bandera==1){
		cout<<"La palabra es palindroma"<<endl;
	}
 else{
	cout<<"La palabra no es palindroma"<<endl;
  	
  }cout<<"\n\nDeseas ejecutar nuevamente el programa? s/n "<<endl;
	cin>>resp;
	resp=tolower(resp);}
	while(resp=='s');
 
  return 0;	
}
