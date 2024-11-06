#include <bits/stdc++.h>
using namespace std;

bool isValidInput(const string &str) {
    if (str.empty()) return false;
    for (char ch : str) {
        if (!isalnum(ch) && ch != ' ') return false;
    }
    return true;
}

vector<int> findPatternIndices(const string &text, const string &pattern) {
    vector<int> indices;
    int n = text.size();
    int m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) indices.push_back(i);
    }
    return indices;
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    if (!isValidInput(text) || !isValidInput(pattern)) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<int> indices = findPatternIndices(text, pattern);
    if (indices.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
