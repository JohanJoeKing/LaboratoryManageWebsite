using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：EquipmentLostRecord
 * 描述：挂失单实体类
 * 作者：刘畅
 * 修改：[1]2019-3-2第一次创建
 * 其他：
 */
public class EquipmentLostRecord
{
    private string e_id;            // 设备编号
    private string lost_reason;     // 丢失原因
    private string lost_time;       // 丢失时间
    private string lost_place;      // 可能丢失地点
    private string person_liable;   // 主要负责人
    private string lost_apply_time; // 挂失时间
    private string lost_applicant;  // 挂失申请人姓名
    private string cancel_lost;     // 是否已注销挂失
    private string lost_id;         // 业务流水号

    // set
    public void setE_id(string e_id) { this.e_id = e_id; }
    public void setLost_reason(string lost_reason) { this.lost_reason = lost_reason; }
    public void setLost_time(string lost_time) { this.lost_time = lost_time; }
    public void setLost_place(string lost_place) { this.lost_place = lost_place; }
    public void setPerson_liable(string person_liable) { this.person_liable = person_liable; }
    public void setLost_apply_time(string lost_apply_time) { this.lost_apply_time = lost_apply_time; }
    public void setLost_applicant(string lost_applicant) { this.lost_applicant = lost_applicant; }
    public void setCancel_lost(string cancel_lost) { this.cancel_lost = cancel_lost; }
    public void setLost_id(string lost_id) { this.lost_id = lost_id; }

    // get
    public string getE_id() { return e_id; }
    public string getLost_reason() { return lost_reason; }
    public string getLost_time() { return lost_time; }
    public string getLost_place() { return lost_place; }
    public string getPerson_liable() { return person_liable; }
    public string getLost_apply_time() { return lost_apply_time; }
    public string getLost_applicant() { return lost_applicant; }
    public string getCancel_lost() { return cancel_lost; }
    public string getLost_id() { return lost_id; }

    /*
     * 函数名：EquipmentLostRecord
     * 作用：无参构造函数
     * 参数：void
     * 返回值：EquipmentLostRecord
     */
    public EquipmentLostRecord()
	{

	}
}