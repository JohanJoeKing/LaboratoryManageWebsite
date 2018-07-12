/********************************************************
* - Project name : MyOperateSystem
* - Filename : MAIN_MEMORY_MANAGE.cpp
* - Author : 刘畅
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : 存储管理
* - Others : 石家庄铁道大学信息科学与技术学院
			 计算机科学与技术系
			 班级 - 信1501-1
			 学号 - 20153178
* - Function list : MAIN_MEMORY_MANAGE
					MEMORY_PRINT_DEFAULT_PANEL
					GENERATE_ADDRESS
					VISIT_LOOP
					RAND_ADDRESS
					ifPageInMemory
					ifExistNullBlock
					fifo_findFirstIn
					lru_findLeastUseBlock
					PRINT_BLOCKS
* - History : [刘畅]2018/6/28第一次修改，完成基本功能
********************************************************/



/****************************
		 文件引用
****************************/
#include "head_memory.h"




/************************************
* Function name : MAIN_MEMORY_MANAGE
* Description : 内存管理主函数
* Variables : void
************************************/
void MAIN_MEMORY_MANAGE(){

	// 打印标题
	MEMORY_PRINT_DEFAULT_PANEL();

	// 选择淘汰算法
	string choice = "";
	cin >> choice;
	int inputN = 0;   // 统计错误输入指令的次数
	while (inputN <= 5 && choice != "1" && choice != "2"){
		inputN++;
		cin >> choice;
	}
	if (inputN > 5 && choice != "1" && choice != "2"){
		// 当指令输入次数超限，退出
		return;
	}

	// 淘汰算法确定
	if (choice == "1"){
		ALGORITHM = 1;
	}
	else if (choice == "2"){
		ALGORITHM = 2;
	}

	// 产生指令地址
	GENERATE_ADDRESS();

	// 开始循环
	VISIT_LOOP();

	// 打印置换图
	PRINT_BLOCKS();

}




/************************************
* Function name : PRINT_DEFAULT_PANEL
* Description : 显示主界面
* Variables : void
************************************/
void MEMORY_PRINT_DEFAULT_PANEL(){

	// 清屏
	system("cls");

	// 打印标题
	printf("****************************************\n\n");
	printf("             存储管理部分          \n\n");
	printf("****************************************\n\n");

	// 打印选项
	printf("选择淘汰算法[1]FIFO\t[2]LRU\n> ");

}






/************************************
* Function name : GENERATE_ADDRESS
* Description : 产生指令地址
* Variables : void
************************************/
void GENERATE_ADDRESS(){

	// 清屏
	system("cls");

	// 初始化指令地址序列
	addr = new int[ADDRESS];
	page = new int[ADDRESS];

	// 随机产生若干个0-10240之间的地址数
	RAND_ADDRESS();

	// 显示淘汰算法
	if (ALGORITHM == FIFO){
		printf("【先进先出算法】\n\n");
	}
	else if (ALGORITHM == LRU){
		printf("【最近最久未使用算法】\n\n");
	}

	// 显示指令地址序列
	int i;
	printf("指令地址流：\n");
	for (i = 0; i < ADDRESS; i++){
		printf("%d\t", addr[i]);
		if ((i + 1) % 10 == 0){
			printf("\n");
		}
	}

	// 分割线
	printf("-----------------------------------------------------------\n");

}





/************************************
* Function name : VISIT_LOOP
* Description : 开始循环
* Variables : void
************************************/
void VISIT_LOOP(){

	// 初始化物理块记录链表
	Block = new block;          // 头结点
	Current = new block;
	Current = Block;      // 找到当前结点
	int addr_buf;   // 指令地址缓存
	int page_buf;   // 页号缓存

	// 循环
	for (int i = 0; i < ADDRESS; i++){

		// 访问一个指令地址
		addr_buf = addr[i];

		// 计算该地址所在的页号
		page_buf = addr_buf / PAGE_SIZE;
		page[i] = page_buf;

		// 查看该页是否在主存
		if (ifPageInMemory(page_buf)){

			// 当该页已存在于主存，建立新过程
			block *b = NULL;
			b = new block;

			// 连接过程并复制
			Current->next = b;
			*b = *Current;
			b->next = NULL;

			// 修改变化的物理块的使用时间
			for (int k = 0; k < PAGE_TABLE_LENGTH; k++){
				if (b->pages[k] == page_buf){
					b->changed[k] = i;
				}
			}

			Current = Current->next;

		} // if

		else{

			// 当该页不在主存
			if (ifExistNullBlock()){

				// 当页表存在空闲条款
				block *b = NULL;
				b = new block;

				// 连接过程并复制
				Current->next = b;
				*b = *Current;
				b->next = NULL;

				// 修改页表
				for (int k = 0; k < PAGE_TABLE_LENGTH; k++){
					if (b->pages[k] == -1){
						b->pages[k] = page_buf;  // 放入页表
						b->changed[k] = i;   // 记录修改时间
						b->in[k] = i;   // 记录进入时间
						break;
					}
				}

				Current = Current->next;

			}

			else{

				// 当页表不存在空闲条款，使用淘汰算法
				if (ALGORITHM == FIFO){
					// 先进先出算法
					block *b = NULL;
					b = new block;

					// 连接过程并复制
					Current->next = b;
					*b = *Current;
					b->next = NULL;

					// 找到换出位置
					int index = fifo_findFirstIn();

					// 插入页面
					b->pages[index] = page_buf;  // 放入页表
					b->changed[index] = i;   // 记录修改时间
					b->in[index] = i;   // 记录进入时间
					b->lack = true;     // 确认缺页

					Current = Current->next;
				}
				else if (ALGORITHM == LRU){
					// 最近最久未使用算法
					block *b = NULL;
					b = new block;

					// 连接过程并复制
					Current->next = b;
					*b = *Current;
					b->next = NULL;

					// 找到换出位置
					int index = lru_findLeastUseBlock();

					// 插入页面
					b->pages[index] = page_buf;  // 放入页表
					b->changed[index] = i;   // 记录修改时间
					b->in[index] = i;   // 记录进入时间
					b->lack = true;     // 确认缺页

					Current = Current->next;
				}

				// 缺页加1
				LACKS++;
			}

		} // else

	} // for

}




