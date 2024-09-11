class Solution {
public:
    int mod = 1000000007;
    
    long long myPow(long long x, long long n)
    {
        if (n == 0)
            return 1;

        long long half = myPow(x, n / 2);

        if (n % 2 == 0)
            return (half * half) % mod;
        else
        {
            if (n > 0)
                return (x * half * half) % mod;
            else
                return ((half * half) / x) % mod;
        }
    }

    int countGoodNumbers(long long n) 
    {
        long long even = n / 2 + n % 2;
        long long odd = n / 2;

        long long ans = (myPow(5, even) * myPow(4, odd)) % mod;

        return ans;
    }
};