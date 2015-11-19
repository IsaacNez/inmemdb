/*
 * RAF.cpp
 *
 *  Created on: 16 de nov. de 2015
 *      Author: isaac
 */

#include "RAF.h"

RAF::RAF(string pFileName) {
	// TODO Auto-generated constructor stub
	_FileName = pFileName;

}

bool RAF::Open(string pOpen){
	if (pOpen == "append"){
		_File.open(_FileName.c_str(), ios::in | ios::out | ios::app | ios::binary);
	}
	if (pOpen == "create"){
		_File.open(_FileName.c_str(), ios::in | ios::out | ios::trunc | ios::binary);
	}
	return (_File ? true : false);
}

void RAF::Close(){
	_File.clear();
	_File.close();
}

void RAF::WriteRecord(Register& pRecord){
	_File.clear();
	_File.seekg(0,ios::end);
	pRecord.WriteRecord(_File);

}

void RAF::ReadRecord(Register& pRecord){
	_File.clear();
	pRecord.ReadRecord(_File);
}

void RAF::SetTable(Register& pRecord){
	_File.clear();
	pRecord.WriteLogicalTable(_File);
}

void RAF::ReadLogicalTable(Register& pRecord){
	_File.clear();
	pRecord.ReadLogicalTable(_File);
	_RecordSize = pRecord.getTamRegister();
}
RAF::~RAF() {
	// TODO Auto-generated destructor stub
}

