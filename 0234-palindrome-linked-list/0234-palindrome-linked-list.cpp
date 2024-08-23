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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = nullptr;

        while (temp != nullptr)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) 
    {
        if(head == nullptr || head -> next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != nullptr && fast -> next -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }   

        ListNode* reversedHead = reverseList(slow -> next);

        ListNode* idx = head;
        ListNode* jdx = reversedHead;

        while(jdx != nullptr)
        {
            if(idx -> val != jdx -> val)
            {
                reverseList(reversedHead);
                return false;
            }

            idx = idx -> next;
            jdx = jdx -> next;
        }

        reverseList(reversedHead);
        return true;
    }
};