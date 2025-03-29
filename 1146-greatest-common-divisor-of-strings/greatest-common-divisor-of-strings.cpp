class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if((str1 + str2) == (str2+str1)){
             int gcdLength = gcd(str1.size(), str2.size());
            return str1.substr(0,gcdLength);
        }else{
            return "";
        }
    }
    int gcd(int a, int b){
        while(b % a != 0){
            int rem = b % a;
            b = a;
            a = rem;
        }
        return a;
    }
};