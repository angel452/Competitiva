#include <iostream>
#include <queue>
#include <list>
#include <math.h>
#include <fstream>
std::ofstream fich("tmp1.txt");

int calcular_cifras(int n)
{
	int contador = 0;
	while (n > 0)
	{
		n = n / 10;
		contador++;
	}
	return 4 - contador;
}

template <class T>
struct CBinTreeNode
{
	CBinTreeNode(T v)
	{
		value = v;
		nodes[0] = nodes[1] = 0;
	}
	T value;
	CBinTreeNode<T>* nodes[2]; //0 left, 1 right
};

template <class T>
class CBinTree
{
public:
	CBinTree();
	CBinTreeNode<T>* Root();
	bool Find(T x, CBinTreeNode<T>**& p);
	bool Ins(T x);
	bool Rem(T x);
	CBinTreeNode<T>** Rep(CBinTreeNode<T>** p);
	int MaxDepth(CBinTreeNode<T>* n);
	void Print(CBinTreeNode<T>* n);
	void Print2(CBinTreeNode<T>* n);
	void Print3(CBinTreeNode<T>* n, int level);
	void Print4(CBinTreeNode<T>* n, int level);
	void InOrder(CBinTreeNode<T>* n);
	int MinDepth(CBinTreeNode<T>* n);
private:
	CBinTreeNode<T>* root;
	bool brep;
	int valor = 0;
};

template <class T>
CBinTree<T>::CBinTree()
{
	root = 0;
	brep = 0;
}

template <class T>
CBinTreeNode<T>* CBinTree<T>::Root()
{
	return root;
}

template <class T>
bool CBinTree<T>::Find(T x, CBinTreeNode<T>**& p)
{
	for (p = &root;
		*p && (*p)->value != x;
		p = &((*p)->nodes[(*p)->value < x])
		);
	return *p != 0;
}

template <class T>
bool CBinTree<T>::Ins(T x)
{
	CBinTreeNode<T>** p;
	if (Find(x, p)) return 0;
	*p = new CBinTreeNode<T>(x);
	return 1;
}
template <class T>
bool CBinTree<T>::Rem(T x)
{
	CBinTreeNode<T>** p;
	if (!Find(x, p)) return 0;
	if ((*p)->nodes[0] && (*p)->nodes[1])
	{
		CBinTreeNode<T>** q = Rep(p);
		(*p)->value = (*q)->value;
		p = q;
	}
	CBinTreeNode<T>* t = *p;
	*p = (*p)->nodes[(*p)->nodes[1] != 0];
	delete t;
	return 1;
}
template <class T>
CBinTreeNode<T>** CBinTree<T>::Rep(CBinTreeNode<T>** p)
{
	CBinTreeNode<T>** q;
	for (q = &(*p)->nodes[!brep];
		(*q)->nodes[brep];
		q = &(*q)->nodes[brep]);
	brep = !brep;
	return q;
}

template <class T>
int CBinTree<T>::MaxDepth(CBinTreeNode<T>* n)
{
	if (!n) return 0;
	return std::max(MaxDepth(n->nodes[0]), MaxDepth(n->nodes[1])) + 1;
}

template <class T>
int CBinTree<T>::MinDepth(CBinTreeNode<T>* n)
{
	if (!n) return 0;
	return std::min(MinDepth(n->nodes[0]), MinDepth(n->nodes[1])) + 1;
}

template <class T>
void CBinTree<T>::InOrder(CBinTreeNode<T>* n)
{
	if (!n) return;
	std::queue<T> q;
	InOrder(n->nodes[0]);
	q.push(n);
	InOrder(n->nodes[1]);
}

