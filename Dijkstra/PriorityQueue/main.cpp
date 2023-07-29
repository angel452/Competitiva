#include <iostream>
#include <vector>
#include "priorityQueue.h"
using namespace std;

int nVertices;
int matrizAdy[100][100];
int matrizResultados[100][2]; // Matriz de resultados o caminos optimos 
bool matrizComprobadora[100]; // para comprobar que todos los vertices ya fueron analisados
Lista priorityQueue; // cola de prioridad

int function1( int vertice ){

    // llenamos los vertices en la cola
    for( int i = 0; i < nVertices; i++ ){
        cout << "evaluacion: " << vertice << " con " << i << endl;
        if( matrizAdy[vertice][i] != 0 && matrizComprobadora[i] == false){
            cout << "Añadiendo" << endl;
            priorityQueue.addValue( vertice, i, matrizAdy[vertice][i] + matrizResultados[vertice][1] );
        }
    }
    priorityQueue.print();

    // Llenoamos el dato de mas prioridad en la tabla resultados:
    int posicionTo = priorityQueue.getPQ_to();
    int posicionFrom = priorityQueue.getPQ_from();
    int posicionCost = priorityQueue.getPQ_cost();

    matrizResultados[posicionTo][0] = posicionFrom;
    matrizResultados[posicionTo][1] = posicionCost;
    matrizComprobadora[posicionTo] = true;

    // eliminamos de la cola de prioridad
    priorityQueue.popFunction();

    cout << "Comprobaciones" << endl;
    priorityQueue.print();
    cout << endl;
    cout << "Matriz de resultados..." << endl;
    for( int i = 0; i < nVertices; i++ ){
        for( int j = 0; j < 2; j++ )
        {
            cout << matrizResultados[i][j] << " ";
        }
        cout << endl;
    }

    //function1( posicionTo );
    return posicionTo;
}

vector<int> printPath2(int v2){
    vector <int> path;
    while(v2 != 0){
        //cout << "v2: " << v2 << endl;
        path.push_back(v2);
        v2 = matrizResultados[v2][0];
    }
    path.push_back(0);
    return path;
}

void printPath(int v2){
    vector <int> path;

    path = printPath2(v2);

    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " -> ";
    }
}

int main(){
    
    //int nVertices; 
    cout << "Numero de vertices: "; cin >> nVertices; // numero de vertices

    cout << "Inserte la matriz de adyacecncia: " << endl;
    for(int i = 0; i < nVertices; i++)
    {
        for(int j = 0; j < nVertices; j++)
        {
            cin >> matrizAdy[i][j];
        }
    }

    cout << "Matriz de Adyacencia..." << endl;
    for( int i = 0; i < nVertices; i++ ){
        for( int j = 0; j < nVertices; j++ )
        {
            cout << matrizAdy[i][j] << " ";
        }
        cout << endl;
    }

    //Marcar los primeros numeros como visitado
    matrizResultados[0][0] = 0;
    matrizResultados[0][1] = 0;

    for( int i = 0; i < nVertices; i++ ){
        matrizComprobadora[i] = false;
    }
    matrizComprobadora[0] = true;

    //function1(0);
    int comprobador = nVertices - 1;
    int aux = 0;
    while (comprobador > 0)
    {
        cout << "VERTICE: " << aux << endl; 
        aux = function1(aux);
        comprobador = comprobador - 1;
    }

    cout << " ---- Matriz de resultados ----- " << endl;
    cout << "|   Nodo   |   From   |     Cost    |" << endl;
    for( int i = 0; i < nVertices; i++ ){
        cout << "     " << i;
        for( int j = 0; j < 2; j++ )
        {
            cout << "           "<< matrizResultados[i][j];
        }
        cout << endl;
    }

    
    cout << " ------ Caminos --------" << endl;
    cout << "|   Nodos   |   Distance   |     Path    |" << endl;
    for( int i = 0; i < nVertices; i++ ){
        cout << "   0 -> " << i;
        cout << "          " <<  matrizResultados[i][1];
        cout << "          ", printPath(i);
        cout << endl;
    } 

    cout << endl;

    /*
    numero de vertices: 4
    */

    /*
    0 5 8 0
    5 0 9 2
    8 9 0 6
    0 2 6 0
    */

    return 0;
}
