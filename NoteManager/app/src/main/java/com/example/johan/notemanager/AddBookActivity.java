package com.example.johan.notemanager;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.Toast;

/******************************************************
 - Project name : NoteManager
 - File name : AddBookActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 添加书籍
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.actionStart
 3.addBook_Click
 - History : //
 *****************************************************/

public class AddBookActivity extends AppCompatActivity {

    // 基本属性
    private String id;      // 编号
    private String name;    // 书名
    private String author;  // 作者
    private String press;   // 出版社
    private String isbn;    // ISBN
    private String kind;    // 书籍种类

    // 控件
    private EditText eId;
    private EditText eName;
    private EditText eAuthor;
    private EditText ePress;
    private EditText eIsbn;
    private Button button;
    private RadioButton rScience;
    private RadioButton rArt;
    private RadioButton rSociety;

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
        setContentView(R.layout.activity_add_book);

        // 绑定控件
        eId = (EditText) findViewById(R.id.editAddBookId);
        eName = (EditText) findViewById(R.id.editAddBookName);
        eAuthor = (EditText) findViewById(R.id.editAddBookAuthor);
        eIsbn = (EditText) findViewById(R.id.editAddBookISBN);
        ePress = (EditText) findViewById(R.id.editAddBookPress);
        button = (Button) findViewById(R.id.buttonAddBook);
        rScience = (RadioButton) findViewById(R.id.radioButton);
        rArt = (RadioButton) findViewById(R.id.radioButton2);
        rSociety = (RadioButton) findViewById(R.id.radioButton3);

        // 数据库服务
        db = new DBWorker(this,"notemanager.db",null,1);
    }




    /*******************************
     - Function name : actionStart
     - Description : 创建
     - Variables : Context context
     *******************************/
    public static void actionStart(Context context)
    {
        Intent intent = new Intent(context,AddBookActivity.class);
        context.startActivity(intent);
    }





    /*******************************
     - Function name : addBook_Click
     - Description : 添加响应
     - Variables : View view
     *******************************/
    public void addBook_Click(View view){
        // 获取输入信息
        id = eId.getText().toString();
        name = eName.getText().toString();
        author = eAuthor.getText().toString();
        press = ePress.getText().toString();
        isbn = eIsbn.getText().toString();
        if(rScience.isChecked() == true){
            kind = "科技类";
        }
        else if(rArt.isChecked() == true){
            kind = "文学类";
        }
        else if(rSociety.isChecked() == true){
            kind = "社科类";
        }

        // 验证输入缺省
        if(id.equals("")){
            Toast.makeText(AddBookActivity.this,"请先填写书籍编号",Toast.LENGTH_LONG).show();
            return;
        }
        if(name.equals("")){
            Toast.makeText(AddBookActivity.this,"请先填写书籍名称",Toast.LENGTH_LONG).show();
            return;
        }
        if(author.equals("")){
            Toast.makeText(AddBookActivity.this,"请先填写作者",Toast.LENGTH_LONG).show();
            return;
        }
        if(press.equals("")){
            Toast.makeText(AddBookActivity.this,"请先填写出版社",Toast.LENGTH_LONG).show();
            return;
        }
        if(isbn.equals("")){
            Toast.makeText(AddBookActivity.this,"请先填写ISBN",Toast.LENGTH_LONG).show();
            return;
        }

        // 插入到book
        db.executeSQL(String.format("insert into book values('%s','%s','%s','%s','%s')", id, name, author, press, isbn));

        // 插入到bookkind
        db.executeSQL(String.format("insert into bookkind values('%s','%s')", id, kind));

        // 提示
        Toast.makeText(AddBookActivity.this,"添加成功",Toast.LENGTH_LONG).show();

        // 返回上一页
        this.finish();
    }
}
