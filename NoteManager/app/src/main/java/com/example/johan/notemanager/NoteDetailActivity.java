package com.example.johan.notemanager;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

/******************************************************
 - Project name : NoteManager
 - File name : NoteDetailActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 笔记详细界面
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.initBook
 3.save_Click
 - History : //
 *****************************************************/

public class NoteDetailActivity extends AppCompatActivity {

    // 基本属性
    private String name;     // 书名
    private String account;  // 账号
    private String date;     // 笔记创建时间
    private String author;   // 作者
    private String content;  // 笔记内容

    // 控件
    private EditText edit;
    private Button button;
    private TextView tname;
    private TextView tdate;
    private TextView tauthor;

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
        setContentView(R.layout.activity_note_detail);

        // 数据库服务
        db = new DBWorker(this,"notemanager.db",null,1);

        // 接收账号和书籍名称、笔记日期
        Intent intent = getIntent();
        account = intent.getStringExtra("account");
        name = intent.getStringExtra("name");
        date = intent.getStringExtra("date");

        // 绑定控件
        edit = (EditText) findViewById(R.id.editTextND1);
        button = (Button) findViewById(R.id.buttonND1);
        tname = (TextView) findViewById(R.id.textViewND1);
        tdate = (TextView) findViewById(R.id.textViewND2);
        tauthor = (TextView) findViewById(R.id.textViewND3);

        // 读取书籍信息
        initBook();
    }




    /*******************************
     - Function name : initBook
     - Description : 读取书籍信息
     - Variables : void
     *******************************/
    private void initBook(){
        // 读取作者信息
        author = db.getStringOf(String.format("select author from book where bname='%s'", name));

        // 读取笔记内容
        content = db.getStringOf(String.format("select content from note where date='%s'", date));

        // 显示
        edit.setText(content);
        tname.setText("书名：" + name);
        tauthor.setText("作者：" + author);
        tdate.setText("创建时间：" + date);
    }





    /*******************************
     - Function name : save_Click
     - Description : 保存笔记
     - Variables : View view
     *******************************/
    public void save_Click(View view){
        // 获取笔记内容
        content = edit.getText().toString();

        // 执行
        db.executeSQL(String.format("update note set content='%s' where date='%s'", content, date));

        // 提示
        Toast.makeText(NoteDetailActivity.this,"已保存",Toast.LENGTH_LONG).show();
    }
}
