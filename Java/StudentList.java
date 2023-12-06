class StudentList
{
	Student start,end;
	 int len=0;
	void add(String name,int age,float cg)
	{
		Student s1=new Student(name,age,cg);
		if(start==null)
		{
			start=s1;
			end=s1;
			len++;
		}
		else
		{
			end.next=s1;
			end=s1;
			len++;
		}
	}
	void traversal()
	{
		Student current=start;
		while(current!=null)
		{
			System.out.println(current);
			current=current.next;
		}
	}
	void deleteByName(String name)
	{
				int flag=0;
		       Student current=start;
		       if(current.name.equals(name))
		       {
				   start=current.next;
				   flag=1;
				   len--;
			   }
			   else
			   {
				   while(current.next.next!=null)
				   {
					   if(current.next.name.equals(name))
					   {
						   current.next=current.next.next;
						   flag=1;
						   len--;
						   return;
					   }
					   current=current.next;
				   }
			   }
			   if(current.next.name.equals(name)&&flag==0)
			   {
				   end=current;
				   end.next=null;
				   len--;
			   }
	}
	void searchByName(String key)
	{
		Student current=start;
		int flag=0;
		while(current!=null)
		{
			if(current.name.equals(key))
			{
				
			flag=1;
			break;
			}
			current=current.next;
		}
		    if(flag==0)
		    {
				System.out.println(key+" not existed..");
			}
			else
				System.out.println(key+" Existed.. Data is "+current);
	}
	void sortByName()
	{
		int out=len-1;
		Student pre,current,post;
		int in=0;
		//current=start;
		 while(out>0)
		 {
			 in=0;
			 pre=null;
			current=start;
			post=current.next;
			 while(in<out)
			 {
					if(current.name.compareTo(post.name)>0)
					{
						current.next=post.next;
						post.next=current;
						if(pre==null)
						{
							start=post;
							//pre=post;
						}
						else
						{
							pre.next=post;
						}
						pre=post;
						post=current.next;					
							
					}
					else
					{
						pre=current;
						current=post;
						post=current.next;
					}
				 in++;
			 }
			
			 out--;
		 }
	}
}
