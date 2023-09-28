#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct Node *create(int item)
{
    Node *node = new Node;
    node->data = item;
    node->left = node->right = NULL;
    return node;
}
void Inorder(Node *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->left);
    cout << temp->data << " ";
    Inorder(temp->right);
}
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = new Node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct Node *deleteNode(struct Node *temp, int data)
{
    if (temp == NULL)
        return temp;
    if (data < temp->data)
        temp->left = deleteNode(temp->left, data);
    else if (data > temp->data)
        temp->right = deleteNode(temp->right, data);
    else
    {
        if (temp->left == NULL)
        {
            struct Node *root = temp->right;
            free(temp);
            return root;
        }
        else if (temp->right == NULL)
        {
            struct Node *root = temp->left;
            free(temp);
            return root;
        }
        struct Node *root = minValueNode(temp->right);
        temp->data = root->data;
        temp->right = deleteNode(temp->right, temp->data);
    }
    return temp;
}
Node *insert(Node *temp, int key)
{
    if (temp == NULL)
    {
        return create(key);
    }
    if (key < temp->data)
    {
        temp->left = insert(temp->left, key);
    }
    else
    {
        temp->right = insert(temp->right, key);
    }
    return temp;
}
void search(Node *temp, int value)
{
    int depth = 0;
    while (temp != NULL)
    {
        depth++;
        if (temp->data == value)
        {
            cout << "\nitem found at depth: " << depth;
            return;
        }
        else if (temp->data > value)
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << "\n item not found";
    return;
}
int main()
{
    struct Node *temp = NULL;
    temp = insert(temp, 18);
    temp = insert(temp, 14);
    temp = insert(temp, 38);
    temp = insert(temp, 22);
    temp = insert(temp, 18);
    temp = insert(temp, 11);
    temp = insert(temp, 16);
    temp = insert(temp, 3);
    int ch, p = 1;
    while (p == 1)
    {
        cout << "\n______MENU______" << endl;
        cout << "1) Insert " << endl;
        cout << "2) Delete " << endl;
        cout << "3) Search " << endl;
        cout << "4) InOrder Transverse " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the Element you want to Insert: " << endl;
            int x;
            cin >> x;
            insert(temp, x);
            Inorder(temp);
            cout << endl;
            break;
        case 2:
            cout << "Enter the Element you want to Delete: " << endl;
            int y;
            cin >> y;
            temp = deleteNode(temp, y);
            Inorder(temp);
            cout << endl;
            break;
        case 3:
            cout << "Enter the Value you want to search: " << endl;
            int z;
            cin >> z;
            search(temp, z);
            cout << endl;
            break;
        case 4:
            cout << "Inorder Tranverse will be: " << endl;
            Inorder(temp);
            cout << endl;
            break;
        default:
            cout << "Enter a valid expression. " << endl;
            break;
        }
    }
    cout << "\n\nPress 1 to continue\n";
    cin >> p;
}