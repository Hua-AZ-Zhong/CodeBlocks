class Dept { // 部门信息
	private int did;
	private String dname;
	private Emp emps[] ; // 一个部门有多个雇员
	private Role role ; // 一个部门有一个角色
	public Dept(int did,String dname) {
		this.did = did ;
		this.dname = dname ;
	}
	public void setEmps(Emp[] emps) {
		this.emps = emps ;
	}
	public Emp[] getEmps() {
		return this.emps ;
	}
	public void setRole(Role role) {
		this.role = role ;
	}
	public Role getRole() {
		return this.role ;
	}
	public String getInfo() {
		return "【部门】did = " + this.did + "，名称 = " + this.dname ;
	}
}
class Emp { // 雇员信息
	private int eid ;
	private String ename ;
	private Dept dept ; // 一个雇员属于一个部门
	public Emp(int eid, String ename) {
		this.eid = eid ;
		this.ename = ename ;
	}
	public void setDept(Dept dept) {
		this.dept = dept ;
	}
	public Dept getDept() {
		return this.dept ;
	}
	public String getInfo() {
		return "【雇员】eid = " + this.eid + "、姓名 = " + this.ename ;
	}
}
class Role { // 角色信息
	private int rid ;
	private String title ;
	private Dept[] depts ; // 多个部门具备此角色
	private Action[] actions ; // 一个角色拥有多个权限
	public Role(int rid,String title){
		this.rid = rid ;
		this.title = title ;
	}
	public void setDepts(Dept[] depts) {
		this.depts = depts ;
	}
	public Dept[] getDepts() {
		return this.depts ;
	}
	public void setActions(Action[] actions) {
		this.actions = actions ;
	}
	public Action[] getActions() {
		return this.actions ;
	}
	public String getInfo() {
		return "【角色】rid = " + this.rid + "、title = " + this.title ;
	}
}
class Action { // 权限, Previlege
	private int aid ;
	private String title ;
	private String flag ;
	private Role[] roles ;
	public Action(int aid,String title,String flag) {
		this.aid = aid ;
		this.title = title ;
		this.flag = flag ;
	}
	public void setRoles(Role[] roles) {
		this.roles = roles ;
	}
	public Role[] getRoles() {
		return this.roles ;
	}
	public String getInfo() {
		return "【权限】aid = " + this.aid + "、title = " + this.title + "、flag = " + this.flag ;
	}
}
public class RoleAction {
	public static void main(String args[]) {
		// 第一步：设置数据之间的关系
		// 1、创建部门数据
		Dept d10 = new Dept(10,"财务部") ;
		Dept d20 = new Dept(20,"市场部") ;
		// 2、创建雇员数据
		Emp e7369 = new Emp(7369,"SMITH") ;
		Emp e7566 = new Emp(7566,"ALLEN") ;
		Emp e7902 = new Emp(7902,"FORD") ;
		Emp e7839 = new Emp(7839,"KING") ;
		Emp e7788 = new Emp(7788,"SCOTT") ;
		// 3、创建角色数据
		Role r100 = new Role(100,"管理者") ;
		Role r200 = new Role(200,"职员层") ;
		// 4、创建权限数据
		Action a1000 = new Action(1000,"雇员入职","emp:add") ;
		Action a2000 = new Action(2000,"雇员晋升","emp:edit") ;
		Action a3000 = new Action(3000,"发布公告","news:add") ;
		Action a6000 = new Action(6000,"查看客户信息","customer:list") ;
		Action a7000 = new Action(7000,"回访记录","customer:add") ;
		// 5、设置角色和权限的关系
		r100.setActions(new Action[] { a1000,a2000,a3000} ) ;
		r200.setActions(new Action[] { a6000,a7000} ) ;
		// 6、设置权限和角色的关系
		a1000.setRoles(new Role[] {r100} );
		a2000.setRoles(new Role[] {r100} );
		a3000.setRoles(new Role[] {r100} );
		a6000.setRoles(new Role[] {r200} );
		a7000.setRoles(new Role[] {r200} );
		// 7、设置部门和角色的关系
		d10.setRole(r100) ;
		d20.setRole(r200) ;
		// 8、设置角色和部门的关系
		r100.setDepts(new Dept[] {d10} );
		r200.setDepts(new Dept[] {d20} );
		// 9、设置雇员和部门的关系
		e7369.setDept(d10) ;
		e7566.setDept(d10) ;
		e7902.setDept(d20) ;
		e7839.setDept(d20) ;
		e7788.setDept(d20) ;
		// 10、设置部门和雇员
		d10.setEmps(new Emp[] { e7369, e7566 } ) ;
		d20.setEmps(new Emp[] { e7902, e7839, e7788  } ) ;

		// 第二步：取出相应数据
		// 要求可以根据一个员工找到他所对应的部门，以及该部门对应的角色，以及每个角色对应的所有权限；
		System.out.println("【1】要求可以根据一个员工找到他所对应的部门，以及该部门对应的角色>，以及每个角色对应的所有权限") ;
		System.out.println(e7369.getInfo()) ;
		System.out.println("\t|- " + e7369.getDept().getInfo()) ;
		System.out.println("\t\t|- " + e7369.getDept().getRole().getInfo()) ;
		for(int x = 0; x < e7369.getDept().getRole().getActions().length; x++) {
			System.out.println("\t\t\t|- " + e7369.getDept().getRole().getActions()[x].getInfo());
		}

		System.out.println("【2】可以根据一个角色找到具备此角色的所有部门，以及该部门下的所有员工") ;
		System.out.println(r200.getInfo()) ;
		for(int x = 0; x < r200.getDepts().length; x++) {
			System.out.println("\t|- " + r200.getDepts()[x].getInfo()) ;
			for(int y = 0; y < r200.getDepts()[x].getEmps().length; y++) {
				System.out.println("\t\t|- " + r200.getDepts()[x].getEmps()[y].getInfo()) ;
			}
		}

		System.out.println("【3】根据一个权限列出具备有该权限的所有的角色以及每一个角色下对应的所有部门，以及每个部门中的所有员工");
		System.out.println(a2000.getInfo()) ;
		for(int x = 0; x < a2000.getRoles().length; x++) {
			System.out.println("\t|- " + a2000.getRoles()[x].getInfo()) ;
			for(int y = 0; y < a2000.getRoles()[x].getDepts().length; y++) {
				System.out.println("\t\t|- " + a2000.getRoles()[x].getDepts()[y].getInfo()) ;
				for(int z = 0; z < a2000.getRoles()[x].getDepts()[y].getEmps().length; z++) {
					System.out.println("\t\t\t|- " + a2000.getRoles()[x].getDepts()[y].getEmps()[z].getInfo());
				}
			}
		}
	}
}
