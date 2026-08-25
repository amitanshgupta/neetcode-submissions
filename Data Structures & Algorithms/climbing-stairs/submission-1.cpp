class Solution {
public:
    int climbStairs(int n) {
        //either i, or i+1
        if(n<=2) return n;
        int a = 1, b =2;
        for(int i = 3; i<=n; i++){
            int temp = a+b;
            a=b;
            b= temp;
        }
        return b;
    }
};
