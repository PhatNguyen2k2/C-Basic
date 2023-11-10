#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
bool canDivideIntoTwoGroups(int N, vector<vector<int>>& A) {
    vector<int> group(N, -1);

    for (int i = 0; i < N; ++i) {
        if (group[i] == -1) {
            group[i] = 0;
            //DFS
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 1) {
                    if (group[j] == -1) {
                        group[j] = 1;
                    }
                    else if (group[j] == group[i]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main() {
    while (true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        vector<vector<int>> A(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> A[i][j];
            }
        }
        if (canDivideIntoTwoGroups(N, A)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}