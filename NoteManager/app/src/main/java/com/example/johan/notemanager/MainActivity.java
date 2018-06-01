package com.example.johan.notemanager;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;


/******************************************************
 - Project name : NoteManager
 - File name : MainActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 打开应用后的第一个活动
 - Others : // 移动开发技术作业
            // 书籍类型：科技类、文学类、社科类
            // 测试书编号1001-1004科技类
            //         1005-1008文学类
            //         1009-1012社科类
 - Function list :
 1.
 - History : //
 *****************************************************/

//// TODO 文件头注释模板
/******************************************************
 - Project name :
 - File name :
 - Author :     Version : 1.0   Date :
 - Description : //
 - Others : //
 - Function list :
 1.onCreate
 2.login_Click
 3.register_Click
 4.loginPassed
 - History : //
 *****************************************************/

//// TODO 函数头注释模板
/*******************************
 - Function name :
 - Description :
 - Variables :
 *******************************/

public class MainActivity extends AppCompatActivity {

    // 控件
    private EditText eAccount;
    private EditText ePassword;

    // 数据库属性
    private DBWorker db;



    /*******************************
     - Function name : onCreate
     - Description : 构造函数
     - Variables : Bundle saveInstanceState
     *******************************/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 初始化数据库
        db = new DBWorker(this,"notemanager.db",null,1);

        // 绑定控件
        eAccount = (EditText) findViewById(R.id.editAccount);
        ePassword = (EditText) findViewById(R.id.editPassword);

        db.executeSQL("insert into note values('123','1001','2018/6/1 15:51:23','今天开始自学Java语言')");
    }





    /*******************************
     - Function name : login_Click
     - Description : 登录响应
     - Variables : View view
     *******************************/
    public void login_Click(View view){
        // 获取输入值
        String account = eAccount.getText().toString();
        String password = ePassword.getText().toString();

        // 检查缺省
        if(account.equals("")){
            Toast.makeText(MainActivity.this,"请先填写账号",Toast.LENGTH_LONG).show();
            return;
        }
        if(password.equals("")){
            Toast.makeText(MainActivity.this,"请先填写密码",Toast.LENGTH_LONG).show();
            return;
        }

        // 登录验证
        if(loginPassed(account, password)){
            // 验证通过
            // 前往书籍种类选择界面
            Intent intent = new Intent(this, KindActivity.class);
            intent.putExtra("account", account);
            startActivity(intent);
            finish();
        }
        else{
            // 验证失败
            Toast.makeText(MainActivity.this,"登录失败",Toast.LENGTH_LONG).show();
        }
    }




    /*******************************
     - Function name : register_Click
     - Description : 注册新用户
     - Variables : View view
     *******************************/
    public void register_Click(View view){
        RegisterActivity.actionStart(MainActivity.this);
    }




    /*******************************
     - Function name : loginPassed
     - Description : 登录验证
     - Variables : String account, String password
     *******************************/
    private boolean loginPassed(String account, String password){
        boolean flag = false;

        // 读取数据库
        SQLiteDatabase dbo = db.getWritableDatabase();
        String sql = "select * from user where uid='" + account + "'";
        Cursor cursor = dbo.rawQuery(sql ,null);
        String temp = "";
        while(cursor.moveToNext()){
            temp = cursor.getString(cursor.getColumnIndex("password"));
        }

        // 验证
        if(temp.equals(password)){
            flag = true;
        }

        return flag;
    }
}
