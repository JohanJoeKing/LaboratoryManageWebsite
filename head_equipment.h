/********************************************************
* - Project name : MyOperateSystem
* - Filename : head_equipment.h
* - Author : 刘畅
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : 设备管理头文件
* - Others : 石家庄铁道大学信息科学与技术学院
			 计算机科学与技术系
			 班级 - 信1501-1
			 学号 - 20153178
* - Function list : EQUIPMENT_PRINT_DEFAULT_PANEL
					EQUIPMENT_INIT
					EQUIPMENT_USER_SET
					EQUIPMENT_START
					EQUIPMENT_LOOP
					EQUIPMENT_ALGORITHM
					changeData
					returnBackData
					checkSecurity
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




/****************************
		 全局变量
****************************/
const int PROCESS = 5;    // 进程数量
const int RESOURCES = 3;  // 资源数量
int **MAX;       // 进程对资源的最大需求量
int *AVAILABLE;  // 系统可用资源数量
int **ALLOCATION;// 进程已得到的资源数量
int **NEED;      // 进程还需要的资源数量
int process;     // 发出请求的进程
int *REQUEST;    // 请求向量



/****************************
		 函数声明
****************************/
void EQUIPMENT_PRINT_DEFAULT_PANEL();
void EQUIPMENT_INIT();
void EQUIPMENT_USER_SET();
void EQUIPMENT_START();
void EQUIPMENT_LOOP();
void EQUIPMENT_ALGORITHM();
void changeData();
void returnBackData();
bool checkSecurity();