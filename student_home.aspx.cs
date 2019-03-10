using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using MySql.Data.MySqlClient;

public partial class student_home : System.Web.UI.Page
{
    /*
     * 函数名：Page_Load
     * 作用：加载界面
     * 参数：object sender, EventArgs e
     * 返回：void
     */
    protected void Page_Load(object sender, EventArgs e)
    {
        // 初始化界面
        init();
    }

    /*
     * 函数名：init
     * 作用：查询数据，显示到界面
     * 参数：void
     * 返回：void
     */
    private void init()
    {
        // 建立数据库连接对象
        MyDatabase MD = new MyDatabase();

        // 连接数据库
        MySqlConnection mycon = new MySqlConnection(MD.getConnection());
        mycon.Open();

        // 查找数据
        string sql = "select * from view_student_basic_info";
        MySqlCommand mycmd = new MySqlCommand(sql, mycon);
        MySqlDataReader reader = null;
        reader = mycmd.ExecuteReader();

        // 显示到表格
        while (reader.Read())
        {
            
        }

        // 关闭连接
        reader.Close();
        mycon.Close();
    }
}