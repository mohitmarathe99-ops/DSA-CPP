class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         if (matrix.empty() || matrix[0].empty()) 
return {};
vector <int> result;
int top = 0, bottom = matrix.size()-1, left =0 , right = matrix[0].size()-1;
while (top<=bottom && left <=right){
    for (int i=left; i<=right; i++){
        result.push_back(matrix[top][i]);
    } top++;
    for (int i=top; i<=bottom; i++){
        result.push_back(matrix[i][right]);
    } right--;
    for (int i=right; i>=left && top<=bottom; i--){
        result.push_back(matrix[bottom][i]);
    } bottom--;
    for (int i=bottom; i>=top && left<=right; i--){
        result.push_back(matrix[i][left]);
    } left++;
    }
return result;
    }
        
};