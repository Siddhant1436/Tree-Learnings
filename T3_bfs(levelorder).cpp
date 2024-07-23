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
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<vector<Node *>> inorder(Node *root)
{

    vector<vector<Node *>> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        int size = q.size();
        vector<Node *> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            if (!node->left)
                q.push(node->left);
            if (!node->right)
                q.push(node->right);
            level.push_back(node);
        }

        ans.push_back(level);
    }

    return ans;
}
int main()
{
    return 0;
}