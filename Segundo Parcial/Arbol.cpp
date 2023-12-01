#include <iostream>
using namespace std;

class Nodo
{
public:
    Nodo(long dato, Nodo *izquierdo = NULL, Nodo *derecho = NULL);
    Nodo *&dameTuDerecho(void);
    Nodo *&dameTuIzquierdo(void);
    long dameTuDato(void);
    void modificaTuDato(long dato);
    void modificaTuIzquierdo(Nodo *izquierdo);
    void modificaTuDerecho(Nodo *derecho);
    void muestraTusDatos(void);

private:
    Nodo *izquierdo;
    long dato;
    Nodo *derecho;
};

Nodo::Nodo(long dato, Nodo *izquierdo, Nodo *derecho)
{
    this->dato = dato;
    this->izquierdo = izquierdo;
    this->derecho = derecho;
}

Nodo *&Nodo::dameTuDerecho(void)
{
    return derecho;
}
Nodo *&Nodo::dameTuIzquierdo(void)
{
    return izquierdo;
}
long Nodo::dameTuDato(void)
{
    return dato;
}
void Nodo::modificaTuDato(long dato)
{
    this->dato = dato;
}
void Nodo::modificaTuIzquierdo(Nodo *izquierdo)
{
    this->izquierdo = izquierdo;
}
void Nodo::modificaTuDerecho(Nodo *derecho)
{
    this->derecho = derecho;
}
void Nodo::muestraTusDatos(void)
{
    if (!izquierdo)
        cout << "NULL";
    else
        cout << izquierdo;
    cout << " <- " << dato << " -> ";
    if (!derecho)
        cout << "NULL";
    else
        cout << derecho;
    cout << endl;
}

class ArbolBB
{
public:
    ArbolBB();
    ~ArbolBB();
    void insertaUnNodo(long d);
    void preOrden(void);
    void postOrden(void);
    void entreOrden(void);
    void mostrarNodosHoja(void);
    int contarNodosHoja(void);
    void mostrarNodosPadre(void);
    int contarNodosEnNivel(int nivel);
    int sumatoriaNodosDesdeNivel(int nivel);
    int contarNodosEnNivelX(int nivel);
    long encontrarMinimo(void);
    long encontrarMaximo(void);
    long encontrarMaximoSubarbolIzquierdo(void);
    long encontrarMinimoSubarbolDerecho(void);

private:
    Nodo *raiz;
    Nodo *actual;
    void poda(Nodo *&);
    void preOrden(Nodo *);
    void postOrden(Nodo *);
    void entreOrden(Nodo *);
    void insertaUnNodo(long d, Nodo *&);
    void mostrarNodosHoja(Nodo *);
    int contarNodosHoja(Nodo *);
    void mostrarNodosPadre(Nodo *);
    int contarNodosEnNivel(Nodo *, int nivel, int currentLevel);
    int sumatoriaNodosDesdeNivel(Nodo *, int nivel);
    int contarNodosEnNivelX(Nodo *, int nivel, int currentLevel);
    long encontrarMinimo(Nodo *);
    long encontrarMaximo(Nodo *);
    long encontrarMaximoSubarbolIzquierdo(Nodo *);
    long encontrarMinimoSubarbolDerecho(Nodo *);
};

ArbolBB::ArbolBB()
{
    raiz = NULL;
    actual = NULL;
}

ArbolBB::~ArbolBB()
{
    poda(raiz);
}

void ArbolBB::insertaUnNodo(long d)
{
    insertaUnNodo(d, raiz);
}
void ArbolBB::preOrden(void)
{
    actual = raiz;
    preOrden(actual);
}
void ArbolBB::postOrden(void)
{
    actual = raiz;
    postOrden(actual);
}
void ArbolBB::entreOrden(void)
{
    actual = raiz;
    entreOrden(actual);
}
void ArbolBB::mostrarNodosHoja(void)
{
    mostrarNodosHoja(raiz);
}

int ArbolBB::contarNodosHoja(void)
{
    return contarNodosHoja(raiz);
}

