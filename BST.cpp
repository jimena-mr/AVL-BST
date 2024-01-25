#include <iostream>
#include <queue>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};


// insert element 
void insert(TreeNode* &root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }

    if (val < root->val) {
        insert(root->left, val);
    } else if (val > root->val) {
        insert(root->right, val);
    }
}


// remove element  
TreeNode* Tree_minimun(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

/*/
TreeNode* Tree_succesor(TreeNode* node){
    if (node->right != NULL)
        return Tree_minimun(node->right);
    int y = node->parent;    
    while( y != NULL && node == y->right){
        node = y;
        y = y->parent;
    }
        return y
}

*/

void remove(TreeNode* &root, int val) {
    if (root == nullptr) {
        return;
    }

    if (val < root->val) {
        remove(root->left, val);
    } else if (val > root->val) {
        remove(root->right, val);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            root = temp;
        } else {
            TreeNode* temp = Tree_minimun(root->right);
            root->val = temp->val;
            remove(root->right, temp->val);
        }
    }
}


void BFS(TreeNode* root) {
        queue<TreeNode*> queue1;
        queue1.push(root);
        while( queue1.size() != 0 ){
            TreeNode* node = queue1.front();
            queue1.pop();
            cout << node->val << " ";

            if ( node->left != nullptr ){
                queue1.push(node->left);
            }

            if (node->right != nullptr){
                queue1.push(node->right);
            }    // node->left == nullptr || node->right == nullptr

            
        }
}


int main(){
    TreeNode* root = nullptr;

    // insertando valores en el arbol
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // Realizando un BFS luego de insertar o remover valores
    cout << "BST after insertion: ";
    BFS(root);
    cout << endl;

    remove(root, 3);

    cout << "BST after removing 3: ";
    BFS(root);
    cout << endl;

    remove(root, 5);

    cout << "BST after removing 5: ";
    BFS(root);
    cout << endl;
 
}