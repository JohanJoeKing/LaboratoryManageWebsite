package com.example.johan.dailyoutcome;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
//import android.widget.Toast;

/***************************************************
 * - Project name : DailyOutcome
 * - Filename : MainActivity.java
 * - Author : Johan
 * - Version : 1.0
 * - Date : 2018/10/6
 * - Description : An application to calculate outcome
 *               of a month and help to judge the
 *               purchasing plan.
 *               一款用于计算每月开销的APP并能帮助调整每月开销计划
 * - Function list :
 * - History : [Johan]2018/10/6 Created the project.
 * - Others :
 ***************************************************/

public class MainActivity extends AppCompatActivity {

    // TODO 控件
    private EditText eEventName1;        // 消费事件名称
    private EditText eEventName2;
    private EditText eEventName3;
    private EditText eEventName4;
    private EditText eEventName5;
    private EditText eEventName6;
    private EditText eEventName7;
    private EditText eEventName8;
    private EditText eEventName9;
    private EditText eEventName10;
    private EditText eEventName11;
    private EditText eEventName12;
    private EditText eEventName13;
    private EditText eEventName14;
    private EditText eEventName15;
    private EditText eEventAmount1;      // 消费次数
    private EditText eEventAmount2;
    private EditText eEventAmount3;
    private EditText eEventAmount4;
    private EditText eEventAmount5;
    private EditText eEventAmount6;
    private EditText eEventAmount7;
    private EditText eEventAmount8;
    private EditText eEventAmount9;
    private EditText eEventAmount10;
    private EditText eEventAmount11;
    private EditText eEventAmount12;
    private EditText eEventAmount13;
    private EditText eEventAmount14;
    private EditText eEventAmount15;
    private EditText eEventOutcome1;     // 消费金额
    private EditText eEventOutcome2;
    private EditText eEventOutcome3;
    private EditText eEventOutcome4;
    private EditText eEventOutcome5;
    private EditText eEventOutcome6;
    private EditText eEventOutcome7;
    private EditText eEventOutcome8;
    private EditText eEventOutcome9;
    private EditText eEventOutcome10;
    private EditText eEventOutcome11;
    private EditText eEventOutcome12;
    private EditText eEventOutcome13;
    private EditText eEventOutcome14;
    private EditText eEventOutcome15;

    private Button calBut;    // 开始计算按钮
    private TextView omText;  // 结果显示

    // TODO 支持量
    private final int EVENTS = 15;    // 固定条目数量
    private String[] eName;           // 消费事件名称
    private String[] eSAmount;        // 字符型数量
    private String[] eSOutcome;       // 字符型金额
    private float[] eAmount;          // 消费次数
    private float[] eOutcome;         // 消费金额


    /********************************************
     * Function name : onCreate
     * Description : TODO 构造函数
     * Variables : Bundle savedInstanceState
     ********************************************/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 获取控件
        initViews();

