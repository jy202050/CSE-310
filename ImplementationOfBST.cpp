// Title: Implementation of BST
// Desc: Paritially completed C++ implementation of BST is given
// Author: JIAYUAN YU
// Date: 06/14/2023



#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
public:
    class node
    {
    public:
        node* left;
        node* right;
        node* parent;
        int key;
        string data;
    };

    node* root;

    BinarySearchTree()
    {
        root = NULL;
    }

    bool isEmpty() const { return root == NULL; }

    void INORDER_TREE_WALK(node*);
    void TREE_INSERT(int);
    void POSTORDER_TREE_WALK(node*);
    void PREORDER_TREE_WALK(node*);
    node* TREE_MINIMUM(node*);
    void REMOVE_MINIMUM();
    node* TREE_SUCCESSOR(node*);
    void TREE_DELETE(int);
};

void BinarySearchTree::TREE_INSERT(int d)
{
    node* z = new node();
    z->key = d;
    z->left = NULL;
    z->right = NULL;
    node* y = NULL;
    node* x = root;
    node* parent = NULL;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    parent = y;
    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
    if (x != NULL)
    {
        if (x->left)
            INORDER_TREE_WALK(x->left);
        cout << " " << x->key << " ";
        if (x->right)
            INORDER_TREE_WALK(x->right);
    }
}

void BinarySearchTree::POSTORDER_TREE_WALK(node* x)
{
    if (x != NULL)
    {
        if (x->left)
            POSTORDER_TREE_WALK(x->left);
        if (x->right)
            POSTORDER_TREE_WALK(x->right);
        cout << " " << x->key << " ";
    }
}

void BinarySearchTree::PREORDER_TREE_WALK(node* x)
{
    if (x != NULL)
    {
        cout << " " << x->key << " ";
        if (x->left)
            PREORDER_TREE_WALK(x->left);
        if (x->right)
            PREORDER_TREE_WALK(x->right);
    }
}

BinarySearchTree::node* BinarySearchTree::TREE_MINIMUM(node* x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}

void BinarySearchTree::REMOVE_MINIMUM()
{
    if (root == NULL)
        return;
    node* x = root;
    node* parent = NULL;
    while (x->left != NULL)
    {
        parent = x;
        x = x->left;
    }
    if (x->right != NULL)
    {
        if (parent == NULL)
            root = x->right;
        else
            parent->left = x->right;
    }
    else
    {
        if (parent == NULL)
            root = NULL;
        else
            parent->left = NULL;
    }
    delete x;
}

BinarySearchTree::node* BinarySearchTree::TREE_SUCCESSOR(node* x)
{
    if (x->right != NULL)
    {
        return TREE_MINIMUM(x->right);
    }
    node* y = x->parent;
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

void BinarySearchTree::TREE_DELETE(int d)
{
    node* z = root;
    node* parent = NULL;
    while (z != NULL && z->key != d)
    {
        parent = z;
        if (d < z->key)
            z = z->left;
        else
            z = z->right;
    }
    if (z == NULL)
        return;
    if (z->left == NULL)
    {
        if (parent == NULL)
            root = z->right;
        else if (z == parent->left)
            parent->left = z->right;
        else
            parent->right = z->right;
    }
    else if (z->right == NULL)
    {
        if (parent == NULL)
            root = z->left;
        else if (z == parent->left)
            parent->left = z->left;
        else
            parent->right = z->left;
    }
    else
    {
        node* y = TREE_SUCCESSOR(z);
        if (y->parent != z)
        {
            if (y->right != NULL)
                y->right->parent = y->parent;
            y->parent->left = y->right;
            y->right = z->right;
            y->right->parent = y;
        }
        if (parent == NULL)
            root = y;
        else if (z == parent->left)
            parent->left = y;
        else
            parent->right = y;
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
}

int main()
{
    BinarySearchTree bst;
    int choice, key;
    while (true)
    {
        cout << endl << endl;
        cout << " Binary Search Tree Example " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Insertion " << endl;
        cout << " 2. In-Order Traversal " << endl;
        cout << " 3. Post-Order Traversal " << endl;
        cout << " 4. Pre-Order Traversal " << endl;
        cout << " 5. Find Minimum " << endl;
        cout << " 6. Remove Minimum " << endl;
        cout << " 7. Successor " << endl;
        cout << " 8. Delete " << endl;
        cout << " 9. Exit " << endl;
        cout << " Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << " Enter key (int value) to be inserted : ";
                cin >> key;
                bst.TREE_INSERT(key);
                break;
            case 2:
                cout << endl;
                cout << " In-Order Traversal " << endl;
                cout << " -------------------" << endl;
                bst.INORDER_TREE_WALK(bst.root);
                break;
            case 3:
                cout << endl;
                cout << " Post-Order Traversal " << endl;
                cout << " --------------------" << endl;
                bst.POSTORDER_TREE_WALK(bst.root);
                break;
            case 4:
                cout << endl;
                cout << " Pre-Order Traversal " << endl;
                cout << " -------------------" << endl;
                bst.PREORDER_TREE_WALK(bst.root);
                break;
            case 5:
                cout << endl;
                cout << " Minimum Key: " << bst.TREE_MINIMUM(bst.root)->key << endl;
                break;
            case 6:
                cout << endl;
                cout << " Removing Minimum Key" << endl;
                bst.REMOVE_MINIMUM();
                break;
            case 7:
                cout << endl;
                cout << " Enter key (int value) to find its successor: ";
                cin >> key;
                {
                    BinarySearchTree::node* node = bst.root;
                    while (node != NULL && node->key != key)
                    {
                        if (key < node->key)
                            node = node->left;
                        else
                            node = node->right;
                    }
                    if (node != NULL)
                    {
                        BinarySearchTree::node* successor = bst.TREE_SUCCESSOR(node);
                        if (successor != NULL)
                            cout << " Successor of " << key << ": " << successor->key << endl;
                        else
                            cout << " No successor found for " << key << endl;
                    }
                    else
                    {
                        cout << " Key " << key << " not found in the tree" << endl;
                    }
                }
                break;
            case 8:
                cout << endl;
                cout << " Enter key (int value) to be deleted : ";
                cin >> key;
                bst.TREE_DELETE(key);
                break;
            case 9:
                system("pause");
                return 0;
            default:
                cout << "Invalid choice";
        }
    }
}
