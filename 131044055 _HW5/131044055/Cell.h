/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cell.h
 * Author: EDA BAHRIOGLU 131044055
 *
 * Created on November 23, 2017, 2:07 PM
 */

#ifndef CELL_H
#define CELL_H

#include <iostream>

namespace CELL_HW6
{
	class Cell
	{
		public:

			//Cell class constructorlari
			Cell();
			Cell(int rowValue, int columnValue);
			Cell(int rowValue ,int columnValue, char userSymValue);
			void setrow(int const rowValue);
			//cell class setterlari
			void setColumn( int const columnValue);
			void setUserSym(char  const userSymValue);
			//inline getter functions
			inline int getrow()const{ return row;}
			inline int getColumn()const{ return column;}
			inline char getUserSym()const{ return userSymbol;}
			
		private:
			int row;
			int column;
			char userSymbol;
	};
}

#endif /* CELL_H */

