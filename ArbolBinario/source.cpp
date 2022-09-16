#include "tree.h"

void printTest1()
{
    TreeNode *root = new TreeNode(0);

    root->right = new TreeNode(1);
    root->left = new TreeNode(2);

    root->right->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(6);

    root->right->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(8);
    
    root->right->left->right = new TreeNode(9);
    root->right->left->left = new TreeNode(10);

    root->left->right->right = new TreeNode(11);
    root->left->right->left = new TreeNode(12);

    root->left->left->right = new TreeNode(13);
    root->left->left->left = new TreeNode(14);
 
    cout << endl << "------ Vertical 1 --------------- "<< endl;
    printNodesV1(root,0);

    cout << endl << "------ Vertical 2 --------------- "<< endl;
    printNodesV2(root,3); //3 = profundidad del arbol
    //cout << endl;

    cout << endl << "------ Horizontal 1 --------------- "<< endl;
    printNodesH1(root);

    cout << endl << "------ Horizontal 2 --------------- "<< endl;
    printNodesH2(root);

}

int main(void)
{
    //print_tree_test_1();
    printTest1();

    return 0;
}