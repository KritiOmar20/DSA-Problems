class Solution {
public:
    int pivotInteger(int n) {
        int num =n;
        int sum =0;
        for(int i =0;i<=n;i++){
            sum+=i;
        }
        int mid =sum/2;
        while(sum>mid){
            sum-=num;
            num--;
        }
        int sum1=0;
        for(int i=1;i<=num+1;i++){
            sum1+=i;
        }
        for(int i=num+1;i<=n;i++){
            sum1-=i;
        }
        if(sum1==0) return num+1;
        return -1;
    }
};