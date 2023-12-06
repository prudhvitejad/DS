class Stack:
    def __init__(self):
        self.arr = []
    
    def push(self,data):
        self.arr.append(data)
        
    def pop(self):
        if(len(self.arr) == 0):
            return -1
        return self.arr.pop()

    def peek(self):
        if(len(self.arr) == 0):
            return -1
        return self.arr[len(self.arr)-1]
    
    def display(self):
        print(self.arr)

stack = Stack()

stack.push(10)
stack.push(20)
stack.push(30)

stack.display()
print("Peek:",stack.peek())

stack.pop()

stack.display()
print("Peek:",stack.peek())
