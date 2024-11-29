#include <iostream>
using namespace std;

struct node
{
    node *child;
    node *sibling;
    node *parent;
    char data;
};

int brackets(string expression);
int check_syntax(string expression);
node *construct(string expression);
void inOrder(node *T);
void preOrder(node *T);
void postOrder(node *T);


int main()
{
    string text;
    cout << "ENTER A TREE DEFINING EXPRESSION: ";
    cin >> text;
    if (check_syntax(text))
    {
        node *Mytree = construct(text);
        cout <<"\nINORDER (LNR) TRAVERSAL OF THE TREE\n";
        inOrder(Mytree);
        cout <<"\nPREORDER (NLR) TRAVERSAL OF THE TREE\n";
        preOrder(Mytree);
        cout <<"\nPOSTORDER (LRN) TRAVERSAL OF THE TREE\n";
        postOrder(Mytree);
        return 0;
    }
    else{
        cout<<"PARSING ABORTED\n";
        return 0;
    }
}

int brackets(string expression)
{
    int n = 0;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
            n++;
        else if (expression[i] == ')')
            n--;
    }
    if (n == 0)
        return 1;
    else
    {
        cout << " ERROR: Unbalanced brackets";
        return 0;
    }
}

int check_syntax(string expression)
{
    if (expression[0] != '(' && expression[0] != ')' && brackets(expression))
        return 1; //single character case
    
    else if (expression[1] == '(' && brackets(expression)) //multiple character case
    {
        for (int i = 1; expression[i] != '\0'; i++)
        {
            if (expression[i] == '(' && expression[i - 1] == '(')
            {
                cout << " ERROR: Expression cannot consist of (( \n";
                return 0;
            }
            if (expression[i] == '(' && expression[i - 1] == ')')
            {
                cout << " ERROR Expression cannot consist of )(\n";
                return 0;
            }
            if (expression[i] == ')' && expression[i - 1] == '(')
            {
                cout << " ERROR Expression cannot consist of ()\n";
                return 0;
            }
        }
        return 1;
    }
    else
    {
        cout << " INVALID EXPRESSION \n";
        return 0;
    }
}

node *construct(string expression)
{
    node *root; // tree head pointer
    node *currNode;
    node *nextNode;
    // create root and set pointers to null
    nextNode = new node;
    nextNode->child = nullptr;
    nextNode->parent = nullptr;
    nextNode->sibling = nullptr;
    nextNode->data = expression[0];
    root = nextNode; // SAVE TREE ROOT IN T
    currNode = nextNode;
    int i = 1;
    while (expression[i] != '\0')
    {
        if (expression[i] == '(') // CREATE CHILD
        {                         // create node and set pointers
            nextNode = new node;
            nextNode->child = nullptr;
            nextNode->sibling = nullptr;
            nextNode->parent = currNode;
            nextNode->data = expression[i + 1];

            currNode->child = nextNode;
            currNode = nextNode;
            i += 1;
        }
        else if (expression[i] == ')') // BACKTRACK
            currNode = currNode->parent;

        else // CREATE SIBBLING
        {
            nextNode = new node;
            nextNode->child = nullptr;
            nextNode->sibling = nullptr;
            nextNode->parent = currNode;
            nextNode->data = expression[i];

            currNode->sibling = nextNode;
            nextNode->parent = currNode->parent;
            currNode = nextNode;
        }
        i += 1;
    }
    return root;
}

void inOrder(node *T)
{
    if (T != nullptr)
    {
        inOrder(T->child);
        cout << T->data;
        inOrder(T->sibling);
    }
    return;
}

void preOrder(node *T)
{
    if (T != nullptr)
    {
        cout << T->data;
        preOrder(T->child);
        preOrder(T->sibling);
    }
    return;
}

void postOrder(node *T)
{
    if (T != nullptr)
    {
        postOrder(T->child);
        postOrder(T->sibling);
        cout << T->data;
    }
    return;
}
