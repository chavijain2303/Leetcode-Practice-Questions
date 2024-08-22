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
    // Map to keep track of visited nodes
    map<ListNode *, int> mpp;

    ListNode *temp = head; // Start traversal from head

    while (temp != nullptr)
    {
        // If the current node has already been visited, a cycle is detected
        if (mpp.find(temp) != mpp.end())
            return temp;

        // Mark the current node as visited
        mpp[temp] = 1;

        // Move to the next node
        temp = temp->next;
    }

    // No cycle detected
    return nullptr;
}
};