/************************************
* Function name : RAND_ADDRESS
* Description : 产生随机指令地址序列
* Variables : void
************************************/
void RAND_ADDRESS(){

	// 自动生成随机指令地址模式
	if (AUTO_RANDOM_ADDRESS){

		int n;
		for (int i = 0; i < 20; i++){
			n = rand();
			while (n <= 0 || n >= 10240){
				n = rand() % 10240 + 1;
			}
			addr[i] = n;
		}

	}

	// 指定指令地址模式
	else{

		addr[0] = 312;
		addr[1] = 1025;
		addr[2] = 3346;
		addr[3] = 234;
		addr[4] = 7142;
		addr[5] = 6685;
		addr[6] = 3442;
		addr[7] = 5665;
		addr[8] = 4123;
		addr[9] = 8099;
		addr[10] = 10000;
		addr[11] = 2344;
		addr[12] = 2454;
		addr[13] = 3122;
		addr[14] = 1111;
		addr[15] = 1134;
		addr[16] = 332;
		addr[17] = 3125;
		addr[18] = 5567;
		addr[19] = 3213;

	}

}





/************************************
* Function name : ifPageInMemory
* Description : 查看页是否在主存
* Variables : int page
************************************/
bool ifPageInMemory(int page){

	for (int i = 0; i < PAGE_TABLE_LENGTH; i++){

		if (Current->pages[i] == page)
			// 当发现该页在主存，返回是
			return true;

	}

	// 该页不在任何一个物理块，返回否
	return false;

}





/************************************
* Function name : ifExistNullBlock
* Description : 查看页表是否有空白条款
* Variables : void
************************************/
bool ifExistNullBlock(){

	for (int i = 0; i < PAGE_TABLE_LENGTH; i++){

		if (Current->pages[i] == -1){

			// 当发现空白条款，返回是
			return true;

		}

	}

	// 当没有发现任何空白条款，返回否
	return false;

}






/************************************
* Function name : fifo_findFirstIn
* Description : 先进先出算法查找最先进入的页面
* Variables : void
************************************/
int fifo_findFirstIn(){

	int index = 0;
	int IN = 999;
	for (int i = 0; i < PAGE_TABLE_LENGTH; i++){

		if (Current->in[i] < IN){
			// 找最小值并保存位置
			index = i;
			IN = Current->in[i];
		}

	}

	return index;

}





/************************************
* Function name : lru_findLeastUseBlock
* Description : 最近最久未使用算法找到最少使用的页面
* Variables : void
************************************/
int lru_findLeastUseBlock(){

	int index = 0;
	int USE = 999;
	for (int i = 0; i < PAGE_TABLE_LENGTH; i++){

		if (Current->changed[i] < USE){
			// 找最小值并保存位置
			index = i;
			USE = Current->changed[i];
		}

	}

	return index;

}





/************************************
* Function name : PRINT_BLOCKS
* Description : 最近最久未使用算法找到最少使用的页面
* Variables : void
************************************/
void PRINT_BLOCKS(){

	// 竖向打印
	block *cur = NULL;
	cur = Block;
	int n = 1;
	while (cur->next){
		printf("[%d]\t地址：%8d\t页面：%5d\t主存：%3d%3d%3d\n"
			, n++
			, addr[n - 2]
			, page[n - 2]
			, cur->next->pages[0]
			, cur->next->pages[1]
			, cur->next->pages[2]);
		cur = cur->next;
	}

	// 计算缺页率
	double lackRate = (double)LACKS / 20.0;

	// 显示缺页率
	printf("\n\n缺页率：%lf", lackRate);

	// 提示继续
	string aaa;
	printf("\n任意键以继续...\n");
	cin >> aaa;
}