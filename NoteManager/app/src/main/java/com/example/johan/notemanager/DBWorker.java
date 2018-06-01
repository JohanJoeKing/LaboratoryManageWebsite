package com.example.johan.notemanager;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/******************************************************
 - Project name : MyNotes
 - File name : DBWorker.java
 - Author : 刘畅    Version : 1.0   Date : 2018/5/31
 - Description : // 本类用于数据库服务
 - Others : // 仅用于作业
 - Function list :
 1.DBWorker
 2.onCreate
 3.onUpdate
 4.init
 5.executeSQL
 6.getAmountOf
 7.getStringOf
 - History : // 系统建立在数据库notemanager上
 // 已完成构造函数
 // 已完成onCreate
 *****************************************************/

public class DBWorker extends SQLiteOpenHelper{

    //// TODO 服务支持项
    SQLiteDatabase db = null;

    /*******************************
     - Function name : DBWorker
     - Description : 构造函数
     - Variables : Context context, String name, SQLiteDatabase.CursorFactory factory, int version
     *******************************/
    public DBWorker(Context context,
                    String name,
                    SQLiteDatabase.CursorFactory factory,
                    int version){
        super(context, name, factory, version);
        db = this.getWritableDatabase();
        init();
    }




    /*******************************
     - Function name : init
     - Description : 建立数据库
     - Variables : void
     *******************************/
    private void init(){
        // 数据库操作语句
        String userSQL = "create table user(\n" +
                "   uid int NOT NULL,\n" +
                "   uname varchar,\n" +
                "   password varchar,\n" +
                "   primary key(uid)\n" +
                ")";
        String bookSQL = "create table book(\n" +
                "   bid int NOT NULL,\n" +
                "   bname varchar NOT NULL,\n" +
                "   author varchar,\n" +
                "   press varchar,\n" +
                "   isbn varchar,\n" +
                "   primary key(bid)\n" +
                ")";
        String noteSQL = "create table note(\n" +
                "   uid int NOT NULL,\n" +
                "   bid int NOT NULL,\n" +
                "   date varchar NOT NULL,\n" +
                "   content varchar,\n" +
                "   primary key(uid,bid,date),\n" +
                "   foreign key(uid) references user(uid),\n" +
                "   foreign key(bid) references book(bid)\n" +
                ")";
        String kindSQL = "create table bookkind(\n" +
                "   bid int NOT NULL,\n" +
                "   kind varchar,\n" +
                "   primary key(bid)\n" +
                ")";

        // 创建表
        try{
            // 用户表
            db.execSQL(userSQL);
        }
        catch (Exception e){
            e.printStackTrace();
        }
        try{
            // 书籍表
            db.execSQL(bookSQL);
        }
        catch (Exception e){
            e.printStackTrace();
        }
        try{
            // 种类表
            db.execSQL(kindSQL);
        }
        catch (Exception e){
            e.printStackTrace();
        }
        try{
            // 笔记表
            db.execSQL(noteSQL);
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }






    /*******************************
     - Function name : onCreate
     - Description : 启动响应
     - Variables : SQLiteDatabase db
     *******************************/
    @Override
    public void onCreate(SQLiteDatabase db) {

    }





    /*******************************
     - Function name : onUpdate
     - Description : 更新响应
     - Variables : SQLiteDatabase db, int oldVersion, int newVersion
     *******************************/
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }





    /*******************************
     - Function name : executeSQL
     - Description : 动作接口
     - Variables : String sql
     *******************************/
    public boolean executeSQL(String sql){
        try{
            db.execSQL(sql);
        }
        catch (Exception e){
            e.printStackTrace();
            return false;
        }
        return true;
    }





    /*******************************
     - Function name : getAmountOf
     - Description : 查数量接口
     - Variables : String sql
     *******************************/
    public int getAmountOf(String sql){
        int x = 0;

        try{
            Cursor cursor = db.rawQuery(sql ,null);
            String temp = "";
            while(cursor.moveToNext()){
                temp = cursor.getString(0);
            }
            x = Integer.parseInt(temp);
        }
        catch (Exception e){
            e.printStackTrace();
        }

        return x;
    }





    /*******************************
     - Function name : getStringOf
     - Description : 查结果接口
     - Variables : String sql
     *******************************/
    public String getStringOf(String sql){
        String x = "";

        try{
            Cursor cursor = db.rawQuery(sql ,null);
            while(cursor.moveToNext()){
                x = cursor.getString(0);
            }
        }
        catch (Exception e){
            e.printStackTrace();
        }

        return x;
    }
}
