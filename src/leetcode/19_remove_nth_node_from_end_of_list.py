from types import Optional

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
        
        
class Solution:
  def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    node = head
    cnt = 0
    while node != None:
      node = node.next
      cnt += 1
    
    node = head 
    prev = None
    for _ in range(cnt+1):
      prev = node
      node = node.next if node != None else None
    prev.next = node
    return head
    