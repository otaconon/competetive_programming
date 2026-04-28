from types import Optional

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
    
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
      node1, node2 = list1, list2
      ans = ListNode()
      ans_head = ans
      
      def insert(node: ListNode):
        nonlocal ans
        ans.next = node
        ans = ans.next
        return node.next
        
      while node1 != None and node2 != None:
        if node1.val < node2.val:
          node1 = insert(node1)
        else:
          node2 = insert(node2)
          
      if node1 != None:
        node1 = insert(node1)
      else:
        node2 = insert(node2)
      
      return ans_head.next