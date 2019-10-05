/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hw3
 * Author: Eda BAHRIOGLU 131044055
 *
 * Created on October 15, 2017, 11:57 PM
 */

#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <iostream>
#include <vector>

using namespace std;
class ConnectFour 
{


		public:

			//ConnectFour class icin constructor tanımlamaları 
		    ConnectFour();
		    ConnectFour(int widthValue, int heightValue);
		    ConnectFour(string filename);
		    ConnectFour(const ConnectFour& other);
		    ConnectFour(int widthValue, int heightValue, char PlayerLetter);

		    //ConnectFour class icin setter tanımlamaları 
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
			void printBoard() const;

		    //Dosyaya yazma islemini yapan fonksiyondur.
			void saveFile(string selectLetter, string filename);

			//Dosyadan okuma  islemini yapan fonksiyondur.
			void loadFile(string selectLetter, string filename);

			//Basılan tas sayisina göre oyunun computer ve user arasında kazananini belirleyerek oyunu sonlandirir. 
			int endOfGame() const;
			//all of game 
			void playGame();

			//Bilgisayar hamlesi icin yazilmistir.
			void play();
			//User hamleleri icin yazilmistir.
			void play(char user);
			void readFunc(string filename);
			ConnectFour& operator=(const ConnectFour& rhs);
			bool operator==(const ConnectFour& other)const;
			bool operator!=(const ConnectFour& other)const;

			~ConnectFour();

		private:
	
			class Cell
			{
				public:

					//Cell class constructorlari
					Cell();
					Cell(int rowValue, int columnValue);
					Cell(int rowValue ,int columnValue, char userSymValue, char incrementValue);
					//cell class setterlari
					void setrow(int const rowValue);		
					void setColumn( int const columnValue);
					void setUserSym(char  const userSymValue);
					void setincrement(char incrementValue);
					void setCharline(char charValue);

					//inline getter functions
					inline int getrow()const{ return row;}
					inline int getColumn()const{ return column;}
					inline char getUserSym()const{ return userSymbol;}
					inline char  getincrement()const{ return incrementChar;}
					inline char getCharline()const { return charline; }
					
					bool operator==(const Cell &other) const;
					friend const Cell operator++(Cell& obje);
    				friend const Cell operator++(Cell& obje,int value);

					friend ostream& operator<<(ostream& outputStream, const Cell& obje);
 					friend istream& operator>>(istream& inputStream, Cell& obje);

				private:
					int row;
					int column;
					char userSymbol;
					char incrementChar;
					char charline;

			};
			friend ostream& operator<<(ostream& outputStream, const ConnectFour::Cell& obje);
			friend istream& operator>>(istream& inputStream, ConnectFour::Cell& obje);
			friend const Cell operator++( ConnectFour::Cell& obje);
    		friend const Cell operator++(ConnectFour::Cell& obje,int value);

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
			int downMove(int &col)const;

			//Yatay haretin yapildigi ve yatay 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			int rightMove(int &col)const;

			//Soldan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			int crossLeftMove(int &col)const;
			//Sagdan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
			int crossRightMove(int &col)const;

			//Hamleler için kullanilan fonksiyondur.
			void legalLetterFunc() const;

};

#endif /* NEWCLASS_H */


