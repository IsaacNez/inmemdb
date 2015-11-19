/*
 * Register.cpp
 *
 *  Created on: 15 de nov. de 2015
 *      Author: isaac
 */

#include "Register.h"
using namespace std;
Register::Register(LinkedList<string>* pData, LinkedList<int>* pDataType) {
	// TODO Auto-generated constructor stub
	_ColumnName = new LinkedList<string>();
	_Data = new LinkedList<string>();
	_DataType = new LinkedList<int>();
	this->_Data = pData;
	this->_DataType = pDataType;
	this->_QuantityData = _Data->getLen();
	this->_TamRegister = _QuantityData*_SizeOfObjects;
}

Register::~Register() {
	// TODO Auto-generated destructor stub
}

LinkedList<string>* Register::getColumnName(){
	return _ColumnName;
}

void Register::setColumnName(LinkedList<string>* columnName) {
	_ColumnName = columnName;
}

LinkedList<string>* Register::getData(){
	return _Data;
}

void Register::setData(LinkedList<string>* data) {
	_Data = data;
}

LinkedList<int>* Register::getDataType(){
	return _DataType;
}

void Register::setDataType(LinkedList<int>* dataType) {
	_DataType = dataType;
}

int Register::getQuantityData(){
	return _QuantityData;
}

void Register::setQuantityData(int quantityData) {
	_QuantityData = quantityData;
}

int Register::getTamRegister(){
	return _TamRegister;
}

void Register::setTamRegister(int tamRegister) {
	_TamRegister = tamRegister;
}

void Register::ReadRecord(fstream& pFile){
	char Record[_TamRegister];
	pFile.read(Record, _TamRegister);
	for (int i = 0; i < _QuantityData; i++){
		string recordData = "";
		for(int j = 0; j < _SizeOfObjects; j++){
			if (Record[(i*_SizeOfObjects+j)] != NULL){
				recordData += Record[(i*_SizeOfObjects+j)];

		}
		//_Data->insertData(recordData);

	}
		cout << recordData << endl;
	}

}

void Register::WriteRecord(fstream& pFile){
	char Record[_TamRegister];
	for(int i = 0; i < _QuantityData; i++){
		string str = _Data->getDatabyIndex(i);
		cout << str << endl;
		int lenghtstr = str.length();
		for (int j = 0; j < _SizeOfObjects; j++){
			if(j < lenghtstr){
				Record[(i*_SizeOfObjects+j)] = str[j];
				cout << str[j] << endl;
				continue;
			}
			Record[(i*_SizeOfObjects+j)] = NULL;
		}
	}
	pFile.clear();
	pFile.write(Record, _TamRegister);
}

void Register::WriteLogicalTable(fstream& pFile){
	char Record[_TamRegister];
	for(int i = 0; i < _QuantityData; i++){
		string str = _Data->getDatabyIndex(i);
		cout << str << endl;
		int lenghtstr = str.length();
		for (int j = 1; j < _SizeOfObjects; j++){
			if(j -1< lenghtstr){
				Record[(i*_SizeOfObjects+j)] = str[j-1];
				cout << str[j] << endl;
				continue;
			}
			Record[(i*_SizeOfObjects+j)] = NULL;
		}
		if (_DataType->getDatabyIndex(i) == 1)
			Record[i*_SizeOfObjects] = '1';
		if (_DataType->getDatabyIndex(i) == 2)
			Record[i*_SizeOfObjects] = '2';
		if (_DataType->getDatabyIndex(i) == 3)
			Record[i*_SizeOfObjects] = '3';
	}
	Record[_TamRegister-1] = '/';
	pFile.clear();
	pFile.write(Record, _TamRegister);
}

void Register::ReadLogicalTable(fstream& pEntrada){
	/**pFile.clear();
	pFile.seekg(0);
	LinkedList<int>* type = new LinkedList<int>();
	bool flag = true;
	for (int i = 0; i < _QuantityData; i++ ){
		char Columna[_TamRegister];
		pFile.read(Columna, _TamRegister);
		if (Columna[i*_SizeOfObjects] == '1')
			type->insertData(1);
		if (Columna[i*_SizeOfObjects] == '2')
			type->insertData(2);
		if (Columna[i*_SizeOfObjects] == '3')
			type->insertData(3);
		string str = "";
		if(Columna[i*_SizeOfObjects] != NULL){
			for(int j = 1; j < _SizeOfObjects; j++){
				if (Columna[i*_SizeOfObjects+j] != NULL){
					str += Columna[i*_SizeOfObjects+j];
				}else{
					_ColumnName->insertData(str);
					break;
				}
			}
			str = "";
		}
	}*/
	pEntrada.clear();
	    pEntrada.seekg(0);//Coloca puntero de lectura al inicio del archivo
	    bool flag = true;

	    /*Lee columna por columna desde el archivo, luego se carga a un vector
	     * Tambien se carga el tipo de dato de cada columna*/
	    while(flag){
	        //Carga el tipo de dato de la columna
	        char nombre[_SizeOfObjects];
	        pEntrada.read(nombre, _SizeOfObjects);//Lee del archivo el nombre de la columna
	        if (nombre[0] == '1'){
	            _DataType->insertData(1);
	        }
	        if (nombre[0] == '2'){
	        	_DataType->insertData(2);
	        }
	        if (nombre[0] == '3'){
	        	_DataType->insertData(3);
	        }
	        //Carga el nombre de la columna
	        string str = "";
	        for (int i=1;i<_SizeOfObjects;i++){
	            if (nombre[i]!=NULL){
	            	if(nombre[i] != '/'){
	                    str+=nombre[i];

	                }
	                else{
	                    flag = false;
	                    break;
	                }
	            }

	        }
	        _ColumnName->insertData(str);
	        cout << str << endl;
	        str = "";
	    }
	    _QuantityData = _ColumnName->getLen();
	    _TamRegister = _SizeOfObjects*_QuantityData;

}


void Register::EraseRecord(fstream& pFile){
	char RecordToErase[_TamRegister];
	for(int i = 0; i < _TamRegister; i++)
		RecordToErase[i] == NULL;
	pFile.clear();
	pFile.write(RecordToErase, _TamRegister);

}































