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

import java.util.ArrayList;
import java.util.List;

/******************************************************
 - Project name : NoteManager
 - File name : NoteActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 笔记界面
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.initNotes
 3.toNoteDetail
 - History : //
 *****************************************************/

public class NoteActivity extends AppCompatActivity {

    // 基本属性
    private String account;     // 账号
    private String name;        // 书籍名称
    private String date;        // 笔记日期
    private int notes;          // 书籍数量
    private List<String> list;  // 列表绑定
    private String[] snote;     // 笔记

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
        setContentView(R.layout.activity_note);

        // 数据库服务
        db = new DBWorker(this,"notemanager.db",null,1);

        // 接收账号和书籍名称
        Intent intent = getIntent();
        account = intent.getStringExtra("account");
        name = intent.getStringExtra("name");

        // 属性设置
        String sql = String.format("select count(*) from note n join book b on n.bid=b.bid where bname='%s' and uid='%s'", name, account);
        notes = db.getAmountOf(sql);
        list = new ArrayList<>();
        try{
            initNotes();   // 读取笔记信息
        }
        catch (Exception e){
            e.printStackTrace();
        }

        // 绑定控件
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, list);
        listView = (ListView) findViewById(R.id.listview3);
        listView.setAdapter(adapter);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                // 获取点击的笔记
                date = list.get(position);

                // 跳转到笔记详细界面
                toNoteDetail();
            }
        });
    }





    /*******************************
     - Function name : initNotes
     - Description : 读取笔记日期
     - Variables : void
     *******************************/
    private void initNotes(){
        snote = new String[notes];

        // 读取数据库
        SQLiteDatabase dbo = db.getWritableDatabase();
        String sql = String.format("select date from note n join book b on b.bid=n.bid where bname='%s' and uid='%s'", name, account);
        Cursor cursor = dbo.rawQuery(sql ,null);
        int i = 0;
        while(cursor.moveToNext()){
            snote[i++] = cursor.getString(0);
        }

        // 存到list
        for(i = 0;i < notes;i++){
            list.add(snote[i]);
        }
    }




    /*******************************
     - Function name : toNoteDetail
     - Description : 前往笔记详细界面
     - Variables : void
     *******************************/
    private void toNoteDetail(){
        Intent intent = new Intent(this, NoteDetailActivity.class);
        intent.putExtra("account", account);
        intent.putExtra("name", name);
        intent.putExtra("date", date);
        startActivity(intent);
    }

}
