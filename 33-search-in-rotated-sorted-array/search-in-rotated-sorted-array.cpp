class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0, high =nums.size()-1;
        while(low<=high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            if (nums[low] <= nums[mid])
            {
                // If the target lies within the sorted left half, search in this half
                if (nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            // If the left half is not sorted, then the right half [mid, high] must be sorted
            else{
                // If the target lies within the sorted right half, search in this half
                if (nums[mid] <= target && target <= nums[high]){
                    low = mid + 1; 
                }else{
                    high = mid - 1; 
                }
            }
        }
        return -1;
    }
};