class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }else if(n == 1 || n ==2){
            return 1;
        }
        vector<int> Fib(n+1);
        Fib[0] = 0;
        Fib[1] = 1;
        Fib[2] = 1;
        for(int i = 3;i < n+1; i++){
            Fib[i] = Fib[i-1]+Fib[i-2];
        }
        return Fib[n];
    }
};