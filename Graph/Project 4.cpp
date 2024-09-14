#include <iostream>
#include<vector>
#include <bits/stdc++.h>


using namespace std;


class UnionSet {
    int *parent;
    int *rank;

public:
    int noOfNode;

    UnionSet(int n) {
        parent = new int[n];
        rank = new int[n];
        noOfNode = n;
        // memset -1, 1
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find node
    int find(int i) {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union two Set : : path compression
    void unionMake(int x, int y) {
        int set1 = find(x);
        int set2 = find(y);

        if (set1 != set2) {
            if (rank[set1] < rank[set2]) {
                parent[set1] = set2; // join
            } else if (rank[set1] > rank[set2]) {
                parent[set2] = set1;
            } else {
                // in same set
                parent[set2] = set1;
                rank[set1] += 1;
            }
        }
    }
};

class Graph {
    vector<vector<int> > repGraph;
    map<long long, int> mstEdgesHash;
    int V;
    map<long long, int> graphEdgesList;

public:
    Graph(int V) {
        this->V = V;
    }

    // kruskal algorithm
    void MST() {
        // Sort descending
        sort(repGraph.begin(), repGraph.end());

        UnionSet setDSU(V);
        int res = 0;
        for (auto edge: repGraph) {
            int w = edge[0];
            int n1 = edge[1];
            int n2 = edge[2];

            // cycle property
            if (setDSU.find(n1) != setDSU.find(n2)) {
                setDSU.unionMake(n1, n2);
                res += w;
                mstEdgesHash[V * n1 + n2] = w;
            }
        }
    }

    bool  isEdgeInEdges(int n1, int n2) {
        if (graphEdgesList.count(V * n1 + n2) > 0) return true;
        return false;
    }

    int getWeight(int n1, int n2) {
        return graphEdgesList[V * n1 + n2];
    }
    void updateEdge(int n1, int n2, int w) {
        graphEdgesList[V * n1 + n2] = w;
    }
    bool  isEdgeInMst(long n1, long n2) {
        if (mstEdgesHash.count(V * n1 + n2) > 0) return true;
        return false;
    }

    // insert edge
    void addEdge(int node1, int node2, int w) {
        repGraph.push_back({w, node1, node2});
        if (graphEdgesList.count(V * node1 + node2) > 0 ){
            if (graphEdgesList[V * node1 + node2] > w) {
                graphEdgesList[V * node1 + node2] = w;
            }
        } else {
            graphEdgesList[V * node1 + node2] = w;
        }

    }
};

int main() {
    int n, m, Q;
    cin >> n >> m >> Q;
    Graph graph = Graph(n);
    int n1, n2, weight;
    for (int i = 0; i < m; ++i) {
        cin >> n1 >> n2 >> weight;
        if (n1 > n2) {
            int temp = n1;
            n1 = n2;
            n2 = temp;
        }
        graph.addEdge(n1, n2, weight);
    }
    graph.MST();

    bool checkProperty;
    for (int i = 0; i < Q; ++i) {
        cin >> n1 >> n2 >> weight;
        if (n1 > n2) {
            int temp = n1;
            n1 = n2;
            n2 = temp;
        }
        if (graph.isEdgeInEdges(n1,n2) && graph.getWeight(n1, n2) < weight ) {
                checkProperty = false;
        } else {
            graph.addEdge(n1, n2, weight);
            graph.MST();
            if (graph.isEdgeInMst(n1,n2)) checkProperty = true; else checkProperty = false;
        }
        if (checkProperty)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
    
}