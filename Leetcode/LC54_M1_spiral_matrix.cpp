#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; ++i) res.push_back(matrix[top][i]);
            ++top;
            // Traverse from top to bottom
            for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
            --right;
            // Traverse from right to left
            if (top <= bottom) {
                for (int i = right; i >= left; --i) res.push_back(matrix[bottom][i]);
                --bottom;
            }
            // Traverse from bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
                ++left;
            }
        }
        return res;
    }
};

int main() {
    // Define a 3x3 matrix using push_back
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{1, 2, 3});
    matrix.push_back(vector<int>{4, 5, 6});
    matrix.push_back(vector<int>{7, 8, 9});
    // Create an instance of the Solution class
    Solution solution;
    // Call the spiralOrder method
    vector<int> result = solution.spiralOrder(matrix);
    // Print the result
    cout << "Spiral order: ";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
