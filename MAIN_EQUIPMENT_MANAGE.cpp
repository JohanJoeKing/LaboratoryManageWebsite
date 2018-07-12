/********************************************************
* - Project name : MyOperateSystem
* - Filename : MAIN_EQUIPMENT_MANAGE.cpp
* - Author : 刘畅
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : 设备管理
* - Others : 石家庄铁道大学信息科学与技术学院
			 计算机科学与技术系
			 班级 - 信1501-1
			 学号 - 20153178
* - Function list :
* - History : [刘畅]2018/6/29第一次修改，基本实现了安全性算法
********************************************************/



/****************************
		 文件引用
****************************/
#include "head_equipment.h"




/****************************
		 函数声明
****************************/




/************************************
* Function name : MAIN_EQUIPMENT_MANAGE
* Description : 设备管理主函数
* Variables : void
************************************/
void MAIN_EQUIPMENT_MANAGE(){

	// 系统变量初始化
	EQUIPMENT_INIT();

	// 指定资源数量和最大需求量
	EQUIPMENT_USER_SET();

	// 打印主界面
	EQUIPMENT_PRINT_DEFAULT_PANEL();

	// 提示并开始
	EQUIPMENT_START();

}




/************************************
* Function name : EQUIPMENT_PRINT_DEFAULT_PANEL
* Description : 显示主界面
* Variables : void
************************************/
void EQUIPMENT_PRINT_DEFAULT_PANEL(){

	// 清屏
	system("cls");

	// 打印标题
	// 打印标题
	printf("****************************************\n\n");
	printf("             设备管理部分          \n\n");
	printf("****************************************\n\n");
}





/************************************
* Function name : EQUIPMENT_INIT
* Description : 初始化
* Variables : void
************************************/
void EQUIPMENT_INIT(){

	// 初始化MAX
	MAX = new int*[PROCESS];
	for (int i = 0; i < PROCESS; i++){
		MAX[i] = new int[RESOURCES];
	}

	// 初始化AVAILABLE
	AVAILABLE = new int[RESOURCES];

	// 初始化ALLOCATION
	ALLOCATION = new int*[PROCESS];
	for (int i = 0; i < PROCESS; i++){
		ALLOCATION[i] = new int[RESOURCES];
	}

	// 初始化NEED
	NEED = new int*[PROCESS];
	for (int i = 0; i < PROCESS; i++){
		NEED[i] = new int[RESOURCES];
	}

	// 初始化请求向量
	REQUEST = new int[RESOURCES];

	// 初始化赋值
	for (int i = 0; i < PROCESS; i++){
		for (int j = 0; j < RESOURCES; j++){
			MAX[i][j] = 0;
			ALLOCATION[i][j] = 0;
			NEED[i][j] = 0;
		}
	}
	for (int i = 0; i < RESOURCES; i++){
		AVAILABLE[i] = 0;
		REQUEST[i] = 0;
	}

}





/************************************
* Function name : EQUIPMENT_USER_SET
* Description : 用户指定赋值
* Variables : void
************************************/
void EQUIPMENT_USER_SET(){

	// 设定资源数量分别为9,8,7
	AVAILABLE[0] = 3;
	AVAILABLE[1] = 3;
	AVAILABLE[2] = 2;

	// 设定进程最大需求量
	MAX[0][0] = 7;
	MAX[0][1] = 5;
	MAX[0][2] = 3;

	MAX[1][0] = 3;
	MAX[1][1] = 2;
	MAX[1][2] = 2;

	MAX[2][0] = 9;
	MAX[2][1] = 0;
	MAX[2][2] = 2;

	MAX[3][0] = 2;
	MAX[3][1] = 2;
	MAX[3][2] = 2;

	MAX[4][0] = 4;
	MAX[4][1] = 3;
	MAX[4][2] = 3;

	// 设置当前ALLOCATION
	ALLOCATION[0][0] = 0;
	ALLOCATION[0][1] = 1;
	ALLOCATION[0][2] = 0;

	ALLOCATION[1][0] = 2;
	ALLOCATION[1][1] = 0;
	ALLOCATION[1][2] = 0;

	ALLOCATION[2][0] = 3;
	ALLOCATION[2][1] = 0;
	ALLOCATION[2][2] = 2;

	ALLOCATION[3][0] = 2;
	ALLOCATION[3][1] = 1;
	ALLOCATION[3][2] = 1;

	ALLOCATION[4][0] = 0;
	ALLOCATION[4][1] = 0;
	ALLOCATION[4][2] = 2;

}





