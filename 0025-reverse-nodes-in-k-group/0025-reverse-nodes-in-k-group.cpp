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

    // recursive --> tc = O(N), sc = O(N) --> stack space
    ListNode *reverseList(ListNode *head)
    {
        // Base case: If the list is empty or has only one node, return it as is
        if (head == nullptr || head->next == nullptr)
            return head;

        // Recursively reverse the rest of the list starting from the second node
        ListNode *newHead = reverseList(head->next);

        // After the recursive call, 'newHead' points to the new head of the reversed list

        // The 'front' node is now the last node in the reversed list, which should point to the current 'head'
        ListNode *front = head->next;
        front->next = head;  // Point the next node of 'front' (i.e., the original head's next) to the current 'head'
        head->next = nullptr; // Set the next of the current 'head' to nullptr, making it the new tail of the list

        // Return the new head of the reversed list
        return newHead;
    }

    ListNode* getkNode(ListNode* temp, int k)
    {
        k -=1;

        while(temp != nullptr && k > 0)
        {
            k--;
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* temp = head;
        ListNode* back = nullptr;

        while(temp != nullptr)
        {
            ListNode* kNode = getkNode(temp, k);

            if(kNode == nullptr)
            {
                if(back)
                    back -> next = temp;
                
                break;
            }
            
            ListNode* front = kNode -> next;

            kNode -> next = nullptr;

            reverseList(temp);

            if(temp == head)
                head = kNode;
            
            else
                back -> next = kNode;
            
            back = temp;
            temp = front;
        }
       return head; 
    }
};