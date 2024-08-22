/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
{
    // Pointers for traversing the list at different speeds
    ListNode *slow = head; // Slow pointer, moves one step at a time
    ListNode *fast = head; // Fast pointer, moves two steps at a time

    // Traverse the list
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps

        // If the slow and fast pointers meet, a cycle is detected
        if (slow == fast)
        {
            slow = head;

            while(slow != fast)
            {
                slow = slow -> next;
                fast = fast -> next;
            }

            return slow;
        }
    }

    // No cycle detected
    return nullptr;
}
};