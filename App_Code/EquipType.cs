using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/*
 * 类名：EquipType
 * 描述：设备尺寸类型实体类
 * 作者：刘畅
 * 修改：[1]2019-3-4第一次创建
 * 其他：
 */
public class EquipType
{
    private string type;
    private string code;

    // set
    public void setType(string type) { this.type = type; }
    public void setCode(string code) { this.code = code; }

    // get
    public string getType() { return this.type; }
    public string getCode() { return this.code; }

    /*
     * 函数名：EquipType
     * 作用：无参构造函数
     * 参数：void
     * 返回值：EquipType
     */
    public EquipType()
	{
		
	}

    /*
     * 函数名：EquipType
     * 作用：有参构造函数
     * 参数：void
     * 返回值：EquipType
     */
    public EquipType(string type, string code)
    {
        this.type = type;
        this.code = code;
    }
}