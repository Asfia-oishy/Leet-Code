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
        if (head == NULL)
            return NULL;
        ListNode *tmp = head, *prev = head;
        vector<int> v, dup;
        v.push_back(tmp->val);
        while (tmp->next != NULL) {
            tmp = tmp->next;
            int x = tmp->val;
            if (find(v.begin(), v.end(), x) == v.end()) {
                v.push_back(x);
                prev = tmp;
            } else {
                dup.push_back(x);
                cout<<x<<endl;
                prev->next = tmp->next;
            }
        }

        prev = head;
        tmp = head;
        bool flag = false;
        while (tmp != NULL) {
            if (find(dup.begin(), dup.end(), tmp->val) != dup.end()) {
                if (tmp == head)
                    head = head->next;
                else if (tmp->next == NULL) {
                    prev->next = NULL;
                    break;
                } else {
                    prev->next = tmp->next;
                    flag = true;
                }
            }
            if (!flag)
                prev = tmp;
            tmp = tmp->next;
            flag=false;
        }
        return head;
    }
};


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
        if (head == NULL)
            return NULL;
        ListNode *tmp = head, *prev = head;
        vector<int> v, dup;
        v.push_back(tmp->val);
        while (tmp->next != NULL) {
            tmp = tmp->next;
            int x = tmp->val;
            if (find(v.begin(), v.end(), x) == v.end()) {
                v.push_back(x);
                prev = tmp;
            } else {
                dup.push_back(x);
                cout<<x<<endl;
                prev->next = tmp->next;
            }
        }

        prev = head;
        tmp = head;
        bool flag = false;
        while (tmp != NULL) {
            if (find(dup.begin(), dup.end(), tmp->val) != dup.end()) {
                if (tmp == head)
                    head = head->next;
                else if (tmp->next == NULL) {
                    prev->next = NULL;
                    break;
                } else {
                    prev->next = tmp->next;
                    flag = true;
                }
            }
            if (!flag)
                prev = tmp;
            tmp = tmp->next;
            flag=false;
        }
        return head;
    }
};
