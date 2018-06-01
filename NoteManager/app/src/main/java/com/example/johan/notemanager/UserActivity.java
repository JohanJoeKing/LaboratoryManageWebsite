package com.example.johan.notemanager;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

/******************************************************
 - Project name : NoteManager
 - File name : UserActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 主界面
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.initBooks
 3.toNote
 - History : //
 *****************************************************/

public class UserActivity extends AppCompatActivity {

    // 基本属性
    private String account;     // 账号
    private String kind;        // 书籍种类
    private int books;          // 书籍数量
    private List<String> list;  // 列表绑定
    private String[] sbook;     // 书名
    private String name;        // 选择的书籍名字

    // 控件
    private ListView listView;

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
        setContentView(R.layout.activity_user);

        // 数据库服务
        db = new DBWorker(this,"notemanager.db",null,1);

        // 接收账号和书籍种类
        Intent intent = getIntent();
        account = intent.getStringExtra("account");
        kind = intent.getStringExtra("kind");

        // 属性设置
        String sql = String.format("select count(*) from bookkind where kind='%s'", kind);
        books = db.getAmountOf(sql);
        list = new ArrayList<>();
        try{
            initBooks();   // 读取书籍信息
        }
        catch (Exception e){
            e.printStackTrace();
        }

        // 绑定控件
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, list);
        listView = (ListView) findViewById(R.id.listview1);
        listView.setAdapter(adapter);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                // 获取点击的书籍
                name = list.get(position);

                // 跳转到笔记界面
                toNote();
            }
        });
    }




    /*******************************
     - Function name : initBooks
     - Description : 读取书名
     - Variables : void
     *******************************/
    private void initBooks(){
        sbook = new String[books];

        // 读取数据库
        SQLiteDatabase dbo = db.getWritableDatabase();
        String sql = String.format("select bname from book b join bookkind bk on b.bid=bk.bid where kind='%s'", kind);
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
     - Function name : toNote
     - Description : 前往笔记界面
     - Variables : void
     *******************************/
    private void toNote(){
        Intent intent = new Intent(this, NoteActivity.class);
        intent.putExtra("account", account);
        intent.putExtra("name", name);
        startActivity(intent);
    }
}
