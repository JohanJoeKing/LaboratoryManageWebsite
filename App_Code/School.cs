using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：School
 * 描述：学院实体类
 * 作者：刘畅
 * 修改：[1]2019-3-4第一次创建
 * 其他：
 */
public class School
{
    private string name;
    private string code;

    // set
    public void setName(string name) { this.name = name; }
    public void setCode(string code) { this.code = code; }

    // get
    public string getName() { return this.name; }
    public string getCode() { return this.code; }

    /*
     * 函数名：School
     * 作用：无参构造函数
     * 参数：void
     * 返回值：School
     */
    public School()
	{
		
	}

    /*
     * 函数名：School
     * 作用：有参构造函数
     * 参数：string name, string code
     * 返回值：School
     */
    public School(string name, string code)
    {
        this.name = name;
        this.code = code;
    }
}