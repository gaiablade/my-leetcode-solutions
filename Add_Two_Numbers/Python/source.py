"""
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
"""

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        c = ListNode()
        head = c
        while l1 is not None or l2 is not None or carry:
            s = carry
            if l1 is not None:
                s += l1.val
                l1 = l1.next
            if l2 is not None:
                s += l2.val
                l2 = l2.next

            carry = s / 10
            c.val = s % 10

            if l1 is not None or l2 is not None or carry:
                c.next = ListNode()
                c = c.next

        return head


