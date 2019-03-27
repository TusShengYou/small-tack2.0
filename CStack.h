#ifndef STACK_H
#define STACK_H
class CStack
{
public:
	// CStack() CStack(int)
	CStack(int) ;
	CStack();// 构造函数，给对象成员变量进行初始化
	// 拷贝构造对象 默认做的是浅拷贝
	CStack(const CStack &src);
	// 赋值重载函数  stack1 = stack1
	void operator=(const CStack &src);
	~CStack() ;// 析构函数，释放对象
	void push(int val) ;// 入栈
	void pop() ;// 出栈
	int top();
	bool full() ;
	bool empty();
	void show();
	void search(int val);
	static CStack* getMstack();
private:
	int *mpstack; // 存储栈的数据
	int mtop; // 表示栈顶下标
	int msize; // 表示栈的总长度

	static CStack *mstack;
	void resize();
	friend class CFile;
	friend class DSSystem;
};

#endif
