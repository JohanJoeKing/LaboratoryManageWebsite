package com.example.johan.notemanager;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/******************************************************
 - Project name : NoteManager
 - File name : AddNoteActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 添加笔记
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.initBooks
 3.addNoteContent_Click
 - History : //
 *****************************************************/

public class AddNoteActivity extends AppCompatActivity {

    // 基本属性
    private String account; // 账号
    private String id;      // 编号
    private String name;    // 名称
    private String content; // 笔记内容
    private String date;    // 创建日期
    private List<String> list;   // 书籍
    private int books;      // 书籍数量
    private String[] sbook; // 书籍缓存

    // 控件
    private Spinner spinner;
    private EditText  eContent;
    private Button button;

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
        setContentView(R.layout.activity_add_note);

        // 数据库服务
        db = new DBWorker(this,"notemanager.db",null,1);

        // 接收账号和书籍种类
        Intent intent = getIntent();
        account = intent.getStringExtra("account");

        // 绑定控件
        spinner = (Spinner) findViewById(R.id.spinner);
        eContent = (EditText) findViewById(R.id.editAddNote);
        button = (Button) findViewById(R.id.buttonAddNote);

        // 控件设置
        String sql = String.format("select count(*) from book");
        books = db.getAmountOf(sql);
        list = new ArrayList<>();
        try{
            initBooks();   // 读取书籍信息
        }
        catch (Exception e){
            e.printStackTrace();
        }
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, list);
        spinner.setAdapter(adapter);

    }




    /*******************************
     - Function name : initBooks
     - Description : 添加笔记
     - Variables : View view
     *******************************/
    private void initBooks(){
        sbook = new String[books];

        // 读取数据库
        SQLiteDatabase dbo = db.getWritableDatabase();
        String sql = String.format("select bname from book");
        Cursor cursor = dbo.rawQuery(sql ,null);
        int i = 0;
        while(cursor.moveToNext()){
            sbook[i++] = cursor.getString(0);
        }

        // 存到list
        for(i = 0;i < books;i++){
            list.add(sbook[i]);
        }
    }





    /*******************************
     - Function name : addNoteContent_Click
     - Description : 添加笔记
     - Variables : View view
     *******************************/
    public void addNoteContent_Click(View view){
        // 获取输入值
        name = spinner.getSelectedItem().toString();
        content = eContent.getText().toString();
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss");
        Date d = new Date(System.currentTimeMillis());
        date = simpleDateFormat.format(d);
        id = db.getStringOf(String.format("select bid from book where bname='%s'", name));

        // 执行
        db.executeSQL(String.format("insert into note values('%s','%s','%s','%s')", account, id, date, content));

        // 提示
        Toast.makeText(AddNoteActivity.this,"记录完毕",Toast.LENGTH_LONG).show();

        // 返回上一页
        this.finish();
    }

}
