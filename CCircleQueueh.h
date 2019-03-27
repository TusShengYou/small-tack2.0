#include<iostream>
using namespace std;
#include"CCircleQueueh.h"

CCircleQueue* CCircleQueue::mCricle=NULL;

	CCircleQueue::CCircleQueue(int size=10) // 构造函数
	{
		msize = size;
		mfront = mrear = 0;
		mpQue = new int[msize];
	}
		CCircleQueue::CCircleQueue() // 构造函数
	{
		msize = 10;
		mfront = mrear = 0;
		mpQue = new int[10];
	}
CCircleQueue* CCircleQueue::getMcricle()
{
	if(mCricle==NULL)
	{
		mCricle=new CCircleQueue(10);
	}
	return mCricle;
}
	CCircleQueue::~CCircleQueue() // 析构函数
	{
		delete[]mpQue;
		mpQue = nullptr;
	}
	CCircleQueue::CCircleQueue(const CCircleQueue &src) // 拷贝构造函数
	{
		this->mpQue = new int[src.msize];
		for (int i = src.mfront; 
			i != src.mrear; 
			i=(i+1)%src.msize)
		{
			mpQue[i] = src.mpQue[i];
		}
		mfront = src.mfront;
		mrear = src.mrear;
		msize = src.msize;
	}
	void CCircleQueue::operator=(const CCircleQueue &src) // 赋值重载函数
	{
		if (this == &src)
			return;

		delete[]mpQue;

		this->mpQue = new int[src.msize];
		for (int i = src.mfront;
			i != src.mrear;
			i = (i + 1) % src.msize)
		{
			mpQue[i] = src.mpQue[i];
		}
		mfront = src.mfront;
		mrear = src.mrear;
		msize = src.msize;
	}

	void CCircleQueue::addQue(int val) // 入队
	{
		if (full())
			resize();
		mpQue[mrear] = val;
		mrear = (mrear + 1) % msize;
	}
	void CCircleQueue::delQue() // 出队
	{
		if (empty())
			return;
		mfront = (mfront + 1) % msize;
	}
	int CCircleQueue::front() // 返回队头元素
	{
		return mpQue[mfront];
	}
	int CCircleQueue::back() // 返回队尾元素
	{
		return mpQue[(mrear-1+msize)%msize];
	}
	bool CCircleQueue::full() { return (mrear + 1) % msize == mfront; } // 判满
	bool CCircleQueue::empty() { return mrear == mfront; } // 判空

	void CCircleQueue::resize() // 2倍扩容循环队列
	{
		int *ptmp = new int[msize * 2];
		int j = 0;
		for (int i = mfront;
			i != mrear;
			i = (i + 1) % msize, j++)
		{
			ptmp[j] = mpQue[i];
		}
		delete[]mpQue;
		mpQue = ptmp;
		mfront = 0;
		mrear = j;
		msize *= 2;
	}

	void CCircleQueue::show()
	{
		for(int i=mfront;i<mrear;i++)
		  {
			  cout<<mpQue[i]<<" " ;
		  }
		  cout<<endl;
	}
	void CCircleQueue::search(int val)
	{
		int flag=0;
		for(int i=0;i<mrear;i++)
		{
			if(mpQue[i]==val)
			{
				flag=1;
				cout<<"查询成功"<<endl;
				break;
			}
		}

		if(!flag)
		{
			cout<<"查询失败"<<endl;
		}

	}



#if 0
class CCircleQueue
{
public:
	CCircleQueue(int size=10)
	{
		mpQue=new int[size];
		mfront=0;
		mrear=0;
		msize=size;
	}
	~CCircleQueue()
	{
		delete[]mpQue;
		mpQue=nullptr;

	}// 析构函数
	CCircleQueue(const CCircleQueue &src)
	{
		mpQue=new int[src.msize];
		for(int i=src.mfront;i<src.msize;i=(i+1)%src.msize)
		{
			mpQue[i]=src.mpQue[i];
		}
		mfront=src.mfront;
		mrear=src.mrear;
		msize=src.msize;
	}// 拷贝构造函数
	void operator=(const CCircleQueue &src)
	{
		if(this==&src )
			return ;
		delete[]mpQue;
		mpQue=new int[src.msize];
		for(int i=src.mfront;i<src.msize;i=(i+1)%src.msize)
		{
			mpQue[i]=src.mpQue[i];
		}
		mfront=src.mfront;
		mrear=src.mrear;
		msize=src.msize;
	}
		// 赋值重载函数

	void addQue(int val)
	{
		if(full())
		 resize();
		mpQue[mrear]=val;
		mrear=(mrear+1)%msize;

	}// 入队
	void delQue()
	{
		if(empty())
			throw "is empty";
		mfront=(mfront+1)%msize;
	}// 出队
	int front()
	{
		return mpQue[mfront];
	}// 返回队头元素
	int back()
	{
		return mpQue[(mrear-1+msize)];
	}// 返回队尾元素

	bool full()
	{
		return (mrear+1)%msize==mfront;
	}// 判满
	bool empty()
	{
		return (mrear+1)%msize==mfront;
	}// 判空

private:
	int *mpQue; //保存队列元素的数据结构
	int mfront; //队头下标
	int mrear; //队尾下标
	int msize; //扩容的总长度

	void resize()
	{
		int *newQ=new int[msize*2];
		int j=0;
		for(int i=mfront;i!=mrear;i=(i+1)%msize,j++)
		{
			newQ[j]=mpQue[i];
		}
		delete[]mpQue;
		mpQue=newQ;
		mfront=0;
		mrear=j;
		msize=msize*2;
	}// 2倍扩容循环队列
};


#endif



