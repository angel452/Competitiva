#include <iostream>
#include <ctime>
#include <cstdlib>
# define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
	virtual pair<int, int> top() = 0;
	virtual pair<int, int> pop() = 0;
	virtual void push(pair<int, int>) = 0;
	virtual int getOperations() = 0;
private:
	int operations;
};

struct Node
{
	pair<int,int> data;
	int degree;
	Node *child, *sibling, *parent;
	
	explicit Node(pair<int, int>);
};

class FibonacciHeap: public Heap
{
public:
	FibonacciHeap();
	pair<int, int> top();//
	pair<int, int> pop();
	void push(pair<int, int>);//
	int getOperations();
	void printTree(Node *h);
	void printHeap();
protected:
	pair<int, int> extractMin();//
	void insertATreeInHeap(Node *tree);
	list<Node*> removeMinFromTreeReturnFHeap(Node *tree,Node*& n);//
	Node* mergeFibonacciTrees(Node *b1, Node *b2);//
	list<Node*> unionFibonacciHeap(list<Node*> l1,Node*,list<Node*> l2,Node*);//
	void adjust();//
	void insert(pair<int,int> key);
	Node* getMin();//
private:
	int operations;
	list<Node*> heap;
	Node *minNode;
};

FibonacciHeap::FibonacciHeap()
{
	operations = 0;
	minNode = NULL;
}

int FibonacciHeap::getOperations()
{
	return operations;
}

void FibonacciHeap::push(pair<int, int> Node)
{
	insert(Node);
	return;
}

pair<int, int> FibonacciHeap::top()
{
	if(heap.size() == 0)
		return make_pair(-1, -1);
	
	return getMin()->data;
}

pair<int, int> FibonacciHeap::pop()//
{
	if(heap.size() == 0)
		return make_pair(-1, -1);
	
	pair<int, int> Node = extractMin();
	
	return Node;
}

Node::Node(pair<int,int> key)
{
	this->data = key;
	this->degree = 0;
	this->child = this->parent = this->sibling = NULL;
}


void FibonacciHeap::insert(pair<int,int> key)
{
	Node *temp = new Node(key);
	insertATreeInHeap(temp);
}

list<Node*> FibonacciHeap::removeMinFromTreeReturnFHeap(Node *tree,Node*& min_lo)
{
	list<Node*> tempheap;
	Node *temp = tree->child;
	Node *lo;
	operations++;
	while (temp)
	{
		if(((temp)->data).first < (min_lo->data).first)
			min_lo = temp;
		lo = temp;
		temp = temp->sibling;
		lo->sibling = NULL;
		tempheap.push_front(lo);
	}
	return tempheap;
}


pair<int, int> FibonacciHeap::extractMin()
{
	if(heap.size() == 0)
		return make_pair(-1, -1);
	list<Node*> new_heap,lo;
	Node *temp;
	temp = getMin();
	list<Node*>::iterator it;
	it = heap.begin();
	Node *min_newheap = new Node(make_pair(INT_MAX,-1));
	Node *min_lo = new Node(make_pair(INT_MAX,-1));
	while (it != heap.end())
	{
		if (*it != temp)
		{
			new_heap.push_back(*it);
			if(((*it)->data).first < (min_newheap->data).first)
				min_newheap = (*it);
		}
		it++;
	}
	operations++;
	lo=removeMinFromTreeReturnFHeap(temp,min_lo);
	heap = unionFibonacciHeap(new_heap,min_newheap,lo,min_lo);
	adjust();
	return temp->data;
}


void swap(Node *b1,Node *b2)
{
	Node *a;
	a=b1;
	b1=b2;
	b2=a;
}

Node* FibonacciHeap::mergeFibonacciTrees(Node *b1, Node *b2)
{
	if ((b1->data).first > (b2->data).first)
	{
		swap(b1, b2);
		operations++;
	}
	b2->parent = b1;
	b2->sibling = b1->child;
	b1->child = b2;
	b1->degree++;
	
	return b1;
}

list<Node*> FibonacciHeap::unionFibonacciHeap(list<Node*> l1,Node *min1, list<Node*> l2, Node *min2)
{
	copy(l1.rbegin(), l1.rend(), front_inserter(l2));
	if(min1==NULL)
		minNode = min2;
	else if(min2==NULL)
		minNode = min1;
	else
	{
		if((min1->data).first < (min2->data).first)
			minNode = min1;
		else
			minNode = min2;
	}
	return l2;
}

void FibonacciHeap::adjust(){
	if (heap.size() <= 1)
		return;
	list<Node*>::iterator it;
	it = heap.begin();
	map<int,Node*>m;
	while(it!=heap.end()){
		while(m[(*it)->degree]!=NULL){
			int deg = (*it)->degree;
			*it = mergeFibonacciTrees(*it,m[(*it)->degree]);
			list<Node*>::iterator it_temp;
			it_temp = heap.begin();
			while((*it_temp)!=m[deg])
				it_temp++;
			it_temp=heap.erase(it_temp);
			m[deg]=NULL;
		}
		m[(*it)->degree]=(*it);
		it++;
	}
	operations++;
	return;
}

void FibonacciHeap::insertATreeInHeap(Node *tree)
{
	list<Node*> temp;
	temp.push_back(tree);
	heap = unionFibonacciHeap(heap,minNode,temp,tree);
	return;
}

Node* FibonacciHeap::getMin()
{
	if (heap.size() == 0)
		return NULL;
	return minNode;
}
void FibonacciHeap::printTree(Node *h)
{
	while (h)
	{
		printTree(h->child);
		h = h->sibling;
	}
}

void FibonacciHeap::printHeap()
{
	list<Node*> ::iterator it;
	it = heap.begin();
	while (it != heap.end())
	{
		printTree(*it);
		it++;
	}
}

class Graph{
private:
	int V;
	list< pair<int, int> > *adj;
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void shortestPath(int s);
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<pair<int, int> > [V];
}

void Graph::addEdge(int u, int v, int w){
	adj[u].push_back(make_pair(v, w));
}

void Graph::shortestPath(int src){
	Heap *heap;
	heap = new FibonacciHeap();
	
	vector<int> dist(V, INF);
	
	(*heap).push(make_pair(0, src));
	
	dist[src] = 0;
	
	while ((*heap).top() != make_pair(-1, -1))
	{
		int u = (*heap).top().second;
		(*heap).pop();
		
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				(*heap).push(make_pair(dist[v], v));
			}
		}
	}
	
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
	
	printf("Number of Operations performed : %d \n", (*heap).getOperations());
	return;
}


int main(){
    int Num_vert=9;
    Graph g(Num_vert);
		vector<vector<int> > adjacencyMatrix
			= { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
			{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
			{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
			{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
			{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
			{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
			{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
			{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
			{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
		
	const int dim=9;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(adjacencyMatrix[i][j]>0){
				g.addEdge(i,j,adjacencyMatrix[i][j]);
			}
		}
	}
	g.shortestPath(0);
	return 0;
}

