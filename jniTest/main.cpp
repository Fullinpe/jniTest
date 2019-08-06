#include <iostream>
#include "SerialPort.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

using namespace std;

int x = 0;

int main()
{
	CSerialPort *mySerialPort=new CSerialPort();

	if (!mySerialPort->InitPort(5))
		std::cout << "initPort fail !" << std::endl;
	else
		std::cout << "initPort success !" << std::endl;

	if (!mySerialPort->OpenListenThread())
		std::cout << "OpenListenThread fail !" << std::endl;
	else
		std::cout << "OpenListenThread success !" << std::endl;

	//if (!mySerialPort->WriteData((unsigned char*)"12323566\n", 9))
	//	std::cout << "WriteData fail !" << std::endl;
	//else
	//	std::cout << "WriteData success !" << std::endl;

	while (1)
		if(_getch()==27)
			x=0;

	if (!mySerialPort->CloseListenThread())
		std::cout << "CloseListenTread fail !" << std::endl;
	else
		std::cout << "CloseListenTread success !" << std::endl;

	system("pause");
	return 0;

}

void Rx_handler(UCHAR rx)
{
	//cout << rx << endl;
	x++;
	//cout << x;
	cout << x<<endl;
	//printf_s("%02X ", rx);

}