#include <iostream>
#include<vector> 

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin>>n)) return 0;
    vector <vector<long long>> a(n, vector<long long> (n));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    if(n < 3) return 0;
    
    for(int i = 1; i <= n - 2; i++){
        for(int j = 1; j <= n-2; j++){
            long long s = 0;
            for(int di = -1; di <= 1; di++){
                for(int dj = -1; dj <= 1; dj++){
                    s += a[i+di][j + dj];
                }
            }
            long long val = (s+4)/9;
            if(j > 1) cout << " ";
            cout << val;
        }
        cout << "\n";
    }
    return 0;
}