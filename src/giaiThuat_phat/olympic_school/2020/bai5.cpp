#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

struct Edge {
    int u, v, cost;
};

struct Compare {
    bool operator()(const Edge& a, const Edge& b) {
        return a.cost > b.cost;
    }
};

int findParent(vector<int>& parent, int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else {
            parent[rootU] = rootV;
            rank[rootV]++;
        }
    }
}

pair<int, int> findMinCosts(const vector<Edge>& edges, int N) {
    vector<int> parent(N + 1);
    vector<int> rank(N + 1, 0);
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    priority_queue<Edge, vector<Edge>, Compare> pq;
    for (const Edge& edge : edges)
        pq.push(edge);

    int minCost = 0;
    int secondMinCost = INT_MAX;
    int numEdges = 0;

    while (!pq.empty() && numEdges < N - 1) {
        Edge currEdge = pq.top();
        pq.pop();

        int u = currEdge.u;
        int v = currEdge.v;
        int cost = currEdge.cost;

        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        if (rootU != rootV) {
            minCost += cost;
            unionSets(parent, rank, rootU, rootV);
            numEdges++;
        }
        else {
            secondMinCost = min(secondMinCost, cost);
        }
    }

    return make_pair(minCost, secondMinCost);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges[i] = { u, v, cost };
    }

    pair<int, int> minCosts = findMinCosts(edges, N);
    int S1 = minCosts.first;
    int S2 = minCosts.second;

    cout << S1 << " " << S2 << endl;

    return 0;
}