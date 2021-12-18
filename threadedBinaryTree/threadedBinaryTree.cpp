#include <iostream>
using namespace std;

class treeNode
{
public:
    /* data */
    int data;
    treeNode *left, *right;
    bool leftThread, rightThread;

    treeNode(/* args */);
};

treeNode::treeNode(/* args */)
{
    left = right = NULL;             // bydefault null left and right child
    data = 0;                        // data set to 0 bydefault
    leftThread = rightThread = true; // bydefault thread is set to true
}

class treeTraversal
{
public:
    treeTraversal(/* args */);

    treeNode *insert(treeNode *);
    treeNode *createNode(treeNode *);
    void displayInorder(treeNode *);
    void displayPreOrder(treeNode *);
};

treeTraversal::treeTraversal(/* args */)
{
}

treeNode *treeTraversal::createNode(treeNode *temp)
{
    cout << "\nEnter the data" << endl;
    cin >> temp->data; // take the data from user
    return temp;
}

treeNode *treeTraversal::insert(treeNode *root)
{

    treeNode *r = root;              // copy the referene of head node
    treeNode *temp = new treeNode(); // create a new child
    temp = createNode(temp);         // set the data in new child
    if (root == NULL)
    {
        treeNode *head = new treeNode(); // create the head to avoid the dangling pointer
        root = temp;                     // root and first node will be same
        head->left = root;               // store root in heads left child
        head->right = head;              // right child of will point to itself
        root->left = head;               // left child of root will point to head
        root->right = head;              // right child of root will point to head
        head->leftThread = false;        // leftthread is set to false
        head->rightThread = false;       // rightThread is set to false

        return head;
    }

    root = root->left; // take original root in root variable

    // check till we dont find null root
    while (root != NULL)
    {

        if (temp->data < root->data)
        {

            // cout << "1 Done" << endl;
            if (root->leftThread == true)
            {

                temp->left = root->left;  // copy the head in temp's left part
                root->left = temp;        // copy temp in parent left part
                root->leftThread = false; // set parent left thread false
                temp->right = root;       // point right node of temp to inorder succssor

                break;
            }

            else
                root = root->left; // traverse to left
        }
        else if (temp->data > root->data)
        {

            if (root->rightThread == true)
            {
                temp->right = root->right; // copy the head in temp's right part
                root->right = temp;        // copy temp in parent right part
                root->rightThread = false; // set parent right thread false
                temp->left = root;         // point left node of temp to inorder predecessor
                break;
            }

            else
                root = root->right; // traverse to right
        }
    }

    return r; // return refeence of head
}

void treeTraversal::displayInorder(treeNode *head)
{

    if (head->left == NULL)
    {
        return; // empty tree
    }

    treeNode *root = head->left; // copy refernce to the orignal root from dummy node

    do
    {
        //  traverse to the leftmost node
        while (root->leftThread != true)
        {
            root = root->left;
        }

        cout << root->data << "  ";

        // traverse to the right most child
        while (root->rightThread == true)
        {
            root = root->right;
            if (root == head)
            {
                return;
            }
            cout << root->data << "  ";
        }
        root = root->right; // traverse back to the inorder successor
    } while (root != head);
};
void treeTraversal::displayPreOrder(treeNode *head)
{

    if (head->left == NULL)
    {
        return; // empty tree
    }
    treeNode *root = head->left;

    do
    {
        //  traverse to the leftmost node
        while (root->leftThread != true)
        {
            cout << root->data << "  ";
            root = root->left;
        }
        cout << root->data << "  ";

        // traverse to the right most child
        while (root->rightThread == true)
        {
            root = root->right;
            if (root == head)
            {
                return;
            }
        }
        root = root->right; // traverse back to the inorder successor
    } while (root != head);
};

int main()
{
    int choice;
    treeNode *root = NULL;
    treeTraversal *temp = new treeTraversal();

    do
    {
        cout << "\n1: Insert" << endl<< "2: Inorder" << endl<< "3: PreOrder" << endl<< "4: Exit" << endl;
        cout << "Enter the choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // insert node in tree
            root = temp->insert(root);
            break;
        case 2:
            //show inorder
            temp->displayInorder(root);
            break;
        case 3:
            //show inorder
            temp->displayPreOrder(root);
            break;
        case 4:
            break;
        default:
            cout<<"Invalid Choice!!!"<<endl;
        }
    } while (choice != 4);

    return 0;
}
