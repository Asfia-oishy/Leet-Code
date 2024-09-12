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
ListNode* reverse_list(ListNode* head) {
    ListNode* tmp = head;
    if (head == nullptr || head->next == nullptr)
        return head;
    vector<int> v;
    while (tmp != nullptr) {
        v.push_back(tmp->val);
        tmp = tmp->next;
    }
    reverse(v.begin(), v.end());
    head = nullptr;
    for (int i = 0; i < v.size(); i++) {
        ListNode* ptr = new ListNode(v[i]);
        if (head == nullptr)
            head = ptr;
        else {
            tmp = head;
            while (1) {
                if (tmp->next == nullptr) {
                    tmp->next = ptr;
                    break;
                } else {
                    tmp = tmp->next;
                }
            }
        }
    }
    return head;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1 = reverse_list(l1), *h2 = reverse_list(l2), *tmp1, *tmp2,
                 *head = NULL, *tmp;
        int sum = 0;
        int carry = 0;
        tmp1 = h1;
        tmp2 = h2;

        while (tmp1 != NULL || tmp2 != NULL || carry!=0) {
            int d1, d2;
            if (tmp1 == NULL)
                d1 = 0;
            else
                d1 = tmp1->val;
            if (tmp2 == NULL)
                d2 = 0;
            else
                d2 = tmp2->val;
            sum = d1 + d2 + carry;
           
            if (sum > 9) {
                carry = sum / 10;
                sum = sum % 10;
            } else
                carry = 0;
            ListNode* ptr = new ListNode(sum);
            if (head == NULL) {
                head = ptr;

            } else {
                tmp = head;
                while (1) {
                    if (tmp->next == nullptr) {
                        tmp->next = ptr;
                        break;
                    } else {
                        tmp = tmp->next;
                    }
                }
            }
            if(tmp1!=NULL)
            tmp1 = tmp1->next;
            if(tmp2!=NULL)
            tmp2 = tmp2->next;
        }
        return reverse_list(head);
    }
};