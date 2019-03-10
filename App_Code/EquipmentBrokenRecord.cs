using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：EquipmentBrokenRecord
 * 描述：报废单实体类
 * 作者：刘畅
 * 修改：[1]2019-3-2第一次创建
 * 其他：
 */
public class EquipmentBrokenRecord
{
    private string e_id;            // 设备编号
    private string broken_reason;   // 报废原因
    private string broken_date;     // 报废日期
    private string applicant_id;    // 办理人编号
    private string broken_solution; // 处理方案
    private string broken_store;    // 暂存地点
    private double broken_cost;     // 处理支出预算
    private double broken_income;   // 处理收入预算
    private string broken_id;       // 业务流水号
    private string broken_cancel;   // 是否注销报废

    // set
    public void setE_id(string e_id) { this.e_id = e_id; }
    public void setBroken_reason(string broken_reason) { this.broken_reason = broken_reason; }
    public void setBroken_date(string broken_date) { this.broken_date = broken_date; }
    public void setApplicant_id(string applicant_id) { this.applicant_id = applicant_id; }
    public void setBroken_solution(string broken_solution) { this.broken_solution = broken_solution; }
    public void setBroken_store(string broken_store) { this.broken_store = broken_store; }
    public void setBroken_cost(double broken_cost) { this.broken_cost = broken_cost; }
    public void setBroken_income(double broken_income) { this.broken_income = broken_income; }
    public void setBroken_id(string broken_id) { this.broken_id = broken_id; }
    public void setBroken_cancel(string broken_cancel) { this.broken_cancel = broken_cancel; }

    // get
    public string getE_id() { return e_id; }
    public string getBroken_reason() { return broken_reason; }
    public string getBroken_date() { return broken_date; }
    public string getApplicant_id() { return applicant_id; }
    public string getBroken_solution() { return broken_solution; }
    public string getBroken_store() { return broken_store; }
    public double getBroken_cost() { return broken_cost; }
    public double getBroken_income() { return broken_income; }
    public string getBroken_id() { return broken_id; }
    public string getBroken_cancel() { return broken_cancel; }

    /*
     * 函数名：EquipmentBrokenRecord
     * 作用：无参构造函数
     * 参数：void
     * 返回值：EquipmentBrokenRecord
     */
    public EquipmentBrokenRecord()
	{
		
	}
}