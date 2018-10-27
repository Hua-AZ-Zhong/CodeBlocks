class Person{
	String name;
	int age;
	public void display(){
		System.out.println("Name = " + name + " , Age = " + age);
	}
}

public class TestDemo{
	public static void main(String args[]){
		Person per = null;
		per = new Person();
		per.display();
	}
}