template <class T>
void CBinTree<T>::Print(CBinTreeNode<T>* n)
{
	if (!root) return;
	int cantidad = MaxDepth(root);
	CBinTreeNode<T>* tmp = new CBinTreeNode<T>(-1);
	std::queue< CBinTreeNode<T>* > q;
	std::queue< T > aux;
	std::queue< T > aux2;
	q.push(root);
	for (int x = 0; x < pow(2, cantidad); x++)
	{
		aux.push(q.front()->value);
		if (q.front()->nodes[0] && q.front()->value != -1) q.push(q.front()->nodes[0]);
		else
		{
			q.push(tmp);
		}
		if (q.front()->nodes[1] && q.front()->value != -1) q.push(q.front()->nodes[1]);
		else
		{
			q.push(tmp);
		}
		q.pop();
	}
	int contador = 0;
	int espacio = pow(2, cantidad);
	int nivel = 1;
	int condicion = 0;
	int medio = 1;
	aux2 = aux;
	aux2.pop();
	while (contador < cantidad)
	{
		for (int y = 0; y < nivel; y++)
		{
			if (nivel > 1)
			{
				for (int z = 0; z < espacio; z++)
				{
					fich << "    ";
				}
				if (y % 2 == 0 && aux2.front() != -1)
				{
					fich << "|   ";
				}
				else if (aux2.front() != -1)
				{
					fich << "   |";
				}
				else
				{
					fich << "    ";
				}
				aux2.pop();
				for (int z = 0; z < espacio - 1; z++)
				{
					fich << "    ";
				}
			}
		}
		fich << std::endl;
		for (int y = 0; y < nivel; y++)
		{
			if (nivel == 1)
			{
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "    ";
				}
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "____";
				}
				for (int cifras = 0; cifras < calcular_cifras(aux.front()); cifras++)
				{
					fich << 0;
				}
				fich << aux.front();
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "____";
				}
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "    ";
				}
			}
			else if (aux.front() != -1)
			{
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "    ";
				}
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "____";
				}
				for (int cifras = 0; cifras < calcular_cifras(aux.front()); cifras++)
				{
					fich << 0;
				}
				fich << aux.front();
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "____";
				}
				for (int z = 0; z < espacio / 2 - 1; z++)
				{
					fich << "    ";
				}
			}
			else
			{
				for (int z = 0; z < espacio; z++)
				{
					fich << "    ";
				}
				fich << "    ";
				for (int z = 0; z < espacio - 1; z++)
				{
					fich << "    ";
				}
			}
			aux.pop();
			medio++;
		}
		fich << std::endl;
		nivel = nivel * 2;
		contador++;
		espacio = espacio / 2;
		medio = 1;
		condicion = 0;
	}
	fich << std::endl;
}

