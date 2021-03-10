#include <iostream>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /* e.g.
        Input: l1 = [2, 4, 3] l2 = [5, 6, 4]
        Output: [7, 0, 8]
        */
       /*
        ListNode* head = l1, * tail = l1;
        int carry_digit{0};
        while (l1 != nullptr || l2 != nullptr) {
            int sum = ((l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val)) + carry_digit;
            l1->val = sum % 10;
            carry_digit = sum / 10;
            if (l1->next == nullptr && l2 && l2->next != nullptr) {
                l1->next = new ListNode();
            }
            if (l1) {
                l1 = l1->next;
                if (l1) tail = l1;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry_digit == 1) {
            tail->next = new ListNode(1);
        }
        return head;
        */
        ListNode* c = new ListNode(), * head = c;
        int carry{0};
        while (l1 || l2 || carry) {
            int sum{carry};

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            c->val = sum % 10;

            if (l1 || l2 || carry) {
                c->next = new ListNode();
                c = c->next;
            }
        }
        return head;
    }
};

ListNode* createNumber(int number) {
        int mod = 100, div = 10, num = -1;
        ListNode* head = new ListNode(number % 10);
        for (ListNode* l = head; num != number; l = l->next) {
            num = number % mod;
            l->next = new ListNode(num / div);
            mod *= 10;
            div *= 10;
        }
        return head;
}

int main() {
    return 0;
}