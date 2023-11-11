#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BST
{
private:
    Node *root;

public:
    BST() { root = nullptr; }
    Node *getroot() { return root; }
    void Insert(int key);
    void RInsert(int key);
    void Preorder(Node *p);
    void Inorder(Node *p);
    void Postorder(Node *p);
    Node *Search(int key);
};

void BST::Insert(int key)
{
    Node *t = root;
    Node *p;
    Node *r;

    // root is empty
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }

    // now t points at null and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

// preorder traversal
void BST::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

// Inorder traversal
void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

// postorder traversal
void BST::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

// search
Node *BST::Search(int key)
{
    Node *t = root;

    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return nullptr;
};

int main()
{
    BST bst;

    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);

    bst.Preorder(bst.getroot());
    cout << endl;

    bst.Inorder(bst.getroot());
    cout << endl;

    bst.Postorder(bst.getroot());
    cout << endl;

    // Search
    Node *temp = bst.Search(2);
    if (temp != nullptr)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}