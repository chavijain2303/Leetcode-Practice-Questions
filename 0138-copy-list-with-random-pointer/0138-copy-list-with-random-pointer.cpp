/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyNodeInBw(Node* head)
    {
        Node* temp = head;

        while(temp != nullptr)
        {
            Node* copyNode = new Node(temp -> val);

            copyNode -> next = temp -> next;
            temp -> next = copyNode;

            temp = temp -> next -> next;
        }
    }

    void connectRandomPtrs(Node* head)
    {
        Node* temp = head;

        while(temp != nullptr)
        {
            Node* copyNode = temp -> next;

            if(temp -> random != nullptr)
            {
                copyNode -> random = temp -> random -> next;
            }

            else
            {
                copyNode -> random = nullptr;
            }

            temp = temp -> next -> next;
        }
    }

    Node* connectNextPtrs(Node* head)
    {
        Node* dNode = new Node(-1);
        Node* res = dNode;

        Node* temp = head;

        while(temp != nullptr)
        {
            res -> next = temp -> next;
            temp -> next = temp -> next -> next;

            res = res -> next;
            temp = temp -> next;
        }

        return (dNode -> next);
    }
    Node* copyRandomList(Node* head) 
    {
        insertCopyNodeInBw(head);
        connectRandomPtrs(head);

        return connectNextPtrs(head);
    }
};