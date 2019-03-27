#include<iostream>
using namespace std;
#include"DSSystem.h"

	DSSystem::DSSystem()
	{
		
	}
	DSSystem::~DSSystem()
	{
	
	}
	void DSSystem::run() // 系统的启动函数
	{
		// 1.加载文件中的数据
		cout<<"文件加载中。。。"<<endl;
		CFile::getMCfile()->loadfile();
		// 2.显示主菜单
		while(1)
		{
			Show_first();
			cin >> mDsChoice;

			switch (mDsChoice)
			{
			case 1:
			case 2:
			case 3:
				runChild();
				break;
			case 4:
				cout << "保存数据中...";
				// 保存数据，写入文件
			CFile::getMCfile()->savefile();

				cout << "保存成功！欢迎下次使用！" << endl;
				return;
			}
		}
	}

	void DSSystem::Show_first()
	{
		cout << "-------------" << endl;
		cout << "1.单链表" << endl;
		cout << "2.栈" << endl;
		cout << "3.队列" << endl;
		cout << "4.退出系统" << endl;
		cout << "-------------" << endl;
		cout << "请选择:";
	}
	void DSSystem::Show_second(char *str)
	{
		cout << "-------------" << endl;
		cout << "当前选择的数据结构是:" << str << endl;
		cout << "1.查看" << endl;
		cout << "2.增加" << endl;
		cout << "3.删除" << endl;
		cout << "4.查询" << endl;
		cout << "5.返回" << endl;
		cout << "-------------" << endl;
		cout << "请选择:";
	}

	void DSSystem::List_handle(int choice)
	{
		int n=0;
		if(mDsChoice == 1)
		{
			Link *plink=Link::getMlink();
			switch (choice)
			{
			case 1:  
				plink->show();
			    break;
			case 2: 
				cout<<"请输入要增加的数据：  ";
				cin>>n;
				cout<<endl;
	        	plink->insertTail(n);
				break;
			case 3:
				cout<<"请输入要删除的数据：  ";
			    cin>>n;
				cout<<endl;
				plink->remove(n);
				break;
			case 4:
				cout<<"请输入要查询的数据：";
				cin>>n;
				cout<<endl;
				plink->search(n);
			case 5:
				return ;
			default:
				break;
			}
		}
		else if(mDsChoice==2)
		{
			CStack *pstack=CStack::getMstack();
			switch (choice)
			{
			case 1:  
				pstack->show();
			    break;
			case 2: 
				cout<<"请输入要增加的数据：  ";
				cin>>n;
				cout<<endl;
				pstack->push(n);
				break;
			case 3:			
				cout<<endl;
				pstack->pop();
				break;
			case 4:
				cout<<"请输入要查询的数据：";
				cin>>n;
				cout<<endl;
				pstack->search(n);
			case 5:
				return ;
			default:
				break;
			}
		}
	else 
		{
			CCircleQueue *pCircle=CCircleQueue::getMcricle();
			switch (choice)
			{
			case 1:  
				pCircle->show();
			    break;
			case 2: 
				cout<<"请输入要增加的数据：  ";
				cin>>n;
				cout<<endl;
				pCircle->addQue(n);
				break;
			case 3:			
				pCircle->delQue();
				break;
			case 4:
				cout<<"请输入要查询的数据：";
				cin>>n;
				cout<<endl;
				pCircle->search(n);
			case 5:
				return ;
			default:
				break;
			}
		}
	}

	char * DSSystem::Type_info(char *str)
	{
		if(mDsChoice==1)
		{
			str="单链表";
		}
		else if(mDsChoice==2)
		{
			str="栈";
		}
		else
		{
			str="队列";
		}
		return str;
	}
	void DSSystem::runChild() // 系统二级菜单的启动函数
	{
		int choice = 0;
		char *str="";
	
		Show_second(Type_info(str));

		cin >> choice;
		 List_handle(choice);
		
	}


  
