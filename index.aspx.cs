using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using MySql.Data.MySqlClient;

public partial class index : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        // 查询管理员信息，显示到界面头
        string account = Request.QueryString["account"];
        string adminName = Request.QueryString["adminName"];
        string rank = Request.QueryString["rank"];
        Label_admin.Text = "用户：" + adminName;
        Image_rank.ImageUrl = "~/Image/adminImg/rank" + rank + ".png";
        Session["AdminAccount"] = account;
        Session["AdminName"] = adminName;
        Session["AdminRank"] = rank;

        // 查询数据库数据，显示设备基本信息到表格
        bind("select * from view_equipment_simple");
    }

    /*
     * 函数名：bind
     * 作用：连接数据库，查询数据，显示到GridView控件
     * 参数：string sql
     * 返回：void
     */
    private void bind(string sql)
    {
        MyDatabase MD = new MyDatabase();
        MySqlConnection conn = new MySqlConnection(MD.getConnection());
        MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
        DataSet ds = new DataSet();
        da.Fill(ds, "tempTable");
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
}