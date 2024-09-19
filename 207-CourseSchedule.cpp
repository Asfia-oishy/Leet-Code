class Solution {
public:
    // Function to add a directed edge to the graph
    void add_edge(vector<vector<int>>& g, int u, int v) {
        g[u].push_back(v);
    }

    // Depth First Search (DFS) function to detect cycles in the graph
    bool dfs(vector<vector<int>>& g, int src, vector<bool>& vis, vector<bool>& recStack) {
        vis[src] = true;
        recStack[src] = true; // Mark the node as part of the current path (recursion stack)

        for (int neighbor : g[src]) {
            // If the neighbor hasn't been visited, recursively perform DFS
            if (!vis[neighbor]) {
                if (dfs(g, neighbor, vis, recStack)) {
                    return true; // Cycle detected
                }
            }
            // If the neighbor is in the recursion stack, we found a back edge (cycle)
            else if (recStack[neighbor]) {
                return true; // Cycle detected
            }
        }

        // Remove the node from the recursion stack once done with DFS for this node
        recStack[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int nodes = numCourses;
        vector<vector<int>> graph(nodes);

        // Build the graph using the prerequisites
        for (const auto& prereq : prerequisites) {
            int u = prereq[1]; // Course u is a prerequisite for course v
            int v = prereq[0];
            add_edge(graph, u, v);
        }

        vector<bool> visited(nodes, false);  // To track visited nodes
        vector<bool> recStack(nodes, false); // To track nodes in the current recursion stack (path)

        // Perform DFS for each node (course)
        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) {
                if (dfs(graph, i, visited, recStack)) {
                    return false; // Cycle detected, cannot finish all courses
                }
            }
        }

        return true; // No cycle detected, all courses can be finished
    }
};
