using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：Teacher
 * 描述：教师实体类
 * 作者：刘畅
 * 修改：[1]2019-3-2第一次创建
 * 其他：
 */
public class Teacher
{
    private string teach_id;        // 教师工号
    private string teach_name;      // 姓名
    private string teach_sex;       // 性别
    private string teach_birth;     // 出生年月
    private string teach_post;      // 职务
    private string teach_title;     // 职称
    private string teach_section;   // 隶属单位
    private string teach_political; // 政治面貌

    // set
    public void setTeach_id(string teach_id) { this.teach_id = teach_id; }
    public void setTeach_name(string teach_name) { this.teach_name = teach_name; }
    public void setTeach_sex(string teach_sex) { this.teach_sex = teach_sex; }
    public void setTeach_birth(string teach_birth) { this.teach_birth = teach_birth; }
    public void setTeach_post(string teach_post) { this.teach_post = teach_post; }
    public void setTeach_title(string teach_title) { this.teach_title = teach_title; }
    public void setTeach_section(string teach_section) { this.teach_section = teach_section; }
    public void setTeach_political(string teach_political) { this.teach_political = teach_political; }

    // get
    public string getTeach_id() { return teach_id; }
    public string getTeach_name() { return teach_name; }
    public string getTeach_sex() { return teach_sex; }
    public string getTeach_birth() { return teach_birth; }
    public string getTeach_post() { return teach_post; }
    public string getTeach_title() { return teach_title; }
    public string getTeach_section() { return teach_section; }
    public string getTeach_political() { return teach_political; }

    /*
     * 函数名：Teacher
     * 作用：无参构造函数
     * 参数：void
     * 返回值：Teacher
     */
	public Teacher()
	{
	}

    /*
     * 函数名：Teacher
     * 作用：有参构造函数
     * 参数：string teach_id
     * 返回值：Teacher
     */
    public Teacher(string teach_id)
    {
        this.teach_id = teach_id;
    }

    /*
     * 函数名：Teacher
     * 作用：有参构造函数
     * 参数：string teach_id, string teach_name, string teach_section
     * 返回值：Teacher
     */
    public Teacher(string teach_id, string teach_name, string teach_section)
    {
        this.teach_id = teach_id;
        this.teach_name = teach_name;
        this.teach_section = teach_section;
    }
}