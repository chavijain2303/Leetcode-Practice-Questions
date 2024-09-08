class Solution {
public:
   double myPow(double x, int n) 
    {
        double ans = 1;
        long long abs_n = abs((long long)n);  // Handle negative n safely

        while (abs_n > 0) 
        {
            if (abs_n % 2 == 1) // If n is odd
            {
                ans *= x;
            }
            x *= x;  // Square the base
            abs_n /= 2;  // Divide the exponent by 2
        }
        if(n < 0)
            return 1 / ans;
        else
            return ans;
    }
};