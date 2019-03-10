using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;
using MySql.Data.MySqlClient;

/*
 * 类名：LoginHelper
 * 描述：登录动作服务类
 * 作者：刘畅
 * 修改：2019-3-2第一次搭建
 * 其他：
 */
public class LoginHelper
{
    // 登录用户属性
    private string account;
    private string pwd;
    private string admin_name;
    private string rank;

    // set
    public void setAccount(string account) { this.account = account; }
    public void setPwd(string pwd) { this.pwd = pwd; }
    public void setAdmin_name(string admin_name) { this.admin_name = admin_name; }
    public void setRank(string rank) { this.rank = rank; }

    // get
    public string getAccount() { return this.account; }
    public string getPwd() { return this.pwd; }
    public string getAdmin_name() { return this.admin_name; }
    public string getRank() { return this.rank; }

    /*
     * 函数名：构造函数
     * 作用：创建对象
     * 参数：void
     * 返回：LoginHelper
     */
	public LoginHelper()
	{
        this.admin_name = "";
        this.rank = "1";
	}

    public LoginHelper(string account, string pwd)
    {
        this.account = account;
        this.pwd = pwd;
        this.admin_name = "";
        this.rank = "1";
    }

    /*
     * 函数名：构造函数
     * 作用：创建对象
     * 参数：void
     * 返回：LoginHelper
     */
    public bool login()
    {
        bool flag = false;

        // 查询密码
        string pwd_input = "";
        MyDatabase MD = new MyDatabase();
        MySqlConnection mycon = new MySqlConnection(MD.getConnection());
        mycon.Open();
        string sql = string.Format("select * from admin_table where admin_id='{0}'", this.account);
        MySqlCommand mycmd = new MySqlCommand(sql, mycon);
        MySqlDataReader reader = null;
        reader = mycmd.ExecuteReader();
        while (reader.Read())
        {
            this.admin_name = reader[1].ToString();
            pwd_input = reader[2].ToString();
            this.rank = reader[3].ToString();
        }
        reader.Close();
        mycon.Close();

        // 验证
        if (this.pwd == pwd_input)
            flag = true;
        else
            flag = false;
        return flag;
    }
}