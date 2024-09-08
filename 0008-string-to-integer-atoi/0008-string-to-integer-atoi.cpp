class Solution {
public:
    int myAtoi(string s) 
    {
        if(s.size() == 0)
            return 0;

        int idx = 0;

        while(idx < s.size() && s[idx] == ' ')
            idx++;
        
        s = s.substr(idx);

        int sign = +1;
        long long ans = 0;

        if(s[0] == '-')
            sign = -1;
        
        int maxi = INT_MAX;
        int mini = INT_MIN;

        idx = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        while(idx < s.size())
        {
            if(s[0] == ' ' || !isdigit(s[idx]))
                break;
            
            ans = ans * 10 + s[idx] - '0';

            if(sign == -1 && (-1 * ans) < mini)
                return mini;

            if(sign == 1 && ans > maxi)
                return maxi;
            
            idx++;
        }

        return(int)(sign * ans);
        
    }
};