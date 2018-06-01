package com.example.johan.notemanager;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

/******************************************************
 - Project name : NoteManager
 - File name : RegisterActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 注册界面
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.actionStart
 3.registerNew_Click
 - History : //
 *****************************************************/

public class RegisterActivity extends AppCompatActivity {

    // 控件
    private EditText eAccount;
    private EditText ePassword;
    private EditText eName;

    // 数据库服务
    private DBWorker db;


    /*******************************
     - Function name : onCreate
     - Description : 构造函数
     - Variables : Bundle savedInstanceState
     *******************************/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        // 数据库服务
        db = new DBWorker(this,"notemanager.db",null,1);

        // 绑定控件
        eAccount = (EditText) findViewById(R.id.editNewAccount);
        ePassword = (EditText) findViewById(R.id.editNewPassword);
        eName = (EditText) findViewById(R.id.editNewName);
    }




    /*******************************
     - Function name : actionStart
     - Description : 创建
     - Variables : Context context
     *******************************/
    public static void actionStart(Context context){
        Intent intent = new Intent(context,RegisterActivity.class);
        context.startActivity(intent);
    }




    /*******************************
     - Function name : registerNew_Click
     - Description : 注册响应
     - Variables : View view
     *******************************/
    public void registerNew_Click(View view){
        // 获取输入值
        String account = eAccount.getText().toString();
        String password = ePassword.getText().toString();
        String name = eName.getText().toString();

        // 检查缺省
        if(account.equals("")){
            Toast.makeText(RegisterActivity.this,"请先填写账号",Toast.LENGTH_LONG).show();
            return;
        }
        if(password.equals("")){
            Toast.makeText(RegisterActivity.this,"请先填写账号",Toast.LENGTH_LONG).show();
            return;
        }
        if(name.equals("")){
            Toast.makeText(RegisterActivity.this,"请先填写账号",Toast.LENGTH_LONG).show();
            return;
        }

        // 构造插入语句
        String sql = String.format("insert into user values('%s','%s','%s')", account, name, password);

        // 执行
        if(db.executeSQL(sql)){
            Toast.makeText(RegisterActivity.this,"注册成功，返回登录",Toast.LENGTH_LONG).show();
        }
        else{
            Toast.makeText(RegisterActivity.this,"注册失败",Toast.LENGTH_LONG).show();
        }
    }
}
