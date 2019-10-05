#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cmath>

#include "ConnectFourPlus.h"
#include "ConnectFourDiag.h"
#include "ConnectFourPlusUndo.h"

using namespace CONNECTFOUR_HW6;
using namespace CELL_HW6;
using namespace std;

int main() 
{
	ConnectFourPlus y;//ConnectFourPlus obje
	ConnectFourDiag x;//ConnectFourDiag obje
	ConnectFourPlusUndo z;//ConnectFourPLusUndo obje

	char mode;
	cout<<"Please change a mode"<<endl;
	cin>>mode;
	if(mode == 'D')
	{
		x.playGame();
	}
	else if(mode == 'P')
	{
		y.playGame();
	}
	else if(mode == 'U')
	{
		z.playGame();
	}

	return 0;
}
