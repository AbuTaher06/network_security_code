#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS
void bfs(const map<char, vector<char>>& graph, char start, char goal) {
    // Queue to store the paths
    queue<vector<char>> paths;
    paths.push({start});  // Start with the starting node
    
    // Set to keep track of visited nodes
    unordered_set<char> visited;
    visited.insert(start);

    while (!paths.empty()) {
        vector<char> path = paths.front();
        paths.pop();
        char current = path.back();  // Get the last node in the current path
        
        // Check if the current node is the goal
        if (current == goal) {
            cout << "Path to goal: ";
            for (char node : path) {
                cout << node << " ";  // Print the path
            }
            cout << endl;
            return;
        }
        
        // Explore neighbors
        for (char neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) { // If not visited
                visited.insert(neighbor);  // Mark as visited
                vector<char> newPath = path;  // Create new path
                newPath.push_back(neighbor);    // Add neighbor to path
                paths.push(newPath);            // Add new path to queue
            }
        }
    }
    
    cout << "No path found." << endl;  // If no path to goal
}

int main() {
    // Define the graph using adjacency list representation
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

    // Example usage
    char start = 'a'; // Starting node
    char goal = 'g';  // Goal node
    bfs(graph, start, goal); // Perform BFS

    return 0;
}
