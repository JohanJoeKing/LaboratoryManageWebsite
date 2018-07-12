/********************************************************
* - Project name : MyOperateSystem
* - Filename : head_file.h
* - Author : 刘畅
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : 文件管理头文件
* - Others : 石家庄铁道大学信息科学与技术学院
			 计算机科学与技术系
			 班级 - 信1501-1
			 学号 - 20153178
* - Function list : FILE_PRINT_DEFAULT_PANEL
					GENERATE_DISKS
					SET_CURRENT_DISK
					FILE_FCFS
					FILE_SSTF
					FILE_SCAN
					FILE_C_SCAN
					SEARCH_SUMMARY
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
#include <cstdlib>
#include <ctime>
#include <cmath>




/****************************
		 全局变量
****************************/
int FILE_ALGORITHM;    // 调度算法
const int FCFS = 1;    // 先来先服务算法
const int SSTF = 2;    // 最短寻道时间优先算法
const int SCAN = 3;    // 扫描算法
const int C_SCAN = 4;  // 循环扫描算法
const int MAX_DISK = 200;   // 最大磁道
const int VISITS = 10;      // 访问磁道数量
int curDisk = 0;            // 当前所在磁道
int *disk;                  // 磁道访问顺序
int direction;              // 当前磁针移动方向
int search_times = 0;       // 总寻道次数
double average_times = 0;   // 平均寻道长度




/****************************
		 函数声明
****************************/
void FILE_PRINT_DEFAULT_PANEL();
void GENERATE_DISKS();
void SET_CURRENT_DISK();
void FILE_FCFS();
void FILE_SSTF();
void FILE_SCAN();
void FILE_C_SCAN();
void SEARCH_SUMMARY();