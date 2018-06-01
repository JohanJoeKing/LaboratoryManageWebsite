package com.example.johan.notemanager;

import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.net.wifi.WifiEnterpriseConfig;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Spinner;
import android.widget.Toast;

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
 2.initBooks
 3.actionStart
 4.buttonRefresh_Click
 5.buttonSave_Click
 6.buttonDelete_Click
 - History : //
 *****************************************************/

public class AlterBookActivity extends AppCompatActivity {

    // 基本属性
    private String id;
    private String name;
    private String author;
    private String press;
    private String isbn;
    private String kind;
    private List<String> list;   // 书籍
    private int books;      // 书籍数量
    private String[] sbook; // 书籍缓存

    // 控件
    private Spinner spinner;
    private EditText eName;
    private EditText eAuthor;
    private EditText ePress;
    private EditText eIsbn;
    private RadioButton rScience;
    private RadioButton rAtr;
    private RadioButton rSociety;
    private Button buttonRefresh;
    private Button buttonSave;
    private Button buttonDelete;

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
        setContentView(R.layout.activity_alter_book);

        // 数据库服务
        db = new DBWorker(this,"notemanager.db",null,1);

        // 绑定控件
        eName = (EditText) findViewById(R.id.editAlterName);
        eAuthor = (EditText) findViewById(R.id.editAlterAuthor);
        ePress = (EditText) findViewById(R.id.editAlterPress);
        eIsbn = (EditText) findViewById(R.id.editAlterIsbn);
        rScience = (RadioButton) findViewById(R.id.radioButton4);
        rAtr = (RadioButton) findViewById(R.id.radioButton5);
        rSociety = (RadioButton) findViewById(R.id.radioButton6);
        buttonRefresh = (Button) findViewById(R.id.buttonAlterRefresh);
        buttonSave = (Button) findViewById(R.id.buttonAlterSave);
        buttonDelete = (Button) findViewById(R.id.buttonAlterDelete);
        spinner = (Spinner) findViewById(R.id.spinner2);

        // 控件设置
        buttonSave.setEnabled(false);
        buttonDelete.setEnabled(false);
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
        String sql = String.format("select bid from book");
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
     - Function name : actionStart
     - Description : 创建
     - Variables : Context context
     *******************************/
    public static void actionStart(Context context){
        Intent intent = new Intent(context,AlterBookActivity.class);
        context.startActivity(intent);
    }




    /*******************************
     - Function name : buttonRefresh_Click
     - Description : 刷新响应
     - Variables : View view
     *******************************/
    public void buttonRefresh_Click(View view){
        // 获取选取的书籍编号
        id = spinner.getSelectedItem().toString();

        // 查询相关信息
        name = db.getStringOf(String.format("select bname from book where bid='%s'", id));
        author = db.getStringOf(String.format("select author from book where bid='%s'", id));
        press = db.getStringOf(String.format("select press from book where bid='%s'", id));
        isbn = db.getStringOf(String.format("select isbn from book where bid='%s'", id));
        kind = db.getStringOf(String.format("select kind from bookkind where bid='%s'", id));

        // 显示
        eName.setText(name);
        eAuthor.setText(author);
        ePress.setText(press);
        eIsbn.setText(isbn);
        if(kind.equals("科技类")){
            rScience.setChecked(true);
        }
        else if(kind.equals("文学类")){
            rAtr.setChecked(true);
        }
        else if(kind.equals("社科类")){
            rSociety.setChecked(true);
        }

        // 打开控件
        buttonDelete.setEnabled(true);
        buttonSave.setEnabled(true);
    }





    /*******************************
     - Function name : buttonSave_Click
     - Description : 保存响应
     - Variables : View view
     *******************************/
    public void buttonSave_Click(View view){
        // 获取输入信息
        id = spinner.getSelectedItem().toString();
        name = eName.getText().toString();
        author = eAuthor.getText().toString();
        press = ePress.getText().toString();
        isbn = eIsbn.getText().toString();
        if(rScience.isChecked()){
            kind = "科技类";
        }
        if(rAtr.isChecked()){
            kind = "文学类";
        }
        if(rSociety.isChecked()){
            kind = "社科类";
        }

        // 检查缺省
        if(name.equals("")){
            Toast.makeText(AlterBookActivity.this,"书名不可缺省",Toast.LENGTH_LONG).show();
        }
        if(author.equals("")){
            Toast.makeText(AlterBookActivity.this,"作者不可缺省",Toast.LENGTH_LONG).show();
        }
        if(press.equals("")){
            Toast.makeText(AlterBookActivity.this,"出版社不可缺省",Toast.LENGTH_LONG).show();
        }
        if(isbn.equals("")){
            Toast.makeText(AlterBookActivity.this,"ISBN号不可缺省",Toast.LENGTH_LONG).show();
        }

        // 执行
        db.executeSQL(String.format("update book set bname='%s',author='%s',press='%s',isbn='%s' where bid='%s'", name, author, press, isbn, id));
        db.executeSQL(String.format("update bookkind set kind='%s' where bid='%s'", kind, id));


        // 显示
        Toast.makeText(AlterBookActivity.this,"修改完成",Toast.LENGTH_LONG).show();
    }





    /*******************************
     - Function name : buttonDelete_Click
     - Description : 删除响应
     - Variables : View view
     *******************************/
    public void buttonDelete_Click(View view){
        // 获取书号
        id = spinner.getSelectedItem().toString();

        // 执行
        db.executeSQL(String.format("delete from book where bid='%s'", id));
        db.executeSQL(String.format("delete from bookkind where bid='%s'", id));
        db.executeSQL(String.format("delete from note where bid='%s'", id));

        // 提示
        Toast.makeText(AlterBookActivity.this,"已删除书籍所有相关记录",Toast.LENGTH_LONG).show();

        // 返回上一页
        this.finish();
    }
}
