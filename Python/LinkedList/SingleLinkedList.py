'''
One way of implementing LinkedList

class Student:
    def __init__(self,name=None,branch=None,cgpa=None):
        self.name = name
        self.branch = branch
        self.cgpa = cgpa
        self.next = None
    
    def addAtTheBeginning(self,new,head):
        if(head == None):
            head = new
            return head
        else:
            new.next = head 
            head = new
            return head
    
    def search(self,head,temp):
        if(head == None):
            return None
        else:
            temp2 = head
            while(temp2):
                if(temp2.name == temp.name and temp2.branch == temp.branch and temp2.cgpa == temp.cgpa):
                    return temp2
                temp2 = temp2.next
            return None

    def display(self,head):
        temp = head
        while(temp):
            print(temp.name,temp.branch,temp.cgpa)
            temp = temp.next
        
        
head = None
new = Student("Prudhvi","CSE",8.9)
head = new.addAtTheBeginning(new,head)
new = Student("Reddy","ECE",8.5)
head = new.addAtTheBeginning(new,head)
new = Student("Sevya","Mech",8.5)
head = new.addAtTheBeginning(new,head)
head.display(head)
'''

#Other way of implementing LinkedList 
class Student:
    def __init__(self, name=None, branch=None, cgpa=None):
        self.name = name
        self.branch = branch
        self.cgpa = cgpa
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def addAtTheBeginning(self,new):
        if self.head is None:
            self.head = new
        else:
            new.next = self.head
            self.head = new

    def addAtTheEnd(self,new):
        if self.head is None:
            self.head = new
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new

    def search(self,temp):
        if self.head is None:
            return None
        else:
            temp2 = self.head
            while(temp2):
                if(temp2.name == temp.name and temp2.branch == temp.branch and temp2.cgpa == temp.cgpa):
                    return temp2
                temp2 = temp2.next
            return None

    def display(self):
        temp = self.head
        while temp:
            print(f"Name: {temp.name}, Branch: {temp.branch}, CGPA: {temp.cgpa}")
            temp = temp.next


# Example usage:
linkedList = LinkedList()

new = Student("John", "Computer Science", 3.8)
linkedList.addAtTheEnd(new)
new = Student("Emily", "Electrical Engineering", 3.5)
linkedList.addAtTheEnd(new)
new = Student("Michael", "Mechanical Engineering", 3.2)
linkedList.addAtTheEnd(new)

new = Student("Pavan","Computer Science",9.8)
linkedList.addAtTheBeginning(new)
new = Student("Kalyan","Computer Science",9.7)
linkedList.addAtTheBeginning(new)

linkedList.display()

temp = Student("Pavan","Computer Science",9.8)
temp2 = linkedList.search(temp)
print(f"Search result:\nName: {temp2.name}, Branch: {temp2.branch}, CGPA: {temp2.cgpa}")

