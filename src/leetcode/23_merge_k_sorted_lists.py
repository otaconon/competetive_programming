from typing import Optional
from collections import List


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  @staticmethod
  def merge(a: Optional[ListNode], b: Optional[ListNode]) -> Optional[ListNode]:
    first = ListNode()
    last = first
    
    while a and b:
      if a.val <= b.val:
        last.next = ListNode(a.val, None)
        a = a.next
      else:
        last.next = ListNode(b.val, None)
        b = b.next
      last = last.next
    
    if a:
      last.next = a
    else:
      last.next = b

    return first.next
        
  def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    if len(lists) <= 0:
      return None
    
    while len(lists) > 1:
      q = []
      for i in range(0, len(lists), 2):
        new_list = Solution.merge(lists[i], lists[i+1] if i+1 < len(lists) else None)
        q.append(new_list)
      lists = q
    return lists[0]

sol = Solution()
