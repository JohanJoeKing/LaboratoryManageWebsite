using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using MySql.Data.MySqlClient;

public partial class studentChangeInfo : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        /*
        string str = Request["stu_id"].ToString();
        Label1.Text = str;
        */
        function();
    }

    private void function()
    {
        // 查询需要修改的设备
        string constr = "server=localhost;User Id=root;password=123456;Database=equipmanage_db";
        MySqlConnection mycon = new MySqlConnection(constr);
        mycon.Open();

        string sql = string.Format("select e_id, e_class from equipment_table where e_id like '1023%'");
        MySqlCommand mycmd = new MySqlCommand(sql, mycon);
        MySqlDataReader reader = null;
        reader = mycmd.ExecuteReader();

        int NUM = 0;
        string[] ID = new string[200];   // e_id
        string[] CLASS = new string[200];// e_class
        while (reader.Read())
        {
            ID[NUM] = reader[0].ToString();
            CLASS[NUM] = reader[1].ToString();
            NUM++;
        }
        reader.Close();
        mycon.Close();

        // 修改
        string constr2 = "server=localhost;User Id=root;password=123456;Database=equipmanage_db";
        MySqlConnection mycon2 = new MySqlConnection(constr2);
        mycon2.Open();
        for (int i = 0;i < NUM;i++)
        {
            string CLA = "";
            if (CLASS[i] == "微型")
                CLA = "01";
            else if (CLASS[i] == "小型")
                CLA = "02";
            else if (CLASS[i] == "中型")
                CLA = "03";
            else if (CLASS[i] == "大型")
                CLA = "04";
            else if (CLASS[i] == "其他")
                CLA = "05";
            string temp = "11" + CLA;
            temp = temp + ID[i].Substring(4, 18);
            string sql2 = string.Format("update equipment_table set e_id='{0}' where e_id={1}", ID[i], temp);
            MySqlCommand mycmd2 = new MySqlCommand(sql2, mycon2);
            mycmd2.ExecuteNonQuery();
        } // for
        mycon2.Close();
    }
}