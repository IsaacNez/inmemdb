/*
 * Register.h
 *
 *  Created on: 15 de nov. de 2015
 *      Author: isaac
 */

#ifndef REGISTER_H_
#define REGISTER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../Data_Structure/LinkedList.h"

using namespace std;

const int _SizeOfObjects = 64;

class Register {
public:
	Register(LinkedList<string>* pData, LinkedList<int>* pDataType);
	virtual ~Register();

	//--- Getters AND Setters---//
	LinkedList<string>* getColumnName();
	void setColumnName(LinkedList<string>* columnName);
	LinkedList<string>* getData();
	void setData(LinkedList<string>* data);
	LinkedList<int>* getDataType();
	void setDataType(LinkedList<int>* dataType);
	int getQuantityData();
	void setQuantityData(int quantityData);
	int getTamRegister();
	void setTamRegister(int tamRegister);

	//---Methods---//
	void ReadRecord(fstream& pFile);
	void WriteRecord(fstream& pFile);
	void WriteLogicalTable(fstream& pFile);
	void ReadLogicalTable(fstream& pFile);
	void EraseRecord(fstream& pFile);

private:
	LinkedList<string>* _ColumnName;
	LinkedList<string>* _Data;
	LinkedList<int>* _DataType;
	int _TamRegister;
	int _QuantityData;

};

#endif /* REGISTER_H_ */
