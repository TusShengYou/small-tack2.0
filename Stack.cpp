#include<iostream>
using namespace std;
#include"Stack.h"

CStack* CStack::mstack=NULL;

CStack* CStack::getMstack()
{
	if(mstack==NULL)
	{
		mstack=new CStack(10);
	}
	return mstack;
}
	// CStack() CStack(int)
void CStack::show()
{
	for(int i=0;i<mtop;i++)
	{
		cout<<mpstack[i]<<"  ";
	}
	cout<<endl;
}
	void CStack::search(int val)
	{
		int i=0;
		for(i=0;i<mtop;i++)
		{
			if(mpstack[i]==val)
			{
			
				cout<<"该值位于："<<i<<endl;
				break;
			}
		}
		if(i==mtop)
		{
			cout<<"不存在"<<endl;
		}
	}
	CStack::CStack(int size = 10) // 构造函数，给对象成员变量进行初始化
	{
		mtop = 0;
		msize = size;
		mpstack = new int[msize];
	}
	CStack::CStack()
	{
		mtop = 0;
		msize = 10;
		mpstack = new int[10];
	}
	// 拷贝构造对象 默认做的是浅拷贝
	CStack::CStack(const CStack &src)
	{
		
		mpstack = new int[src.msize];
		for (int i = 0; i < src.msize; ++i)
		{
			mpstack[i] = src.mpstack[i];
		}
		mtop = src.mtop;
		msize = src.msize;
	}
	// 赋值重载函数  stack1 = stack1
	void CStack::operator=(const CStack &src)
	{
		cout << "operator=" << endl;

		// 防止自赋值
		if (this == &src)
			return;

		// 先释放this指向对象现有的外部资源
		delete[]mpstack;

		// 根据src引用的对象资源尺寸，重新开辟空间，拷贝数据
		mpstack = new int[src.msize];
		for (int i = 0; i < src.msize; ++i)
		{
			mpstack[i] = src.mpstack[i];
		}
		mtop = src.mtop;
		msize = src.msize;
	}
	CStack::~CStack() // 析构函数，释放对象
	{

		delete[]mpstack;
		mpstack = nullptr;
	}
	void CStack::push(int val) // 入栈
	{
		if (full())
			resize();
		mpstack[mtop++] = val;
	}
	void CStack::pop() // 出栈
	{
		if (empty())
		{
			cout<<"栈为空"<<endl;
			return;
		}
			--mtop;
		cout<<"出栈成功"<<endl;
	}
	int CStack::top()
	{
		if (empty())
			throw "stack is empty!";
		return mpstack[mtop-1];
	}
	bool CStack::full() { return mtop == msize; }
	bool CStack::empty() { return mtop == 0; }



	void CStack::resize()
	{
		int *ptmp = new int[msize * 2];
		//memcpy(ptmp, mpstack, sizeof(int)*msize);
		//realloc  对象扩容禁止使用realloc/memcpy这些函数!!!
		for (int i = 0; i < msize; ++i)
		{
			ptmp[i] = mpstack[i];
		}
		delete []mpstack;
		mpstack = ptmp;
		msize *= 2;
	}














#if 0
const int inc=2;
class Stack
{ 
public:
	Stack(int size=10)
	{
		mpstack=new int[sizeof(int)*size];
        mtop=0;
		msize=size;
	}

	Stack(const Stack &src)
	{
		mpstack=new int[src.msize];
		for(int i=0;i<src.msize;++i)
		{
			mpstack[i]=src.mpstack[i];
		}
		mtop=src.mtop;
		msize=src.msize;
	}

	void operator=(const Stack &src)
	{
		if(this==&src)
			return ;    //防止自赋值
		delete[]mpstack;//释放自身空间
			mpstack=new int[src.msize];//进行深拷贝
		for(int i=0;i<src.msize;++i)
		{
			mpstack[i]=src.mpstack[i];
		}
		mtop=src.mtop;
		msize=src.msize;
	}
	~Stack()
	{
			delete[] mpstack;
			mpstack=nullptr;
	}

	void push(int val)
	{
		if(full())
			resize();
		mpstack[mtop]=val;
		msize++;
		mtop++;
	}
	void pop()
	{
		if(empty())
		   throw "stack is empty";
		mtop--;
		msize--;
	}
	int top()
	{
		if(empty())
			throw "stack is empty";
		return mpstack[mtop-1];
	}
	bool full()
	{
		return mtop==msize;
	}
	bool empty()
	{
		return mtop==0;
	}
private:
	int *mpstack;
	int mtop;                                                                                                                                                                                                                                                                                                             
	int msize;
	

	void  resize()
	{
		int *newmps=new int [msize*inc];
		for(int i=0;i<msize;i++)
		{
			newmps[i]=mpstack[i];
		}
		delete[]mpstack;
	    mpstack=newmps;
	   msize=msize*inc;
	}

};
#endif

