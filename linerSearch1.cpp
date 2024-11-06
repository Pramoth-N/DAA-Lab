#include <bits/stdc++.h>

using  namespace std;

int main(){
    int n;
    cin >> n;

    if(n<=0){
        cout << "-1" << endl;
        return 0;
    }
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(cin.fail()){
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    int x;
    cin >> x;
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(v[i] == x){
            ans = i;
            break;
        }
    }

    if(ans == -1){
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found" << endl;
    }
}