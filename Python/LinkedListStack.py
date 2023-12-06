class LinkedList:
    def __init__(self,data=None):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.head = None
    
    def push(self,new):
        if self.head is None:
            self.head = new
        else:
            temp = self.head
            while(temp.next):
                temp = temp.next
            temp.next = new

    def pop(self):
        if self.head is None:
            return None
        temp = self.head
        while(temp.next.next):
            temp = temp.next
        temp2 = temp.next
        temp.next = None
        return temp2

    def peek(self):
        if self.head is None:
            return None
        temp = self.head
        while(temp.next):
            temp = temp.next
        return temp
    
    def display(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next


stack = Stack()

stack.display()
print("Peek:",stack.peek())
print("Pop:",stack.pop())

new  = LinkedList(10)
stack.push(new)
new = LinkedList(20)
stack.push(new)
new = LinkedList(30)
stack.push(new)

stack.display()
print("Peek:",stack.peek().data)
print("Pop:",stack.pop().data)

stack.display()
