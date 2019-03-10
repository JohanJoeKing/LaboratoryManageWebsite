using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using MySql.Data.MySqlClient;
using System.Net;

public partial class studentManage : System.Web.UI.Page
{
    // 属性
    SqlConnection sqlcon;   // 连接器
    SqlCommand sqlcom;      // SQL命令
    string strCon;          // 连接语句

    /*
     * 函数名：Page_Load
     * 作用：加载界面
     * 参数：object sender, EventArgs e
     * 返回：void
     */
    protected void Page_Load(object sender, EventArgs e)
    {
        MyDatabase MD = new MyDatabase();
        strCon = MD.getConnection2();
        if (!IsPostBack)
        {
            bind();
        }
    }

    /*
     * 函数名：GridView1_RowEditing
     * 作用：修改数据
     * 参数：object sender, GridViewEditEventArgs e
     * 返回：void
     */
    protected void GridView1_RowEditing(object sender, GridViewEditEventArgs e)
    {
        /**/
        GridView1.EditIndex = e.NewEditIndex;
        bind();
        

    }

    /*
     * 函数名：GridView1_RowDeleting
     * 作用：删除数据
     * 参数：object sender, GridViewDeleteEventArgs e
     * 返回：void
     */
    protected void GridView1_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
        string sqlstr = "delete from student_table where stu_id='" + GridView1.DataKeys[e.RowIndex].Value.ToString() + "'";
        sqlcon = new SqlConnection(strCon);
        sqlcom = new SqlCommand(sqlstr,sqlcon);
        sqlcon.Open();
        sqlcom.ExecuteNonQuery();
        sqlcon.Close();
        bind();
    }

    /*
     * 函数名：GridView1_RowUpdating
     * 作用：更新数据
     * 参数：object sender, GridViewUpdateEventArgs e
     * 返回：void
     */
    protected void GridView1_RowUpdating(object sender, GridViewUpdateEventArgs e)
    {
        sqlcon = new SqlConnection(strCon);
        string sqlstr = "update view_student_basic_info set 姓名='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[1].Controls[0])).Text.ToString().Trim() + "',班级='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[2].Controls[0])).Text.ToString().Trim() + "',学号='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[3].Controls[0])).Text.ToString().Trim() + "',性别='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[4].Controls[0])).Text.ToString().Trim() + "',学院='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[5].Controls[0])).Text.ToString().Trim() + "',专业='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[6].Controls[0])).Text.ToString().Trim() + "',出生年月='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[7].Controls[0])).Text.ToString().Trim() + "',导员='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[8].Controls[0])).Text.ToString().Trim() + "',政治面貌='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[9].Controls[0])).Text.ToString().Trim() + "',民族='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[10].Controls[0])).Text.ToString().Trim() + "',就读校区='"
            + ((TextBox)(GridView1.Rows[e.RowIndex].Cells[11].Controls[0])).Text.ToString().Trim() + "' where id='" 
            + GridView1.DataKeys[e.RowIndex].Value.ToString() + "'";
        sqlcom = new SqlCommand(sqlstr,sqlcon);
        sqlcon.Open();
        sqlcom.ExecuteNonQuery();
        sqlcon.Close();
        GridView1.EditIndex = -1;
        bind();
    }

    /*
     * 函数名：GridView1_RowCancelingEdit
     * 作用：取消
     * 参数：object sender, GridViewCancelEditEventArgs e
     * 返回：void
     */
    protected void GridView1_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
    {
        GridView1.EditIndex = -1;
        bind();
    }

    /*
     * 函数名：bind
     * 作用：绑定
     * 参数：void
     * 返回：void
     */
    public void bind()
    {
        string sql = "select * from view_student_basic_info";
        MyDatabase MD = new MyDatabase();
        MySqlConnection conn = new MySqlConnection(MD.getConnection());
        MySqlDataAdapter da = new MySqlDataAdapter(sql, conn);
        DataSet ds = new DataSet();
        da.Fill(ds, "student_table");
        GridView1.DataSource = ds;
        GridView1.DataKeyNames = new string[] { "学号" };  //主键
        GridView1.DataBind();
    }
}