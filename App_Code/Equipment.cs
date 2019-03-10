using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：Equipment
 * 描述：设备实体类
 * 作者：刘畅
 * 修改：[1]2019-2-26第一次创建
 * 其他：[1]e_class：大型，中型，小型，微型，其他
 *      [2]设备编号构成：
 *      使用单位编号2位
 *    + 设备尺寸类别编号1位
 *    + 设备类别编号4位
 *    + 型号编号3位
 *    + 投运日期8位
 *    + 顺序号4位
 *    
 *     【注】
 *      1.单位编号：土木学院10，信息学院11，机械学院12，
 *      电气学院13，交通学院14，力学系15，材料学院16，
 *      经管学院17，文法学院18，建艺学院19，研究生学院20，
 *      数理系21，外语系22， 马克思主义学院23，工程训练中心24，
 *      其他大于等于25
 *      2.尺寸类别号：微型1，小型2，中型3，大型4，其他5
 *      设备类别编号、型号编号：见实验室设备种类表
 */

public class Equipment
{
    private string e_id;                // 设备编号
    private string e_name;              // 设备名称
    private string e_class;             // 设备类别
    private string e_type;              // 设备型号
    private string e_picture_path;      // 设备图片路径
    private string e_producer;          // 制造单位
    private string e_produce_date;      // 生产日期
    private string e_guarantee_period;  // 保质期
    private string e_purchase_date;     // 购入日期
    private string e_use_date;          // 投运日期
    private string e_supply_unit;       // 供应单位
    private string e_purchase_unit;     // 采购单位
    private string e_use_unit;          // 使用单位
    private string e_laboratory;        // 隶属实验室
    private string e_project;           // 实习项目
    private string e_function;          // 项目内用途
    private double e_price;             // 单价
    private string e_count_unit;        // 计量单位
    private string e_note;              // 备注
    private int e_consist;              // 附属设备数量
    private string e_status;            // 设备状态
    private string e_store;             // 设备存储位置
    private string e_teacher;           // 管理人员
    private string e_teacher_id;        // 管理人工号

    // set
    public void setE_id(string e_id) { this.e_id = e_id; }
    public void setE_name(string e_name) { this.e_name = e_name; }
    public void setE_class(string e_class) { this.e_class = e_class; }
    public void setE_type(string e_type) { this.e_type = e_type; }
    public void setE_picture_path(string e_picture_path) { this.e_picture_path = e_picture_path; }
    public void setE_producer(string e_producer) { this.e_producer = e_producer; }
    public void setE_produce_date(string e_produce_date) { this.e_produce_date = e_produce_date; }
    public void setE_guarantee_period(string e_guarantee_period) { this.e_guarantee_period = e_guarantee_period; }
    public void setE_purchase_date(string e_purchase_date) { this.e_purchase_date = e_purchase_date; }
    public void setE_use_date(string e_use_date) { this.e_use_date = e_use_date; }
    public void setE_supply_unit(string e_supply_unit) { this.e_supply_unit = e_supply_unit; }
    public void setE_purchase_unit(string e_purchase_unit) { this.e_purchase_unit = e_purchase_unit; }
    public void setE_use_unit(string e_use_unit) { this.e_use_unit = e_use_unit; }
    public void setE_laboratory(string e_laboratory) { this.e_laboratory = e_laboratory; }
    public void setE_project(string e_project) { this.e_project = e_project; }
    public void setE_function(string e_function) { this.e_function = e_function; }
    public void setE_price(double e_price) { this.e_price = e_price; }
    public void setE_count_unit(string e_count_unit) { this.e_count_unit = e_count_unit; }
    public void setE_note(string e_note) { this.e_note = e_note; }
    public void setE_consist(int e_consist) { this.e_consist = e_consist; }
    public void setE_status(string e_status) { this.e_status = e_status; }
    public void setE_store(string e_store) { this.e_store = e_store; }
    public void setE_teacher(string e_teacher) { this.e_teacher = e_teacher; }
    public void setE_teacher_id(string e_teacher_id) { this.e_teacher_id = e_teacher_id; }

    // get
    public string getE_id() { return e_id; }
    public string getE_name() { return e_name; }
    public string getE_class() { return e_class; }
    public string getE_type() { return e_type; }
    public string getE_picture_path() { return e_picture_path; }
    public string getE_producer() { return e_producer; }
    public string getE_produce_date() { return e_produce_date; }
    public string getE_guarantee_period() { return e_guarantee_period; }
    public string getE_purchase_date() { return e_purchase_date; }
    public string getE_use_date() { return e_use_date; }
    public string getE_supply_unit() { return e_supply_unit; }
    public string getE_purchase_unit() { return e_purchase_unit; }
    public string getE_use_unit() { return e_use_unit; }
    public string getE_laboratory() { return e_laboratory; }
    public string getE_project() { return e_project; }
    public string getE_function() { return e_function; }
    public double getE_price() { return e_price; }
    public string getE_count_unit() { return e_count_unit; }
    public string getE_note() { return e_note; }
    public int getE_consist() { return e_consist; }
    public string getE_status() { return e_status; }
    public string getE_store() { return e_store; }
    public string getE_teacher() { return e_teacher; }
    public string getE_teacher_id() { return e_teacher_id; }

    // 构造函数
	public Equipment()
    {
        e_price = 0.0;
        e_consist = 0;
    }

    // 带参构造函数
    public Equipment(string e_id)
    {
        e_price = 0.0;
        e_consist = 0;
    }
}