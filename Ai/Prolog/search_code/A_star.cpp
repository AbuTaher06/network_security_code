#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent a node
struct Node {
    int vertex;
    float g;  // Cost from start to current node
    float h;  // Heuristic cost from current node to goal
    float f;  // Total cost (g + h)

    // Operator to compare nodes based on f value
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Heuristic function to estimate the cost (for simplicity, using a fixed heuristic)
float heuristic(int node, int goal) {
    // A simple heuristic (can be replaced with a more meaningful one)
    return abs(node - goal); 
}

// A* algorithm implementation
vector<int> aStar(const vector<vector<int>>& graph, int start, int goal) {
    priority_queue<Node, vector<Node>, greater<Node>> openList;
    unordered_set<int> closedList;
    unordered_map<int, int> cameFrom;
    unordered_map<int, float> gCost;

    openList.push({start, 0.0f, heuristic(start, goal), heuristic(start, goal)});
    gCost[start] = 0.0f;

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (current.vertex == goal) {
            vector<int> path;
            int temp = goal;
            while (temp != start) {
                path.push_back(temp);
                temp = cameFrom[temp];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        closedList.insert(current.vertex);

        for (int neighbor : graph[current.vertex]) {
            if (closedList.find(neighbor) != closedList.end()) {
                continue;  // Ignore already evaluated nodes
            }

            float tentativeG = gCost[current.vertex] + 1;  // Assuming a cost of 1 for each step

            if (gCost.find(neighbor) == gCost.end() || tentativeG < gCost[neighbor]) {
                cameFrom[neighbor] = current.vertex;
                gCost[neighbor] = tentativeG;
                openList.push({neighbor, tentativeG, heuristic(neighbor, goal), tentativeG + heuristic(neighbor, goal)});
            }
        }
    }
    
    return {};  // Return an empty path if goal is not reachable
}

int main() {
    // Define the graph as an adjacency list
    vector<vector<int>> graph = {
        {},
        {2, 3},   // Neighbors of node 1
        {1, 4, 5}, // Neighbors of node 2
        {1, 6},   // Neighbors of node 3
        {2},      // Neighbors of node 4
        {2},      // Neighbors of node 5
        {3, 7},   // Neighbors of node 6
        {6}       // Neighbors of node 7
    };

    int start = 1;  // Starting node
    int goal = 5;   // Goal node
    vector<int> path = aStar(graph, start, goal);

    if (!path.empty()) {
        cout << "A* Path from " << start << " to " << goal << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << goal << "." << endl;
    }

    return 0;
}