template <class T>
void CBinTree<T>::Print2(CBinTreeNode<T>* n)
{
	if (!root) return;
	int cantidad = MaxDepth(root);
	CBinTreeNode<T>* tmp = new CBinTreeNode<T>(-1);
	std::list< CBinTreeNode<T>* > q;
	std::list< T > aux;
	std::list< T > aux2;
	q.push_back(root);
	for (int x = 0; x < pow(2, cantidad); x++)
	{
		aux.push_back(q.front()->value);
		if (q.front()->nodes[0] && q.front()->value != -1) q.push_back(q.front()->nodes[0]);
		else
		{
			q.push_back(tmp);
		}
		if (q.front()->nodes[1] && q.front()->value != -1) q.push_back(q.front()->nodes[1]);
		else
		{
			q.push_back(tmp);
		}
		q.pop_front();
	}
	int contador = 0;
	int espacio = 2;
	int nivel = pow(2, cantidad - 1);
	int condicion = 0;
	int medio = 1;
	aux.pop_back();
	aux2 = aux;
	while (contador < cantidad)
	{
		for (int y = 0; y < nivel; y++)
		{
			if (nivel == 1)
			{
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "    ";
				}
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "----";
				}
				for (int cifras = 0; cifras < calcular_cifras(aux.back()); cifras++)
				{
					fich << 0;
				}
				fich << aux.back();
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "----";
				}
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "    ";
				}
			}
			else if (aux.back() != -1)
			{
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "    ";
				}
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "----";
				}
				for (int cifras = 0; cifras < calcular_cifras(aux.back()); cifras++)
				{
					fich << 0;
				}
				fich << aux.back();
				for (int z = 0; z < espacio / 2; z++)
				{
					fich << "----";
				}
				for (int z = 0; z < espacio / 2 - 1; z++)
				{
					fich << "    ";
				}
			}
			else
			{
				for (int z = 0; z < espacio; z++)
				{
					fich << "    ";
				}
				fich << "    ";
				for (int z = 0; z < espacio - 1; z++)
				{
					fich << "    ";
				}
			}
			aux.pop_back();
			medio++;
		}
		fich << std::endl;
		for (int y = 0; y < nivel; y++)
		{
			if (nivel > 1)
			{
				for (int z = 0; z < espacio; z++)
				{
					fich << "    ";
				}
				if (y % 2 == 0 && aux2.back() != -1)
				{
					fich << "|   ";
				}
				else if (aux2.back() != -1)
				{
					fich << "   |";
				}
				else
				{
					fich << "    ";
				}
				for (int z = 0; z < espacio - 1; z++)
				{
					fich << "    ";
				}
				aux2.pop_back();
			}
		}
		fich << std::endl;
		nivel = nivel / 2;
		contador++;
		espacio = espacio * 2;
		medio = 1;
		condicion = 0;
	}
	fich << std::endl;
}

template <class T>
void CBinTree<T>::Print3(CBinTreeNode<T>* n, int level)
{
	if (!n)
	{
		return;
	}
	Print3(n->nodes[1], level + 1);
	for (int i = 0; i < level; i++)
	{
		if (level - i == 1 && level != 0) {
			fich << "      |";
			for (int i = 0; i < level; i++)
			{
				fich << "---";
			}
		}
		else {
			fich << "    ";
		}
	}
	if (n == root)
	{
		for (int cifras = 0; cifras < calcular_cifras(n->value); cifras++)
		{
			fich << 0;
		}
		fich << n->value << "----" << std::endl;
	}
	else
	{
		for (int cifras = 0; cifras < calcular_cifras(n->value); cifras++)
		{
			fich << 0;
		}
		fich << n->value << std::endl;
	}
	Print3(n->nodes[0], level + 1);
}
template <class T>
void CBinTree<T>::Print4(CBinTreeNode<T>* n, int level)
{
	if (!n)
	{
		return;
	}
	Print4(n->nodes[1], level - 1);
	for (int i = 0; i < level; i++)
	{
		fich << "    ";
	}
	if (n == root)
	{
		for (int cifras = 0; cifras < calcular_cifras(n->value); cifras++)
		{
			fich << 0;
		}
		fich << "    ----" << n->value << std::endl;
	}
	else
	{
		for (int cifras = 0; cifras < calcular_cifras(n->value); cifras++)
		{
			fich << 0;
		}
		fich << n->value;
	}
	if (level != MaxDepth(root))
	{
		fich << "---|    ";
	}
	fich << std::endl;
	Print4(n->nodes[0], level - 1);
}

int main()
{
	CBinTree<int> t;
	t.Ins(5000);
	t.Ins(8000);
	t.Ins(3000);
	t.Ins(4000);
	t.Ins(7);
	t.Ins(9000);
	t.Ins(6000);
	t.Ins(2000);
	t.Ins(9999);
	t.Print(t.Root());
	fich <<"================================================================================================================" << std::endl;
		t.Print2(t.Root());
	fich <<"================================================================================================================" << std::endl;
		t.Print3(t.Root(), 0);
	fich <<"================================================================================================================" << std::endl;
		t.Print4(t.Root(), t.MaxDepth(t.Root()));
	if (!fich)
	{
		fich << "Error al abrir ejemplo.dat\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		fich << "Hello \n";
	}
}