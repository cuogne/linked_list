class Node :
    def __init__(self,data):
        self.data = data 
        self.next = None

class LinkedList :
    def __init__(self):
        self.head = None

    def add_data(self,data):
        new_node = Node(data) # khoi tao gia tri cho Node
        if not self.head : # neu self.head chua tro vao dau
            self.head = new_node 
        else :
            temp = self.head 
            while temp.next != None:
                temp = temp.next # cho chay bien temp den node cuoi cung de add them node vao cuoi ll
            temp.next = new_node
    
    def bubbleSortLL (self):
        if self.head == None or self.head.next == None :
            return
        
        swapped = True
        temp = None 
        lastSorted = None 

        while swapped :
            swapped = False 
            temp = self.head
            while temp.next != lastSorted :
                if temp.data > temp.next.data :
                    temp.data, temp.next.data = temp.next.data, temp.data
                    swapped = True
                temp = temp.next
            lastSorted = temp
    def printLL (self):
        temp = self.head 
        while temp :
            print (temp.data, end =" ")
            temp = temp.next

ll = LinkedList()
ll.add_data(3)
ll.add_data(8)
ll.add_data(2)
ll.add_data(6)
ll.add_data(4)
ll.bubbleSortLL()
ll.printLL()
        
