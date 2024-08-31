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
    ListNode* getkNode(ListNode* temp, int k)
    {
        int cnt = 1;

        while(temp != nullptr)
        {
            if(cnt == k)
                return temp;
            
            cnt++;
            temp = temp -> next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == nullptr || k == 0)
            return head;
            
        int len = 1;
        ListNode* temp = head;
        ListNode* tail = head;

        while(tail -> next != nullptr)
        {
            len++;
            tail = tail -> next;
        }

        if(k % len == 0)
            return head;

        k = k % len;

        tail -> next = head;

        ListNode* newTail = getkNode(head, len - k);

        head = newTail -> next;
        newTail -> next = nullptr;

        return head;
        
    }
};