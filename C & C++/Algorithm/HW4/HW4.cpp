#include <iostream>
using namespace std;

class BTNode
{
    int *x;
    int *y;
    char *z;
    int min_degree;
    int flag;          // for building tree
    BTNode **Children; // Child pointers array
    int n;             // # of nodes
    bool leaf;         // True => node is leaf, otherwise false
public:
    BTNode(int _minDegree, bool _leaf, int _flag); // Constructor

    void insertNF(int x, int y, char z);

    void split(int i, BTNode *y);

    void prefixTraverse();

    friend class BTree;
};

class BTree
{
    BTNode *root;
    int min_degree;
    int flag;

public:
    BTree(int degree, int _flag)
    {
        root = NULL;
        min_degree = degree;
        flag = _flag;
    }
    void prefixTraverse()
    {
        if (root != NULL)
            root->prefixTraverse();
    }
    void insert(int x_added, int y, char z);
};

BTNode::BTNode(int t1, bool leaf1, int flag1)
{
    min_degree = t1;
    leaf = leaf1;
    flag = flag1;
    x = new int[2 * min_degree - 1];
    y = new int[2 * min_degree - 1];
    z = new char[2 * min_degree - 1];
    Children = new BTNode *[2 * min_degree];
    n = 0;
}

void BTNode::prefixTraverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "(" << x[i] << "," << y[i] << "," << z[i] << ")";
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
        {
            Children[i]->prefixTraverse();
        }
    }
    if (leaf == false)
    {
        Children[i]->prefixTraverse();
    }
}

void BTree::insert(int x_added, int y, char z)
{
    if (root == NULL)
    {
        root = new BTNode(min_degree, true, flag);
        root->x[0] = x_added;
        root->y[0] = y;
        root->z[0] = z;
        root->n = 1;
    }
    else
    {
        if (root->n == 2 * min_degree - 1)
        {
            bool isLeaf = false;
            BTNode *s = new BTNode(min_degree, isLeaf, flag);
            s->Children[0] = root;
            s->split(0, root);
            int i = 0;
            if (flag == 0)
            {
                if (s->x[0] < x_added)
                    i++;
                s->Children[i]->insertNF(x_added, y, z);
                root = s;
            }
            if (flag == 1)
            {
                if (s->y[0] < y)
                    i++;
                s->Children[i]->insertNF(x_added, y, z);
                root = s;
            }
            if (flag == 2)
            {
                if (s->z[0] < z)
                    i++;
                s->Children[i]->insertNF(x_added, y, z);
                root = s;
            }
        }
        else
            root->insertNF(x_added, y, z);
    }
}

void BTNode::insertNF(int x_added, int y_added, char z_added)
{
    int i = n - 1;

    if (leaf == true)
    {
        if (flag == 0)
        {
            while (i >= 0 && x[i] > x_added)
            {
                x[i + 1] = x[i];
                z[i + 1] = z[i];
                y[i + 1] = y[i];
                i--;
            }
        }
        else if (flag == 1)
        {
            while (i >= 0 && y[i] > y_added)
            {
                x[i + 1] = x[i];
                z[i + 1] = z[i];
                y[i + 1] = y[i];
                i--;
            }
        }
        else if (flag == 2)
        {
            while (i >= 0 && z[i] > z_added)
            {
                x[i + 1] = x[i];
                z[i + 1] = z[i];
                y[i + 1] = y[i];
                i--;
            }
        }

        x[i + 1] = x_added;
        y[i + 1] = y_added;
        z[i + 1] = z_added;
        n = n + 1;
    }
    else
    {
        if (flag == 0)
        {
            while (i >= 0 && x[i] > x_added)
                i--;
        }
        else if (flag == 1)
        {
            while (i >= 0 && y[i] > y_added)
                i--;
        }
        else if (flag == 2)
        {
            while (i >= 0 && z[i] > z_added)
                i--;
        }

        if (Children[i + 1]->n == 2 * min_degree - 1)
        {
            split(i + 1, Children[i + 1]);

            if (flag == 0)
            {
                if (x[i + 1] < x_added)
                    i++;
            }
            else if (flag == 1)
            {
                if (y[i + 1] < y_added)
                    i++;
            }
            else if (flag == 2)
            {
                if (z[i + 1] < z_added)
                    i++;
            }
        }
        Children[i + 1]->insertNF(x_added, y_added, z_added);
    }
}

void BTNode::split(int i, BTNode *y0)
{
    BTNode *z0 = new BTNode(y0->min_degree, y0->leaf, y0->flag);
    z0->n = min_degree - 1;
    bool isNotLeaf = false;
    for (int j = 0; j < min_degree - 1; j++)
    {
        z0->x[j] = y0->x[j + min_degree];
        z0->y[j] = y0->y[j + min_degree];
        z0->z[j] = y0->z[j + min_degree];
    }
    if (y0->leaf == isNotLeaf)
    {
        for (int j = 0; j < min_degree; j++)
            z0->Children[j] = y0->Children[j + min_degree];
    }
    y0->n = min_degree - 1;

    for (int j = n; j >= i + 1; j--)
        Children[j + 1] = Children[j];

    Children[i + 1] = z0;

    for (int j = n - 1; j >= i; j--)
    {
        x[j + 1] = x[j];
        y[j + 1] = y[j];
        z[j + 1] = z[j];
    }
    x[i] = y0->x[min_degree - 1];
    y[i] = y0->y[min_degree - 1];
    z[i] = y0->z[min_degree - 1];
    n = n + 1;
}

int main()
{
    int node_count, degree_of_BT;
    cin >> node_count;
    cin >> degree_of_BT;
    char keydegree_to_be_considered;
    cin >> keydegree_to_be_considered;
    int flag = 0;
    if (keydegree_to_be_considered == 'x')
        flag = 0;
    if (keydegree_to_be_considered == 'y')
        flag = 1;
    if (keydegree_to_be_considered == 'z')
        flag = 2;

    BTree bTree(degree_of_BT, flag);
    int first_number;
    int second_number;
    char letter;
    for (int i = 0; i < node_count; i++)
    {
        cin >> first_number >> second_number >> letter;
        bTree.insert(first_number, second_number, letter);
    }

    bTree.prefixTraverse();

    return 0;
}
