#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, a, b = 0, c = 1;
    cin >> n >> k;
    a = n;
    if (k == 1) {
        cout << n - 1 << " " << 0 << " " << 1 << endl;
        return 0;
    }
    int count = 1;
    for (int i = 0; i < n - 2; i++) {
        while (count < k) {
            ++count;
        }
        if (count == k) {
            b = i + 1;
            a = n - i + 2;
            cout << a << " " << b << " " << c << endl;
            return 0;
        }
    }
    b = count - 1;
    a = n - count;
    count++;

}