void ArbolBB::mostrarNodosPadre(void)
{
    mostrarNodosPadre(raiz);
}

int ArbolBB::contarNodosEnNivel(int nivel)
{
    return contarNodosEnNivel(raiz, nivel, 1);
}

int ArbolBB::sumatoriaNodosDesdeNivel(int nivel)
{
    return sumatoriaNodosDesdeNivel(raiz, nivel);
}

int ArbolBB::contarNodosEnNivelX(int nivel)
{
    return contarNodosEnNivelX(raiz, nivel, 1);
}

long ArbolBB::encontrarMinimo(void)
{
    return encontrarMinimo(raiz);
}

long ArbolBB::encontrarMaximo(void)
{
    return encontrarMaximo(raiz);
}

long ArbolBB::encontrarMaximoSubarbolIzquierdo(void)
{
    return encontrarMaximoSubarbolIzquierdo(raiz->dameTuIzquierdo());
}

long ArbolBB::encontrarMinimoSubarbolDerecho(void)
{
    return encontrarMinimoSubarbolDerecho(raiz->dameTuDerecho());
}

void ArbolBB::insertaUnNodo(long d, Nodo *&raiz)
{
    Nodo *aux = raiz;
    if (aux == NULL)
    {
        raiz = new Nodo(d);
    }
    else
    {
        if (d <= aux->dameTuDato())
        {
            insertaUnNodo(d, aux->dameTuIzquierdo());
        }
        else
        {
            insertaUnNodo(d, aux->dameTuDerecho());
        }
    }
}
void ArbolBB::poda(Nodo *&aux)
{
    if (aux)
    {
        poda(aux->dameTuIzquierdo());
        poda(aux->dameTuDerecho());
        delete (aux);
        aux = NULL;
    }
}
void ArbolBB::preOrden(Nodo *aux) // prefijo
{
    if (aux)
    {
        cout << aux->dameTuDato() << endl;
        preOrden(aux->dameTuIzquierdo());
        preOrden(aux->dameTuDerecho());
    }
}
void ArbolBB::postOrden(Nodo *aux) // postfijo
{
    if (aux)
    {
        postOrden(aux->dameTuIzquierdo());
        postOrden(aux->dameTuDerecho());
        cout << aux->dameTuDato() << endl;
    }
}
void ArbolBB::entreOrden(Nodo *aux) //infijo
{
    if (aux)
    {
        entreOrden(aux->dameTuIzquierdo());
        cout << aux->dameTuDato() << endl;
        entreOrden(aux->dameTuDerecho());
    }
}

void ArbolBB::mostrarNodosHoja(Nodo *aux)
{
    if (aux)
    {
        if (!aux->dameTuIzquierdo() && !aux->dameTuDerecho())
        {
            cout << aux->dameTuDato() << " ";
        }
        mostrarNodosHoja(aux->dameTuIzquierdo());
        mostrarNodosHoja(aux->dameTuDerecho());
    }
}

int ArbolBB::contarNodosHoja(Nodo *aux)
{
    if (aux)
    {
        if (!aux->dameTuIzquierdo() && !aux->dameTuDerecho())
        {
            return 1;
        }
        return contarNodosHoja(aux->dameTuIzquierdo()) + contarNodosHoja(aux->dameTuDerecho());
    }
    return 0;
}

void ArbolBB::mostrarNodosPadre(Nodo *aux)
{
    if (aux)
    {
        if (aux->dameTuIzquierdo() || aux->dameTuDerecho())
        {
            cout << aux->dameTuDato() << " ";
        }
        mostrarNodosPadre(aux->dameTuIzquierdo());
        mostrarNodosPadre(aux->dameTuDerecho());
    }
}

int ArbolBB::contarNodosEnNivel(Nodo *aux, int nivel, int currentLevel)
{
    if (!aux)
    {
        return 0;
    }

    if (nivel == currentLevel)
    {
        return 1;
    }

    return contarNodosEnNivel(aux->dameTuIzquierdo(), nivel, currentLevel + 1) +
           contarNodosEnNivel(aux->dameTuDerecho(), nivel, currentLevel + 1);
}

