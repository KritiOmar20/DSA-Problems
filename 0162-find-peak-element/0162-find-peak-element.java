class Solution {
    public int findPeakElement(int[] nums) {
        int maxnum=Integer.MIN_VALUE;
        for(int x:nums){
            maxnum=Math.max(maxnum,x);
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]==maxnum){
                return i;
            }
        }
        return -1;
    }
    
}