/************************************
* Function name : EQUIPMENT_START
* Description : 提示并开始
* Variables : void
************************************/
void EQUIPMENT_START(){

	// 打印资源总量
	printf("各类资源总量：\n");
	for (int i = 0; i < RESOURCES; i++){
		printf("%3d", AVAILABLE[i]);
	}
	printf("\n\n");

	// 打印各进程最大需求量
	printf("各进程最大资源需求量：\n");
	for (int i = 0; i < PROCESS; i++){
		for (int j = 0; j < RESOURCES; j++){
			printf("%3d", MAX[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// 提示开始
	printf("任意键以开始...\n");
	string aaa;
	cin >> aaa;

	// 开始请求资源
	system("cls");
	EQUIPMENT_LOOP();

}





/************************************
* Function name : EQUIPMENT_LOOP
* Description : 提示并开始
* Variables : void
************************************/
void EQUIPMENT_LOOP(){

	//while (1){

		// 前大分割线
		printf("###############################################\n");

		// 计算Need矩阵
		int i, j;
		for (i = 0; i < PROCESS; i++){
			for (j = 0; j < RESOURCES; j++){
				NEED[i][j] = MAX[i][j] - ALLOCATION[i][j];
			}
		}

		// 显示MAX矩阵
		printf("Max\n");
		for (i = 0; i < PROCESS; i++){
			for (j = 0; j < RESOURCES; j++){
				printf("%3d", MAX[i][j]);
			}
			printf("\n");
		}

		// 显示ALLOCATION矩阵
		printf("Allocation\n");
		for (i = 0; i < PROCESS; i++){
			for (j = 0; j < RESOURCES; j++){
				printf("%3d", ALLOCATION[i][j]);
			}
			printf("\n");
		}

		// 显示NEED矩阵
		printf("Need\n");
		for (i = 0; i < PROCESS; i++){
			for (j = 0; j < RESOURCES; j++){
				printf("%3d", NEED[i][j]);
			}
			printf("\n");
		}

		// 显示AVAILABLE向量
		printf("Available\n");
		for (i = 0; i < RESOURCES; i++){
			printf("%3d", AVAILABLE[i]);
		}
		printf("\n\n");

		// 输入请求向量
		printf("输入请求进程：");
		cin >> process;
		printf("输入请求向量：");
		for (i = 0; i < RESOURCES; i++){
			cin >> REQUEST[i];
		}
		printf("\n");

		// 银行家算法
		EQUIPMENT_ALGORITHM();

		// 后大分割线
		//printf("###############################################\n");
		printf("任意键以继续...\n");
		string aaa;
		cin >> aaa;

	//} // while

}




/************************************
* Function name : EQUIPMENT_ALGORITHM
* Description : 银行家算法
* Variables : void
************************************/
void EQUIPMENT_ALGORITHM(){

	// request是否小于need
	bool flag = true;
	int i, j;
	for (i = 0; i < RESOURCES; i++){
		if (REQUEST[i] > NEED[process][i]){
			flag = false;
			break;
		}
	}
	if (flag){

		// request不大于need，比较available
		bool flag2 = true;
		for (i = 0; i < RESOURCES; i++){
			if (REQUEST[i] > AVAILABLE[i]){
				flag2 = false;
				break;
			}
		}
		if (flag2){

			// request不大于available，尝试分配
			changeData();

			// 安全性检测
			if (!checkSecurity()){
				// 当分配不安全
				returnBackData();       // 回滚操作
				printf("分配不安全\n"); // 提示
			}
			else{
				// 当分配安全，安全序列已在本条语句之前显示
				printf("故分配安全\n");
			}

		}

		else{

			// request大于available，不能分配
			printf("Request大于Available，不能分配\n");
			return;

		}


	} // if

	else{

		// request大于need，异常退出
		printf("Request大于Need，不予分配\n");
		return;

	} // else

}





/************************************
* Function name : changeData
* Description : 尝试分配
* Variables : int process
************************************/
void changeData(){

	// 分配资源
	for (int i = 0; i < RESOURCES; i++){
		AVAILABLE[i] -= REQUEST[i];
		ALLOCATION[process][i] += REQUEST[i];
		NEED[process][i] -= REQUEST[i];
	}

}





/************************************
* Function name : returnBackData
* Description : 回滚操作
* Variables : int process
************************************/
void returnBackData(){

	// 回滚分配
	for (int i = 0; i < RESOURCES; i++){
		AVAILABLE[i] += REQUEST[i];
		ALLOCATION[process][i] -= REQUEST[i];
		NEED[process][i] += REQUEST[i];
	}

}






/************************************
* Function name : checkSecurity
* Description : 安全性检验
* Variables : void
************************************/
bool checkSecurity(){

	int WORK;              // WORK是某类资源可用数量
	bool FINISH[PROCESS];  // FINISH是某进程是否完成的标记
	int temp[PROCESS];     // temp是缓存安全序列
	int i, j, k = 0;       // k用于指示安全序列数组的位置

	// 初始化所有进程都未完成
	for (i = 0; i < PROCESS; i++)
		FINISH[i] = false;

	//用安全性检查算法判断系统是否安全（即是否为 true）
	// 按资源类别循环
	for (j = 0; j < RESOURCES; j++)
	{
		// 读取当前某资源可用数量到WORK
		WORK = AVAILABLE[j];

		// 让i等于进程号
		i = process;

		// 遍历进程号
		while (i < PROCESS)
		{
			if (FINISH[i] == false && NEED[i][j] <= WORK)
			{
				// 当进程i未完成且该进程需要的资源数量不大于该类可用资源
				// 全部分配给该进程后释放所有占用资源
				WORK = WORK + ALLOCATION[i][j];

				// 标记该进程已完成
				FINISH[i] = true;

				// 记录到安全序列
				temp[k] = i;
				k++;

				// 从头遍历进程完成情况
				i = 0;
			}
			else
			{
				// 若遍历到的进程已完成或不能满足其需要的资源
				// 跳转到下一个进程
				i++;
			}
		} // while


		// 遍历进程完成情况，若都能完成
		// 则说明找到了一个安全序列
		// 否则没有
		for (i = 0; i < PROCESS; i++)
		if (FINISH[i] == false)
		{
			printf("检测到进程%d未完成\n", i);
			return false;
		}
	} // for


	// 通过上面的安全性检验过程后
	// 到达该位置时已能证明存在一个安全序列
	// 显示出该安全序列
	printf("可得到的安全序列：");
	for (i = 0; i < PROCESS; i++){
		printf("%3d", temp[i]);
	}
	printf("\n");
	return true;

}