class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def swap_Nodes(self, keyX, keyY):
        if keyX == keyY:
            return

        prevX, curX = None, self.head
        prevY, curY = None, self.head

        # find node with value keyX
        while curX and curX.data != keyX:
            prevX, curX = curX, curX.next
        
        # find node with value keyY
        while curY and curY.data != keyY:
            prevY, curY = curY, curY.next

        # check if curX or curY is None after loop
        if not curX or not curY:
            return 
        
        # update next for prevX
        if prevX: #prevX not head
            prevX.next = curY
        else:
            self.head = curY
        
        # update next for prevY
        if prevY: #prevY not head
            prevY.next = curX
        else:
            self.head = curX

        # swap 
        curX.next, curY.next = curY.next, curX.next

    # function print linked list
    def display(self):
        temp = self.head
        while temp:
            print(temp.data,"->",end=" ")
            temp = temp.next
        print("None")

# check 
ll = LinkedList()
ll.head = Node(1)
ll.head.next = Node(2)
ll.head.next.next = Node(3)
ll.head.next.next.next = Node(4)

#swap node 2 and 3
ll.swap_Nodes(2, 3)

ll.display()
