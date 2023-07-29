// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <math.h>
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;
int val[] = {1,2,3,4,11,23};
vector<int> keyes_order;
auto keys_it = keyes_order.begin();
vector<int> a;
struct Node {
    int key;
    Node* left;
    Node* right;
};
Node* CreateNode(int key)
{
    Node* newNode = new Node();
    if (!newNode) {
        //cout << "Memory error\n";
        return NULL;
    }
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* InsertNode(Node* root, int key)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(key);
        return root;
    }

  
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
void inorder(Node* temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    //cout << temp->key << ' ';
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
        //cout << root->key << " ";
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

    while (1)
    {
        int nodeCount = q.size();

        if (nodeCount == 0)
            break;
        while (nodeCount > 0)
        {
            Node *node = q.front();
            q.pop();

            if (!node) {
                //cout << "null" << " ";
                keyes_order.push_back(99);
            } else {
                keyes_order.push_back(node->key);
                //cout << node->key << " ";
                q.push(node->left);
                q.push(node->right);
            }

            nodeCount--;
        }
        //cout << endl;
    }
}

void levelorder(Node *root){
    int null_in_queue = 0;
    queue<Node*> q;

    q.push(root);
    //cout <<q.size() << " "<< null_in_queue <<endl;
    while(q.size() != null_in_queue){
        Node* temp=q.front();
        q.pop();
        if(!temp)
        {
            keyes_order.push_back(99);
            //cout << 0 << " ";
            q.push(NULL);
            q.push(NULL);
            null_in_queue++; // One was removed, two were added
        }
        else
        {
             //cout << temp->key << " ";
            keyes_order.push_back(temp->key);
            q.push(temp->left);
            q.push(temp->right);
            if (!temp->left) null_in_queue++;
            if (!temp->right) null_in_queue++;
        }
    }cout <<endl;
    for(auto ak = keyes_order.begin(); ak != keyes_order.end(); ak++){
        cout << *ak << " ";
    }cout <<endl;


}

void printNodesAtLevel(Node* root, int currentLevel, int level) {

    if(root == NULL) {
        keyes_order.push_back(0);
        //cout << "\t" ;
        return;
    }
    if(currentLevel == level) {
        keyes_order.push_back(root->key);
        //printf(" %d ", root->key);

        return;
    }

    printNodesAtLevel(root->left, currentLevel+1, level);
    printNodesAtLevel(root->right, currentLevel+1, level);
}
void printmt(vector<vector<int>> &mat_tre){
    ofstream f("file1.txt",fstream::app);
    if (f.is_open()){
    for (int k = 0  ; k < mat_tre.size() ;k++){
        for(int j = 0; j < mat_tre[k].size() ; j++){
            if(mat_tre[k][j] == 0){
                cout << "\t";
                f << "\t" ;
            }
            else{
                cout << mat_tre[k][j] << "\t";
                f << mat_tre[k][j] << "\t";
            //cout << "aaaaaaaaaaaa";
            }
        }
        cout <<endl;
        f << '\n';
    }
    }
    f.close();
}

vector<vector<int>> rotate(vector<vector<int>> input){

    int n =input.size();
    int m = input[0].size();
    vector<int> val1 ;
    val1.assign(n,0);
    vector<vector<int>> output;
    output.assign(m,val1);

        for (int i=0; i<n; i++)
            for (int j=0;j<m; j++)
                output [j][n-1-i] = input[i][j];
        return output;




}
void fill_level(int lvl,int nodesmx_level,vector<vector<int>> &mat_tre, int deep){
    //for(poner elemento){
    //cout <<"quefue";
    int lv_c= lvl;
    int divs = val[deep] ;
    int pos = 0;

    for(int j = 0 ; j < pow(2,lvl); j++){
        
        if(*keys_it == 0){
            keys_it++;
            j++;
        } else {
            mat_tre[divs][lvl] = *keys_it;
            keys_it++;
        }

        //lv_c--;
        divs += val[deep] ;

        //divs  = val[]
    }
    
}
void print_filed_tree(Node* root,int n_nodes_maxlvl){

    int deep = maxDepth(root);
    int deeper_nodes = pow(2,deep);
    vector<int> rowt;
    rowt.assign(deep+1,0);
    vector<vector<int>> prt_tree;
    prt_tree.assign(pow(2,deep)+pow(2,deep)/2,rowt);
 
    int ite_dep = deep;
    for(int i = 0; i <= deep; i++){
        fill_level(i,deeper_nodes,prt_tree, ite_dep--);
    }
    printmt(prt_tree);

    vector<vector<int>> prt_3 = rotate(prt_tree);
  

    vector<vector<int>> prt_4 = rotate(prt_3);
    vector<vector<int>> prt_5 = rotate(prt_4);
   
    cout<<endl;
    printmt(prt_3);
    cout<<endl;
    printmt(prt_4);
    cout<<endl;
    printmt(prt_5);

}

int main()
{
    Node* root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root = InsertNode(root, 4);
    root = InsertNode(root, 5);
    root = InsertNode(root, 6);
    

    levelorder(root);

    keys_it = keyes_order.begin();

    print_filed_tree(root,6);




    return 0;
}