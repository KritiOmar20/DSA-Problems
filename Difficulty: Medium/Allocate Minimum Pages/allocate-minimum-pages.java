class Solution {
    public int findPages(int[] arr, int k) {
        if(k>arr.length) return -1;
        int st=0;
        int end=0;
        for(int x:arr){
            st=Math.max(x,st);
            end+=x;
        }
        int ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isAllocationPossible(arr,mid,k)){
                ans=mid;
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
    public static boolean isAllocationPossible(int []arr,int maxpages,int student){
        int stcount=1;
        int pages=0;
        for(int a:arr){
            pages+=a;
            if(pages>maxpages){
                pages=a;
                stcount++;
            }
            if(stcount>student){
                return false;
            }
        }
        return true;
    }
}