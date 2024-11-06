#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int sum = accumulate(nums.begin() + l , nums.begin() + r+1, 0);
        cout << sum << endl;
    }
    return 0;
}