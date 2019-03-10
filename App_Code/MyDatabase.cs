using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/***************************************************
 * - Project name : LaboratoryEquipmentManagementWebsite
 * - Filename : MyDatabase.cs
 * - Author : 刘畅    Version : 1.0   Date : 2018/5/26
 * - Description : 该类用于表示系统连接的数据库的基本属性
 *                 在系统中的各个需要连接数据库的部分，都
 *                 需要调用该类的参数去连接数据库
 * - Function list :
 * 1.
 * - Others :
 * [刘畅]2018/5/26第一次修改，完成类的搭建
 * [刘畅]2018/5/27第二次修改，添加连接字段
 ***************************************************/

/// <summary>
/// MyDatabase 的摘要说明
/// </summary>
public class MyDatabase
{
    // 基本属性
    private string SERVER;   // 服务器
    private string USER;     // 用户
    private string PASSWORD; // 密码
    private string DATABASE; // 数据库名称
    private string CONNECTION = "Data Source=localhost;database=equipmanage_db;uid=root;password=123456";
    private string CONNECTION2 = "Data Source=(local);Database=equipmanage_db;Uid=root;Pwd=123456";
    private string CONNECTION3 = "server=localhost;User Id=root;password=123456;Database=equipmanage_db";


    // set
    public void setServer(string SERVER) { this.SERVER = SERVER; }
    public void setUser(string USER) { this.USER = USER; }
    public void setPassword(string PASSWORD) { this.PASSWORD = PASSWORD; }
    public void setDatabase(string DATABASE) { this.DATABASE = DATABASE; }


    // get
    public string getServer() { return SERVER; }
    public string getUser() { return USER; }
    public string getPassword() { return PASSWORD; }
    public string getDatabase() { return DATABASE; }
    public string getConnection() { return CONNECTION; }
    public string getConnection2() { return CONNECTION2; }
    public string getConnection3() { return CONNECTION3; }



    /*****************************************************
    * - Function name : MyDatabase
    * - Description : 构造函数
    * - Variables : void
    *****************************************************/
    public MyDatabase()
    {
        SERVER = "localhost";
        USER = "root";
        PASSWORD = "123456";
        DATABASE = "equipmanage_db";
    }





    /*****************************************************
    * - Function name : setConnectionStr
    * - Description : 修改连接字段
    * - Variables : void
    *****************************************************/
    public void setConnectionStr()
    {
        CONNECTION = string.Format("Data Source={0};database={1};uid={2};password={3}",
            SERVER,
            DATABASE,
            USER,
            PASSWORD);
    }
}