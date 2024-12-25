// Dec'25, 2024 04:36 pm

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
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>&mp){
        if(node==NULL){
            return NULL;
        }

        if(mp.find(node)!=mp.end()){
            return mp[node];
        }

        mp[node]= new Node(node->val, {});
        for(auto neighbor: node->neighbors){
            mp[node]->neighbors.push_back(dfs(neighbor, mp));
        }

        return mp[node];
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        queue<Node*>q;
        q.push(node);
        unordered_map<Node*, Node*>mp;

        while(!q.empty()){
            Node* newNode= q.front();
            q.pop();
            
            if(mp.find(newNode)== mp.end()){
                mp[newNode]= new Node(newNode->val);
            }

            for(auto neighbor: newNode->neighbors){
                if(mp.find(neighbor) != mp.end()){
                    mp[newNode]->neighbors.push_back(mp[neighbor]);
                    continue;
                }
                mp[neighbor]= new Node(neighbor->val);
                mp[newNode]->neighbors.push_back( mp[neighbor] );
                q.push(neighbor);
            }
        }

        return mp[node];
        // return dfs(node, mp);
    }
};

// 30 min
// DFS already done
// Comments for BFS