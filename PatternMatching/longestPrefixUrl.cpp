#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool isValidURL(const string &url) {
    if (url.empty()) return false;
    for (char ch : url) {
        if (!isalnum(ch) && ch != '/' && ch != '.' && ch != ':' && ch != '-') return false;
    }
    return true;
}

string longestPrefixMatch(const vector<string> &urls, const string &request) {
    string longestMatch = "";
    for (const string &url : urls) {
        if (request.find(url) == 0 && url.length() > longestMatch.length()) {
            longestMatch = url;
        }
    }
    return longestMatch;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    if (n <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<string> knownURLs(n);
    for (int i = 0; i < n; i++) {
        getline(cin, knownURLs[i]);
        if (!isValidURL(knownURLs[i])) {
            cout << "Invalid input" << endl;
            return 0;
        }
    }

    string request;
    getline(cin, request);

    if (!isValidURL(request)) {
        cout << "Invalid input" << endl;
        return 0;
    }

    string result = longestPrefixMatch(knownURLs, request);
    if (result.empty()) {
        cout << "No match found" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