int ArbolBB::sumatoriaNodosDesdeNivel(Nodo *aux, int nivel)
{
    if (!aux || nivel < 1)
    {
        return 0;
    }

    if (nivel == 1)
    {
        return aux->dameTuDato();
    }

    return sumatoriaNodosDesdeNivel(aux->dameTuIzquierdo(), nivel - 1) +
           sumatoriaNodosDesdeNivel(aux->dameTuDerecho(), nivel - 1);
}

int ArbolBB::contarNodosEnNivelX(Nodo *aux, int nivel, int currentLevel)
{
    if (!aux)
    {
        return 0;
    }

    if (nivel == currentLevel)
    {
        return 1;
    }

    return contarNodosEnNivelX(aux->dameTuIzquierdo(), nivel, currentLevel + 1) +
           contarNodosEnNivelX(aux->dameTuDerecho(), nivel, currentLevel + 1);
}

long ArbolBB::encontrarMinimo(Nodo *aux)
{
    while (aux->dameTuIzquierdo())
    {
        aux = aux->dameTuIzquierdo();
    }

    return aux->dameTuDato();
}

long ArbolBB::encontrarMaximo(Nodo *aux)
{
    while (aux->dameTuDerecho())
    {
        aux = aux->dameTuDerecho();
    }

    return aux->dameTuDato();
}

long ArbolBB::encontrarMaximoSubarbolIzquierdo(Nodo *aux)
{
    if (!aux)
    {
        return INT_MIN; // Valor mínimo para indicar que no hay subárbol izquierdo.
    }

    while (aux->dameTuDerecho())
    {
        aux = aux->dameTuDerecho();
    }

    return aux->dameTuDato();
}

long ArbolBB::encontrarMinimoSubarbolDerecho(Nodo *aux)
{
    if (!aux)
    {
        return INT_MAX; // Valor máximo para indicar que no hay subárbol derecho.
    }

    while (aux->dameTuIzquierdo())
    {
        aux = aux->dameTuIzquierdo();
    }

    return aux->dameTuDato();
}

int main(void)
{
    ArbolBB A;
    A.insertaUnNodo(531);
    A.insertaUnNodo(580);
    A.insertaUnNodo(540);
    A.insertaUnNodo(530);
    A.insertaUnNodo(535);
    A.insertaUnNodo(520);
    A.insertaUnNodo(525);
    A.insertaUnNodo(518);
    A.insertaUnNodo(502);
    A.insertaUnNodo(100);

    cout << "\nA en entreorden:" << endl;
    A.entreOrden();
    cout << endl
         << endl;
    cout << "\nA en Postorden:" << endl;
    A.postOrden();
    cout << endl
         << endl;
    cout << "\nA en Preorden:" << endl;
    A.preOrden();
    cout << endl
         << endl;
    cout << "\nNodos hoja de A:" << endl;
    A.mostrarNodosHoja();
    cout << "\n\nCantidad de nodos hoja: " << A.contarNodosHoja() << endl;
    cout << "\nNodos padre de A:" << endl;
    A.mostrarNodosPadre();
    cout << "\n\nCantidad de nodos en el nivel 3: " << A.contarNodosEnNivel(3) << endl;
    cout << "\nSumatoria de nodos desde el nivel 2: " << A.sumatoriaNodosDesdeNivel(2) << endl;
    cout << "\nCantidad de nodos en el nivel 2: " << A.contarNodosEnNivelX(2) << endl;
    cout << "\nValor más pequeño del árbol: " << A.encontrarMinimo() << endl;
    cout << "\nValor más grande del árbol: " << A.encontrarMaximo() << endl;
    cout << "\nValor más grande del subárbol izquierdo: " << A.encontrarMaximoSubarbolIzquierdo() << endl;
    cout << "\nValor más pequeño del subárbol derecho: " << A.encontrarMinimoSubarbolDerecho() << endl;

    return 0;
}
