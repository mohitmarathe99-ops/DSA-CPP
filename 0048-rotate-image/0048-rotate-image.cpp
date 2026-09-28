class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
        for (int row = 0; row < n; row++) {
            for (int col = row + 1; col < n; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        for (int row = 0; row < n; row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};
void printMatrix(vector<vector<int>>& matrix) {
    cout << '[';
    for (int row = 0; row < matrix.size(); row++) {
        if (row > 0) {
            cout << ", ";
        }
 
        cout << '[';
        for (int col = 0; col < matrix[row].size(); col++) {
            if (col > 0) {
                cout << ", ";
            }
 
            cout << matrix[row][col];
        }
 
        cout << ']';
    }
  cout << "]\n";
}
