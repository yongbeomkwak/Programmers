#include <bits/stdc++.h>
#define P pair<int, int>
#define null NULL
using namespace std;

vector<vector<int>> answer = {{}, {}};

typedef struct NODE
{
    int x;
    int y;
    int idx;
    NODE *left;
    NODE *right;
} Node;

bool comp(Node a, Node b)
{
    if (a.y == b.y)
    {
        return a.x < b.x; // x가 작은것이 먼저 오게(즉 자신의 왼쪽 노드)
    }
    return a.y > b.y; //루트를 위에 놓기 위해
}

void Make_Tree(Node *parent, Node *child)
{
    if (child->x < parent->x) //자식의 x값이 더 작으면 왼쪽노드
    {
        if (parent->left == null) //왼쪼 자리가 비어있으면
        {
            parent->left = child; //해당 루트의 왼쪽을 child
            return;
        }
        //만약 이미 left자리가 있다면
        Make_Tree(parent->left, child); //해당 left와 child를 다시 비교
    }
    else
    {
        if (parent->right == null)
        {
            parent->right = child;
            return;
        }
        Make_Tree(parent->right, child);
    }
}

void preOrder(const Node *node) // 자기자신-왼쪽-오른쪽
{
    if (node == null)
        return;
    answer[0].push_back(node->idx);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(const Node *node) //왼쪽-오른쪽-나
{
    if (node == null)
        return;
    postOrder(node->left);
    postOrder(node->right);
    answer[1].push_back(node->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{

    const int len = nodeinfo.size();
    vector<Node> Tree;

    for (int i = 0; i < len; i++)
    {
        const int x = nodeinfo[i][0];
        const int y = nodeinfo[i][1];
        const int idx = i + 1;
        Tree.push_back({x, y, idx});
    }
    sort(Tree.begin(), Tree.end(), comp);
    Node *root = &Tree[0];

    for (int i = 1; i < len; i++)
        Make_Tree(root, &Tree[i]);

    preOrder(root);
    postOrder(root);

    return answer;
}