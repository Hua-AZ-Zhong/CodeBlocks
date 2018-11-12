class Outer { // 定义一个外部类
	private String msg = "Hello World!" ;
	class Inner { // 定义一个内部类
		public void print() {
			//System.out.println(msg);   等同于下一句带this的输出
			System.out.println(Outer.this.msg);
		}
	}
	public void fun() {
		Inner in = new Inner();  // 内部类对象
		in.print();  // 内部类提供的print()方法
	}
}

public class NestClass {
	public static void main(String[] args) {
		Outer out = new Outer();  // 外部类对象
		out.fun();   // 调用外部类中的方法
		// 声明内部类对象
		Outer.Inner inA = new Outer().new Inner();
		inA.print();
	}
}
