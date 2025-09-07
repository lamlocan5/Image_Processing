#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> matrix[i][j];
            if (matrix[i][j] > k){
                matrix[i][j] = 255;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}