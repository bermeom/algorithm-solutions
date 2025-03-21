/*
    2. Add Two Numbers
    Author: Miguel Angel Bermeo Ayerbe
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* it_l1 = l1;
        ListNode* it_l2 = l2;
        ListNode* answer = NULL;
        ListNode* it_answer = NULL;
        ListNode* it_answer_i = NULL;

        int carry = 0, sum_i;
        for (; it_l1 != NULL || it_l2 != NULL;) {
            sum_i = carry;

            if (it_l1 != NULL) {
                sum_i += it_l1->val;
                it_l1 = it_l1->next;
            }

            if (it_l2 != NULL) {
                sum_i += it_l2->val;
                it_l2 = it_l2->next;
            }
            carry = sum_i / 10;
            sum_i = sum_i % 10;

            it_answer_i = new ListNode(sum_i);
            if (answer == NULL) {
                answer = it_answer_i;
                it_answer = answer;
            } else {
                it_answer->next = it_answer_i;
                it_answer = it_answer->next;
            }
        }

        if (carry > 0) {
            it_answer_i = new ListNode(carry);
            if (answer == NULL) {
                answer = it_answer_i;
                it_answer = answer;
            } else {
                it_answer->next = it_answer_i;
                it_answer = it_answer->next;
            }
        }

        return answer;
    }
};