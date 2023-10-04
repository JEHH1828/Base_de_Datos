
#include <iostream>
#include <stdlib.h>
#include <time.h>
//menu para colas
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
	     void decrementa(void);
         int  tamaño(void);
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
void Cola::decrementa(void)
{
    Nodo *Aux=Inicio;
	while(Aux){
        Aux-> modificaTuDato(Aux-> dameTuDato()-1);
		Aux=Aux-> dameTuSiguiente();
	}
}
void Cola::vercola(void){
    Nodo *Aux=Inicio;
	while(Aux){
		cout<<"\n"<<Aux->dameTuDato();
		Aux=Aux-> dameTuSiguiente();
	}
}
void Cola :: tamaño(void){
    Nodo *Aux=Inicio; int Cont=0;
	while(Aux){
		Cont++;
		Aux=Aux-> dameTuSiguiente();
	}
	return Cont;

}
//termina de hacer los mismo que en tarea2.c++, todos sus casos 
//llenar 2 colas de tamaño 1
/*
imprimirlas
al vaciarlas llenar la cola 3: intercalado cada 1 

*/
//******************************************************************************
int main()
{ char resp; int opc, tam, num;
  	 do{ system("cls");
  	     cout<<"\n\nMENU PARA COLAS "<<endl;
  	     cout<<"\n1) Agregar elemento a la cola"<<endl;
  	 	 cout<<"2) Borrar elemento de la cola "<<endl;
  	 	 cout<<"3) Ver toda la cola "<<endl;
         cout<<"4) Decrementar toda la cola "<<endl;
         cout<<"5) Tamaño de la cola "<<endl;
  	 	 cout<<"0) PARA SALIR DEL MENU "<<endl;
  	 	 cout<<"\nElige una opcion:" ;
  	 	 cin>>opc;
  	 	 switch(opc)
  	 	 {  case 0: break;
  	 	    case 1:
  	 	        cout<<"\n1) Agregar nodos "<<endl;
  	 	        cout<<"\nCuantos nodos deseas agregar ";
  	 	        cin>>num;
  	 	        for(int i=0; i<tam; i++)
                {
                    cout<<i<<")Dame un entero: ";
					cin >>num;
					Cola.insertar(num);
  	 	        }
  	 	 	       break;
  	 	 	case 2:
			cout<< "\n 2)Borrar un nodo";
			cout <<"\n Se borro el "<< Cola.elimina();  
  	 	 	       break;
  	 	 	case 3:
			cout<<"\n3) Ver toda la pila"<<endl;
			Cola();
  	 	 	       break;
            case 4:
            cout<<"\n4) Decrementar toda la cola";
            cout<<"\n La fila antes del decremento es: ";
            Cola.vercola();
            Cola.decrementa();
            break;
            case 5:
            cout<<"\n5) Tamaño de la cola"<<endl;
			 cout <<"\n Hay "<< Cola.tamaño()<<" nodos formados en la cola";
				   Cola break;
            break;
  	 	 	default: cout<<"\nNo existe esa opcion!! "<<endl;
		 }

  	 	 system("pause");
  }while(resp=='s');
  system("pause");
  return 0;	
}
