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
    void MostrarIndicePar(void);
	void MostrarContenidoPar(void);
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
este es el caso 5*/
void Pila::MostrarContenidoPar(void)
{ Nodo *Aux=tope;
   while(Aux){
   	if(Aux->dameTuDato()%2==0)
	cout<<"\n "<<Aux->dameTuDato();
	Aux=Aux->dameTuSiguiente();
	   }		
}


/********************************************************************************/
int main(void)
{ char resp; int opc, tam, num;
  do{ system("cls");
    Pila Pilita; // objeto de tipo pila
  	 do{ system("csl");
  	     cout<<"\n\n  M E N U  D E  P I L A S"<<endl;
  	     cout<<"\n1) Agregar nodos "<<endl;
  	 	 cout<<"\n2) Borrar un nodo"<<endl;
  	 	 cout<<"\n3) Ver toda la pila"<<endl;
		 cout<<"\n4) Tamaño de la pila"<<endl;
		 cout<<"\n5) Nodos con contenido par "<<endl;
		 cout<<"\n6) Nodos con contenido par "<<endl;
  	 	 cout<<"\n0) PARA SALIR DEL MENU "<<endl;
  	 	 cout<<"\n\nElige una opcion: " ;
  	 	 cin>>opc;
  	 	 switch(opc)
  	 	 {  case 0: break;
  	 	    case 1:
  	 	        cout<<"\n1) Agregar nodos "<<endl;
  	 	        cout<<"\nCuantos nodos deseas agregar ";
  	 	        cin>>tam;
  	 	        for(int i=0; i<tam; i++)
                {
                    cout<<i<<")Dame un entero: ";
					cin >>num;
					Pilita.push(num);
  	 	        }
  	 	 	       break;
  	 	 	case 2:
			cout<< "\n 2)Borrar un nodo";
			cout <<"\n Se borro el "<< Pilita.pop();  
  	 	 	       break;
  	 	 	case 3:
			cout<<"\n3) Ver toda la pila"<<endl;
			Pilita.Verpila();
  	 	 	       break;
			case 4:
			 cout<<"\n4) Tamanio de la pila"<<endl;
			 cout <<"\n Hay "<< Pilita.tamanio()<<" nodos en la pila";
				   break;
			case 5:
			 cout<<"\n5) Tamanio de la pila"<<endl;
			 Pilita.MostrarContenidoPar();
				   break;
			case 6:
			 cout<<"\n6) Nodos con contenido par"<<endl;
			 Pilita.MostrarIndicePar();
				   break;
  	 	 	default: cout<<"\nNo existe esa opcion!! "<<endl;
		 }

  	 	 system("pause");
	   }while(opc); // del menu

  	cout<<"\n\n¿Deseas ejecutar nuevamente el programa? s/n "<<endl;
	cin>>resp;
	resp=tolower(resp);
  }while(resp=='s');
  system("pause");
  return 0;
}
