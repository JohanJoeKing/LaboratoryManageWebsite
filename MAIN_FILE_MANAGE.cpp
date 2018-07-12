/********************************************************
* - Project name : MyOperateSystem
* - Filename : MAIN_FILE_MANAGE.cpp
* - Author : 刘畅
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : 文件管理
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
* - History : [刘畅]2018/6/28第一次修改，完成了基本功能实现
********************************************************/



/****************************
		 文件引用
****************************/
#include "head_file.h"




/****************************
		 函数声明
****************************/




/************************************
* Function name : MAIN_FILE_MANAGE
* Description : 文件管理主函数
* Variables : void
************************************/
void MAIN_FILE_MANAGE(){

	// 打印标题
	FILE_PRINT_DEFAULT_PANEL();

	// 选择调度算法
	int choice;
	cin >> choice;
	int inputN = 0;   // 统计错误输入指令的次数
	while (inputN <= 5 && choice < 1 && choice > 4){
		inputN++;
		cin >> choice;
	}
	if (inputN > 5 && choice < 1 && choice > 4){
		// 当指令输入次数超限，退出
		return;
	}

	// 调度算法确定
	FILE_ALGORITHM = choice * 10 / 10;

	// 产生访问磁道的依次顺序
	GENERATE_DISKS();

	// 确定当前磁道位置
	SET_CURRENT_DISK();

	// 选择调度算法并开始
	if (FILE_ALGORITHM == FCFS){
		// 先来先服务算法
		FILE_FCFS();
	}
	else if (FILE_ALGORITHM == SSTF){
		// 最短寻道时间优先算法
		FILE_SSTF();
	}
	else if (FILE_ALGORITHM == SCAN){
		// 扫描算法
		FILE_SCAN();
	}
	else if (FILE_ALGORITHM == C_SCAN){
		// 循环扫描算法
		FILE_C_SCAN();
	}

	// 显示统计寻道数据
	SEARCH_SUMMARY();

	// 提示继续
	string aaa;
	printf("任意键以继续...\n");
	cin >> aaa;

}




/************************************
* Function name : FILE_PRINT_DEFAULT_PANEL
* Description : 显示主界面
* Variables : void
************************************/
void FILE_PRINT_DEFAULT_PANEL(){

	// 清屏
	system("cls");

	// 打印标题
	printf("****************************************\n\n");
	printf("             文件管理部分          \n\n");
	printf("****************************************\n\n");

	// 打印选项
	printf("选择磁盘调度算法\n[1]先来先服务算法\n[2]最短寻道时间优先算法\n[3]扫描算法\n[4]循环扫描算法\n> ");

}





/************************************
* Function name : GENERATE_DISKS
* Description : 生成访问磁道位置
* Variables : void
************************************/
void GENERATE_DISKS(){

	// 初始化磁道访问顺序列表
	disk = new int[VISITS];

	// 随机生成访问磁道
	for (int i = 0; i < VISITS; i++){
		disk[i] = rand() % 200 + 1;
		while (disk[i] <= 0 || disk[i] >= MAX_DISK){
			disk[i] = rand() % 200 + 1;
		}
	}

	// 显示访问顺序
	system("cls");
	printf("访问磁道的顺序：\n");
	for (int i = 0; i < VISITS; i++){
		printf("%d\t", disk[i]);
	}
	printf("\n\n");

}





/************************************
* Function name : SET_CURRENT_DISK
* Description : 确定当前磁道位置
* Variables : void
************************************/
void SET_CURRENT_DISK(){

	// 提示输入
	printf("请输入当前磁道位置：");
	cin >> curDisk;
	while (curDisk < 0 || curDisk > MAX_DISK){
		cin >> curDisk;
	}

}





/************************************
* Function name : FILE_FCFS
* Description : 先来先服务算法
* Variables : void
************************************/
void FILE_FCFS(){

	// 算法提示
	printf("\n【先来先服务算法】\n\n");

	// 列表标题
	printf("当前磁道\t欲访问磁道\t寻道长度\n");
	printf("---------------------------------------------\n");

	// 依次访问
	for (int i = 0; i < VISITS; i++){

		// 磁道信息显示
		printf("%5d%20d%15d\n"
			, curDisk
			, disk[i]
			, abs(curDisk - disk[i]));

		// 寻道长度统计
		search_times += abs(curDisk - disk[i]);

		// 修改当前磁道
		curDisk = disk[i];

	} // for

}




