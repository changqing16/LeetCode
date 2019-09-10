#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node() {}

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *cloneGraph(Node *node)
{
    queue<Node *> NQ;
    unordered_map<Node *, Node *> NM;

    Node *ans = new Node(node->val, vector<Node *>());
    NM[node] = ans;
    NQ.push(node);
    Node *cur1;
    Node *tmp;
    while (!NQ.empty())
    {
        cur1 = NQ.front();
        cout << cur1->val << endl;
        NQ.pop();

        for (Node *nbo : cur1->neighbors)
        {
            if (NM.count(nbo) == 0)
            {
                tmp = new Node(nbo->val, vector<Node *>());
                NM[nbo] = tmp;
                NQ.push(nbo);
            }
            NM[cur1]->neighbors.push_back(NM[nbo]);
        }
    }
    return ans;
}

int main()
{
    Node *node1 = new Node(1, vector<Node *>());
    Node *node2 = new Node(2, vector<Node *>());
    Node *node3 = new Node(3, vector<Node *>());
    Node *node4 = new Node(4, vector<Node *>());
        Node *node5 = new Node(5, vector<Node *>());
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node5);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node5);
    node4->neighbors.push_back(node3);
    node5->neighbors.push_back(node4);
    node5->neighbors.push_back(node1);
    Node *ans = cloneGraph(node1);
    cout << ans->val << endl;
}