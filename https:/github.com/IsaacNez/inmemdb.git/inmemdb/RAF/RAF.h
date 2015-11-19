/*
 * RAF.h
 *
 *  Created on: 16 de nov. de 2015
 *      Author: isaac
 */

#ifndef RAF_RAF_H_
#define RAF_RAF_H_
#include <iostream>
#include <fstream>

#include "../Data_Structure/LinkedList.h"
#include "../Register/Register.h"
using namespace std;

class RAF {
public:
	RAF(string pFileName);
	bool Open(string pOpen);
	void Close();
	void ReadRecord(Register& pRecord);
	void WriteRecord(Register& pRecord);
	void SetTable(Register& pRecord);
	void ReadLogicalTable(Register& pRecord);
	virtual ~RAF();
private:
	int _EOF;
	int _Head;
	int _RecordSize;
	string _FileName;
	fstream _File;
};

#endif /* RAF_RAF_H_ */
