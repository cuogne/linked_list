class Node :
    # __init__() la phuong thuc dac biet sd de tao 1 doi tuong khi no duoc tao
    def __init__(self,data):
        self.data = data # node nay luu tru du lieu
        self.next = None # node nay luu tru con tro giu dia chi node ke tiep

class LinkedList :
    def __init__(self):
        self.head = None # head duoc gan bang None khi chua co Node nao

    def add_data(self,data):
        new_node = Node(data) # khoi tao gia tri cho Node
        if not self.head : # neu self.head chua tro vao dau
            self.head = new_node 
        else :
            temp = self.head 
            while temp.next != None:
                temp = temp.next # cho chay bien temp den node cuoi cung de add them node vao cuoi ll
            temp.next = new_node

    def search_data (self,data):
        temp = self.head
        while temp :
            if temp.data == data :
                return f"{data} exist in linked list"
            temp = temp.next
        return f"{data} not exist in linked list"
    
    def insert_before (self, data, bf_data):
        new_node = Node(data) # khoi tao 1 nut moi
        # neu danh sach rong hoac chen vao dau danh sach
        if not self.head or self.head.data == bf_data :
            new_node.next = self.head # next cua node tro vao head
            self.head = new_node # gan head lai cho new node
        else :
            temp = self.head
            # duyet qua danh sach de tim nut truoc can chen
            while temp.next :
                #temp ke tiep co gia tri = voi bf_data
                if temp.next.data == bf_data:
                    new_node.next = temp.next # lay next cua thang new node tro vao temp ke tiep
                    temp.next = new_node # lay next cua temp hien tai tro vao new node
                    return 
                temp = temp.next

    def delete_node (self,data):
        if not self.head :
            return 
        if self.head.data == data :
            self.head = self.head.next
            return
        
        temp = self.head 
        while temp.next :
            if temp.next.data == data :
                temp.next = temp.next.next
                return 
            temp = temp.next

    
    def traverse (self):
        temp = self.head 
        while temp :
            print(temp.data, end = " ")
            temp = temp.next # di chuyen bien temp sang node ke tiep
        
        print ("")

    def numNodes (self):
        temp = self.head 
        idx = 0 
        while temp :
            idx += 1
            temp = temp.next
        
        return idx

ll = LinkedList()
ll.add_data(1)
ll.add_data(2)
ll.add_data(6)
ll.add_data(4)
ll.add_data(5)
ll.traverse()

print (ll.search_data(4))
ll.insert_before(7,2)
ll.traverse()
ll.delete_node(4)
ll.traverse()
print (ll.numNodes())
