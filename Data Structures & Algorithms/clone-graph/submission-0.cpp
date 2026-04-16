/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<int,Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(m.find(node->val) != m.end()) return m[node->val];
        Node* cur = new Node(node->val);

        m[node->val] = cur;
        for(auto x: node->neighbors){
            (cur->neighbors).push_back(cloneGraph(x));
        }
        return cur;

    }
};
