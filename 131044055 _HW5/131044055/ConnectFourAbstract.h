/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFourAbstract.h
 * Author: EDA BAHRIOGLU 131044055
 *
 * Created on November 23, 2017, 2:07 PM
 */

#ifndef CONNECTFOURABSTRACT_H
#define CONNECTFOURABSTRACT_H

#include <iostream>

#include "Cell.h"

using std::string;
using namespace CELL_HW6;
namespace CONNECTFOUR_HW6
{
	class ConnectFourAbstract 
	{
		public:

			//ConnectFourAbstract class icin constructor tanımlamaları 
		    ConnectFourAbstract();
		    ConnectFourAbstract(int widthValue, int heightValue);
		    ConnectFourAbstract(int widthValue, int heightValue, char PlayerLetter);
		    ConnectFourAbstract(const ConnectFourAbstract& other);

		    //ConnectFourAbstract class icin setter tanımlamaları 
		    void setWidth(int widthValue);
		    void setHeight( int heightValue);
		    void setPlayer(char PlayerLetter);
		    inline char getPlayer()const {return player; }
		    inline int getWidth()const { return boardWidth;}
		    inline int getHeight()const { return boardHeight;}
		    static int totalCell(){ return totalLivingCells;}

		    //Boardun başlangic durumundaki boş halini oluşturan fonksiyon
			bool startingBoard();
		    //Boardu ekrana basan fonksiyondur.
			void printBoard();
		    //Dosyaya yazma islemini yapan fonksiyondur.
			void saveFile(string selectLetter, string filename);
			//Dosyadan okuma  islemini yapan fonksiyondur.
			void loadFile(string selectLetter, string filename);
			//Basılan tas sayisina göre oyunun computer ve user arasında kazananini belirleyerek oyunu sonlandirir. 
			void endOfGame() const;
			//all of game 
			void playGame();
			//Bilgisayar hamlesi icin yazilmistir.
			void play();
			//User hamleleri icin yazilmistir.
			void play(string selectLetter);
			//Assigment operator fonksiyonudur.
			ConnectFourAbstract& operator=(const ConnectFourAbstract& rhs);
			//Destructor fonksiyonudur.
			virtual ~ConnectFourAbstract();

		protected:

			int boardWidth; // Width of game board
			int boardHeight; // Height of game board
			char player;

			//Toplam living cell dondurur.
			static int totalLivingCells;
			Cell ** gameBoard;	
				
			//Default argumenli fonksiyondur.
			//Taslarin hamleleri icin gidebilecekleri doğru alanlarin kontrolü yapılır.
			void legalCheckFunction(string selectLetter, char user1Character, int satir=-1);
			//Dikey haretin yapildigi ve dikey 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			virtual void downMove(int &col)const = 0;
			//Yatay haretin yapildigi ve yatay 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			virtual void rightMove(int &col)const = 0;
			//Soldan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			virtual void crossLeftMove(int &col)const = 0;
			//Sagdan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			virtual void crossRightMove(int &col)const = 0;
			//Hamleler için kullanilan fonksiyondur.
			void legalLetterFunc(string parse1,char user);
			//undo harketi icin her hamleyi dosyaya kaydeder.
			virtual void undoSaveFunc() = 0;
			//Undo icin keydedilen her hamleyi dosyadan alir.
			virtual void undoLoadFunc() = 0;
	};
}

#endif /* CONNECTFOURABSTRACT_H */

