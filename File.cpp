#include<iostream>
using namespace std;
#include"File.h"
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

CFile *CFile :: mCfile=NULL;

CFile::CFile()
{}
CFile::~CFile()
{}
CFile* CFile::getMCfile()
{
	if(mCfile==NULL)
		mCfile=new CFile();
	return mCfile;
}
void CFile::loadfile()
{
	CStack *stack_f=CStack::getMstack();
	Link *link_f=Link::getMlink();
	CCircleQueue *queue_f=CCircleQueue::getMcricle();
    FILE *fp1;

	if((fp1=fopen("E:\\Desktop\\dataStack.txt","r"))==NULL)
	{
		printf("open file is error!\n");
		return;
	}
	
   int data=0;

   while(fscanf(fp1,"%d",&data)!=EOF)
   {
	   stack_f->push(data);
   }
	  fclose(fp1);

    FILE *fp2;
	if((fp2=fopen("E:\\Desktop\\dataLink.txt","r"))==NULL)
	{
		printf("open file is error!\n");
		return;
	}

   while(fscanf(fp2,"%d",&data)!=EOF)
   {
	   link_f->insertTail(data);
   }

   fclose(fp2);

    FILE *fp3;
	if((fp3=fopen("E:\\Desktop\\dataCircle.txt","r"))==NULL)
	{
		printf("open file is error!\n");
		return;
	}

	while(fscanf(fp3,"%d",&data)!=EOF)
   {
	     queue_f->addQue(data);
   }

   fclose(fp3);

  
   cout<<"加载文件成功"<<endl;
}

void CFile::savefile()
{
	CStack *stack_f=CStack::getMstack();
	Link *link_f=Link::getMlink();
	CCircleQueue *queue_f=CCircleQueue::getMcricle();

    FILE *fp1;

	if((fp1=fopen("E:\\Desktop\\dataStack.txt","w"))==NULL)
	{
		printf("open file is error!\n");
		return;
	} 
	for(int i=0;i<stack_f->mtop;i++)
	{
		fprintf(fp1,"%d ",stack_f->mpstack[i]);
		//fwrite(&(stack_f->mpstack[i]),sizeof(int),1,fp1);
	}
	fclose(fp1);

	 FILE *fp2;
	if((fp2=fopen("E:\\Desktop\\dataLink.txt","w"))==NULL)
	{
		printf("open file is error!\n");
		return;
	}

     Link::Node *pcur = link_f->mphead->mpnext;
		while (pcur != nullptr)
		{
			fprintf(fp2,"%d ",pcur->mdata);
			pcur = pcur->mpnext;
		}
		fclose(fp2);

	 FILE *fp3;
	if((fp3=fopen("E:\\Desktop\\dataCircle.txt","w"))==NULL)
	{
		printf("open file is error!\n");
		return;
	}
	for(int i=queue_f->mfront;i<queue_f->mrear;i++)
	{
		fprintf(fp3,"%d ",queue_f->mpQue[i]);
	}
	fclose(fp3);

}
		

