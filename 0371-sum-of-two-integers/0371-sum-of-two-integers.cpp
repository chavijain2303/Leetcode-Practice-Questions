class Solution {
public:
    int getSum(int a, int b) 
    {
        uint32_t carry = a & b;
        int sumWithoutCarry = a ^ b;
        int acCarry = carry << 1;

        while(carry != 0)
        {
            carry = sumWithoutCarry & acCarry;
            sumWithoutCarry = sumWithoutCarry ^ acCarry;
            acCarry = carry << 1;
        }
        return sumWithoutCarry;
    }
};