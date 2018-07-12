/********************************************************
* - Project name : MyOperateSystem
* - Filename : head_process.h
* - Author : 刘畅
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : 进程管理头文件
* - Others : 石家庄铁道大学信息科学与技术学院
			 计算机科学与技术系
			 班级 - 信1501-1
			 学号 - 20153178
* - Function list : producer
					consumer
					PROCESS_PRINT_DEFAULT_PANEL
					PRODUCER_CONSUMER_DEMO
					PROCESS_DEMO
					PROCESS_DEMO_LOOP
					PROCESS_DEMO_INIT
					PROCESS_DEMO_PRINT
					insertIntoReady
					insertIntoFinish
					showQueue
					rebuildQueue
					getInCPU
					CPU_OPERATE
********************************************************/



/************************************
* Function name :
* Description :
* Variables :
************************************/



/****************************
		 预编译指令
****************************/

#pragma once

#include "head.h"
#include <thread>
#include <windows.h>



/****************************
		  结构体
****************************/
typedef struct pcb{
	int name;      // 进程名
	int prio;      // 优先数
	int arrive;    // 到达时间
	int needtime;  // 需要运行时间
	int cputime;   // 已用CPU时间
	int finishtime;// 结束时间
	int state;     // 进程状态
	pcb *next;     // next指针
}PCB;



/****************************
		 全局变量
****************************/
const int BUF_MAX = 8;     // 缓冲池最大容量为8
int products = 5;          // 初试产品数量为5
int PRODUCE_TIMES = 20;    // 控制演示时间
const int PRO_READY = 0;   // 就绪态
const int PRO_RUN = 1;     // 运行态
const int PRO_FINISH = 2;  // 完成态
PCB *ready;   // 就绪队列
PCB *run;     // 执行指针
PCB *finish;  // 完成队列
const int DEMO_PROCESS = 5;  // 演示进程数量
const int PRIO_WEIGHT = 50;  // 优先级确定标称
const int NEEDTIME_INTERVAL = 2;   // 默认需求时间间隔
int TIME = 0;    // 时间片

string PROCESS_ALGORITHM;  // 调度算法
const string HRRN = "1";   // 最高响应比算法
const string SSTF = "2";   // 短作业优先算法
const string HPFS = "3";   // 高优先级优先算法





/****************************
		 函数声明
****************************/
void producer();
void consumer();
void PROCESS_PRINT_DEFAULT_PANEL();
void PRODUCER_CONSUMER_DEMO();
void PROCESS_DEMO();
void PROCESS_DEMO_LOOP();
void PROCESS_DEMO_INIT();
void PROCESS_DEMO_PRINT();
void insertIntoReady(PCB *p);
void insertIntoFinish(PCB *p);
void showQueue(PCB *p);
void rebuildQueue();
void rebuildQueueByTime();
void rebuildQueueHRRN();
void getInCPU();
void CPU_OPERATE();