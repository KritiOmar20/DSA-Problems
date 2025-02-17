class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] > nums[high]){ // minimum element must be on the right side of mid
                low = mid + 1;
            }
            else if(nums[mid] < nums[high]){ //minimum element is at mid or on the left side.
                high =mid;
            }
            else{ // handle duplicate
                high--;
            }
        }
        return nums[low];
        
    }
};