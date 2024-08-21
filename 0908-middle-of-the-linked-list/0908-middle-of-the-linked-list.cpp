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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* temp = head;
        int cnt = 0;

        while(temp != nullptr)
        {
            cnt++;
            temp = temp -> next;
        }

        temp = head;
        int midNodeIdx = (cnt / 2) + 1;

        while(temp != nullptr)
        {
            midNodeIdx--;

            if(midNodeIdx == 0)
                break;

            temp = temp -> next;
        }
        return temp;
    }
};