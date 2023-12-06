class Student
{
	String name;
	int age;
	float cgpa;
	Student next;
	Student(String name,int age,float cg)
	{
		this.name=name;
		this.age=age;
		this.cgpa=cg;
		this.next=null;
	}
	public String toString()
	{
		return name+" "+age+" "+cgpa;
	}
}
