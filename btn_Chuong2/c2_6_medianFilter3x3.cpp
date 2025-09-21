#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;
int main(){
    int n;
    if(!(cin >>n)) return 0;
    
    vector <vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < n-1; j++) {
            vector<int> window;
            for(int di = -1; di <= 1; di++)
                for(int dj = -1; dj <= 1; dj++)
                    window.push_back(a[i+di][j+dj]);
            sort(window.begin(), window.end());
            int med = window[4];
            if(j > 1) cout << " ";
            cout << med;
        }
        cout << "\n";
    }
    
    return 0;
}