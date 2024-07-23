#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node *node)
{

    if (node == NULL)
        return;

    cout << node->data;

    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node)
{

    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

void postorder(Node *node)
{

    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

// postOrder using iterative method

vector<int> postOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> s;

    s.push(root);

    while (!s.empty())
    {

        Node *temp = s.top();
        ans.push_back(temp->data);
        s.pop();

        if (temp->left != NULL)
            s.push(temp->left);

        if (temp->right != NULL)
            s.push(temp->right);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

vector<int> preOrder(Node *root)
{
    vector<int> ans;
    stack<Node *> s;

    s.push(root);

    while (!s.empty())
    {

        Node *temp = s.top();
        ans.push_back(temp->data);
        s.pop();

        if (temp->right != NULL)
            s.push(temp->right);

        if (temp->left != NULL)
            s.push(temp->left);
    }

    return ans;
}

// all traversals in one

void traversal(vector<int> &inorder, vector<int> &preorder, vector<int> &postorder, Node *root)
{

    stack<pair<Node *, int>> s;

    s.push({root, 1});
    while (!s.empty())
    {

        auto t = s.top();
        s.pop();

        // this is the part of pre
        // increment (node,1) to (node,2);
        // and push the updated (node,2) back in stack;
        // go to the left and push it in the stack
        if (t.second == 1)
        {
            preorder.push_back(t.first->data);
            t.second++;
            s.push(t);
            if (t.first->left != NULL)
            {
                s.push({t.first->left, 1});
            }
        }

        // this is the part of in
        // increment (node,2) to (node,3);
        // and push the updated (node,3) back in stack;
        // go to the right and push it in the stack
        else if (t.second == 2)
        {
            inorder.push_back(t.first->data);
            t.second++;
            s.push(t);
            if (t.first->right != NULL)
            {
                s.push({t.first->right, 1});
            }
        }

        // this is the part of post
        // no need to push anything in the stack
        else
        {
            postorder.push_back(t.first->data);
        }
    }
}
int main()
{
    return 0;
}