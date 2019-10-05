/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFourDiag.h
 * Author: EDA BAHRIOGLU 131044055
 *
 * Created on November 23, 2017, 2:08 PM
 */

#ifndef CONNECTFOURDIAG_H
#define CONNECTFOURDIAG_H

#include "ConnectFourAbstract.h"

namespace CONNECTFOUR_HW6
{
	class ConnectFourDiag : public ConnectFourAbstract
	{
		public:
			//ConnectFourDiag constructors
		    ConnectFourDiag();
		    ConnectFourDiag(const ConnectFourDiag& orig);
		    //ConnectFour class assigment
		    ConnectFourDiag& operator=(const ConnectFourDiag& rhs);
		    //ConnectFourDiag class destructor
		    ~ConnectFourDiag();

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
#endif /* CONNECTFOURDIAG_H */

