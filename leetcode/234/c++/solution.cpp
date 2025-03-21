/*
    234. Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode *current_node, *last_node, *next_node, *tail, *current_node1;
        u_int64_t length = 0, middle;

        for (current_node = head; current_node != NULL;
             current_node = current_node->next) {
            ++length;
        }

        if (length == 1) {
            return true;
        }

        middle = length / 2 + length % 2;
        current_node = head;
        for (size_t i = 0; i < middle && current_node->next != NULL; ++i) {
            current_node = current_node->next;
        }

        next_node = current_node->next;
        current_node->next = NULL;
        last_node = current_node;
        current_node = next_node;
        while (current_node != NULL) {
            next_node = current_node->next;
            current_node->next = last_node;
            last_node = current_node;
            current_node = next_node;
        }

        tail = last_node;
        bool is_palindrome = true;
        for (current_node = head, current_node1 = tail; current_node1 != NULL;
             current_node = current_node->next,
            current_node1 = current_node1->next) {
            if (current_node->val != current_node1->val) {
                is_palindrome = false;
                break;
            }
        }

        current_node = tail;
        next_node = current_node->next;
        current_node->next = NULL;
        last_node = current_node;
        current_node = next_node;
        while (current_node != NULL) {
            next_node = current_node->next;
            current_node->next = last_node;
            last_node = current_node;
            current_node = next_node;
        }

        return is_palindrome;
    }
};