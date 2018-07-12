/********************************************************
 * - Project name : MyOperateSystem
 * - Filename : main.cpp
 * - Author : 刘畅
 * - Version : 1.0
 * - Start date : 2018/6/26
 * - Description : 2018夏季学期操作系统实训-主函数实验代码
 * - Others : 石家庄铁道大学信息科学与技术学院
			  计算机科学与技术系
			  班级 - 信1501-1
			  学号 - 20153178
 * - Function list : main
				     PRINT_DEFAULT_PANEL
 * - History : [刘畅]2018/6/26第一次修改，建立项目
			   [刘畅]2018/6/28第二次修改，添加存储管理模块
 ********************************************************/




/****************************
		  文件引用
****************************/
#include "head.h"




/****************************
		  函数声明
****************************/
void PRINT_DEFAULT_PANEL();




/************************************
* Function name : main
* Description : 主函数
* Variables : void
************************************/
void main(){

	// 循环操作
	while (1){

		// 显示主界面
		PRINT_DEFAULT_PANEL();

		// 输入选择
		string choise = "";   // 指令
		cin >> choise;

		// 分析指令并跳转
		if (choise == "1"){
			// 进程管理
			MAIN_PROCESS_MANAGE();
		}
		else if (choise == "2"){
			// 设备管理
			MAIN_EQUIPMENT_MANAGE();
		}
		else if (choise == "3"){
			// 文件管理
			MAIN_FILE_MANAGE();
		}
		else if (choise == "4"){
			// 存储管理
			MAIN_MEMORY_MANAGE();
		}

	} // while

}





/************************************
* Function name : PRINT_DEFAULT_PANEL
* Description : 显示主界面
* Variables : void
************************************/
void PRINT_DEFAULT_PANEL(){

	// 清屏
	system("cls");

	// 打印标题
	printf("****************************************\n\n");
	printf("             模拟操作系统          \n\n");
	printf("****************************************\n\n");

	// 打印选项
	printf("[1]进程管理\t[2]设备管理\n[3]文件管理\t[4]存储管理\n> ");

}