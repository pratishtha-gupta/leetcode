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
    ListNode* sortList(ListNode* head) {
        vector<int> st;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            st.push_back(temp->val);
            temp = temp->next;
        }
        sort(st.begin(),st.end());
        ListNode* temp1 = head;
        int i=0;
        while(temp1!=nullptr)
        {
             temp1->val = st[i];
             i++;
             temp1= temp1->next;
        }
        return head;
    }
};