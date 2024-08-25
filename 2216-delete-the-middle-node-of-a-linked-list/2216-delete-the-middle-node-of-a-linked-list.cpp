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
    int lengthOfLL(ListNode *head)
    {
        int cnt = 0;           // Counter to count nodes
        ListNode *temp = head; // Temp pointer to traverse the list

        while (temp)
        {
            temp = temp->next; // Move to the next node
            cnt++;             // Increment counter
        }
        return cnt;
    }

    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head == nullptr || head -> next == nullptr)
            return nullptr;

        int cnt = lengthOfLL(head);
        ListNode* temp = head;

        int prevMidNode = cnt / 2;

        while(temp != nullptr)
        {
            prevMidNode--;
            if(prevMidNode == 0) break;
            temp = temp -> next;
        }

        ListNode* delNode = temp -> next;
        temp -> next = delNode -> next;
        delete delNode;

        return head;
        
    }
};