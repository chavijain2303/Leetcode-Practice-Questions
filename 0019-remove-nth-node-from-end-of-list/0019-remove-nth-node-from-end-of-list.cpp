class Solution {
public:
    int lengthOfLL(ListNode* head) {
        int cnt = 0; // Counter to count nodes
        ListNode* temp = head; // Temp pointer to traverse the list

        while (temp) {
            temp = temp->next; // Move to the next node
            cnt++; // Increment counter
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        for(int i = 0; i < n; i++)
            fast = fast -> next;
        
        if (fast == nullptr) 
            return head -> next;

        ListNode* slow = head;

        while(fast -> next != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next;
        }

        ListNode* delNode = slow->next;
        slow->next = delNode->next; // Store the next node before deletion
        delete delNode;

        return head;
    }
};
