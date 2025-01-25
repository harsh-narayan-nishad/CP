#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int>res;
        if (matrix.empty() || matrix[0].empty()) return res;

        int m = matrix.size();
        int n = matrix[0].size();
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
    // Input the dimensions of the matrix
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Create a 2D vector to store the matrix
    vector<vector<int> > matrix(rows, vector<int>(cols));

    // Input the elements of the matrix using a nested for loop
    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Create an instance of the Solution class
    Solution solution;

    // Call the spiralOrder method
    vector<int> result = solution.spiralOrder(matrix);

    // Print the result
    cout << "Spiral order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
