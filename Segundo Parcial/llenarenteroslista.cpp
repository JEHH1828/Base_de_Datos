
#include <iostream>
#include <stdlib.h>
#include <time.h>
// llenar l1 de tamaño n con enteros, copiar l1 para llenar l2 sin repetir 
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
class ListaSimple {
   private:
         Nodo* Inicio;
   public:
         ListaSimple();
	    ~ListaSimple();
	     void Insertar(int d);
	     int  Eliminar(int d);
	     bool laListaSimpleEstaVacia(void);
	     void mostrar(void);
};
ListaSimple::ListaSimple()
{   Inicio = NULL;
}
void ListaSimple::Insertar(int d)
{  Nodo* aux;
   if(laListaSimpleEstaVacia() || Inicio->dameTuDato() > d)
       Inicio = new Nodo(d, Inicio);
   else {
      aux = Inicio;
      while(aux->dameTuSiguiente() && aux->dameTuSiguiente()->dameTuDato() <= d) 
         aux = aux->dameTuSiguiente();
      aux->modificaTuSiguiente(new Nodo(d, aux->dameTuSiguiente()))  ;
   }
}

int ListaSimple::Eliminar(int d)
{  int borra=0;
   Nodo *anterior, *aux;
   if(!laListaSimpleEstaVacia())
   {
   	aux = Inicio;
   	anterior = NULL;
   	while(aux && aux->dameTuDato() < d) {
      anterior = aux; 
      aux = aux->dameTuSiguiente();
   	}
   	if(!aux || aux->dameTuDato() != d) 
        return -1;
   	else { // Borrar el nodo 
      if(!anterior) // Primer elemento 
         Inicio = aux->dameTuSiguiente();
      else  // un elemento cualquiera
         anterior->modificaTuSiguiente(aux->dameTuSiguiente()) ;
      borra = aux->dameTuDato();  
      delete aux;
     }
   }   
   else{ cout << "La ListaSimple esta vacia"<<endl ;
         system("pause");
         exit(-1);
        }
   return borra;
}

bool ListaSimple::laListaSimpleEstaVacia(void)
{  return Inicio == NULL;
}
ListaSimple::~ListaSimple()
{  Nodo *aux;
   
   while(Inicio) {
      aux = Inicio;
      Inicio = Inicio->dameTuSiguiente();
      delete aux;
   }
}
void ListaSimple::mostrar(void)
{ Nodo* aux=Inicio;
  while(aux)
  {  cout<<"\n"<<aux->dameTuDato();
      aux=aux->dameTuSiguiente();
  }
}
int main()
{
    int opc,numero;
   char resp;
   do{  ListaSimple L1;
   	  system("cls");
   	  do{
   	  	 cout<<"\n\nMenu de lista Simple";
   	  	 cout<<"\n1) Insertar"; 
		 cout<<"\n2) Borrar";
		 cout<<"\n3) Mostrar";
		 cout<<"\n0) Salir del menu";
		 cout<<"\n\n Elija  una opcion: ";
		 cin>>opc;
		 switch(opc)	   
		 {   case 1:cout<<"\nDame un entero: ";
		            cin>>numero;
		            L1.Insertar(numero);
		 	        break;
		 	 case 2: 
		            if (L1.laListaSimpleEstaVacia())
		                cout<<"No hay nodos para borrar..."<<endl;
		            else
					{   cout<<"\nDame un entero para borrar: ";
                        cin>>numero;
                        if(L1.Eliminar(numero)<0)
                           cout<<"No existe el "<<numero <<" en la lista..."<<endl;
                        else
                           cout<<"\nSe borro el "<<numero;
                    }
		 	        break;
			 case 3:cout<<"\nEsta es la fila...";
			        L1.mostrar();
		 	        break;
			 case 4: 
		 	        break;		 		        
		 }//del switch
	 }while(opc!=0);//del menu
   	
   	 cout<<"\n\nDesea repetir el programa? s/n: ";
   	 cin>>resp;
   } while(resp=='s');
   system("pause");
    return 0;
}
