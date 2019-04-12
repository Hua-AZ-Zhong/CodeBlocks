class Link {  // 负责链表的操作
    // 将Node定义为内部类，表示Node类只为Link类服务
    private class Node {  // 负责数据与节点关系的匹配
        private Object data;
        private Node next;
        public Node(Object data) {
            this.data = data;
        }
        public void addNode(Node newNode) {
            if (this.next == null) {
                this.next = newNode;
            } else {
                this.next.addNode(newNode);
            }
        }
        public void toArrayNode() {
            Link.this.retData[Link.this.foot++] = this.data;
            if (this.next != null) {
                this.next.toArrayNode();
            }
        }
        public boolean containsNode(Object search) {
            if (search.equals(this.data)) {
                return true;
            } else {
                if (this.next != null) {
                    return this.next.containsNode(search);
                } else {
                    return false;
                }
            }
        }
        public Object getNode(int index) {
            if (Link.this.foot++ == index) {
                return this.data;
            } else {
                return this.next.getNode(index);
            }
            /*
            System.out.println("0: " + this.data);
            if (Link.this.foot == index) {
                System.out.println("1: Found " + this.data);
                return this.data;
            } else {
                System.out.println("2: continue call getNode() " + this.data);
                foot++;
                return this.next.getNode(index);
            }
            */
        }
        public void setNode(int index, Object newData) {
            if (Link.this.foot++ == index) {
                this.data = newData;
            } else {
                if (this.next != null) {
                    this.next.setNode(index, newData);
                }
            }
        }
        
        // 第1次调用：this = Link.root.next, previous = Link.root
        // 第2次调用：this = Link.root.next.next, previous = Link.root.next
        public void removeNode(Node previous, Object data) {
            if (this.data.equals(data)) {
                previous.next = this.next;
            } else {
                this.next.removeNode(this, data);
            }
        }
    }

    private Node root;
    private int count;
    private Object[] retData;
    private int foot = 0;
    public void add(Object data) {
        if (data == null) {
            return;
        }
        Node newNode = new Node(data);
        if (this.root == null) {
            this.root = newNode;
        } else {
            this.root.addNode(newNode);
        }
        count++;
    }
    public int size() {
        return this.count;
    }
    public boolean isEmpty() {
        return this.root == null && this.count == 0;
    }
    public Object[] toArray() {
        if (this.count == 0) {
            return null;
        }
        this.retData = new Object[this.count];
        this.foot = 0;
        this.root.toArrayNode();
        return this.retData;
    }
    public boolean contains(Object search) {
        if (search == null || this.root == null) {
            return false;
        }
        return this.root.containsNode(search);
    }
    public Object get(int index) {
        if (index >= this.count) {
            return null;
        }
        this.foot = 0;
        return this.root.getNode(index);
    }
    public void set(int index, Object newData) {
        if (index >= this.count) {
            return;
        }
        this.foot = 0;
        this.root.setNode(index, newData);
    }
    public void remove(Object data) {
        if (this.contains(data)) {  // 如果该数据存在，则进行删除处理
            if (this.root.data.equals(data)) {  // 判断是否为根节点数据
                this.root = this.root.next;
            } else {  // 不是根节点
                this.root.next.removeNode(this.root, data);
            }
            this.count--;
        }
    }
}
public class NodeLink {
    public static void main(String[] args) throws Exception {
        Link all = new Link();
        System.out.println(all.size() + " = " + all.isEmpty());
        all.add("hello");
        all.add("world");
        all.add("everyone");
        System.out.println(all.size() + " = " + all.isEmpty());
        
        System.out.println("===================");
        Object[] result = all.toArray();
        for (int x = 0; x < result.length; x++)
            System.out.println(result[x]);

        System.out.println("===================");
        System.out.println(all.contains("hello"));
        System.out.println(all.contains("xxoo"));
        System.out.println(all.contains(null));

        System.out.println("===================");
        System.out.println(all.get(0));
        System.out.println(all.get(1));
        System.out.println(all.get(2));
        System.out.println("OutOfIndex example: " + all.get(3));
        
        System.out.println("===================");
        all.set(1, "Milk");
        System.out.println(all.get(0));
        System.out.println(all.get(1));
        System.out.println(all.get(2));

        System.out.println("===================");
        all.remove("Milk");
        System.out.println(all.get(0));
        System.out.println(all.get(1));
        System.out.println(all.get(2));
    }
}
