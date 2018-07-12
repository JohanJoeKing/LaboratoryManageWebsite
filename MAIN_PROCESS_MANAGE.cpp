/********************************************************
* - Project name : MyOperateSystem
* - Filename : MAIN_PROCESS_MANAGE.cpp
* - Author : 刘畅
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : 进程管理
* - Others : 石家庄铁道大学信息科学与技术学院
			 计算机科学与技术系
			 班级 - 信1501-1
			 学号 - 20153178
* - Function list :
* - History : 
********************************************************/



/****************************
		 文件引用
****************************/
#include "head_process.h"




/****************************
		 函数声明
****************************/




/************************************
* Function name : MAIN_PROCESS_MANAGE
* Description : 进程管理主函数
* Variables : void
************************************/
void MAIN_PROCESS_MANAGE(){

	// 打印标题
	PROCESS_PRINT_DEFAULT_PANEL();
	TIME = 0;

	// 选择演示
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

	// 进入演示
	if (choice == "1"){
		// 生产者-消费者程序演示
		PRODUCER_CONSUMER_DEMO();
	}
	else if (choice == "2"){
		// 动态优先级调度演示
		string c2;
		printf("\n[1]高响应比算法\n[2]短作业优先\n[3]高优先级优先算法\n> ");
		cin >> c2;
		int k = 0;
		while (k <= 5 && c2 != "1" && c2 != "2" && c2 != "3"){
			k++;
			cin >> c2;
		}
		if (k > 5 && c2 != "1" && c2 != "2" && c2 != "3"){
			// 当指令输入次数超限，退出
			return;
		}
		PROCESS_ALGORITHM = c2;

		// 开始演示
		PROCESS_DEMO();
	}

}





/************************************
* Function name : producer
* Description : 生产者
* Variables : void
************************************/
void producer(){

	while (PRODUCE_TIMES > 0){

		// 当缓冲池已满，则等待片刻再生产
		if (products >= BUF_MAX)
		{
			printf("[提示]\t缓冲池已满，等候片刻\n");
			Sleep(3000);
		}

		// 当缓冲池未满，继续生产
		else
		{
			products++;
			printf("[生产]\t产品数量：%d\n", products);
			Sleep(1300);
		}

		// 控制演示时间
		PRODUCE_TIMES--;
	}

}





/************************************
* Function name : consumer
* Description : 消费者
* Variables : void
************************************/
void consumer(){

	while (PRODUCE_TIMES > 0)
	{

		// 当缓冲池已空，等待消费
		if (products == 0)
		{
			printf("[提示]\t缓冲池已空，等待片刻\n");
			Sleep(2000);
		}

		// 当缓冲池有资源，即刻消费
		else
		{
			products--;
			printf("[消费]\t产品数量：%d\n", products);
			Sleep(2000);
		}
	}

}





/************************************
* Function name : PROCESS_PRINT_DEFAULT_PANEL
* Description : 显示标题
* Variables : void
************************************/
void PROCESS_PRINT_DEFAULT_PANEL(){

	// 清屏
	system("cls");

	// 打印标题
	// 打印标题
	printf("****************************************\n\n");
	printf("             进程管理部分          \n\n");
	printf("****************************************\n\n");

	// 打印选项
	printf("选择演示\n[1]生产者-消费者程序\t[2]动态优先级调度演示\n> ");

}





/************************************
* Function name : PRODUCER_CONSUMER_DEMO
* Description : 生产者-消费者程序演示
* Variables : void
************************************/
void PRODUCER_CONSUMER_DEMO(){

	// 打印标题
	system("cls");
	printf("> 演示：生产者-消费者程序\n\n");

	// 打开多线程
	thread t1(producer);
	thread t2(consumer);
	t1.join();
	t2.join();

}





/************************************
* Function name : PROCESS_DEMO
* Description : 动态优先级调度演示
* Variables : void
************************************/
void PROCESS_DEMO(){

	// 初始化支持项
	PROCESS_DEMO_INIT();

	// 打印标题
	system("cls");
	printf("> 演示：动态优先级调度\n\n");

	// 显示已在就绪队列中的进程
	printf("已在就绪队列中的进程有：");
	showQueue(ready->next);
	printf("\n\n");

	// 显示所有进程情况
	PROCESS_DEMO_PRINT();

	// 确认开始
	printf("任意键以开始...\n");
	string aaa;
	cin >> aaa;

	// 开始调度
	PROCESS_DEMO_LOOP();

}




