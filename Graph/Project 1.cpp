#include <iostream>
#include <queue>


using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    queue<pair<int, int> > listStates;
    int t1, t2;
    int grid[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            grid[i][j] = -1;
        }
    }

    for (int i = 0; i < k; ++i) {
        cin >> t1 >> t2;
        pair<int, int> newpair;
        newpair.first = t1 - 1;
        newpair.second = t2 - 1;
        listStates.push(newpair);
        grid[newpair.first][newpair.second] = 0 ;

    }

    pair<int, int> lastState;
    lastState.first = n - 1;
    lastState.second = m - 1;
    while (!listStates.empty()) {
        pair<int, int> currentPair = listStates.front();
        listStates.pop();

//        cout << currentPair.first << "     " << currentPair.second << " ---> " << grid[currentPair.first][currentPair.second] << endl;
        if (grid[currentPair.first][currentPair.second] > grid[lastState.first][lastState.second]) {
            lastState = currentPair;

        }
        if (grid[currentPair.first][currentPair.second] == grid[lastState.first][lastState.second] & currentPair.first + currentPair.second < lastState.first + lastState.second) {
            lastState = currentPair;
        }
        pair<int, int> tempPair;
        if (currentPair.second != 0) {
            tempPair.first = currentPair.first;
            tempPair.second = currentPair.second - 1;
            if (grid[tempPair.first][tempPair.second] == -1) {
                grid[tempPair.first][tempPair.second] = grid[currentPair.first][currentPair.second] + 1;
                listStates.push(tempPair);
            }
        }
        if (currentPair.first != 0) {
            tempPair.first = currentPair.first - 1;
            tempPair.second = currentPair.second;
            if (grid[tempPair.first][tempPair.second] == -1) {
                grid[tempPair.first][tempPair.second] = grid[currentPair.first][currentPair.second] + 1;
                listStates.push(tempPair);
            }
        }

        if (currentPair.second != m - 1) {
            tempPair.first = currentPair.first;
            tempPair.second = currentPair.second + 1;
            if (grid[tempPair.first][tempPair.second] == -1) {
                grid[tempPair.first][tempPair.second] = grid[currentPair.first][currentPair.second] + 1;
                listStates.push(tempPair);
            }
        }

        if (currentPair.first != n - 1) {
            tempPair.first = currentPair.first + 1;
            tempPair.second = currentPair.second;
            if (grid[tempPair.first][tempPair.second] == -1) {
                grid[tempPair.first][tempPair.second] = grid[currentPair.first][currentPair.second] + 1;
                listStates.push(tempPair);
            }
        }




    }


    cout << lastState.first + 1 << " " << lastState.second + 1;
    return 0;
}