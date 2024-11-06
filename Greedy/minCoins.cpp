#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        if(cin.fail()){
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    int target;
    cin >> target;
    sort(coins.begin(), coins.end(),greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(coins[i] <= target){
            ans += target / coins[i];
            target %= coins[i];
            if(target == 0){
                break;
            }
        }
    }

    if(target > 0){
        cout << "-1";
    }else{
        cout << ans;
    }

}