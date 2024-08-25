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
        int cnt = lengthOfLL(head);

        if (cnt == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int num = cnt - n;
        ListNode* temp = head;

        while (num > 1) {
            temp = temp->next;
            num--;
        }

        ListNode* delNode = temp->next;
        temp->next = delNode->next; // Store the next node before deletion
        delete delNode;

        return head;
    }
};
