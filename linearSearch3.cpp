#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n<=0){
        cout<<"-1"<<endl;
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
    sort(v.begin(), v.end());
    bool duplicates = false;
    for (int i = 0; i+1 < n; i++){
        if(v[i] == v[i+1]){
            duplicates = true;
            break;
        }
    }
    if(duplicates){
        cout << "Duplicates Found" << endl;
    } else {
        cout << "No Duplicates Found" << endl;
    }
}