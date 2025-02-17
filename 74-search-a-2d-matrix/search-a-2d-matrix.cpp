class Solution {
public:
    bool searchInRow(vector<vector<int>>& matrix, int target, int row){
        int m= matrix[0].size();
        int start = 0 , end = m-1;
        while(start<= end){
            int mid= (start+end)/2;
            if(target == matrix[row][mid]){
                return true;
            }else if(target> matrix[row][mid]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m = matrix[0].size();
        int start = 0, end = n-1;
        while(start <= end){
            int mid = (start + end)/2;
            if(target>= matrix[mid][0] && target <= matrix[mid][m-1]){
                //Found the row
                return searchInRow(matrix, target, mid);
            }
            else if(target >= matrix[mid][m-1]){
                //down => right
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }
};