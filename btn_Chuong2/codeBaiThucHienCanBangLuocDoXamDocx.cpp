
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int L = 8; 
    int R, C;
    if (!(cin >> R >> C)) return 0;
    vector<vector<int>> img(R, vector<int>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> img[i][j];

    int n = R * C;
    vector<int> hist(L, 0);
    for (auto &row : img)
        for (int v : row) hist[v]++;


    vector<double> pdf(L, 0.0), cdf(L, 0.0);
    for (int k = 0; k < L; ++k) pdf[k] = double(hist[k]) / n;
    double s = 0.0;
    for (int k = 0; k < L; ++k) { s += pdf[k]; cdf[k] = s; }

    auto round_half_up = [](double x) -> int {
        return (int)floor(x + 0.5);
    };

    vector<int> mp(L, 0);
    for (int k = 0; k < L; ++k) mp[k] = round_half_up((L - 1) * cdf[k]);

    vector<vector<int>> out = img;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            out[i][j] = mp[ img[i][j] ];


    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (j) cout << ' ';
            cout << out[i][j];
        }
        cout << '\n';
    }
    return 0;
}
