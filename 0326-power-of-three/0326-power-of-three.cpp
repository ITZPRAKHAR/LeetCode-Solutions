class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1){
            return true;
        }
        long long  ans = 3;
        
        while(ans != n){
            ans = ans*3;
            if(ans > n){
                return false;
            }
        }

        return true;
    }
};