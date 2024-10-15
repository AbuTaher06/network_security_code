#include <bits/stdc++.h>
using namespace std;

void dfs(const map<char, vector<char>>& graph, char start, unordered_set<char>& visited) {
    cout << start << " ";  // Print the current node
    visited.insert(start);  // Mark the current node as visited
    
    for (char neighbor : graph.at(start)) {  // Iterate over neighbors
        if (visited.find(neighbor) == visited.end()) {  // If neighbor is not visited
            dfs(graph, neighbor, visited);  // Recursive call to DFS
        }
    }
}

int main() {
    map<char, vector<char>> graph = {
        {'a', {'b', 'c'}},
        {'b', {'a', 'd', 'e'}},
        {'c', {'a', 'f'}},
        {'d', {'b', 'g'}},
        {'e', {'b', 'h'}},
        {'f', {'c', 'i'}},
        {'g', {'d'}},
        {'h', {'e'}},
        {'i', {'f'}}
    };
    
    unordered_set<char> visited;  // Set to track visited nodes
    cout << "DFS Traversal starting from node 'a': ";
    dfs(graph, 'a', visited);  // Start DFS from node 'a'
    cout << endl;

    return 0;
}