/************************************
* Function name : PROCESS_DEMO_LOOP
* Description : 动态优先级调度过程
* Variables : void
************************************/
void PROCESS_DEMO_LOOP(){

	// 清屏
	system("cls");

	// 循环调度
	// 当就绪队列和CPU为空时退出
	while (run->next != NULL || ready->next != NULL){

		// 为就绪队列排序
		if (PROCESS_ALGORITHM == HRRN){
			// 最高响应比算法
			rebuildQueueHRRN();
		}
		else if (PROCESS_ALGORITHM == SSTF){
			// 短作业优先
			rebuildQueueByTime();
		}
		else if (PROCESS_ALGORITHM == HPFS){
			// 高优先级优先算法
			rebuildQueue();
		}


		// 队头（最优进程）进入CPU执行
		getInCPU();


		// 打印所有进程信息
		system("cls");
		PROCESS_DEMO_PRINT();

		// CPU执行该进程
		CPU_OPERATE();

		// 时间片增加
		printf("当前时间：%d\n", TIME);
		TIME++;

		// 任意键以继续
		printf("任意键以继续...\n");
		string aaa;
		cin >> aaa;

	} // while

	// 统计平均周转时间和平均带权周转时间
	double avgTime, avgWeightTime;
	double sumTime = 0, sumWeightTime = 0;
	PCB *c = NULL;
	c = finish->next;
	while (c){
		sumTime += ((double)c->finishtime - (double)c->arrive);
		sumWeightTime += ((double)c->needtime / ((double)c->finishtime - (double)c->arrive));
		c = c->next;
	}
	avgTime = sumTime / (double)DEMO_PROCESS;
	avgWeightTime = sumWeightTime / (double)DEMO_PROCESS;

	// 结束提示
	system("cls");
	PROCESS_DEMO_PRINT();
	printf("\n\n所有进程已完成\n");
	printf("平均周转时间：%lf\n平均带权周转时间：%lf\n\n",
		avgTime, avgWeightTime);

	// 任意键以继续
	printf("任意键以继续...\n");
	string aaa;
	cin >> aaa;

}




/************************************
* Function name : PROCESS_DEMO_INIT
* Description : 动态优先级调度演示初始化
* Variables : void
************************************/
void PROCESS_DEMO_INIT(){

	// 初始化三个指针
	ready = NULL;
	run = NULL;
	finish = NULL;
	ready = new PCB;
	run = new PCB;
	finish = new PCB;
	ready->next = NULL;
	run->next = NULL;
	finish->next = NULL;

	// 向就绪队列中插入若干进程
	int nameBuf = 0;      // 进程名称
	int needTimeBuf = 2;  // 进程需要的时间数
	for (int i = 0; i < DEMO_PROCESS; i++){

		// 产生新的PCB
		PCB *n = NULL;
		n = new PCB;

		// 赋值
		n->name = nameBuf++;                  // 进程名称
		n->needtime = needTimeBuf;            // 进程需要时间
		n->prio = PRIO_WEIGHT - needTimeBuf;  // 进程优先级
		needTimeBuf += NEEDTIME_INTERVAL;
		n->arrive = 0;          // 进程到达时间
		n->cputime = 0;         // 进程已使用CPU时间
		n->finishtime = -1;     // 进程完成时间
		n->state = PRO_READY;   // 进程状态
		n->next = NULL;         // next指针为空

		// 插入到就绪队列
		insertIntoReady(n);

	} // for

}





