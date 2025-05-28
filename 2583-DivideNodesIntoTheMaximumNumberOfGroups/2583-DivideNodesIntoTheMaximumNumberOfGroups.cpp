// Last updated: 5/28/2025, 9:50:35 PM
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from].emplace_back(to);
            graph[to].emplace_back(from);
        }
      
        vector<int> nodes;
        vector<bool> visited(n + 1,false);
        int totalCount = 0;
      
        function<void(int)> depthFirstSearch = [&](int node) {
            nodes.emplace_back(node);
            visited[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    depthFirstSearch(neighbor);
                }
            }
        };
      
        auto breadthFirstSearch = [&](int startNode) {
            int localCount = 1;
            int distances[n + 1];
            memset(distances, 0x3f, sizeof distances);
            distances[startNode] = 1;
            queue<int> queue;
            queue.push(startNode);
          
            while (!queue.empty()) {
                int currentNode = queue.front();
                queue.pop();
                for (int neighbor : graph[currentNode]) {
                    if (distances[neighbor] == 0x3f3f3f3f) {
                        localCount = distances[neighbor] = distances[currentNode] + 1;
                        queue.push(neighbor);
                    }
                }
            }
          
            for (int& node : nodes) {
                if (distances[node] == 0x3f3f3f3f) {
                    distances[node] = ++localCount;
                }
            }
          
            for (int& node : nodes) {
                for (int& neighbor : graph[node]) {
                    if (abs(distances[node] - distances[neighbor]) != 1) {
                        return -1;
                    }
                }
            }
            return localCount;
        };
      
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                depthFirstSearch(i);
                int maxDistance = -1;
                for (int& node : nodes) {
                    maxDistance = max(maxDistance, breadthFirstSearch(node));
                }
                if (maxDistance == -1) return -1; // If impossible to find a magnificent set
                totalCount += maxDistance;
                nodes.clear();
            }
        }
        return totalCount;
    }
};