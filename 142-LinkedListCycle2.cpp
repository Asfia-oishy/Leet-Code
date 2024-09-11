//only functional part

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* tmp = head;
        vector<ListNode*> v;
        v.push_back(head);
        while (tmp!=NULL) {
            tmp=tmp->next;
            if (find(v.begin(), v.end(), tmp) == v.end()) {
                v.push_back(tmp);
            }
            else
            {

                return tmp;
            }
        }
        return NULL;
    }
};
