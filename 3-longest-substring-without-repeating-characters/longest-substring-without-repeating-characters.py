class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d=dict()
        ans=0
        st=0
        for i in range(len(s)):
            if(s[i] in d):
                st=max(st,d[s[i]]+1)
            d[s[i]]=i
            ans=max(ans,i-st+1)
        return ans