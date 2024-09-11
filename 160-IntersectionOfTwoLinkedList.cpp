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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode *tmp1 = headA, *tmp2 = headB, *ans;
        tmp1 = headA;
        tmp2 = headB;
        map<ListNode*, int> mp;
        while (tmp1 != NULL) {
            mp[tmp1]++;
            tmp1 = tmp1->next;
        }

        while (tmp2 != NULL) {
                if(mp.find(tmp2)!=mp.end()) {
                return tmp2;
                } else
                    tmp2 = tmp2->next;
        }
        return NULL;
    }
};
