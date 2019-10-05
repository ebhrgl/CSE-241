/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFourPlusUndo.h
 * Author: EDA BAHRIOGLU 131044055
 *
 * Created on November 23, 2017, 2:08 PM
 */

//ConnectfourPLus sinifindan türetilmis siniftir.Yatay ve dikey hareketleri miras alarak ayni zamanda undo hareketini saglar.
#ifndef CONNECTFOURPLUSUNDO_H
#define CONNECTFOURPLUSUNDO_H

#include "ConnectFourPlus.h"

namespace CONNECTFOUR_HW6
{
	class ConnectFourPlusUndo : public ConnectFourPlus
	{
		public:
			//ConnectFourPlusUndo constructors
		    ConnectFourPlusUndo();
		    ConnectFourPlusUndo(const ConnectFourPlusUndo& orig);
		    //ConnectFourPlusUndo class assigment
		    ConnectFourPlusUndo& operator=(const  ConnectFourPlusUndo& rhs);
		    ////ConnectFourPlusUndo class destructor
		    ~ConnectFourPlusUndo();

		    //Undo hareti icin her hamleyi bir undo dosyasina kaydeder.
			void undoSaveFunc();
			//Undo hareketi icin her hamleyi undo dosyasindan alir.
			void undoLoadFunc();
	};
}
#endif /* CONNECTFOURPLUSUNDO_H */

