/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };*/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *tmp = head, *tail = NULL;
        stack<int> s;

        while (tmp != nullptr) {
            int data = tmp->val;
            while (!s.empty() && s.top() < data) {
                s.pop();
            }
            s.push(data);
            tmp = tmp->next;
        }
        if (s.empty() || head == NULL || head->next == NULL)
            return head;



        while (!s.empty()) {
            ListNode *prev = new ListNode(s.top());
            prev->next = tail;
            tail = prev;
            s.pop();
        }

        return tail;
    }
};
