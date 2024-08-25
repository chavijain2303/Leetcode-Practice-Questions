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
    ListNode* sortList(ListNode* head) 
    {
        if(head == nullptr || head -> next == nullptr)
            return head;

        vector<int> ls;
        int i;

        ListNode* temp = head;

        while(temp != nullptr)
        {
            ls.push_back(temp -> val);
            i++;
            temp = temp -> next;
        }

        sort(ls.begin(), ls.end());
        temp = head;

        for(int j = 0; j < ls.size(); j++)
        {
            temp -> val = ls[j];
            temp = temp -> next;        
        }

        return head;
    }
};