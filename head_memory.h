/********************************************************
* - Project name : MyOperateSystem
* - Filename : head_memory.h
* - Author : 刘畅
* - Version : 1.0
* - Start date : 2018/6/26
* - Description : 存储管理头文件
* - Others : 石家庄铁道大学信息科学与技术学院
			 计算机科学与技术系
			 班级 - 信1501-1
			 学号 - 20153178
* - Function list : MEMORY_PRINT_DEFAULT_PANEL
					GENERATE_ADDRESS
					VISIT_LOOP
					RAND_ADDRESS
					ifPageInMemory
					ifExistNullBlock
					fifo_findFirstIn
					lru_findLeastUseBlock
					PRINT_BLOCKS
********************************************************/



/************************************
* Function name :
* Description :
* Variables :
************************************/



/****************************
		 预编译指令
****************************/
#include "head.h"
#include <cstdlib>
#include <ctime>


/****************************
		 结构体说明
****************************/
struct block{
	int pages[3];    // 物理块
	int changed[3];  // 发生变化的时间
	int in[3];       // 进入块时间
	bool lack;     // 是否发生缺页
	block *next;   // next指针

	block(){
		for (int i = 0; i < 3; i++){
			pages[i] = -1;    // -1表示NULL
			changed[i] = -1;  // -1表示未发生过修改
			in[i] = -1;       // -1表示NULL
		}
		lack = false;         // 默认未缺页
		next = NULL;
	}
};



/****************************
		 函数声明
****************************/
void MEMORY_PRINT_DEFAULT_PANEL();
void GENERATE_ADDRESS();
void VISIT_LOOP();
void RAND_ADDRESS();
bool ifPageInMemory(int page);
bool ifExistNullBlock();
int fifo_findFirstIn();
int lru_findLeastUseBlock();
void PRINT_BLOCKS();




/****************************
		 全局变量
****************************/
int ALGORITHM;       // 淘汰算法类型
int *addr;           // 指令地址序列
int *page;           // 对应页面序列
block *Block;        // 物理块的变化记录链表头指针，参与记录
block *Current;      // 当前物理块
int LACKS = 0;       // 发生缺页的次数
const int FIFO = 1;  // 先进先出算法为1
const int LRU = 2;   // 最近最少使用算法为2
const int ADDRESS = 20;   // 产生的地址数量为20个
const int PAGE_SIZE = 1024;   // 页面尺寸
const int PAGE_TABLE_LENGTH = 3;   // 页表长度
const bool AUTO_RANDOM_ADDRESS = true;