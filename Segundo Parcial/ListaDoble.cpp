#include <iostream>
#include <stdlib.h>
using namespace std;
class NodoD
{
    public:
	 NodoD(int dato,NodoD* siguiente=NULL, NodoD* anterior=NULL );
	 int     dameTuDato(void);
	 NodoD*  dameTuSiguiente(void);
	 NodoD*  dameTuAnterior(void);
	 void    modificaTuDato(int dato);
	 void    modificaTuSiguiente(NodoD* siguiente);
	 void    modificaTuAnterior(NodoD* anterior);
	 void    muestraTusDatos(void);
    private:
   	 NodoD* anterior;
	 int    dato;
	 NodoD* siguiente;
};
NodoD::NodoD(int dato, NodoD* siguiente, NodoD* anterior)
{ this->dato = dato;
  this->siguiente = siguiente;
  this->anterior = anterior;
}
int NodoD::dameTuDato(void)
{  return dato;
}
NodoD* NodoD::dameTuSiguiente(void)
{     return siguiente;
}
NodoD* NodoD::dameTuAnterior(void)
{     return anterior;
}
void NodoD::modificaTuDato(int dato)
{ this->dato = dato;
}
void NodoD::modificaTuSiguiente(NodoD* siguiente)
{  this->siguiente = siguiente;
}
void NodoD::modificaTuAnterior(NodoD* anterior)
{  this->anterior = anterior;
}
void NodoD::muestraTusDatos(void)
{  cout<<dato<<" : ";
  if(siguiente==NULL)
  {
    cout<<"NULL";
  }
  else
     cout<<siguiente<<"->";
  cout << endl;
}
class ListaDoble
{
    public:
            ListaDoble();
           ~ListaDoble();
     void   insertaUnNodo(int dato);
     bool   vacia(void);
     void   borraUnNodo(int dato);
     void   muestraTusDatosID(void);
     void   muestraTusDatosDI(void);
     NodoD* dameTuSiguienteNodo(NodoD*);
     NodoD* dameTuAnteriorNodo(NodoD*);
     NodoD* dameTuInicio(void);
     void   copiaPares(ListaDoble &L2);
     void   guardaTusDatos(void);
     
    private:
         NodoD* inicio,*fin;
};
ListaDoble::ListaDoble()
{
   inicio = fin = NULL;
}
ListaDoble:: ~ListaDoble()
{ NodoD* actual = inicio;
  while(actual)
  { inicio = inicio->dameTuSiguiente();
    delete(actual);
    actual = inicio;
  }
}
void ListaDoble::insertaUnNodo(int dato)
{ NodoD* actual;
  if(vacia() || dato < inicio->dameTuDato())
  { actual = new NodoD(dato,inicio);
    if(fin == NULL)
      fin =  actual;     
    else
      inicio-> modificaTuAnterior(actual);        
    inicio = actual;
  }
  else
  { NodoD* anterior= NULL;
    actual = inicio;
    while(actual && actual->dameTuDato() <= dato)
    {  anterior = actual;
       actual = actual->dameTuSiguiente();
    }
    if(actual)
    { anterior->modificaTuSiguiente(new NodoD(dato,anterior->dameTuSiguiente(),anterior));
      actual->modificaTuAnterior(anterior->dameTuSiguiente());
    }
    else
    {  fin->modificaTuSiguiente(new NodoD(dato,NULL,fin));
       fin = fin->dameTuSiguiente();
    }
  }
}
bool ListaDoble::vacia(void)
{
  return  inicio == NULL;
}
void ListaDoble::borraUnNodo(int dato)
{  if(!vacia())
   { NodoD* actual = inicio;
     if( dato == inicio->dameTuDato())
      {  inicio = inicio->dameTuSiguiente();
	     inicio->modificaTuAnterior(NULL);
	     delete (actual);
	     if(!inicio)
	        fin=inicio;
      }
      else
      {  NodoD *anterior=NULL;
    	 while(actual && actual->dameTuDato() < dato)
    	 {  anterior = actual;
    	    actual = actual->dameTuSiguiente();
    	 }
    	 if(actual)
    	 {  if (actual->dameTuDato() == dato)
    	    {  anterior->modificaTuSiguiente(actual->dameTuSiguiente());
    	       if(actual->dameTuSiguiente())
    	           actual->dameTuSiguiente()->modificaTuAnterior(anterior);
    	       else
    	           fin = fin->dameTuAnterior();
    	       delete(actual);
    	    }
    	    else
    	       cout << "El dato "<< dato << " no esta en la lista" <<endl;
    	 }
    	 else
    	    cout << "El dato "<< dato << " no esta  en la lista" <<endl;
      }
   }
   else
       cout << "Lista vacia"<<endl;
}
void ListaDoble::muestraTusDatosDI(void)
{
  NodoD* actual = fin;
  while(actual)
  { cout << actual->dameTuDato()<<"->";
    actual = actual->dameTuAnterior();
  }
  cout << endl;
}
void ListaDoble::muestraTusDatosID(void)
{ NodoD* actual = inicio;
  while(actual)
  { cout << actual->dameTuDato()<<"->";
    actual = actual->dameTuSiguiente();
  }
  cout << endl;
}
 NodoD* ListaDoble::dameTuAnteriorNodo(NodoD* aux)
 { if(!vacia())
   { if( aux->dameTuAnterior() == NULL)
     {  cout << "Es el primer nodo";
        system("pause");
        exit(-3);
     }
   }
   else{
        cout << "La lista esta vacia";
        system("pause");
        exit(-1);
       }
   return  aux->dameTuAnterior();

 }
NodoD* ListaDoble::dameTuInicio(void)
{
    return inicio;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  Escriba aqui su codigo %%%%%%%%%%%%%%%%%%%
void  ListaDoble::copiaPares(ListaDoble &L2)
{  NodoD *Aux= inicio;
   while (Aux)
   {  if (Aux->dameTuDato()%2==0)
            L2.insertaUnNodo(Aux->dameTuDato());  
      Aux = Aux->dameTuSiguiente();
   }
}

void   ListaDoble::guardaTusDatos(void)
{

}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main(void)
{   ListaDoble L1,L2;

    L1.insertaUnNodo(31);
    L1.insertaUnNodo(12);
    L1.insertaUnNodo(54);
    L1.insertaUnNodo(43);
    L1.insertaUnNodo(20);
    L1.insertaUnNodo(2);
    L1.insertaUnNodo(5);

    cout << "Lista 1" << endl;
    L1.muestraTusDatosID();
    L1.muestraTusDatosDI();

// %%%%%%%%%%%%%%%%%%%%%%%%%%%  Prueba del ejercicio 1   %%%%%%%%%%%%%%%%%%%%%%
    cout <<endl <<"Lista 2" << endl;
    L1.copiaPares(L2);
    L2.muestraTusDatosID();
    L2.muestraTusDatosDI();

// %%%%%%%%%%%%%%%%%%%%%%%%%%%  Prueba del ejercicio 2   %%%%%%%%%%%%%%%%%%%%%%

    L2.guardaTusDatos();



    return 0;
}
