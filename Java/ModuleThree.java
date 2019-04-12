class Student {
    private int stuid;
    private String name;
    private int age;
    //private Course[] courses;
    private StudentCourse[] studentCourses;
    public Student() {}
    public Student(int stuid, String name, int age) {
        this.stuid = stuid;
        this.name = name;
        this.age = age;
    }
    /*
    public void setCourses(Course[] courses) {
        this.courses = courses;
    }
    */
    public void setStudentCourses(StudentCourse[] studentCourses) {
        this.studentCourses = studentCourses;
    }
    public StudentCourse[] getStudentCourses() {
        return this.studentCourses;
    }
    /*
    public Course[] getCourses() {
        return this.courses;
    }
    */
    public String getInfo() {
        return "【STUDENT】学生编号：" + this.stuid + "，姓名：" + this.name + "，年龄：" + this.age;
    }
}
class Course {
    private int cid;
    private String name;
    private int credit;
    //private Student[] students;
    private StudentCourse[] studentCourses;
    public Course() {}
    public Course(int cid,String name,int credit) {
        this.cid = cid;
        this.name = name;
        this.credit = credit;
    }
    /*
    public void setStudents(Student[] students) {
        this.students = students;
    }
    public Student[] getStudents() {
        return this.students;
    }
    */
    public void setStudentCourses(StudentCourse[] studentCourses) {
        this.studentCourses = studentCourses;
    }
    public StudentCourse[] getStudentCourses() {
        return this.studentCourses;
    }
    public String getInfo() {
        return "【COURSE】课程编号：" + this.cid + "，名称：" + this.name + "，学分：" + this.credit;
    }
}
class StudentCourse { // 学生选课
    private Student student;
    private Course course;
    private double score;
    public StudentCourse() {}
    public StudentCourse(Student student,Course course,double score) {
        this.student = student;
        this.course = course;
        this.score = score;
    }
    public Student getStudent() {
        return this.student;
    }
    public Course getCourse() {
        return this.course;
    }
    public double getScore() {
        return this.score;
    }
}
public class ModuleThree {
    public static void main(String[] args) {
        // 第一步：根据结构进行关系的设置
        // 1、创建各自的独立对象
        Student stu1 = new Student(1, "张三", 18);
        Student stu2 = new Student(2, "李四", 19);
        Student stu3 = new Student(3, "齐五", 20);
        Course ca = new Course(1001, "马克思主义哲学", 3);
        Course cb = new Course(1002, "操作系统", 2);
        // 2、需要设置学生和课程的关系，这里面需要准备出成绩
        stu1.setStudentCourses(new StudentCourse[] {
            new StudentCourse(stu1, ca, 99.9),
            new StudentCourse(stu1, cb, 87.0)
        });
        stu2.setStudentCourses(new StudentCourse[] {
            new StudentCourse(stu2, ca, 78.9)
        });
        stu3.setStudentCourses(new StudentCourse[] {
            new StudentCourse(stu3, cb, 98.9)
        });
        // 3、设置课程和学生关系
        ca.setStudentCourses(new StudentCourse[] {
            new StudentCourse(stu1, ca, 99.9),
            new StudentCourse(stu2, ca, 78.9)
        });
        cb.setStudentCourses(new StudentCourse[] {
            new StudentCourse(stu1, cb, 87.0),
            new StudentCourse(stu3, cb, 98.9)
        });
        // 第二步：根据结构取出数据
        // 1、可以找到一门课程，以及参加此课程的所有的学生信息，和他的成绩；
        System.out.println(ca.getInfo());
        for (int x = 0; x < ca.getStudentCourses().length; x++) {
            System.out.print("\t|- " +
            ca.getStudentCourses()[x].getStudent().getInfo());
            System.out.print("，成绩：" +
            ca.getStudentCourses()[x].getScore());
            System.out.println();
        }
        System.out.println("==============================");
        // 2、可以找到一名学生，以及学生所有课程信息，和他的成绩
        System.out.println(stu1.getInfo());
        for (int x = 0; x < stu1.getStudentCourses().length; x++) {
            System.out.print("\t|- " +
            stu1.getStudentCourses()[x].getCourse().getInfo());
            System.out.print("，成绩：" +
            stu1.getStudentCourses()[x].getScore());
            System.out.println();
        }
    }
}
