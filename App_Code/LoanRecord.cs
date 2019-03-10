using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：LoanRecord
 * 描述：借用记录实体类
 * 作者：刘畅
 * 修改：[1]2019-3-2第一次创建
 * 其他：
 */
public class LoanRecord
{
    private string e_id;            // 设备编号
    private string loaner_id;       // 借用者编号
    private string loaner_id_type;  // 证件类型
    private string loaner_type;     // 借用者身份
    private string loan_reason;     // 借用原因
    private string loan_date;       // 外借日期
    private string return_date;     // 应归还日期
    private string loan_note;       // 备注

    // set
    public void setE_id(string e_id) { this.e_id = e_id; }
    public void setLoaner_id(string loaner_id) { this.loaner_id = loaner_id; }
    public void setLoaner_id_type(string loaner_id_type) { this.loaner_id_type = loaner_id_type; }
    public void setLoaner_type(string loaner_type) { this.loaner_type = loaner_type; }
    public void setLoan_reason(string loan_reason) { this.loan_reason = loan_reason; }
    public void setLoan_date(string loan_date) { this.loan_date = loan_date; }
    public void setReturn_date(string return_date) { this.return_date = return_date; }
    public void setLoan_note(string loan_note) { this.loan_note = loan_note; }

    // get
    public string getE_id() { return e_id; }
    public string getLoaner_id() { return loaner_id; }
    public string getLoaner_id_type() { return loaner_id_type; }
    public string getLoaner_type() { return loaner_type; }
    public string getLoan_reason() { return loan_reason; }
    public string getLoan_date() { return loan_date; }
    public string getReturn_date() { return return_date; }
    public string getLoan_note() { return loan_note; }

    /*
     * 函数名：LoanRecord
     * 作用：无参构造函数
     * 参数：void
     * 返回值：LoanRecord
     */
	public LoanRecord()
	{
		
	}
}