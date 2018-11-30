class Link {  // 负责链表的操作
}
interface Pet {  // 定义宠物接口
	public String getName() ;
	public String getColor() ;
	public int getAge() ;
}
class PetShop {
	private Link pets = new Link() ;  // 开辟一个链表，保存多个宠物
	public void add(Pet pet) {  // 上架宠物
		this.pets.add(pet) ;
	}
	public void remove(Pet pet) {  // 下架宠物
		this.pets.remove(pet) ;
	}
	public Link getPets() {  // 取得全部宠物
		return this.pets ;
	}
	public Link search(String keyWord) {  // 按关键字查找宠物，并保存结果
		Link result = new Link() ;  // 保存查询结果
		Object[] data = this.pets.toArray() ;
		for (int x = 0 ; x < data.length ; x++) {
			Pet pet = (Pet) data[x] ;
			if(pet.getName().contains(keyWord) || pet.getColor().contains(keyWord)) {
				result.add(pet) ;
			}
		}
		return result ;
	}
}
class Dog implements Pet {
	private String name ;
	private int age ;
	private String color ;
	public Dog(String name, int age, String color) {
		this.name = name ;
		this.age = age ;
		this.color = color ;
	}
	public String getName() {
		return this.name ;
	}
	public int getAge() {
		return this.age ;
	}
	public String getColor() {
		return this.color ;
	}
	public String toString() {
		return "【狗】名字： " + this.name + "，年龄； " + this.age + "，颜色： " + this.color ;
	}
	public boolean equals(Object data) {
		if(data == null) {
			return false ;
		}
		if(this == data) {
			return true ;
		}
		if(!(data instanceof Dog)) {
			return false ;
		}
		Dog pet = (Dog) data ;
		return this.name.equals(pet.name) && this.age == pet.age && this.color.equals(pet.color) ;
	}
}
class Cat implements Pet {
	private String name ;
	private int age ;
	private String color ;
	public Cat(String name, int age, String color) {
		this.name = name ;
		this.age = age ;
		this.color = color ;
	}
	public String getName() {
		return this.name ;
	}
	public int getAge() {
		return this.age ;
	}
	public String getColor() {
		return this.color ;
	}
	public String toString() {
		return "【猫】名字： " + this.name + "，年龄； " + this.age + "，颜色： " + this.color ;
	}
	public boolean equals(Object data) {
		if(data == null) {
			return false ;
		}
		if(this == data) {
			return true ;
		}
		if(!(data instanceof Cat)) {
			return false ;
		}
		Cat pet = (Cat) data ;
		return this.name.equals(pet.name) && this.age == pet.age && this.color.equals(pet.color) ;
	}
}
public class PetShopDemo {
	public static void main(String[] args) throws Exception {
		PetShop shop = new PetShop() ;
		shop.add(new Dog("哈士奇",1,"黑白"));
		shop.add(new Dog("金毛",2,"棕色"));
		shop.add(new Dog("腊肠",3,"棕黑"));
		shop.add(new Dog("拉布拉多",3,"灰白"));
		shop.add(new Cat("加菲猫",1,"金色"));
		shop.add(new Cat("波斯猫",2,"白色"));
		Link all = shop.search("金") ;
		Object[] data = all.toArray() ;
		for(int x = 0 ; x < data.length ; x++) {
			System.out.println(data[x]) ;
		}
	}
}
