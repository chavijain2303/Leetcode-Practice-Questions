/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) 
    {
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        int carry = 0;
        
        while(temp1 != nullptr || temp2 != nullptr)
        {
            int sum = carry;
            
            if(temp1)
                sum = sum + temp1 -> val;
            
            if(temp2)
                sum = sum + temp2 -> val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr -> next = newNode;
            curr = curr -> next;

            if(temp1)
                temp1 = temp1 -> next;

            if(temp2)
                temp2 = temp2 -> next;
        }
        
        if(carry)
        {
            ListNode* carryNode = new ListNode(carry);
            curr -> next = carryNode;
        }

        return dummyNode -> next;
    }
};