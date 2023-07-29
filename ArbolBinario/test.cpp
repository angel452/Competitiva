// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <math.h>
#include <cmath>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
vector<int> a;
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* CreateNode(int key)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert element in binary tree
Node* InsertNode(Node* root, int key)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(key);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(key);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(key);
            return root;
        }
    }
}

/* Inorder traversal of a binary tree */

void inorder(Node* temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->key << ' ';
    inorder(temp->right);
}
struct Node* deletion(struct Node* root, int key)
{
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->key==key)
            return NULL;
        else
            return root;
    }
    Node* key_node=NULL;
    Node* temp;
    Node* last;
    queue<Node*> q;
    q.push(root);
    // Do level order traversal to find deepest
    // node(temp), node to be deleted (key_node)
    // and parent of deepest node(last)
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->key==key)
            key_node=temp;
        if(temp->left)
        {
            last=temp;//storing the parent node
            q.push(temp->left);
        }
        if(temp->right)
        {
            last=temp;// storing the parent node
            q.push(temp->right);
        }


    }
    if(key_node!=NULL)
    {
        key_node->key=temp->key;//replacing key_node's data to deepest node's data
        if(last->right==temp)
            last->right=NULL;
        else
            last->left=NULL;
        delete(temp);
    }
    return root;
}

int maxDepth(struct Node* temp)
{
    if (temp == NULL)
        return -1;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(temp->left);
        int rDepth = maxDepth(temp->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}


/* Function to print level
order traversal a tree*/
int height(Node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}
/* Print nodes at a current level */
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1){
        a.push_back(root->key);
        cout << root->key << " ";
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
// Iterative method to do level order traversal
// line by line
void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL) return;

    // Create an empty queue for level order traversal
    queue<Node *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false)
    {
        // nodeCount (queue size) indicates number
        // of nodes at current level.
        int nodeCount = q.size();

        // Dequeue all nodes of current level and
        // Enqueue all nodes of next level
        while (nodeCount > 0)
        {
            Node *node = q.front();
            cout << node->key << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}





/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/

void printNodesAtLevel(Node* root, int currentLevel, int level) {

    if(root == NULL) {
        return;
    }
    if(currentLevel == level) {
        printf(" %d ", root->key);
        return;
    }

    printNodesAtLevel(root->left, currentLevel+1, level);
    printNodesAtLevel(root->right, currentLevel+1, level);
}
void fill_level(int lvl,int nodesmx_level,vector<vector<int>> &mat_tre, int deep){
    //for(poner elemento){
    cout <<"quefue";
    int pos = 0;
    for(int j = 0 ; j < pow(2,lvl); j++){
        pos += floor(mat_tre.size()/lvl+2);
        mat_tre[lvl][pos-1] = 1;//a
    }
    // not working on it...
    /*
        for(int i = 1; i <=nodesmx_level;i++){
            if(i = i/(n_nodesbylvl+2)){
                //poner nodo->next cada ves por nivel
                //verificar que si hay null ponga 0 un valor vacio
                //mat_tre.push_back()
                cout<< "1" << endl;
            }
            else
                cout << endl;0,1,1-3,2-6,3-12,4-24-(2^lvl)+(2^lvl)/2
                                                2^4
        }
    //}*/
}
void print_filed_tree(Node* root,int n_nodes_maxlvl){

    int deep = maxDepth(root);
    int deeper_nodes = pow(2,deep);
    vector<int> rowt;
    rowt.assign(deep+1,0);
    vector<vector<int>> prt_tree;
    prt_tree.assign(pow(2,deep)+pow(2,deep)/2,rowt);

    //fill_level()
    for(int i = 0; i < deep; i++)
        fill_level(i,deeper_nodes,prt_tree, deep);

    for (int k = 0  ; k < prt_tree.size() ;k++){
        for(int j = 0; j < prt_tree[k].size() ; j++){
            cout << prt_tree[k][j] << " ";
            //cout << "aaaaaaaaaaaa";
        }
        cout <<endl;
    }
}
// Driver code
int main()
{
    Node* root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);



    //root->right->right = CreateNode(8);
/*
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 12;
    root = InsertNode(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;


    cout << "Inorder traversal before deletion : ";
    inorder(root);

    int data = 11;
    root = deletion(root, data);

    cout << endl;
    cout << "Inorder traversal after deletion : " ;*/
    //inorder(root);

    //cout << "Level Order traversal of binary tree is \n";
    //printLevelOrder(root);
    //printLevelOrder(root);


    //cout << "Height of tree is " << maxDepth(root);
    //cout << endl;
    //for(int i = 0;i<= maxDepth(root); i++ ){
    //    printNodesAtLevel(root,0,i);
    //cout << endl;}
    cout << "a";
    print_filed_tree(root,6);
/*
    for(auto ak = a.begin(); ak != a.end(); ak++){
        cout << *ak << " ";
    }*/
    return 0;
}
