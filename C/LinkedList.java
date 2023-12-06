import java.util.*;

public class LinkedList
{    
    private int data;
    private LinkedList next;    
    
    LinkedList(int data)
    {
      this.data = data;
    }
    
    LinkedList() { }
        
    LinkedList insertAtTheEnd(LinkedList head,LinkedList new1)
    {
        if(head.next == null && head.data == 0)
        {
          head = new1;
          return head;
        }
        else if(head.next == null && head.data != 0)
        {
            head.next = new1;
            return head;
        }
        else
        {
            LinkedList temp = head;
            
            while(temp.next != null)
                temp = temp.next;
                
            temp.next = new1;
            return head;
        }
    }
    
    void display(LinkedList head)
    {
        LinkedList temp = head;
        while(temp != null)
        {
            System.out.print(temp.data+"->");
            temp = temp.next;
        }
    }        
    
    public static void main(String[] args)
    {
        LinkedList head = null;
        LinkedList new1 = null;
        LinkedList temp = null;
        
        head = new LinkedList();
        
        new1 = new LinkedList(10);
        
        head = head.insertAtTheEnd(head,new1);
        
        new1 = new LinkedList(20);
        
        head = head.insertAtTheEnd(head,new1);
        
        new1 = new LinkedList(30);
        
        head = head.insertAtTheEnd(head,new1);
        
        head.display(head);
        System.out.println();
    }
}





