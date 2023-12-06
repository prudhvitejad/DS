import java.io.*;
import java.util.*;
class StudentListDemo
{
	public static void main(String args[])throws IOException
	{
		StudentList f2=new StudentList();
		FileReader fr=new FileReader("students.txt");
		BufferedReader br=new BufferedReader(fr);
		String line="";
		while((line=br.readLine())!=null)
		{
			StringTokenizer st=new StringTokenizer(line," ");
			//while()
			String name=st.nextToken();
			int age=Integer.parseInt(st.nextToken());
			float cg=Float.parseFloat(st.nextToken());
			f2.add(name,age,cg);
			
		}	
		f2.traversal();
		f2.searchByName("Bhavya");
		f2.deleteByName("Munna");
		f2.add("Virat",33,8.7F);
		f2.traversal();
		f2.sortByName();
		System.out.println("------------------");
		f2.traversal();
	}
}
