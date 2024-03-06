class Node :
    # __init__() la phuong thuc dac biet sd de tao 1 doi tuong khi no duoc tao
    def __init__(self,data):
        self.data = data # node nay luu tru du lieu
        self.next = None # node nay luu tru con tro giu dia chi node ke tiep

class LinkedList :
    def __init__(self):
        self.head = None # head duoc gan bang None khi chua co Node nao

    def add_data(self,data):
        data = Node(data) # khoi tao gia tri cho Node
        if not self.head : 
            self.head = data 
        else :
            temp = self.head 
            while temp.next != None:
                temp = temp.next # cho chay bien temp den node cuoi cung de add them node vao cuoi ll
            temp.next = data

    def traverse (self):
        temp = self.head 
        print("Node")
        while temp :
            print(temp.data, end = " ")
            temp = temp.next # di chuyen bien temp sang node ke tiep

ll = LinkedList()
ll.add_data(1)
ll.add_data(2)
ll.add_data(6)
ll.add_data(4)
ll.add_data(5)

ll.traverse()
