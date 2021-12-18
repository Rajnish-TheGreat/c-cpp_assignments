#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class node
{
public:
    int data;
    node *right, *left;
};

class b_tree
{
public:
    node *root;
    node *create();
    void inorder(node *);
    void leaf(node *);
    int countleaf(node *);
    node *copy(node *);
    int height(node *);
    b_tree()
    {
        root = NULL;
    }
};

node *b_tree::create()
{
    node *root;
    char ans, L, R;
    int x;
    cout << "\nEnter the value of X:\t";
    cin >> x;
    root = new node;
    root->data = x;
    if (x == -1)
    {
        return NULL;
    }
    cout << "\nEnter to the left of: " << x;
    root->left = create();
    cout << "\nEnter to the right of: " << x;
    root->right = create();
    return root;
}

void b_tree::leaf(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        cout << "\nLeaf Node is: " << root->data;
        return;
    }
    leaf(root->left);
    leaf(root->right);
}

int b_tree::countleaf(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countleaf(root->left) + countleaf(root->right);
}

node *b_tree::copy(node *root)
{
    node *temp;
    node *newnode;
    if (root != NULL)
    {
        temp = new node;
        temp->data = root->data;
        temp->left = copy(root->left);
        temp->right = copy(root->right);
    }
    return temp;
}

int b_tree::height(node *root)
{
    int d1, d2;
    if (root->left == NULL && root->right == NULL)
        return 0;
    d1 = 1 + height(root->left);
    d2 = 1 + height(root->right);
    if (d1 >= d2)
    {
        return d1;
    }
    else
    {
        return d2;
    }
}

void b_tree::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

int main()
{
    b_tree b;
    int count = 0;
    b.root = b.create();
    int choice, height;
    do
    {
        cout << "\n*****MENU*****";
        cout << "\n1 Display nodes\n";
        cout << "\n2.Find leaf node\n";
        cout << "\n3.No. of leaf nodes\n";
        cout << "\n4.Copy tree\n";
        cout << "\n5.Height of the tree\n";
        cout << "\n6.Exit";
        cout << "\nEnter your choice:::";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b.inorder(b.root);
            break;
        case 2:
            b.leaf(b.root);
            break;
        case 3:
            count = b.countleaf(b.root);
            cout << "\n"<< count;
            break;
        case 4:
            b.copy(b.root);
            cout << "\nTree copied successfully\n";
            break;
        case 5:
            height = b.height(b.root);
            cout << "\nHeight of tree is==>" << height;
            break;
        case 6:
            cout << "\nExiting...";
            break;
        default:
            cout << "Invalid Choice!!!";
        }
    } while (choice!=6);
    return 0;
}
