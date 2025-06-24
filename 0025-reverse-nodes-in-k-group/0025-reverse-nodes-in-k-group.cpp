class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode h, *tail = &h;
        while (head) {
            auto prev = tail;
            int i = 0;
            for (auto p = head; i < k && p; ++i, p = p->next);
            if (i < k) {
                tail->next = head;
                break;
            }
            for (int i = 0; i < k && head; ++i) {
                auto node = head;
                head = head->next;
                node->next = prev->next;
                prev->next = node;
            }
            while (tail->next) tail = tail->next;
        }
        return h.next;
    }
};