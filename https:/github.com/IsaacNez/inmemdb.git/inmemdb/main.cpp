/*
 * main.cpp
 *
 *  Created on: 16 de nov. de 2015
 *      Author: isaac
 */
#include "Data_Structure/LinkedList.h"
#include "Register/Register.h"
#include "RAF/RAF.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	LinkedList<string>* data = new LinkedList<string>();
	LinkedList<int>* type = new LinkedList<int>();
	data->insertData("Celular");
	type->insertData(1);
	data->insertData("Nombre");
	type->insertData(3);
	data->insertData("Recibo");
	type->insertData(3);
	/**Register* object = new Register(data, type);
	fstream p;
	p.open("example", ios::in | ios::binary | ios::out);
	object->WriteLogicalTable(p);
	object->ReadLogicalTable(p);
	cout << sizeof(long) << endl;*/
	RAF random("example");
	if (random.Open("create")){
		Register record(data, type);
		random.SetTable(record);
		random.ReadLogicalTable(record);
	}
	random.Close();


}



