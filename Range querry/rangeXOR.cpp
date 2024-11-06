#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    vector<int> prefixXOR(n);
    prefixXOR[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        if (l < 0 || r >= n || l > r) {
            cout << "Invalid input" << endl;
        } else {
            int result = (l == 0) ? prefixXOR[r] : prefixXOR[r] ^ prefixXOR[l - 1];
            cout << result << endl;
        }
    }

    return 0;
}
