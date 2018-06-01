package com.example.johan.notemanager;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

/******************************************************
 - Project name : NoteManager
 - File name : AccountActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 我的账户界面
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.initBooks
 - History : //
 *****************************************************/

public class AccountActivity extends AppCompatActivity {

    // 基本属性
    private String account;  // 账号
    private String name;     // 昵称
    private int notes;       // 笔记数量
    private int books;          // 书籍数量
    private List<String> list;  // 列表绑定
    private String[] sbook;     // 书名

    // 控件
    private TextView tName;
    private TextView tId;
    private TextView tNotes;
    private ListView listview;

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
        setContentView(R.layout.activity_account);

        // 数据库服务
        db = new DBWorker(this,"notemanager.db",null,1);

        // 接收账号
        Intent intent = getIntent();
        account = intent.getStringExtra("account");

        // 统计
        name = db.getStringOf(String.format("select uname from user where uid='%s'", account));
        notes = db.getAmountOf(String.format("select count(*) from note where uid='%s'", account));

        // 控件绑定
        tName = (TextView) findViewById(R.id.textAccountName);
        tId = (TextView) findViewById(R.id.textAccountId);
        tNotes = (TextView) findViewById(R.id.textAccountNotes);
        listview = (ListView) findViewById(R.id.listview4);

        // 控件设置
        tName.setText("昵称：" + name);
        tId.setText("账号：" + account);
        tNotes.setText("总笔记数量：" + notes + "条");
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
        listview.setAdapter(adapter);
    }





    /*******************************
     - Function name : initBooks
     - Description : 读取书名
     - Variables : void
     *******************************/
    private void initBooks(){
        sbook = new String[books];
        int[] N = new int[books];

        // 读取数据库
        SQLiteDatabase dbo = db.getWritableDatabase();
        String sql = String.format("select bname from book" );
        Cursor cursor = dbo.rawQuery(sql ,null);
        int i = 0;
        while(cursor.moveToNext()){
            sbook[i] = cursor.getString(0);
            N[i] = db.getAmountOf(String.format("select count(*) from note n join book b on n.bid=b.bid where b.bname='%s' and n.uid='%s'", sbook[i], account));
            i++;
        }

        // 存到list
        for(i = 0;i < books;i++){
            list.add(sbook[i] + "：" + N[i] + "次笔记");
        }
    }
}
