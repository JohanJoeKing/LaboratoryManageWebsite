package com.example.johan.notemanager;

import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

/******************************************************
 - Project name : NoteManager
 - File name : AboutActivity.java
 - Author : 刘畅    Version : 1.0   Date : 2018/6/1
 - Description : // 我的读书笔记管理系统
                 // 系统关于界面
 - Others : // 移动开发技术作业
 - Function list :
 1.onCreate
 2.actionStart
 - History : //
 *****************************************************/

public class AboutActivity extends AppCompatActivity {




    /*******************************
     - Function name : onCreate
     - Description : 构造函数
     - Variables : Bundle savedInstanceState
     *******************************/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_about);
    }





    /*******************************
     - Function name : actionStart
     - Description : 创建
     - Variables : Context context
     *******************************/
    public static void actionStart(Context context)
    {
        Intent intent = new Intent(context,AboutActivity.class);
        context.startActivity(intent);
    }
}
