from types import Optional

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    start = ListNode()
    start.next = head
    prev = start
    while prev.next and prev.next.next:
      first = prev.next
      second = prev.next.next
      next = prev.next.next.next
      
      second.next = first
      prev.next = second
      first.next = next
      prev = first
    return start.next