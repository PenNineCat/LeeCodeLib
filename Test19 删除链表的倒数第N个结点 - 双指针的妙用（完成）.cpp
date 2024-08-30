struct ListNode {
    int val;
    ListNode* next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode* next)
    {
        val = x;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* virtualHead = new ListNode;
        virtualHead->next = head;
        ListNode* fir = nullptr;
        int length = 0;
        ListNode* sen = nullptr;
        ListNode* temp = nullptr;
        fir = virtualHead;
        sen = virtualHead;
        if (head->next == nullptr)
        {
            return nullptr;
        }
        while (1)
        {
            if (fir->next != nullptr && length < n)
            {
                fir = fir->next;
                length++;
            }
            else if (fir->next != nullptr && length >= n)
            {
                fir = fir->next;
                sen = sen->next;
            }
            else
            {
                temp = sen->next;
                if (temp->next != nullptr)
                {
                    temp = temp->next;
                    sen->next = temp;
                }
                else
                {
                    sen->next = nullptr;
                }
                break;
            }
        }
        return virtualHead->next;
    }
};
