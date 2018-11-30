class Node {
    private Object data ;
    private Node next ;         // 定义下一个节点
    public Node(Object data) {  // 节点所保存的数据
        this.data = data ;
    }
    public void setData(Object data) {
        this.data = data ;
    }
    public Object getData() {
        return this.data ;
    }
    public void setNext(Node next) {
        this.next = next ;
    }
    public Node getNext() {
        return this.next ;
    }
}
public class TestLinkDemo {
    public static void main(String[] args) {
        // 1. 封装几个节点
        Node root = new Node("火车头") ;
        Node n1 = new Node("车厢A") ;
        Node n2 = new Node("车厢B") ;
        Node n3 = new Node("车厢C") ;
        // 2. 设置节点之间的关系
        root.setNext(n1) ;
        n1.setNext(n2) ;
        n2.setNext(n3) ;
        // 3. 输出链表
        print(root);
    }
    public static void print(Node node) {
        if (node != null) {
            System.out.println(node.getData());
            print(node.getNext());
        }
    }
}
