#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<int> differences(n);
    for (int i = 0; i < n; i++) {
        cin >> differences[i];
    }

    int max = INT_MIN;
    int current_max = 0;

    for (int i = 0; i < n; i++) {
        current_max = max(differences[i], current_max + differences[i]);
        max = max(max, current_max);
    }

    cout << max << endl;
    return 0;
}
