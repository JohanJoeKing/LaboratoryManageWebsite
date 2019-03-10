using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：Student
 * 描述：学生实体类
 * 作者：刘畅
 * 修改：[1]2019-3-2第一次创建
 * 其他：
 */
public class Student
{
    private string stu_name;            // 姓名
    private string stu_id;              // 学号
    private string stu_sex;             // 性别
    private string stu_birth;           // 出生年月
    private string stu_class;           // 班级
    private string stu_instructor_id;   // 导员工号
    private string stu_school;          // 学院
    private string stu_major;           // 专业
    private string political;           // 政治面貌
    private string stu_nation;          // 民族
    private string stu_status;          // 学籍状态
    private string stu_sch_region;      // 所在校区

    // set
    public void setStu_name(string stu_name) { this.stu_name = stu_name; }
    public void setStu_id(string stu_id) { this.stu_id = stu_id; }
    public void setStu_sex(string stu_sex) { this.stu_sex = stu_sex; }
    public void setStu_birth(string stu_birth) { this.stu_birth = stu_birth; }
    public void setStu_class(string stu_class) { this.stu_class = stu_class; }
    public void setStu_instructor_id(string stu_instructor_id) { this.stu_instructor_id = stu_instructor_id; }
    public void setStu_school(string stu_school) { this.stu_school = stu_school; }
    public void setStu_major(string stu_major) { this.stu_major = stu_major; }
    public void setPolitical(string political) { this.political = political; }
    public void setStu_nation(string stu_nation) { this.stu_nation = stu_nation; }
    public void setStu_status(string stu_status) { this.stu_status = stu_status; }
    public void setStu_sch_region(string stu_sch_region) { this.stu_sch_region = stu_sch_region; }

    // get
    public string getStu_name() { return stu_name; }
    public string getStu_id() { return stu_id; }
    public string getStu_sex() { return stu_sex; }
    public string getStu_birth() { return stu_birth; }
    public string getStu_class() { return stu_class; }
    public string getStu_instructor_id() { return stu_instructor_id; }
    public string getStu_school() { return stu_school; }
    public string getStu_major() { return stu_major; }
    public string getPolitical() { return political; }
    public string getStu_nation() { return stu_nation; }
    public string getStu_status() { return stu_status; }
    public string getStu_sch_region() { return stu_sch_region; }

    /*
     * 函数名：Student
     * 作用：无参构造函数
     * 参数：void
     * 返回值：Student
     */
	public Student()
	{
	}

    /*
     * 函数名：Student
     * 作用：有参构造函数
     * 参数：string stu_id
     * 返回值：Student
     */
    public Student(string stu_id)
    {
        this.stu_id = stu_id;
    }

    /*
     * 函数名：Student
     * 作用：有参构造函数
     * 参数：string stu_id, string stu_name, string stu_class
     * 返回值：Student
     */
    public Student(string stu_id, string stu_name, string stu_class)
    {
        this.stu_id = stu_id;
        this.stu_name = stu_name;
        this.stu_class = stu_class;
    }
}