        // 初始化支持量
        eName = new String[EVENTS];
        eAmount = new float[EVENTS];
        eSAmount = new String[EVENTS];
        eOutcome = new float[EVENTS];
        eSOutcome = new String[EVENTS];
        for(int i = 0;i < EVENTS;i++){
            eName[i] = eSAmount[i] = eSOutcome[i] = "";
            eAmount[i] = eOutcome[i] = 0;
        }
    }




    /********************************************
     * Function name : initViews
     * Description : TODO 初始化控件
     * Variables : void
     ********************************************/
    private void initViews(){
        // 消费事件名称
        eEventName1 = (EditText)findViewById(R.id.eventName1);
        eEventName2 = (EditText)findViewById(R.id.eventName2);
        eEventName3 = (EditText)findViewById(R.id.eventName3);
        eEventName4 = (EditText)findViewById(R.id.eventName4);
        eEventName5 = (EditText)findViewById(R.id.eventName5);
        eEventName6 = (EditText)findViewById(R.id.eventName6);
        eEventName7 = (EditText)findViewById(R.id.eventName7);
        eEventName8 = (EditText)findViewById(R.id.eventName8);
        eEventName9 = (EditText)findViewById(R.id.eventName9);
        eEventName10 = (EditText)findViewById(R.id.eventName10);
        eEventName11 = (EditText)findViewById(R.id.eventName11);
        eEventName12 = (EditText)findViewById(R.id.eventName12);
        eEventName13 = (EditText)findViewById(R.id.eventName13);
        eEventName14 = (EditText)findViewById(R.id.eventName14);
        eEventName15 = (EditText)findViewById(R.id.eventName15);

        // 消费次数
        eEventAmount1 = (EditText)findViewById(R.id.eventAmount1);
        eEventAmount2 = (EditText)findViewById(R.id.eventAmount2);
        eEventAmount3 = (EditText)findViewById(R.id.eventAmount3);
        eEventAmount4 = (EditText)findViewById(R.id.eventAmount4);
        eEventAmount5 = (EditText)findViewById(R.id.eventAmount5);
        eEventAmount6 = (EditText)findViewById(R.id.eventAmount6);
        eEventAmount7 = (EditText)findViewById(R.id.eventAmount7);
        eEventAmount8 = (EditText)findViewById(R.id.eventAmount8);
        eEventAmount9 = (EditText)findViewById(R.id.eventAmount9);
        eEventAmount10 = (EditText)findViewById(R.id.eventAmount10);
        eEventAmount11 = (EditText)findViewById(R.id.eventAmount11);
        eEventAmount12 = (EditText)findViewById(R.id.eventAmount12);
        eEventAmount13 = (EditText)findViewById(R.id.eventAmount13);
        eEventAmount14 = (EditText)findViewById(R.id.eventAmount14);
        eEventAmount15 = (EditText)findViewById(R.id.eventAmount15);

        // 消费金额
        eEventOutcome1 = (EditText)findViewById(R.id.eventOutcome1);
        eEventOutcome2 = (EditText)findViewById(R.id.eventOutcome2);
        eEventOutcome3 = (EditText)findViewById(R.id.eventOutcome3);
        eEventOutcome4 = (EditText)findViewById(R.id.eventOutcome4);
        eEventOutcome5 = (EditText)findViewById(R.id.eventOutcome5);
        eEventOutcome6 = (EditText)findViewById(R.id.eventOutcome6);
        eEventOutcome7 = (EditText)findViewById(R.id.eventOutcome7);
        eEventOutcome8 = (EditText)findViewById(R.id.eventOutcome8);
        eEventOutcome9 = (EditText)findViewById(R.id.eventOutcome9);
        eEventOutcome10 = (EditText)findViewById(R.id.eventOutcome10);
        eEventOutcome11 = (EditText)findViewById(R.id.eventOutcome11);
        eEventOutcome12 = (EditText)findViewById(R.id.eventOutcome12);
        eEventOutcome13 = (EditText)findViewById(R.id.eventOutcome13);
        eEventOutcome14 = (EditText)findViewById(R.id.eventOutcome14);
        eEventOutcome15 = (EditText)findViewById(R.id.eventOutcome15);

        // 辅助控件
        calBut = (Button)findViewById(R.id.calButton);
        omText = (TextView)findViewById(R.id.outcomeText);
    }




    /********************************************
     * Function name : button_calculateOnClick
     * Description : TODO 开始计算事件
     * Variables : View v
     ********************************************/
    public void button_calculateOnClick(View v){
        // 用于判断条目是否纳入计算的标识
        boolean[] FLAG = new boolean[EVENTS];
        for(int i = 0;i < EVENTS;i++){
            FLAG[i] = false;
        }

        // 获取每个条目的输入信息
        // 消费事件名称
        eName[0] = eEventName1.getText().toString();
        eName[1] = eEventName2.getText().toString();
        eName[2] = eEventName3.getText().toString();
        eName[3] = eEventName4.getText().toString();
        eName[4] = eEventName5.getText().toString();
        eName[5] = eEventName6.getText().toString();
        eName[6] = eEventName7.getText().toString();
        eName[7] = eEventName8.getText().toString();
        eName[8] = eEventName9.getText().toString();
        eName[9] = eEventName10.getText().toString();
        eName[10] = eEventName11.getText().toString();
        eName[11] = eEventName12.getText().toString();
        eName[12] = eEventName13.getText().toString();
        eName[13] = eEventName14.getText().toString();
        eName[14] = eEventName15.getText().toString();

        // 消费次数
        eSAmount[0] = eEventAmount1.getText().toString();
        eSAmount[1] = eEventAmount2.getText().toString();
        eSAmount[2] = eEventAmount3.getText().toString();
        eSAmount[3] = eEventAmount4.getText().toString();
        eSAmount[4] = eEventAmount5.getText().toString();
        eSAmount[5] = eEventAmount6.getText().toString();
        eSAmount[6] = eEventAmount7.getText().toString();
        eSAmount[7] = eEventAmount8.getText().toString();
        eSAmount[8] = eEventAmount9.getText().toString();
        eSAmount[9] = eEventAmount10.getText().toString();
        eSAmount[10] = eEventAmount11.getText().toString();
        eSAmount[11] = eEventAmount12.getText().toString();
        eSAmount[12] = eEventAmount13.getText().toString();
        eSAmount[13] = eEventAmount14.getText().toString();
        eSAmount[14] = eEventAmount15.getText().toString();

        // 消费金额
        eSOutcome[0] = eEventOutcome1.getText().toString();
        eSOutcome[1] = eEventOutcome2.getText().toString();
        eSOutcome[2] = eEventOutcome3.getText().toString();
        eSOutcome[3] = eEventOutcome4.getText().toString();
        eSOutcome[4] = eEventOutcome5.getText().toString();
        eSOutcome[5] = eEventOutcome6.getText().toString();
        eSOutcome[6] = eEventOutcome7.getText().toString();
        eSOutcome[7] = eEventOutcome8.getText().toString();
        eSOutcome[8] = eEventOutcome9.getText().toString();
        eSOutcome[9] = eEventOutcome10.getText().toString();
        eSOutcome[10] = eEventOutcome11.getText().toString();
        eSOutcome[11] = eEventOutcome12.getText().toString();
        eSOutcome[12] = eEventOutcome13.getText().toString();
        eSOutcome[13] = eEventOutcome14.getText().toString();
        eSOutcome[14] = eEventOutcome15.getText().toString();

        // 第一遍筛选纳入计算的条目
        for(int i = 0;i < EVENTS;i++){
            if(eSAmount[i].equals("") || eSOutcome[i].equals("")){
                FLAG[i] = false;
            }
            else{
                FLAG[i] = true;
            }
        }

        // 转换为计算量，第二遍筛选
        for(int i = 0;i < EVENTS;i++){
            try{
                eAmount[i] = Float.parseFloat(eSAmount[i]);
            }
            catch (Exception e){
                FLAG[i] = false;
                //Toast.makeText(this, eSAmount[i] + "不是合法数字字符", Toast.LENGTH_SHORT).show();
                continue;
            }
        }
        for(int i = 0;i < EVENTS;i++){
            try{
                eOutcome[i] = Float.parseFloat(eSOutcome[i]);
            }
            catch (Exception e){
                FLAG[i] = false;
                //Toast.makeText(this, eSOutcome[i] + "不是合法数字字符", Toast.LENGTH_SHORT).show();
                continue;
            }
        }

        // 计算总量
        float sum = 0;
        for(int i = 0;i < EVENTS;i++){
            if(FLAG[i]){
                sum += eAmount[i] * eOutcome[i];
            }
        }

        // 显示总量
        omText.setText("计划总消费：" + sum + "元");
    }
}
