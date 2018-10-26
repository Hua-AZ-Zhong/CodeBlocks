class Person{
	String name;
	int age;
}

public class TestDemo{
	public static void main(String args[]){
		Person per = null;
		per = new Person();
		System.out.println("Name = " + per.name + "," + "Age = " + per.age);
	}
}
