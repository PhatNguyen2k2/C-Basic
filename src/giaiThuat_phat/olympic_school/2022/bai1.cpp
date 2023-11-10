#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count;
    for (int i = 2; i <= n; i++) {
        count = 0;
        while (n % i == 0) {
            ++count;
            n /= i;
        }
        if (count) {
            if (count > 1) {
                while (count--) {
                    cout << i;
                    if (count > 0) cout << "*";
                }
            }
            else cout << i;
            if (n > i) {
                cout << "*";
            }
        }
    }
}