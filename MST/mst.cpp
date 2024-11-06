
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    
    if (n < 0 || e < 0) {
        cout << "Invalid input\n";
        return 0;
    }
    
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].emplace_back(v-1, w);
        adj[v-1].emplace_back(u-1, w);
    }
    
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);
    int totalWeight = 0;
    
    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += weight;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int edgeWeight = edge.second;
            if (!inMST[v]) {
                pq.emplace(edgeWeight, v);
            }
        }
    }
    
    cout << totalWeight << endl;
    return 0;
}