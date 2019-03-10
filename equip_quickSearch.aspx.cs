using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class equip_quickSearch : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        // 查询管理员信息，显示到界面头
        Label_admin.Text = "管理员：" + Session["AdminName"];
        Image_rank.ImageUrl = "~/Image/adminImg/rank" + Session["AdminRank"] + ".png";

        // 设置默认设备图片
        Img_equip.ImageUrl = "~/Image/EquipImg/default.png";
    }

    /*
     * 函数名：TextBox1_TextChanged
     * 作用：响应设备编号输入实时查询
     * 参数：object sender, EventArgs e
     * 返回：void
     */
    protected void TextBox1_TextChanged(object sender, EventArgs e)
    {
        // 获取输入的编号
        string e_id = Text_equip_id.Text.ToString();

        // 验证是否为正确编号
        if (e_id.Length < 22)
            return;

        // 查询设备并显示
        printEquip(e_id);
    }

    /*
     * 函数名：ImageButton1_Click
     * 作用：点击按钮以查询设备
     * 参数：object sender, ImageClickEventArgs e
     * 返回：void
     */
    protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
    {
        // 获取输入的编号
        string e_id = Text_equip_id.Text.ToString();

        // 验证是否为正确编号
        if (e_id.Length < 22)
            return;

        // 查询设备并显示
        printEquip(e_id);
    }

    /*
     * 函数名：printEquip
     * 作用：查询设备并显示
     * 参数：string e_id
     * 返回：void
     */
    private void printEquip(string e_id)
    {
        // 查询设备
        EquipmentService es = new EquipmentService();
        Equipment equip = es.searchEquipment(e_id);

        // 显示到界面
        // 设备名称
        string name = equip.getE_name();
        if (name == "" || name == null)
            Label_equip_name.Text = "空";
        else
            Label_equip_name.Text = name;

        // 设备种类
        string eClass = equip.getE_class();
        if (eClass == "" || eClass == null)
            Label_equip_class.Text = "空";
        else
            Label_equip_class.Text = eClass;

        // 设备型号
        string type = equip.getE_type();
        if (type == "" || type == null)
            Label_equip_type.Text = "空";
        else
            Label_equip_type.Text = type;

        // 设备生产商
        string producer = equip.getE_producer();
        if (producer == "" || producer == null)
            Label_equip_producer.Text = "空";
        else
            Label_equip_producer.Text = producer;

        // 生产日期
        string produce_date = equip.getE_produce_date();
        if (produce_date == "" || produce_date == null)
            Label_produce_date.Text = "空";
        else
            Label_produce_date.Text = produce_date;

        // 保质期
        string guarantee_period = equip.getE_guarantee_period();
        if (guarantee_period == "" || guarantee_period == null)
            Label_guarantee_period.Text = "空";
        else
            Label_guarantee_period.Text = guarantee_period;

        // 购买日期
        string purchase_date = equip.getE_purchase_date();
        if (purchase_date == "" || purchase_date == null)
            Label_purchase_date.Text = "空";
        else
            Label_purchase_date.Text = purchase_date;

        // 投运日期
        string use_date = equip.getE_use_date();
        if (use_date == "" || use_date == null)
            Label_use_date.Text = "空";
        else
            Label_use_date.Text = use_date;

        // 供应单位
        string supply_unit = equip.getE_supply_unit();
        if (supply_unit == "" || supply_unit == null)
            Label_supply_unit.Text = "空";
        else
            Label_supply_unit.Text = supply_unit;

        // 采购单位
        string purchase_unit = equip.getE_purchase_unit();
        if (purchase_unit == "" || purchase_unit == null)
            Label_purchase_unit.Text = "空";
        else
            Label_purchase_unit.Text = purchase_unit;

        // 使用单位
        string use_unit = equip.getE_use_unit();
        if (use_unit == "" || use_unit == null)
            Label_use_unit.Text = "空";
        else
            Label_use_unit.Text = use_unit;

        // 隶属实验室
        string lab = equip.getE_laboratory();
        if (lab == "" || lab == null)
            Label_lab.Text = "空";
        else
            Label_lab.Text = lab;

        // 项目内用途
        string function = equip.getE_function();
        if (function == "" || function == null)
            Label_function.Text = "空";
        else
            Label_function.Text = function;

        // 计量单位
        string count_unit = equip.getE_count_unit();
        if (count_unit == "" || count_unit == null)
            Label_count_unit.Text = "空";
        else
            Label_count_unit.Text = count_unit;

        // 附属设备数量
        string consist = "" + equip.getE_consist();
        if (consist == "" || consist == null)
            Label_consist.Text = "空";
        else
            Label_consist.Text = consist;

        // 存放位置
        string store = "" + equip.getE_store();
        if (store == "" || store == null)
            Label_store.Text = "空";
        else
            Label_store.Text = store;

        // 分管人员
        string teacher = "" + equip.getE_teacher();
        if (teacher == "" || teacher == null)
            Label_teacher.Text = "空";
        else
            Label_teacher.Text = teacher;

        // 单价
        string price = "" + equip.getE_price();
        if (price == "" || price == null)
            Label_equip_price.Text = "空";
        else
            Label_equip_price.Text = price;

        // 设备状态
        string status = "" + equip.getE_status();
        if (status == "" || status == null)
            Label_equip_status.Text = "空";
        else
            Label_equip_status.Text = status;

        // 实习项目
        string project = "" + equip.getE_project();
        if (project == "" || project == null)
            Label_equip_project.Text = "空";
        else
            Label_equip_project.Text = project;

        // 备注
        string note = "" + equip.getE_note();
        if (note == "" || note == null)
            Label_equip_note.Text = "空";
        else
            Label_equip_note.Text = note;

        // 设备图片
        string img = equip.getE_picture_path();
        if (img == "" || img == null)
            Img_equip.ImageUrl = "~/Image/EquipImg/default.png";
        else
            Img_equip.ImageUrl = img;
        
    }
}