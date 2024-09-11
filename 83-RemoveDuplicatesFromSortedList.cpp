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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
        return NULL;
        ListNode *tmp = head, *prev = head;
        vector<int> v;
        v.push_back(tmp->val);
        while (tmp->next != NULL) {
            tmp = tmp->next;
            int x =tmp->val;
            if (find(v.begin(), v.end(), x) == v.end()) {
                v.push_back(x);
                prev=tmp;
            }
            else {
                prev->next = tmp->next;
            }


        }
        return head;
    }
};
