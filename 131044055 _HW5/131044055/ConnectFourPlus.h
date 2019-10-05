/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFourPlus.h
 * Author: EDA BAHRIOGLU 131044055
 *
 * Created on November 23, 2017, 2:07 PM
 */

#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H

#include "ConnectFourAbstract.h"

namespace CONNECTFOUR_HW6
{
	class ConnectFourPlus : public ConnectFourAbstract
	{
		public:
			//ConnectFourPLus class constructors
			ConnectFourPlus();
			ConnectFourPlus(const ConnectFourPlus& orig);
			//ConnectFourPLus class assigment operator
			ConnectFourPlus& operator=(const ConnectFourPlus& rhs);
			//ConnectFour destructor
			~ConnectFourPlus();

			//Yatay haretin yapildigi ve yatay 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			void rightMove(int &col)const;
			//Dikey haretin yapildigi ve dikey 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			void downMove(int &col)const;
			//Soldan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			void crossLeftMove(int &col)const;
			//Sagdan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			void crossRightMove(int &col)const;
			//Undo hareti icin her hamleyi bir undo dosyasina kaydeder.
			void undoSaveFunc();
			//Undo hareketi icin her hamleyi undo dosyasindan alir.
			void undoLoadFunc();
	};
}
#endif /* CONNECTFOURPLUS_H */

