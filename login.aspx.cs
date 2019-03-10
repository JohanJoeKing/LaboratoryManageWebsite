using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    /*
     * 函数名：ImageButton1_Click
     * 作用：响应登录
     * 参数：object sender, ImageClickEventArgs e
     * 返回：void
     */
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        string account = Text_account.Text.ToString();
        string pwd = Text_pwd.Text.ToString();
        LoginHelper helper = new LoginHelper(account, pwd);
        if (helper.login())
        {
            Response.Write("<script>alert('欢迎登录！')</script>");
            string url = string.Format("index.aspx?account={0}&adminName={1}&rank={2}", account, helper.getAdmin_name(), helper.getRank());
            Response.Redirect(url);
        }
        else
        {
            Response.Write("<script>alert('用户名或密码错误，登录失败！')</script>");
            Text_account.Text = "";
            Text_pwd.Text = "";
        }
    }
}