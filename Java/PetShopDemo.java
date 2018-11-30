class Link {  // 负责链表的操作
    // 将Node定义为内部类，表示Node类只为Link类服务
    private class Node {  // 负责数据与节点关系的匹配
        private Object data ;
        private Node next ;
        public Node(Object data) {
            this.data = data ;
        }
        public void addNode(Node newNode) {
            if (this.next == null) {
                this.next = newNode ;
            } else {
                this.next.addNode(newNode) ;
            }
        }
        public void toArrayNode() {
            Link.this.retData[Link.this.foot++] = this.data ;
            if (this.next != null) {
                this.next.toArrayNode() ;
            }
        }
        public boolean containsNode(Object search) {
            if (search.equals(this.data)) {
                return true ;
            } else {
                if (this.next != null) {
                    return this.next.containsNode(search) ;
                } else {
                    return false ;
                }
            }
        }
        public Object getNode(int index) {
            if (Link.this.foot++ == index) {
                return this.data ;
            } else {
                return this.next.getNode(index) ;
            }
            /*
            System.out.println("0: " + this.data) ;
            if (Link.this.foot == index) {
                System.out.println("1: Found " + this.data) ;
                return this.data ;
            } else {
                System.out.println("2: continue call getNode() " + this.data) ;
                foot++ ;
                return this.next.getNode(index) ;
            }
            */
        }
        public void setNode(int index, Object newData) {
            if (Link.this.foot++ == index) {
                this.data = newData ;
            } else {
                if (this.next != null) {
                    this.next.setNode(index, newData) ;
                }
            }
        }
        
        // 第1次调用：this = Link.root.next, previous = Link.root
        // 第2次调用：this = Link.root.next.next, previous = Link.root.next
        public void removeNode(Node previous, Object data) {
            if (this.data.equals(data)) {
                previous.next = this.next ;
            } else {
                this.next.removeNode(this, data) ;
            }
        }
    }

    private Node root ;
    private int count ;
    private Object[] retData ;
    private int foot = 0 ;
    public void add(Object data) {
        if (data == null) {
            return ;
        }
        Node newNode = new Node(data);
        if (this.root == null) {
            this.root = newNode ;
        } else {
            this.root.addNode(newNode) ;
        }
        count++ ;
    }
    public int size() {
        return this.count ;
    }
    public boolean isEmpty() {
        return this.root == null && this.count == 0 ;
    }
    public Object[] toArray() {
        if (this.count == 0) {
            return null;
        }
        this.retData = new Object[this.count] ;
        this.foot = 0 ;
        this.root.toArrayNode() ;
        return this.retData ;
    }
    public boolean contains(Object search) {
        if (search == null || this.root == null) {
            return false ;
        }
        return this.root.containsNode(search) ;
    }
    public Object get(int index) {
        if (index >= this.count) {
            return null ;
        }
        this.foot = 0 ;
        return this.root.getNode(index) ;
    }
    public void set(int index, Object newData) {
        if (index >= this.count) {
            return ;
        }
        this.foot = 0 ;
        this.root.setNode(index, newData) ;
    }
    public void remove(Object data) {
        if (this.contains(data)) {  // 如果该数据存在，则进行删除处理
            if (this.root.data.equals(data)) {  // 判断是否为根节点数据
                this.root = this.root.next ;
            } else {  // 不是根节点
                this.root.next.removeNode(this.root, data) ;
            }
            this.count--;
        }
    }
}
interface Pet {  // 定义宠物接口
    String getName() ;
    String getColor() ;
    int getAge() ;
}
class PetShop {
    private Link pets = new Link() ;  // 开辟一个链表，保存多个宠物
    public void add(Pet pet) {  // 上架宠物
        this.pets.add(pet) ;
    }
    public void delete(Pet pet) {  // 下架宠物
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
            if (pet.getName().contains(keyWord) || pet.getColor().contains(keyWord)) {
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
        if (data == null) {
            return false ;
        }
        if (this == data) {
            return true ;
        }
        if (!(data instanceof Dog)) {
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
        if (data == null) {
            return false ;
        }
        if (this == data) {
            return true ;
        }
        if (!(data instanceof Cat)) {
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
        System.out.println("【查询结果个数】：" + data.length);
        for (int x = 0 ; x < data.length ; x++) {
            System.out.println(data[x]) ;
        }
        System.out.println();
        shop.delete(new Dog("金毛",2,"棕色"));
        all = shop.search("金") ;
        data = all.toArray() ;
        System.out.println("【查询结果个数】：" + data.length);
        for (int x = 0 ; x < data.length ; x++) {
            System.out.println(data[x]) ;
        }
    }
}
