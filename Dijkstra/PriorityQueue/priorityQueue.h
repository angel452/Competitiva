#include<iostream>
using namespace std;

struct Node
{
    int from;
    int to;    
    int cost;
    Node *next;
};

class Lista
{
    private:    
        Node* queue = nullptr;

    public:

        bool addValue(int _from, int _to, int _cost){
            Node *newNodo = new Node(); 
            newNodo->from = _from;
            newNodo->to = _to;
            newNodo->cost = _cost;

            Node *aux1 = queue;
            Node *aux2;

            while ( (aux1 != nullptr) && (aux1->cost < _cost)){
                aux2 = aux1;
                aux1 = aux1->next;
            }

            if(queue == aux1){
                queue = newNodo;
            }   
            else{
                aux2->next = newNodo;
            }

            newNodo->next = aux1;
            return true;
        }

        bool deleteValue(int _from, int _to, int _cost){
            if(queue != nullptr){
                cout <<  endl << " Elemento con el costo: " << _cost << " sera eliminado" << endl;
                Node *aux1 = queue;
                Node *aux2 = nullptr;
                
                while ( (aux1 != nullptr) && (aux1->cost != _cost)){
                    aux2 = aux1;
                    aux1 = aux1->next;
                }

                if( aux1 == nullptr ){
                    cout << "Elemento no encontrado" << endl;
                    //return false;
                }
                else if(aux2 ==  nullptr){
                    queue = queue->next;
                    delete aux1;
                }
                else{
                    aux2->next = aux1->next;
                    delete aux1;
                }
                return true;
            }

            return true;
        }

        bool conteinsSerch(int _from, int _to, int _cost){
            Node *aux = queue;
            while (aux != nullptr)
            {
                if(aux->cost == _cost)
                {
                    cout << "SI se encontro el elemento" << endl;
                    return true;
                }
                aux = aux->next;
            }
            cout << endl;
            cout << "NO se encontro el elemento" << endl;
            return false;
        }


        void print(){
            Node *aux = queue;
            cout << "---------- Lista ------------- " << endl;
            while (aux != nullptr)
            {
                cout << "| FROM: " << aux->from << " | TO: " << aux->to << " | COST: " << aux->cost << " |" << endl;
                aux = aux->next; 
            }
            cout << endl;
        }

        int getPQ_to(){
            Node *aux = queue;
            return aux->to;
        }

        int getPQ_from(){
            Node *aux = queue;
            return aux->from;
        }

        int getPQ_cost(){
            Node *aux = queue;
            return aux->cost;
        }

        void popFunction(){
            Node *aux = queue;

            queue = queue->next;
            delete aux;
        }
};