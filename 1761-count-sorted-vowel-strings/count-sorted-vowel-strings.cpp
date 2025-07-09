class Solution {
public:
vector<char>vowels{'a','e','i','o','u'};
void solve(int n, int last, int &count){
    if(n==0){
        count++;
        return;
    }
    for(int i=0; i<5;i++){
        if(i>=last){
            solve(n-1,i, count);
        }
    }
}
    int countVowelStrings(int n) {
       int count =0;
       solve(n,0,count);
       return count; 
    }
};