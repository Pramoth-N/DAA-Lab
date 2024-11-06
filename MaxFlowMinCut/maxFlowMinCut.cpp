
// Maximum Flow Minimum Cut

// Input:

// 4 5
// 0 1 10
// 0 2 5
// 1 2 15
// 1 3 10
// 2 3 10
// 0 3

// Output

// 15

#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &res, int source, int sink, vector<int> &parent) {
    int n = res.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && res[u][v] > 0) {
                if (v == sink) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int compute(vector<vector<int>> &graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> res = graph;
    vector<int> parent(n);
    int maxFlow = 0;

    while (bfs(res, source, sink, parent)) {
        int pathFlow = INT_MAX;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, res[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            res[u][v] -= pathFlow;
            res[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n < 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] += c;
    }

    int source, sink;
    cin >> source >> sink;

    cout << compute(graph, source, sink) << endl;

    return 0;
}
