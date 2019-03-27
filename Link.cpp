#include<iostream>
using namespace std;
#include"Link.h"

Link * Link::mLink=NULL;
	Link::Link() // 构造函数
	{
		mphead = new Node(); // new Node;
	}
	Link* Link :: getMlink()
	{
		if(mLink==NULL)
		{
			mLink=new Link( );
		}
		return mLink;
	}
	Link::~Link() // 析构函数
	{
		Node *pcur = mphead;
		while (pcur != nullptr)
		{
			mphead = mphead->mpnext;
			delete pcur;
			pcur = mphead;
		}
	}
	void Link::insertHead(int val)
	{
		Node *ptmp = new Node(val); // Node node(val);
		ptmp->mpnext = mphead->mpnext;
		mphead->mpnext = ptmp;
	}
	void Link::insertTail(int val)
	{
		Node *pcur = mphead;
		while (pcur->mpnext != nullptr)
		{
			pcur = pcur->mpnext;
		}
		pcur->mpnext = new Node(val);
		cout<<"增加成功"<<endl;
	}
	void Link::remove(int val) // 删除所有值为val的节点
	{
		Node *ppre = mphead;
		Node *pcur = mphead->mpnext;
		 
		int flag=0;

		while (pcur != nullptr)
		{
			if (pcur->mdata == val)
			{
				flag=1;
				ppre->mpnext = pcur->mpnext;
				delete pcur;
				pcur = ppre->mpnext;
			}
			else
			{
				ppre = pcur;
				pcur = pcur->mpnext;
			}
		}
		if(flag==0)
		{
			cout<<"不存在该数"<<endl;
		}
		else
		{
			cout<<"删除成功"<<endl;
		}
	}
	void Link::show()
	{
		Node *pcur = mphead->mpnext;
		while (pcur != nullptr)
		{
			cout << pcur->mdata << " ";
			pcur = pcur->mpnext;
		}
		cout << endl;
	}
	

	void Link::search(int val)
	{
		Node *p=mphead->mpnext;
		while(nullptr!=p)
		{
			if(p->mdata==val)
			{
				cout<<"查询成功"<<endl;
				break;
			}
		}
		if(nullptr==p)
		{
			cout<<"查询失败"<<endl;
		}
	}


	

#if 0
class Link
{
public:
	Link()// 构造函数
	{
		mphead=new Node();
	}
	~Link() // 析构函数
	{
		delete mphead;
		Node *p=mphead;
		while(nullptr!=p)
		{
			Node *q=p;
			p=p->mpnext;
			delete q;
			q=nullptr;
		}
		
	}
	void insertHead(int val)
	{
		Node *p=new Node();
		p->mdata=val;
		p->mpnext=mphead->mpnext; 
		mphead->mpnext=p;
	}
	void insertTail(int val)
	{
		Node *p=new Node();
		p->mdata=val;
		Node *rail=mphead;
		while(nullptr!=rail->mpnext)
		{
			rail=rail->mpnext;
		}
		rail->mpnext=p;
		p=rail->mpnext;
	}
	void remove(int val)
	{
		Node *p=mphead;
		Node *q=mphead->mpnext;
		while(NULL!=p->mpnext)
		{
			if(p->mpnext->mdata==val)
			{
			        p->mpnext = q->mpnext;
				delete q;
				q= p->mpnext;

			}
			else
			{
				p=q;
				q=q->mpnext;
			}
		}
			
	}// 删除所有值为val的节点
	void show()
	{
		Node *p=mphead->mpnext;
		while(nullptr!=p)
		{
			cout<<p->mdata<<"  ";
			p=p->mpnext;
		}
		cout<<endl;
	}
private:
	// 节点类型
	struct Node
	{
		Node(int data = 0)
		{
			mdata = data;
			mpnext = nullptr;
		}
		int mdata;
		Node *mpnext;
	};

	// private化拷贝构造和赋值重载函数
	Link(const Link&);
	void operator=(const Link&);
	Node *mphead;
};
#endif
