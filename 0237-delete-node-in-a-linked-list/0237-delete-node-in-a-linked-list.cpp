/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* deleteHead(ListNode *head)
    {
        if (head == nullptr) // If LL is empty
            return nullptr;

        ListNode *temp = head; // Storing head in temp
        head = head->next; // Moving starting point to next element
        delete temp;       // Delete the 1st element
        return head;       // Return the new head
    }

    ListNode* deleteTail(ListNode *head)
    {
        // If LL is empty or has only a single element
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *temp = head; // Temp to store head

        // Traverse to the second last node
        while (temp->next->next != nullptr)
        {                      
            temp = temp->next; // Traversal
        }

        delete temp->next;    // Delete the tail node
        temp->next = nullptr; // Set the second last node as the new tail
        return head;          // Return the head (which is unchanged)
    }

    void deleteNode(ListNode* node) 
    {
        if(node == nullptr)
            return;

        // If node is the head, delete it using deleteHead
        if(node == head)
        {
            head = deleteHead(head);
            return;
        }

        // If node is the tail, delete it using deleteTail
        if(node->next == nullptr)
        {
            head = deleteTail(head);
            return;
        }

        // General case: copy the next node's data into the current node and delete the next node
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }

private:
    ListNode* head = nullptr; // Keep a reference to the head of the list
};
