#ifndef LINK_H
#define LINK_H

class Link
{
public:
	Link(); // 构造函数

	~Link() ;// 析构函数

	void insertHead(int val);

	void insertTail(int val);

	void remove(int val) ;// 删除所有值为val的节点

	void show();

	void search(int val);
	
	friend class CFile;
	friend class DSSystem;
	
	static Link* getMlink();
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
	
	static Link *mLink;
	Node *mphead;
};

#endif
