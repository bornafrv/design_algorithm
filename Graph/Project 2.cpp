#include <iostream>
#include<vector>
#include <bits/stdc++.h>


using namespace std;


void selectedBubbleSort(int array[],  vector<int> box)
{
    sort(box.begin(), box.end());

    bool isSwapMode;
    for (int i = 0; i < box.size() - 1; i++) {
        isSwapMode = false;
        for (int j = 0; j < box.size() - i - 1; j++) {
            if (array[box.at(j)] > array[box.at(j+1)]) {
                swap(array[box.at(j)], array[box.at(j+1)]);
                isSwapMode = true;
            }
        }
        // by inner loop, terminated
        if (!isSwapMode)
            break;
    }
}

void DFSFIND(int nodeIndex, bool visited[], vector<int>& component, vector<int> adjList[] ) {
    visited[nodeIndex] = true;
    component.push_back(nodeIndex);
    for (auto it = adjList[nodeIndex].begin(); it != adjList[nodeIndex].end(); it++)
        if (!visited[*it]) {
            DFSFIND(*it, visited, component, adjList);
        }
    }


void findConnectedComponents(int queueList[], int n, vector<int> adjList[])
{
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        // memset(visited,1,n * sizeof(*visited));
    }

    for (int nodeIndex = 0; nodeIndex < n; nodeIndex++) {
        if (!visited[nodeIndex]) {
            vector<int> component;
            DFSFIND(nodeIndex, visited, component, adjList);
            if (component.size() > 1) {
                selectedBubbleSort(queueList, component);
            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    int queueList[n];
    for (int i = 0; i < n; ++i) {
        cin >> queueList[i];
    }
    char temp;
    vector<int> adjacencyList[n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            if (temp == '1'){
                adjacencyList[i].push_back(j);
            }
        }
    }
    findConnectedComponents(queueList, n, adjacencyList);
    for (int i = 0; i < n; ++i) {
        if (i != n-1) {
            cout << queueList[i] << " ";
        } else cout << queueList[i];
    }
    return 0;
}