/************************************
* Function name : FILE_SSTF
* Description : 最短寻道时间优先算法
* Variables : void
************************************/
void FILE_SSTF(){

	// 对访问磁道进行升序排序
	int i, j, temp;
	for (i = 0; i < VISITS; i++){
		for (j = i + 1; j < VISITS; j++){
			if (disk[i] > disk[j]){
				temp = disk[i];
				disk[i] = disk[j];
				disk[j] = temp;
			}
		}
	}

	// 分情况进行寻道
	if (curDisk <= disk[0]){

		// 当当前磁道在最小的访问磁道前，升序访问
		for (int k = 0; k < VISITS; k++){

			// 磁道信息显示
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// 寻道长度统计
			search_times += abs(curDisk - disk[k]);

			// 修改当前磁道
			curDisk = disk[k];
		}


	} // if

	else if (curDisk >= disk[VISITS - 1]){

		// 当当前磁道在最大的访问磁道后，降序访问
		for (int k = VISITS - 1; k >= 0; k--){

			// 磁道信息显示
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// 寻道长度统计
			search_times += abs(curDisk - disk[k]);

			// 修改当前磁道
			curDisk = disk[k];
		}


	} // else if

	else{

		// 当当前磁道在磁道顺序之间，寻找前后相邻的访问磁道
		int behind, front;
		for (int k = 0; k < VISITS; k++){
			if (disk[k] <= curDisk && disk[k + 1] > curDisk){
				front = k;       // 当前磁道前
				behind = k + 1;  // 当前磁道后
			}
		}

		// 判断离哪个更近
		if (abs(curDisk - disk[front]) < abs(curDisk - disk[behind])){

			// 当离前一个邻接访问磁道更近，先降序访问再升序访问
			for (int k = front; k >= 0; k--){
				// 磁道信息显示
				printf("%5d%20d%15d\n"
					, curDisk
					, disk[k]
					, abs(curDisk - disk[k]));

				// 寻道长度统计
				search_times += abs(curDisk - disk[k]);

				// 修改当前磁道
				curDisk = disk[k];
			}
			for (int k = behind; k < VISITS; k++){
				// 磁道信息显示
				printf("%5d%20d%15d\n"
					, curDisk
					, disk[k]
					, abs(curDisk - disk[k]));

				// 寻道长度统计
				search_times += abs(curDisk - disk[k]);

				// 修改当前磁道
				curDisk = disk[k];
			}

		}

		else{

			// 当离后一个邻接访问磁道更近，先升序访问再降序访问
			for (int k = behind; k < VISITS; k++){
				// 磁道信息显示
				printf("%5d%20d%15d\n"
					, curDisk
					, disk[k]
					, abs(curDisk - disk[k]));

				// 寻道长度统计
				search_times += abs(curDisk - disk[k]);

				// 修改当前磁道
				curDisk = disk[k];
			}
			for (int k = front; k >= 0; k--){
				// 磁道信息显示
				printf("%5d%20d%15d\n"
					, curDisk
					, disk[k]
					, abs(curDisk - disk[k]));

				// 寻道长度统计
				search_times += abs(curDisk - disk[k]);

				// 修改当前磁道
				curDisk = disk[k];
			}

		}

	} // else
}





/************************************
* Function name : FILE_SCAN
* Description : 扫描算法
* Variables : void
************************************/
void FILE_SCAN(){

	// 对访问磁道进行升序排序
	int i, j, temp;
	for (i = 0; i < VISITS; i++){
		for (j = i + 1; j < VISITS; j++){
			if (disk[i] > disk[j]){
				temp = disk[i];
				disk[i] = disk[j];
				disk[j] = temp;
			}
		}
	}

	// 判断磁针位置
	if (curDisk < disk[0]){
		// 当前磁针位置在最小的磁道之前，升序访问
		for (int k = 0; k < VISITS; k++){

			// 磁道信息显示
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// 寻道长度统计
			search_times += abs(curDisk - disk[k]);

			// 修改当前磁道
			curDisk = disk[k];
		}
	} // if

	else{
		// 当磁针在访问磁道中间,寻找磁针前后访问磁道
		int behind = 0, front = 0;
		for (int k = 0; k < VISITS; k++){
			if (disk[k] <= curDisk && disk[k + 1] > curDisk){
				front = k;       // 当前磁道前
				behind = k + 1;  // 当前磁道后
			}
		}

		// 先升序再降序
		for (int k = behind; k < VISITS; k++){
			// 磁道信息显示
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// 寻道长度统计
			search_times += abs(curDisk - disk[k]);

			// 修改当前磁道
			curDisk = disk[k];
		}
		for (int k = front; k >= 0; k--){
			// 磁道信息显示
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// 寻道长度统计
			search_times += abs(curDisk - disk[k]);

			// 修改当前磁道
			curDisk = disk[k];
		}
	}

}





/************************************
* Function name : FILE_C_SCAN
* Description : 循环扫描算法
* Variables : void
************************************/
void FILE_C_SCAN(){

	// 对访问磁道进行升序排序
	int i, j, temp;
	for (i = 0; i < VISITS; i++){
		for (j = i + 1; j < VISITS; j++){
			if (disk[i] > disk[j]){
				temp = disk[i];
				disk[i] = disk[j];
				disk[j] = temp;
			}
		}
	}

	// 判断磁针位置
	if (curDisk <= disk[0] || curDisk > disk[VISITS - 1]){

		// 当磁针在最小磁道之前或最大磁道之后，都升序访问
		for (int k = 0; k < VISITS; k++){

			// 磁道信息显示
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// 寻道长度统计
			search_times += abs(curDisk - disk[k]);

			// 修改当前磁道
			curDisk = disk[k];
		}

	} // if

	else{

		// 当磁针在访问磁道之间，找相邻访问磁道
		int behind, front;
		for (int k = 0; k < VISITS; k++){
			if (disk[k] <= curDisk && disk[k + 1] > curDisk){
				front = k;       // 当前磁道前
				behind = k + 1;  // 当前磁道后
			}
		}

		// 先升序访问到最大磁道，在从最小磁道开始访问
		for (int k = behind; k < VISITS; k++){
			// 磁道信息显示
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// 寻道长度统计
			search_times += abs(curDisk - disk[k]);

			// 修改当前磁道
			curDisk = disk[k];
		}
		for (int k = 0; k <= front; k++){
			// 磁道信息显示
			printf("%5d%20d%15d\n"
				, curDisk
				, disk[k]
				, abs(curDisk - disk[k]));

			// 寻道长度统计
			search_times += abs(curDisk - disk[k]);

			// 修改当前磁道
			curDisk = disk[k];
		}

	} // else
}





/************************************
* Function name : SEARCH_SUMMARY
* Description : 统计寻道数据
* Variables : void
************************************/
void SEARCH_SUMMARY(){

	// 计算
	average_times = (double)search_times / (double)VISITS;

	// 显示
	printf("\n总寻道长度：%d\n平均寻道长度：%lf\n\n"
		, search_times
		, average_times);

}