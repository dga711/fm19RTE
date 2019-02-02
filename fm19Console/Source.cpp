#include <iostream>
#include <Windows.h>
#include "GameVersions.h"
#include "Helpers.h"

using namespace std;

//Current team setting
unsigned int currentMoney;

//Change team setting
int newMoney;

int main() {
	SetConsoleTitle(L"FM19 REAL EDITOR");
	About();
	HANDLE phandle = GameLoad(windowName);

	CurrentMemory currentMoney = FindDmaAddy(phandle, moneyAddress, moneyOffsets, 5);
	cout << "currentMoney value: " << currentMoney.currentValue << endl;
	cout << "Please enter an new money value: ";
	cin >> newMoney;


	int isWriteProcess = WritePointer(phandle, moneyAddress, newMoney, moneyOffsets, 5);
	if (!isWriteProcess) {
		std::cerr << "Couldn't write process memory:" << GetLastError() << std::endl;
		getchar();
	}
	cout << "changed money : " << newMoney <<endl;

	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");


	return ERROR_SUCCESS;
}



