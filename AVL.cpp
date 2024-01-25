#include <iostream>
using namespace std; 


struct TreeNode {
	int val;
    int height;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int max(int a, int b) { 
	return (a > b)? a : b; 
} 


int height (TreeNode* tree){
    int h=0;
    if (tree == NULL)
        return 0;
    else{
        int l_h = height(tree->left);
        int r_h = height(tree->right);

        if (l_h > r_h)
            return l_h+1;
        else
            return r_h+1; 
        }
}

int getBalance(TreeNode *tree) {
    if (tree == NULL)
        return 0;
    return height(tree->left) - height(tree->right);
}

TreeNode *rightRotation(TreeNode *y) { 
	TreeNode *x = y->left; 
	TreeNode *T2 = x->right; 

	x->right = y; 
	y->left = T2; 

	y->height = max(height(y->left), height(y->right)) + 1; 
	x->height = max(height(x->left), height(x->right)) + 1; 

	return x; 
} 

TreeNode *leftRotation(TreeNode *x) { 
	TreeNode *y = x->right; 
	TreeNode *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left), height(x->right)) + 1; 
	y->height = max(height(y->left), height(y->right)) + 1; 
	return y; 
} 

/*
TreeNode* transplant(TreeNode* T, u ,v){
    if (u->parent == NULL)
        T->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else if (u->parent->right == v)
        if (v != NULL)
            v->parent = u->parent;
}
*/

TreeNode *insert(TreeNode *root, int key) {
    if (root == NULL)
        return new TreeNode(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    else 
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left 
    if (balance > 1 && key < root->left->val)
        return rightRotation(root);

    // Right Right 
    if (balance < -1 && key > root->right->val)
        return leftRotation(root);

    // Left Right 
    if (balance > 1 && key > root->left->val) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // Right Left 
    if (balance < -1 && key < root->right->val) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}


int main(){

    TreeNode *root = NULL;

    // Árbol desbalanceado
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 8);

    // desbalance
    root = insert(root, 1);


    root = rightRotation(root); // rotación a la derecha

 
}