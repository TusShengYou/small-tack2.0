#ifndef  CCIRCLE_H
#define CCIRCLE_H

class CCircleQueue
{
	private:
	int *mpQue; //保存队列元素的数据结构
	int mfront; //队头下标
	int mrear; //队尾下标
	int msize; //扩容的总长度
	static CCircleQueue* mCricle;

	void resize(); // 2倍扩容循环队列
public:
	CCircleQueue(int); 
	CCircleQueue();// 构造函数
	~CCircleQueue() ;// 析构函数
	CCircleQueue(const CCircleQueue &src) ;// 拷贝构造函数
	void operator=(const CCircleQueue &src) ;// 赋值重载函
	void addQue(int val) ;// 入队
	void delQue() ;// 出队
	int front() ;// 返回队头元素
	int back(); // 返回队尾元素
	bool full() ;// 判满
	bool empty() ; // 判空
	void show();
	void search(int val);
	static CCircleQueue*getMcricle();
	friend class CFile;
	friend class DSSystem;


};
#endif
