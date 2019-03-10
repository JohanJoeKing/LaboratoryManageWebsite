using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;
using MySql.Data.MySqlClient;

/*
 * 类名：EquipmentService
 * 描述：设备服务类
 * 作者：刘畅
 * 修改：[1]2019-2-28第一次创建
 * 其他：
 */
public class EquipmentService
{
    // 属性
    private Equipment equip;    // 设备实体

    /*
     * 函数名：EquipmentService
     * 作用：构造函数1
     * 参数：void
     * 返回：EquipmentService
     */
	public EquipmentService()
	{
        this.equip = new Equipment();
    }

    /*
     * 函数名：EquipmentService
     * 作用：构造函数2
     * 参数：Equipment
     * 返回：EquipmentService
     */
    public EquipmentService(Equipment equip)
    {
        this.equip = equip;
    }

    /*
     * 函数名：searchEquipment
     * 作用：根据设备编号从数据库查询设备
     * 参数：string equip_id
     * 返回：bool
     */
    public void setEquipmentId(string equip_id)
    {
        this.equip.setE_id(equip_id);
    }

    /*
     * 函数名：searchEquipment
     * 作用：根据设备编号从数据库查询设备
     * 参数：string equip_id
     * 返回：Equipment
     */
    public Equipment searchEquipment(string equip_id)
    {
        this.equip.setE_id(equip_id);

        // 连接数据库
        MyDatabase MD = new MyDatabase();
        MySqlConnection mycon = new MySqlConnection(MD.getConnection());
        mycon.Open();

        // 查询数据基本信息
        string sql = string.Format("select * from equipment_table where e_id='{0}'", equip.getE_id());
        MySqlCommand mycmd = new MySqlCommand(sql, mycon);
        MySqlDataReader reader = null;
        reader = mycmd.ExecuteReader();
        while (reader.Read())
        {
            this.equip.setE_name(reader[1].ToString());
            this.equip.setE_class(reader[2].ToString());
            this.equip.setE_type(reader[3].ToString());
            this.equip.setE_picture_path(reader[4].ToString());
            this.equip.setE_producer(reader[5].ToString());
            this.equip.setE_produce_date(reader[6].ToString());
            this.equip.setE_guarantee_period(reader[7].ToString());
            this.equip.setE_purchase_date(reader[8].ToString());
            this.equip.setE_use_date(reader[9].ToString());
            this.equip.setE_supply_unit(reader[10].ToString());
            this.equip.setE_purchase_unit(reader[11].ToString());
            this.equip.setE_use_unit(reader[12].ToString());
            this.equip.setE_laboratory(reader[13].ToString());
            this.equip.setE_project(reader[14].ToString());
            this.equip.setE_function(reader[15].ToString());
            this.equip.setE_price(Int16.Parse(reader[16].ToString()));
            this.equip.setE_count_unit(reader[17].ToString());
            this.equip.setE_note(reader[18].ToString());
            this.equip.setE_consist(Int16.Parse(reader[19].ToString()));
        }
        reader.Close();

        // 查询设备状态
        sql = string.Format("select * from view_equip_status_simple where 设备编号='{0}'", equip.getE_id());
        MySqlCommand mycmd2 = new MySqlCommand(sql, mycon);
        MySqlDataReader reader2 = null;
        reader2 = mycmd2.ExecuteReader();
        while (reader2.Read())
        {
            this.equip.setE_status(reader2[3].ToString());
            this.equip.setE_store(reader2[4].ToString());
            this.equip.setE_teacher(reader2[5].ToString());
            this.equip.setE_teacher_id(reader2[6].ToString());
        }
        reader2.Close();
        mycon.Close();

        return this.equip;
    }
}