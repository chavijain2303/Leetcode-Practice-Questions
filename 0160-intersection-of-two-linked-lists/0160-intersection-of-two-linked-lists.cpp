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
    int lengthOfLL(ListNode* head)
    {
        int cnt = 0; //counter to count
        ListNode* temp = head; // temp to move forward

        while(temp)
        {
            temp = temp -> next; //moving to next node
            cnt++; //whenever we move to next node we increment counter
        }
        return cnt;
    }
    ListNode* collisionPt(ListNode* smallerHead, ListNode* largerHead, int diff)
    {
        while(diff)
        {
            diff--;
            largerHead = largerHead -> next;
        }

        while(smallerHead != largerHead)
        {
            smallerHead = smallerHead -> next;
            largerHead = largerHead -> next;
        }

        return smallerHead;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* tempA = headA;
        int nA = lengthOfLL(headA);

        ListNode* tempB = headB;
        int nB = lengthOfLL(headB);

        if(nA < nB)
            return collisionPt(headA, headB, nB - nA);
        else
            return collisionPt(headB, headA, nA - nB);
    }
};