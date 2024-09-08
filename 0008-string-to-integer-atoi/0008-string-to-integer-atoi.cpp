class Solution {
public:
int myAtoiHelper(const string& s, int index, int sign, long long result) {
    if (index >= s.length() || !isdigit(s[index])) {
        // Check for overflow
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
        return result * sign;
    }
    
    // Update result and check for overflow before the recursive call
    if (result > (INT_MAX - (s[index] - '0')) / 10) {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }
    
    result = result * 10 + (s[index] - '0');
    return myAtoiHelper(s, index + 1, sign, result);
}

    int myAtoi(const std::string& s) {
    int index = 0;
    int sign = 1;
    long long result = 0;
    
    // Step 1: Ignore leading whitespace
    while (index < s.length() && s[index] == ' ') {
        ++index;
    }
    
    // Step 2: Check for sign
    if (index < s.length() && (s[index] == '-' || s[index] == '+')) {
        sign = (s[index] == '-') ? -1 : 1;
        ++index;
    }
    
    // Step 3: Start recursive conversion
    return myAtoiHelper(s, index, sign, result);
}
};