#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n-1];
}

int main() {
    int n;
    cin >> n;

    if (n < 0) {
        cout << "Invalid input" << endl;
    } else {
        cout << fibonacci(n) << endl;
    }

    return 0;
}
