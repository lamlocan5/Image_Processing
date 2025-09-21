#include <iostream>
#include <vector>
#include <algorithm> // dùng cho std::min, std::max
using namespace std;

int main() {
    double a, b;
    int n;

    // Nhập a, b
    cin >> a >> b;

    // Nhập n
    cin >> n;

    // Đọc ma trận ảnh
    vector<vector<int>> image(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image[i][j];
        }
    }

    // Biến đổi tuyến tính
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int new_val = static_cast<int>(a * image[i][j] + b);
            // Giới hạn giá trị trong [0, 255]
            new_val = max(0, min(255, new_val));
            cout << new_val;
            if (j < n - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
