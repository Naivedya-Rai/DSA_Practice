#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int val)
{
    struct node *Node = new node;
    Node->data = val;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}
// Inorder with recursion
void Inorder(node *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->left);
    cout << temp->data << " ";
    Inorder(temp->right);
}
// Inorder without recursion
void inOrder(struct node *root)
{
    stack<node *> s;
    node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
// Postorder without recursion
void postOrder(struct node *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<node *> s;
    s.push(root);
    stack<int> out;
    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();
        out.push(curr->data);
        if (curr->left)
        {
            s.push(curr->left);
        }
        if (curr->right)
        {
            s.push(curr->right);
        }
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}
// Preorder without recursion
void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> st;
    node *curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            if (curr->right)
                st.push(curr->right);
            curr = curr->left;
        }
        if (st.empty() == false)
        {
            curr = st.top();
            st.pop();
        }
    }
}
// Postorder with recursion
void Postorder(node *temp)
{
    if (temp == NULL)
        return;
    Postorder(temp->left);
    Postorder(temp->right);
    cout << temp->data << " ";
}
// Preorder with recursion
void Preorder(node *temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    Preorder(temp->left);
    Preorder(temp->right);
}
int main()
{
    struct node *root = createNode(6);
    root->left = createNode(5);
    root->right = createNode(7);
    root->left->left = createNode(14);
    root->left->right = createNode(13);
    root->left->left->left = createNode(9);
    root->left->left->right = createNode(3);
    root->right->left = createNode(16);
    root->right->right = createNode(21);
    root->right->right->left = createNode(28);
    root->right->right->right = createNode(8);
    int ch, p = 1;
    while (p == 1)
    {
        cout << "\n______MENU______" << endl;
        cout << "1) Inorder Transverse " << endl;
        cout << "2) Postorder Transverse " << endl;
        cout << "3) Preorder Transverse \n"
             << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "1) Inorder with recursion: " << endl;
            cout << "2) Inorder without recursion: " << endl;
            // Inorder(root);
            cout << endl;
            int ch1;
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                Inorder(root);
                cout << endl;
                break;
            case 2:
                inOrder(root);
                cout << endl;
                break;
            default:
                cout << "Enter a valid expression. " << endl;
                break;
            }
            break;
        case 2:
            cout << "1) Postorder with recursion. " << endl;
            cout << "2) Postorder without recursion. " << endl;
            // Postorder(root);
            cout << endl;
            int ch2;
            cin >> ch2;
            switch (ch2)
            {
            case 1:
                Postorder(root);
                break;
            case 2:
                postOrder(root);
                break;
            default:
                cout << "Enter a valid expression. " << endl;
                break;
            }
            cout << endl;
            break;
        case 3:
            cout << "1) Preorder with recursion. " << endl;
            cout << "2) Preorder without recursion. " << endl;
            // Preorder(root);
            cout << endl;
            int ch3;
            cin >> ch3;
            switch (ch3)
            {
            case 1:
                Preorder(root);
                break;
            case 2:
                preOrder(root);
                break;
            default:
                cout << "Enter a valid expression. " << endl;
                break;
            }
            break;
        default:
            cout << "Enter a valid expression. " << endl;
            break;
        }
    }
    cout << "\n\nPress 1 to continue\n";
    cin >> p;
}
