#include <iostream> 
#include <vector>
using namespace std;

struct Nodo
{
    int pos;
    Nodo *anterior;
    Nodo *siguiente;
    
};

void mostrarDatos(Nodo *lista) //muestra los datos de derecha a izquierda e izquierda a derecha
{
    Nodo *puntero = new Nodo();
    puntero = lista;

    cout << "Lista de siguientes" << endl;
    do
    {
        cout << puntero->pos << " --> ";
        puntero = puntero->siguiente;
    } while (puntero->siguiente != NULL);
    cout << puntero->pos;
    
    cout <<endl <<"Lista de anteriores" << endl;
    while(puntero->pos != lista->pos)
    {
        cout << puntero->pos << " --> ";
        puntero = puntero->anterior;
    }
    cout << puntero->pos; 
    cout << endl;
}

int contadorNodos(Nodo *&head)
{
    int contador = 0;
    Nodo *aux = head;
    while(aux != NULL)
    {
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}

bool nodoRetorno(Nodo *&head, int x)
{
    //cout << "dentro" << endl;
    //cout << "test: " << head->pos << endl;
    if(head->pos == x)
    {   
        //cout << "retorna true" << endl;
        return true;
    }
    //cout << "retorna false" << endl;
    return false;
}

bool buscarNodo(Nodo *head, int n)
{
    Nodo *puntero = new Nodo();
    puntero = head;

    while(puntero != NULL)
    {
        if (puntero->pos == n)
        {
           return true;
        }
        puntero = puntero->siguiente;
    }

    return false;
}

void insertarNodo(Nodo *&head, int pos_x)
{
    //cout << "Entrammos a la funcion" << endl;
    //Verificar si el nodo ya esta
    if( buscarNodo(head,pos_x) )
    {
        return;
    }
    //cout << "flag1" << endl;

    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->pos = pos_x;

    Nodo *aux1 = head;
    Nodo *aux2;

    while((aux1 != NULL)&&(aux1->pos < pos_x)) // colocamos aux1  hasta llegar a null o su sucesor y aux 2 en el anterior
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    //cout << "flag2" << endl;

    if(head == aux1) // lista vacia
    {
        head = nuevoNodo;
    }
    else
    {
        aux2->siguiente = nuevoNodo;
        nuevoNodo->anterior = aux2;
    }

    //cout << "flag3" << endl;

    nuevoNodo->siguiente = aux1;
    if( (nodoRetorno(head,pos_x)) && (contadorNodos(head)>1) ) //caso cuando se inserta un nodo a la derecha
    {
        //cout << "flag4" << endl;
        aux1->anterior = nuevoNodo;
        //cout << "flag5" << endl;
    }
    //cout << "fin de la funcion" << endl;
}

void insertarNodo2(Nodo *&head, int l, int r)
{
    // Caso 1: Lista vacia
    if ( head == NULL )
    {
        Nodo *nuevoNodo3 = new Nodo();
        nuevoNodo3->pos = l;

        Nodo *aux3 = head;

        head = nuevoNodo3;

        Nodo *nuevoNodo4 = new Nodo();
        nuevoNodo4->pos = r;

        nuevoNodo3->siguiente = nuevoNodo4;

        nuevoNodo3->siguiente = aux3;
    }

    //Caso 2: 


    //Verificar si el nodo ya esta
    if( buscarNodo(head,l) )
    {
        return;
    }
    //cout << "flag1" << endl;

    Nodo *nuevoNodo1 = new Nodo();
    nuevoNodo1->pos = l;

    Nodo *nuevoNodo2 = new Nodo();
    nuevoNodo2->pos = r;

    Nodo *aux1 = head;
    Nodo *aux2;

    while((aux1 != NULL)&&(aux1->pos < l)) // colocamos aux1  hasta llegar a null o su sucesor y aux 2 en el anterior
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    //cout << "flag2" << endl;

    if(head == aux1) // lista vacia
    {
        head = nuevoNodo1;
    }
    else
    {
        aux2->siguiente = nuevoNodo1;
        nuevoNodo1->anterior = aux2;
    }

    //cout << "flag3" << endl;

    nuevoNodo1->siguiente = aux1;
    if( (nodoRetorno(head,l)) && (contadorNodos(head)>1) ) //caso cuando se inserta un nodo a la derecha
    {
        //cout << "flag4" << endl;
        aux1->anterior = nuevoNodo1;
        //cout << "flag5" << endl;
    }
    //cout << "fin de la funcion" << endl;
}

// #####################################################################################
int main()
{
    int n, m, l, r, d;
    bool ok=true;

    cout << "numero de personas: "; cin>>n; //personas
    cout << "numero de targetas: "; cin>>m; //n info

    int **matriz = new int*[m*2];
    for(int i = 0; i < m*2; i++)
    {
        matriz[i] = new int[3];
    }

    for(int i = 0; i < m*2; i++)
    {
        for( int j = 0; j < 3; j++)
        {
            if( i%2 == 0 )
            {
                cin>>matriz[i][j];
            }
            else
            {
                matriz[i][j] = matriz[i-1][j+1];
                j++;
                matriz[i][j] = matriz[i-1][j-1];
                j++;
                matriz[i][j] = (matriz[i-1][j])*(-1);
            }
        }
    }

    /*
    // Mostrar matriz
    for(int i = 0; i < m*2; i++)
    {
        for( int j = 0; j < 3; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    */

    Nodo *head = NULL;
    
    for(int i=0; i<m*2; i++) 
    {
        /*
        cout << "L: "; cin >> l; 
        cout << "R: "; cin >> r;
        cout << "D: "; cin >> d;

        cout << "insertando el primer dato" << endl;
        insertarNodo(head,l);
        cout << "insertando el segundo dato" << endl;
        insertarNodo(head,r);
        */

       insertarNodo2(head,matriz[i][0], matriz[i][1]);

        cout << "insertando ficha " << i+1 << endl;
        insertarNodo2(head,l,r);

    }

    mostrarDatos(head);

    return 0;
}