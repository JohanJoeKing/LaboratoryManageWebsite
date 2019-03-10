using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml;

public partial class equip_addEquipment : System.Web.UI.Page
{
    // 支持项
    private IList<School> schoolList;
    private IList<EquipType> typeList;

    /*
     * 函数名：Page_Load
     * 作用：页面加载
     * 参数：object sender, EventArgs e
     * 返回：void
     */
    protected void Page_Load(object sender, EventArgs e)
    {
        // 获取并显示用户信息
        try
        {
            String adminName = Session["AmdinName"].ToString();
            String rank = Session["AdminRank"].ToString();
            if (adminName == null)
                Label_adminName.Text = "null";
            else
                Label_adminName.Text = adminName;

            if (rank == null)
                Label_rank.Text = "null";
            else
                Label_rank.Text = rank;
        }
        catch(Exception ex)
        {
            Label_adminName.Text = "null";
            Label_rank.Text = "null";
        }
        

        // 初始化界面
        init();
    }

    /*
     * 函数名：init
     * 作用：初始化
     * 参数：void
     * 返回：void
     */
    private void init()
    {
        // 读取学院代码文件到程序
        readSchoolXml();

        // 读取尺寸码
        readTypeXml();
    }

    /*
     * 函数名：readSchoolXml
     * 作用：读取学校单位代码的XML文件
     * 参数：void
     * 返回：void
     */
    private void readSchoolXml()
    {
        schoolList = new List<School>();
        XmlDocument xmlDocument = new XmlDocument();
        xmlDocument.Load("./LabManageWeb/schoolCode.xml");
        XmlNodeList xmlNodeList = xmlDocument.SelectSingleNode("university").ChildNodes;
        int N = 0;
        foreach (XmlNode list in xmlNodeList)
        {
            School sch = new School
            (
                list.SelectSingleNode("name").InnerText,
                list.SelectSingleNode("code").InnerText
            );
            schoolList.Add(sch);
            N++;
        }
        for (int i = 0; i < N; i++)
        {
            DropDownList_unit.Items.Add(schoolList[i].getName());
        }
    }

    /*
     * 函数名：readTypeXml
     * 作用：读取设备尺寸代码的XML文件
     * 参数：void
     * 返回：void
     */
    private void readTypeXml()
    {
        typeList = new List<EquipType>();
        XmlDocument xmlDocument = new XmlDocument();
        xmlDocument.Load("./LabManageWeb/equipSize.xml");
        XmlNodeList xmlNodeList = xmlDocument.SelectSingleNode("lab").ChildNodes;
        int N = 0;
        foreach (XmlNode list in xmlNodeList)
        {
            EquipType et = new EquipType
            (
                list.SelectSingleNode("type").InnerText,
                list.SelectSingleNode("code").InnerText
            );
            typeList.Add(et);
            N++;
        }
        for (int i = 0; i < N; i++)
        {
            DropDownList_size.Items.Add(typeList[i].getType());
        }
    }
}