class Solution {
    public int[] searchRange(int[] nums, int target) {
        return new int[]{solvefirst(nums,target),solvelast(nums,target)};
    }
    public static int solvefirst (int nums[],int target){
        int n=nums.length-1;
        int left=0;
        int right=n;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                ans=mid;
                right=mid-1;
            }
            else if(nums[mid]<target){
                left= mid+1;
            }
            else{
                right= mid-1;
            }
        }
        return ans;
    } 
    public static int solvelast(int nums[],int target){
        int n=nums.length-1;
        int left=0;
        int right=n;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                ans=mid;
                left=mid+1;
            }
            else if(nums[mid]<target){
                left= mid+1;
            }
            else{
                right= mid-1;
            }
        }
        return ans;
    }
}