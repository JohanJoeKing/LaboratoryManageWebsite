package com.example.johan.notemanager;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;
import java.util.List;

/******************************************************
 - Project name : NoteManager
 - File name : KindActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 书籍种类选择界面
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.toUser
 3.onCreateOptionsMenu
 4.onOptionsItemSelected
 5.addNote_Click
 - History : //
 *****************************************************/

public class KindActivity extends AppCompatActivity {

    // 基本属性
    private String account;   // 账号
    private String kind;      // 书籍种类
    private List<String> list;// 书籍种类列表

    // 控件
    private ListView listView;



    /*******************************
     - Function name : onCreate
     - Description : 构造函数
     - Variables : Bundle savedInstanceState
     *******************************/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_kind);

        // 接收账号
        Intent intent = getIntent();
        account = intent.getStringExtra("account");

        // 绑定控件
        list = new ArrayList<>();
        list.add("科技类");
        list.add("文学类");
        list.add("社科类");
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, list);
        listView = (ListView) findViewById(R.id.listview2);
        listView.setAdapter(adapter);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                // 获取选择的种类
                kind = list.get(position);

                // 跳转到用户界面
                toUser();
            }
        });
    }




    /*******************************
     - Function name : toUser
     - Description : 跳转到用户界面
     - Variables : void
     *******************************/
    private void toUser(){
        Intent intent = new Intent(this, UserActivity.class);
        intent.putExtra("account", account);
        intent.putExtra("kind", kind);
        startActivity(intent);
    }





    /*******************************
     - Function name : onCreateOptionMenu
     - Description : 创建菜单
     - Variables : Menu menu
     *******************************/
    public boolean onCreateOptionsMenu(Menu menu){
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return true;
    }




    /*******************************
     - Function name : onOptionsItemSelected
     - Description : 菜单点击事件
     - Variables : MenuItem item
     *******************************/
    public boolean onOptionsItemSelected(MenuItem item)
    {
        switch (item.getItemId())
        {
            case R.id.mnuUser:
                // 我的账户
                Intent intent = new Intent(this, AccountActivity.class);
                intent.putExtra("account", account);
                startActivity(intent);
                break;
            case R.id.mnuMainAbout:
                // 关于界面
                AboutActivity.actionStart(KindActivity.this);
                break;
            case R.id.mnuAddBook:
                // 添加书籍
                AddBookActivity.actionStart(KindActivity.this);
                break;
            case R.id.mnuAlterBook:
                // 编辑书籍
                AlterBookActivity.actionStart(KindActivity.this);
                break;
            case  R.id.mnuMainClose:
                // 退出
                finish();
                break;
        }

        return true;
    }




    /*******************************
     - Function name : addNote_Click
     - Description : 添加笔记
     - Variables : View view
     *******************************/
    public void addNote_Click(View view){
        Intent intent = new Intent(this, AddNoteActivity.class);
        intent.putExtra("account", account);
        startActivity(intent);
    }
}
