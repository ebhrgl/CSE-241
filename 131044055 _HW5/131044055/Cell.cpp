/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cell.cpp
 * Author: EDA BAHRIOGLU 131044055
 * 
 * Created on November 23, 2017, 2:07 PM
 */

#include "Cell.h"

#include "ConnectFourAbstract.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include<fstream>

using namespace std;
namespace CELL_HW6
{
	Cell::Cell()
	{
		setrow(0);
		setColumn(0);
		setUserSym('.');
	}

	Cell::Cell(int row, int column)
	{
		setrow(row);
		setColumn(column);
		setUserSym('.');
	}

	Cell::Cell(int row ,int column, char userSymbol)
	{
		setrow(row);
		setColumn(column);
		setUserSym(userSymbol);
	}

	void Cell::setrow(const int rowValue)
	{
		if(rowValue<0)
		{
			cerr<<"invalid command"<<endl;
		}
		row = rowValue;

	}
					
	void Cell::setColumn(const int columnValue)
	{
		if(columnValue<0)
		{
			cerr<<"invalid command"<<endl;
		}

		column = columnValue;
	}
					
	void Cell::setUserSym(const char userSymValue)
	{

		userSymbol = userSymValue;

	}

}