/************************************
* Function name : PROCESS_DEMO_PRINT
* Description : 显示所有进程情况
* Variables : void
************************************/
void PROCESS_DEMO_PRINT(){

	// 打印标题
	printf("---------------------------------------------------\n");
	printf("名称  优先级  需要时间  已用时间  到达时间  结束时间\n");
	printf("---------------------------------------------------\n");

	// 打印运行态进程
	printf("运行态：\n");
	if (run->next != NULL){
		// 运行态有进程
		printf("%3d%9d%9d%9d%9d%9d\n"
			, run->next->name
			, run->next->prio
			, run->next->needtime
			, run->next->cputime
			, run->next->arrive
			, run->next->finishtime);
	}
	else{
		// 无正在运行的进程
		printf("%3c%9c%9c%9c%9c%9c\n"
			, '-', '-', '-', '-', '-', '-');
	}
	printf("---------------------------------------------------\n");

	// 打印就绪态进程
	printf("就绪态：\n");
	if (ready->next != NULL){
		// 有就绪态进程
		PCB *cur = NULL;
		cur = ready->next;

		// 遍历
		while (cur){
			printf("%3d%9d%9d%9d%9d%9d\n"
				, cur->name
				, cur->prio
				, cur->needtime
				, cur->cputime
				, cur->arrive
				, cur->finishtime);
			cur = cur->next;
		}

		// 回收指针
		delete cur;
	}
	else{
		// 无就绪态进程
		printf("%3c%9c%9c%9c%9c%9c\n"
			, '-', '-', '-', '-', '-', '-');
	}
	printf("---------------------------------------------------\n");

	// 打印完成态进程
	printf("完成态：\n");
	if (finish->next != NULL){
		// 有就绪态进程
		PCB *cur = NULL;
		cur = finish->next;

		// 遍历
		while (cur){
			printf("%3d%9d%9d%9d%9d%9d\n"
				, cur->name
				, cur->prio
				, cur->needtime
				, cur->cputime
				, cur->arrive
				, cur->finishtime);
			cur = cur->next;
		}

		// 回收指针
		delete cur;
	}
	else{
		// 无就绪态进程
		printf("%3c%9c%9c%9c%9c%9c\n"
			, '-', '-', '-', '-', '-', '-');
	}
	printf("---------------------------------------------------\n");

}




/************************************
* Function name : insertIntoReady
* Description : 插入进程控制块到就绪队列
* Variables : PCB *p
************************************/
void insertIntoReady(PCB *p){

	// 新建移动指针
	PCB *cur = NULL;

	// 指向就绪队列头
	cur = ready;

	// 寻找就绪队列尾
	while (cur->next){
		cur = cur->next;
	}

	// 链接
	cur->next = p;

	// 修改状态
	p->state = PRO_READY;
	p->next = NULL;

}





/************************************
* Function name : insertIntoFinish
* Description : 插入进程控制块到完成队列
* Variables : PCB *p
************************************/
void insertIntoFinish(PCB *p){

	// 新建移动指针
	PCB *cur = NULL;

	// 指向就绪队列头
	cur = finish;

	// 寻找就绪队列尾
	while (cur->next){
		cur = cur->next;
	}

	// 链接
	cur->next = p;

	// 修改状态
	p->state = PRO_FINISH;
	p->next = NULL;

}




/************************************
* Function name : showQueue
* Description : 遍历队列
* Variables : PCB *p
************************************/
void showQueue(PCB *p){

	// 新建移动指针
	PCB *cur = NULL;

	// 指向队列头
	cur = p;

	// 遍历输出
	while (cur){
		printf("%5d", cur->name);
		cur = cur->next;
	}

}




/************************************
* Function name : rebuildQueue
* Description : 按优先级对队列排序
* Variables : void
************************************/
void rebuildQueue(){

	// 新建伪队列头
	PCB *head = NULL;
	head = new PCB;

	// 替换ready
	head->next = ready->next;

	// ready置空
	ready->next = NULL;

	// 重新插入到ready
	// 当head没有后继时退出
	while (head->next){

		int index;    // 最大优先级进程的名称
		int max = 0;  // 优先级最大值

		// 新建移动指针
		PCB *cur = NULL;
		cur = head->next;

		// 寻找最大优先级进程
		while (cur){
			if (cur->prio > max){
				// 找到比最大值大的进程，记录
				max = cur->prio;
				index = cur->name;
			}
			cur = cur->next;
		}

		// 根据定位再找最大优先级进程，进入ready
		PCB *cur2 = NULL;
		cur2 = head;
		while (cur2){
			if (cur2->next->name == index){
				// 找到最大优先级进程
				PCB *b = NULL;
				b = cur2->next;       // b就是最大优先数进程的PCB
				cur2->next = b->next; // 修改链接
				insertIntoReady(b);   // 插入到ready队列
				b->next = NULL;       // 置空尾结点后继指针
				break;
			}
			else{
				cur2 = cur2->next;
			}
		}

	} // while

}





