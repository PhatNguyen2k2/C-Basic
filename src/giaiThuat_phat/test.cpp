#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<long> a[n];
    while (n--) {
        long i;  cin >> i;
        a->insert(i);
    }
    cout << a->size();
}