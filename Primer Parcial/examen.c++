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
class Cola {
   private:
         Nodo* Inicio;
	     Nodo* Fin;
   public:
         Cola();
	    ~Cola();
	     void insertar(int d);
	     int  elimina(void);
	     bool laColaEstaVacia(void);
	     void vercola(void);
};
Cola::Cola()
{  Fin = Inicio = NULL;
}
void Cola::insertar(int d)
{
   if(!laColaEstaVacia())
   { Fin->modificaTuSiguiente(new Nodo(d));
     Fin = Fin->dameTuSiguiente();
   }
   else{ Fin = Inicio = new Nodo(d);
        }
}
int Cola::elimina()
{  Nodo* aux = Inicio;
   int d;
   if(!laColaEstaVacia())
   { Inicio = Inicio->dameTuSiguiente();
     d = aux->dameTuDato();
     delete aux;
   }
   else{ cout << "La cola esta vacia" ;
         Fin = NULL;
         exit(1);
        }
   return d;
}

bool Cola::laColaEstaVacia(void)
{  return Inicio == NULL;
}
Cola::~Cola()
{ while(!laColaEstaVacia())
     cout << elimina()<< endl;
  system("pause");
}

void Cola::vercola(void){
    Nodo *Aux=Inicio;
	while(Aux){
		cout<<"\n"<<Aux->dameTuDato();
		Aux=Aux-> dameTuSiguiente();
	}
}
int main()
{ char resp; int opc, tam, num;
        Cola Coly1, Coly2, Coly3;
  	 do{ system("cls");
  	     cout<<"\n\nMENU PARA COLAS "<<endl;
  	     cout<<"\n1) Agregar elemento a la cola"<<endl;
  	 	 cout<<"2) Vaciar cola 1 y llenar otras 2 "<<endl;
  	 	 cout<<"0) PARA SALIR DEL MENU "<<endl;
  	 	 cout<<"\nElige una opcion:" ;
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
					Coly1.insertar(num);
  	 	        }
  	 	 	       break;
  	 	 	case 2:
            cout<<"\n2) Vacia la cola y agregala a otras 2 "<<endl;
            
                Coly2.insertar(Coly1.elimina());
                Coly3.insertar(Coly2.elimina());
                Coly2.vercola();
                Coly3.vercola();
  	 	 	break;
  	 	 	default: cout<<"\nNo existe esa opcion!! "<<endl;
		 }

  	 	 system("pause");
  }while(resp=='s');
  system("pause");