#ifndef DSSYSTEM_H
#define DSSYTEM_H

#include"Stack.h"
#include"Link.h"
#include "CCircleQueueh.h"
#include "File.h"

class DSSystem
{

public:
	DSSystem();
	~DSSystem();
	void run(); // 系统的启动函数
	void runChild(); // 系统二级菜单的启动函数
	void Show_second(char*);
	void Show_first();
	void List_handle(int);
	char* Type_info(char*);
private:

	int mDsChoice; // 表示主菜单选择的数据结构
};
  

#endif
