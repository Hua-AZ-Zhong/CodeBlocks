/*
class Outer {
	private String msg = "Hello World!" ;
	public String getMsg() {
		return this.msg;
	}
	public void fun() {
		Inner in = new Inner();
		in.print();
	}
}

class Inner {
	public void print() {
		System.out.println(new Outer().getMsg());
	}
}

public class TestNest {
	public static void main(String[] args) {
		Outer out = new Outer();
		out.fun();
	}
}
*/

class Outer {
	private String msg = "Hello World!" ;
	public String getMsg() {
		return this.msg;
	}
	public void fun() {  // 3、现在由out对象调用了fun()方法
		Inner in = new Inner(this);   // 4、this标识当前对象
		in.print();  // 7、调用方法
	}
}

// 将主方法中的Outer类对象传递到Inner类中
class Inner {
	private Outer out;
	public Inner(Outer out) {  // 5、Inner.out = main.out
		this.out = out;  // 6、引用传递
	}
	public void print() {   // 8、执行此方法
		System.out.println(this.out.getMsg());
	}
}

public class TestNest {
	public static void main(String[] args) {
		Outer out = new Outer();  // 1、实例化Outer类对象
		out.fun();  // 2、调用Outer类方法
	}
}
