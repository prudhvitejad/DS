class Node:
    def __init__(self,data=None):
        self.data = data
        self.left = None
        self.right = None

class Stack:
    def __init__(self):
        self.stack = []
    
    def push(self,node):
        self.stack.append(node)
    
    def pop(self):
        if(len(self.stack)>0):
            return self.stack.pop()
        else:
            return None
    
    def peek(self):
        if(len(self.stack)>0):
            return self.stack[len(self.stack)-1]
        else:
            return None
    
    def isEmpty(self):
        return len(self.stack) == 0

class Queue:
    def __init__(self):
        self.queue = []
    
    def enqueue(self,node):
        self.queue.append(node)
    
    def dequeue(self):
        if self.isEmpty():
            print("Queue Underflow")
            return None
        else:
            return self.queue.pop(0)

    def isEmpty(self):
        return len(self.queue) == 0

class BinaryTree:
    def __init__(self):
        self.root = None
    
    '''
        #We use Level Order traversal logic to add/insert the nodes to the binary tree.
        
        if root is Null
            then new node become root
        else
            create a Queue and enqueue the root node to it.
            iterate until the queue length becomes zero
                temp-node = dequeue()
                if temp-node -> left is Null
                    temp-node-> left = new-node
                else
                    enqueue the temp-node-> left
                if temp-node -> right is Null
                    temp-node-> right = new-node
                else
                    enqueue the temp-node-> right
    '''
    def insert(self,node):
        if self.root is None:
            self.root = node
        else:
            queue = Queue()
            queue.enqueue(self.root)

            while(not queue.isEmpty()):
                temp = queue.dequeue()

                if(temp.left is not None):
                    queue.enqueue(temp.left)
                if(temp.left is None):
                    temp.left = node
                    return
                
                if(temp.right is not None):
                    queue.enqueue(temp.right)
                if(temp.right is None):
                    temp.right = node
                    return             
    
    def preOrder(self, root):
        if(root is not None):
            print(root.data, end=" ")
            self.preOrder(root.left)
            self.preOrder(root.right)

    # Pre-order recursivc traversal. The nodes' values are appended to the result list in traversal order 
    def preorderRecursive(self, root, result): 
        if not root: 
            return 
        result.append(root.data) 
        self.preorderRecursive(root.left, result) 
        self.preorderRecursive(root.right, result)

    """
        In the recursive version, a stack is required as we need to remember the current node so that after completing 
        the left subtree we can go to the right subtree. To simulate the same, first we process the current node and 
        before going to the left subtree, we store the current node on stack. After completing the left subtree processing, 
        pop the element nnd go to its right subtree. Continue this process until stack is non-empty. 
    """
    def preOrderIterative(self):
        if(self.root is not None):
            stack = Stack()
            stack.push(self.root)

            while( not stack.isEmpty() ):
                temp = stack.pop()
                print(temp.data,end=" ")

                if(temp.right is not None):
                    stack.push(temp.right)
                
                if(temp.left is not None):
                    stack.push(temp.left)


node = Node(10)
binaryTree = BinaryTree()
binaryTree.insert(node)

node = Node(20)
binaryTree.insert(node)
node = Node(30)
binaryTree.insert(node)
node = Node(40)
binaryTree.insert(node)
node = Node(50)
binaryTree.insert(node)

binaryTree.preOrderIterative()
print()
binaryTree.preOrder(binaryTree.root)
