#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
using namespace std;

int main() {
    int n, m;
    
    cin >> n;
    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }
    
    cin >> m;
    if (m < 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, {v, w}});
    }

    int source;
    cin >> source;
    if (source < 0 || source >= n) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i < n; i++) {
        for (const auto &edge : edges) {
            int u = edge.first;
            int v = edge.second.first;
            int w = edge.second.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Path not found" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
