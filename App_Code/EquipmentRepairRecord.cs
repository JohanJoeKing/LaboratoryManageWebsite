using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：EquipmentRepairRecord
 * 描述：报修单实体类
 * 作者：刘畅
 * 修改：[1]2019-3-2第一次创建
 * 其他：
 */
public class EquipmentRepairRecord
{
    private string e_id;                // 设备编号
    private string rp_describe;         // 故障描述
    private string rp_solution;         // 报修方案
    private string rp_applicant_id;     // 报修人编号
    private string rp_applicant_name;   // 报修人姓名
    private string rp_date;             // 报修日期
    private double rp_cost;             // 预计开销
    private string rp_time;             // 预计维修时长
    private string rp_id;               // 报修单号

    // set
    public void setE_id(string e_id) { this.e_id = e_id; }
    public void setRp_describe(string rp_describe) { this.rp_describe = rp_describe; }
    public void setRp_solution(string rp_solution) { this.rp_solution = rp_solution; }
    public void setRp_applicant_id(string rp_applicant_id) { this.rp_applicant_id = rp_applicant_id; }
    public void setRp_applicant_name(string rp_applicant_name) { this.rp_applicant_name = rp_applicant_name; }
    public void setRp_date(string rp_date) { this.rp_date = rp_date; }
    public void setRp_cost(double rp_cost) { this.rp_cost = rp_cost; }
    public void setRp_time(string rp_time) { this.rp_time = rp_time; }
    public void setRp_id(string rp_id) { this.rp_id = rp_id; }

    // get
    public string getE_id() { return e_id; }
    public string getRp_describe() { return rp_describe; }
    public string getRp_solution() { return rp_solution; }
    public string getRp_applicant_id() { return rp_applicant_id; }
    public string getRp_applicant_name() { return rp_applicant_name; }
    public string getRp_date() { return rp_date; }
    public double getRp_cost() { return rp_cost; }
    public string getRp_time() { return rp_time; }
    public string getRp_id() { return rp_id; }

    /*
     * 函数名：EquipmentRepairRecord
     * 作用：无参构造函数
     * 参数：void
     * 返回值：EquipmentRepairRecord
     */
    public EquipmentRepairRecord()
	{
		
	}
}