from typing import Optional

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
    if head == None:
      return None

    node = head
    set_head = True
    prev_last = None
    while node:
      q = []
      for i in range(k):
        q.append(node)
        if not node:
          return head
        node = node.next

      rev_node = q.pop()
      if prev_last:
        prev_last.next = rev_node
      if set_head:
        head = rev_node
        set_head = False
      while len(q):
        rev_node.next = q.pop()
        rev_node = rev_node.next
      rev_node.next = node
      prev_last = rev_node
    return head


sol = Solution()
node = ListNode(1)
head = node
for i in range(2, 6):
  node.next = ListNode(i) 
  node = node.next
  
ans = sol.reverseKGroup(head, 2)
while ans:
  print(ans.val)
  ans = ans.next
