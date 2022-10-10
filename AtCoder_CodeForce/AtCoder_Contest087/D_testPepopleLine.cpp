#include<cstdio>
#include<iostream>
#define MAX (100000 + 20)
using namespace std;
 
struct Node {
	Node* next = this;
	int pos = 0;
}p[MAX];
 
Node* find(Node* p) {
	if(p->next == p) 
		return p;
	Node* root = find(p->next);
	p->pos += p->next->pos;
	p->next = root;
	return p->next;
}
 
int main() {
	int n, m;
	int l, r, d;
	bool ok = true;
	Node *root_l, *root_r;

	cin >> n >> m;
	
	for(int i=0; i<m; i++) 
    {
		cin >> l >> r >> d;
		root_l = find(&p[l]), root_r = find(&p[r]);
		if(root_l != root_r) {
			root_l->pos = p[r].pos - p[l].pos - d;
			root_l->next = root_r;
		} else if(p[l].pos + d != p[r].pos){
			ok = false;
			break;
		}
	}
	cout << (ok ? "Yes" : "No");
	return 0;
}