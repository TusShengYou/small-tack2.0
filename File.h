#ifndef  FILE_H
#define FILE_H
#include"Stack.h"
#include"Link.h"
#include"CCircleQueueh.h"

class CFile
{
	CFile();
	~CFile();
	static CFile *mCfile;
public:
	 void loadfile();
	 void savefile();
	static CFile* getMCfile();
};

#endif