/************************************
* Function name : rebuildQueueByTime
* Description : 按CPU时间对队列排序
* Variables : void
************************************/
void rebuildQueueByTime(){

	// 新建伪队列头
	PCB *head = NULL;
	head = new PCB;

	// 替换ready
	head->next = ready->next;

	// ready置空
	ready->next = NULL;

	// 重新插入到ready
	// 当head没有后继时退出
	while (head->next){

		int index;        // 最短作业时间进程的名称
		int min = 99999;  // 作业时间最大值

		// 新建移动指针
		PCB *cur = NULL;
		cur = head->next;

		// 寻找最大优先级进程
		while (cur){
			if (cur->cputime < min){
				// 找到比最小值小的进程，记录
				min = cur->cputime;
				index = cur->name;
			}
			cur = cur->next;
		}

		// 根据定位再找最短走也时间进程，进入ready
		PCB *cur2 = NULL;
		cur2 = head;
		while (cur2){
			if (cur2->next->name == index){
				// 找到最大优先级进程
				PCB *b = NULL;
				b = cur2->next;       // b就是最大优先数进程的PCB
				cur2->next = b->next; // 修改链接
				insertIntoReady(b);   // 插入到ready队列
				b->next = NULL;       // 置空尾结点后继指针
				break;
			}
			else{
				cur2 = cur2->next;
			}
		}

	} // while

}




/************************************
* Function name : rebuildQueueHRRN
* Description : 最高响应比算法
* Variables : void
************************************/
void rebuildQueueHRRN(){

	// 新建伪队列头
	PCB *head = NULL;
	head = new PCB;

	// 替换ready
	head->next = ready->next;

	// ready置空
	ready->next = NULL;

	// 重新插入到ready
	// 当head没有后继时退出
	while (head->next){

		int index;       // 最早来的进程的名称
		int max = 0;     // 最大响应比

		// 新建移动指针
		PCB *cur = NULL;
		cur = head->next;

		// 寻找最大优先级进程
		while (cur){
			float wait = (float)TIME - (float)cur->arrive;
			float k = ((float)cur->needtime + wait) / wait;
			if (k > max){
				// 找到比最早时间早的进程，记录
				max = k;
				index = cur->name;
			}
			cur = cur->next;
		}

		// 根据定位再找最早进程，进入ready
		PCB *cur2 = NULL;
		cur2 = head;
		while (cur2){
			if (cur2->next->name == index){
				// 找到最早进程
				PCB *b = NULL;
				b = cur2->next;       // b就是最大优先数进程的PCB
				cur2->next = b->next; // 修改链接
				insertIntoReady(b);   // 插入到ready队列
				b->next = NULL;       // 置空尾结点后继指针
				break;
			}
			else{
				cur2 = cur2->next;
			}
		}

	} // while
}




/************************************
* Function name : getInCPU
* Description : 队头进入CPU
* Variables : void
************************************/
void getInCPU(){

	// 当ready为空，退出
	if (ready->next == NULL){
		return;
	}

	// 当run为空
	if (run->next == NULL){
		// run指针指向队头结点
		run->next = ready->next;

		// ready头指针后移
		ready->next = run->next->next;

		// 修改状态
		run->next->state = PRO_RUN;
	}

	// 当run不为空，先将换出的进程插入就绪队列，再进入CPU
	else{
		// 高响应比算法
		if (PROCESS_ALGORITHM == HRRN){
			float w1 = (float)TIME - (float)run->next->arrive;
			float w2 = (float)TIME - (float)ready->next->arrive;
			float k1 = (w1 + (float)run->next->needtime) / w1;
			float k2 = (w2 + (float)ready->next->needtime) / w2;
			if (k1 < k2){
				// 就绪队列作业响应比更高，替换
				insertIntoReady(run->next);
				run->next = NULL;
				getInCPU();
			}
			else{
				// 运行进程更高，退出
				return;
			}
		}

		// 短作业优先算法
		else if (PROCESS_ALGORITHM == SSTF){
			if (run->next->needtime > ready->next->needtime){
				// 就绪队列作业更短，替换
				insertIntoReady(run->next);
				run->next = NULL;
				getInCPU();
			}
			else{
				// 运行进程更短，退出
				return;
			}
		}

		// 高优先级优先算法
		else if (PROCESS_ALGORITHM == HPFS){
			if (run->next->prio < ready->next->prio){
				// 优先级比在运行的进程大，替换
				insertIntoReady(run->next);
				run->next = NULL;
				getInCPU();
			}
			else{
				// 优先级没有在运行的进程大，退出
				return;
			}
		}

	}

}





/************************************
* Function name : CPU_OPERATE
* Description : CPU执行进程
* Variables : void
************************************/
void CPU_OPERATE(){

	// 执行一个时间片，优先级减1
	run->next->prio--;

	// 修改执行时间
	run->next->cputime++;

	// 当进程完毕
	if (run->next->cputime == run->next->needtime){
		// 记录结束时间
		run->next->finishtime = TIME + 1;

		// 进入完成队列
		insertIntoFinish(run->next);

		// 置空run
		run->next = NULL;
	}

}