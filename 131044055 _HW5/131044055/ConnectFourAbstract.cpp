/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFourAbstract.cpp
 * Author: EDA BAHRIOGLU 131044055
 * 
 * Created on November 23, 2017, 2:07 PM
 */

#include "ConnectFourAbstract.h"
#include "Cell.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include<fstream>

using namespace std;
namespace CONNECTFOUR_HW6
{
	int ConnectFourAbstract::totalLivingCells = 0;
			
	ConnectFourAbstract::ConnectFourAbstract()
	{
		setWidth(4);
		setHeight(4);
		setPlayer('P');

		gameBoard = new Cell*[getHeight()];
		for(int i=0; i<getHeight(); i++)
			gameBoard[i] = new Cell[getWidth()];

		startingBoard();	
	}
		   
	ConnectFourAbstract::ConnectFourAbstract(int widthValue, int heightValue)
	{
		setWidth(widthValue);
		setHeight(heightValue);
		setPlayer('P');

		gameBoard = new Cell*[getHeight()];
		for(int i=0; i<getHeight(); i++)
			gameBoard[i] = new Cell[getWidth()];

		startingBoard();
	}

	ConnectFourAbstract::ConnectFourAbstract(int widthValue, int heightValue, char PlayerLetter)
	{
		setWidth(widthValue);
		setHeight(heightValue);
		setPlayer(PlayerLetter);

		gameBoard = new Cell*[getHeight()];
		for(int i=0; i<getHeight(); i++)
			gameBoard[i] = new Cell[getWidth()];

		startingBoard();
	}

	ConnectFourAbstract::ConnectFourAbstract(const ConnectFourAbstract& other)
	{
		setHeight(other.getHeight());
	    setWidth(other.getWidth());
	    setPlayer(other.getPlayer());
	  

		gameBoard = new Cell*[getHeight()];
		for(int i=0; i<getHeight(); i++)
			gameBoard[i] = new Cell[getWidth()];

		for (int i = 0; i < getHeight(); i++)
	    {
	        for (int j = 0; j < getWidth(); j++)
	        {
	            gameBoard[i][j] = other.gameBoard[i][j];
	        }
	    }
	}

//Dynamic array tutuldugu icin yapilmasi gereken assigment operatoru overloadudur.
	ConnectFourAbstract& ConnectFourAbstract::operator=(const ConnectFourAbstract& rhs)
	{
		if(this == &rhs)
		{
			return *this;
		}
		else
		{
			setWidth(rhs.getWidth());
			setHeight(rhs.getHeight());
			setPlayer(rhs.getPlayer());

			for(int i = 0; i < getHeight(); i++)
			{
	 			delete gameBoard[i];
	 		}
			delete gameBoard;

			gameBoard = new Cell*[getHeight()];
			for(int i=0; i<getHeight(); i++)
				gameBoard[i] = new Cell[getWidth()];


			for (int i = 0; i < getHeight(); i++)
		    {
		        for (int j = 0; j < getWidth(); j++)
		        {
		            gameBoard[i][j] = rhs.gameBoard[i][j];
		        }
		    }
	    	return *this;
		}
	}

//Abstract class constructors
	ConnectFourAbstract::~ConnectFourAbstract()
	{
		for(int i = 0; i < getHeight(); i++)
		{
	 		delete gameBoard[i];
	 	}
		delete gameBoard;
	}


	void ConnectFourAbstract::setWidth(int widthValue)
	{
		if(widthValue > 0 )
		{
			boardWidth = widthValue;
		}
		
	}
		   
	void ConnectFourAbstract::setHeight(int heightValue)
	{
		if(heightValue > 0)
		{
			boardHeight = heightValue;
		}

	}

	void ConnectFourAbstract::setPlayer(char PlayerLetter)
	{	
		player = PlayerLetter;
	}

	//Oyunun başlangıç durumundaki boş board un oluşturulduğu fonksiyondur.
	bool ConnectFourAbstract::startingBoard() 
	{
		int i,j;

		for (i = 0; i <getHeight() ; i++) 
		{		
			for (j = 0; j < getWidth(); j++)
			{	

				gameBoard[i][j].setUserSym('.');
			}	
		}
	}

	//Board ekranda gösterilir.
	void ConnectFourAbstract::printBoard()
	{
		string letter[] = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
		int i, j;
		
		for (i = 0; i < getWidth(); i++)
			cout << letter[i];
			cout <<endl;

		for (i = 0; i <getHeight() ; i++) 
		{		
			for (j = 0; j < getWidth(); j++)
			{		
				cout << gameBoard[i][j].getUserSym();
			}
			cout << endl;
		}

	}

	//parametre olarak gonderilen dosya ismindeki dosyaya oyunun istenilen andaki board unu kaydeder.
	void ConnectFourAbstract::saveFile(string selectLetter, string filename)
	{
		ofstream saveFile;
		saveFile.open(filename);
		
		int k,l;
		if(saveFile.is_open()==false)
		{
			cerr << "Output file opening failed." << endl;
			exit(1);
		}

		int satir=-1;
		vector<string>letter = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
		int i = 0;

		for(i=0;i<getWidth();++i)
		{
			if(selectLetter == letter[i]){
				satir=i;
				i=getWidth();
			}
		}

		for (int i = 0; i <getHeight() ; i++) 
		{		
			for (int j = 0; j < getWidth(); j++)
			{	
				
				saveFile << gameBoard[i][j].getUserSym();
			}
			saveFile << endl;
		}
			saveFile.close();
			//printBoard();
			rightMove(satir);
			downMove(satir);	
			crossLeftMove(satir);
		    crossRightMove(satir);
	}
	//Dosyadan okudugu boardu ekrana basar ve oyunu kaldıgı kaydedilen yerden devam etirerek ilerletir.
	void ConnectFourAbstract::loadFile(string selectLetter, string filename)
	{
		ifstream loadFile;
	    string line;
	    int height=0;
		int widcol =0;

		loadFile.open(filename);

		if(loadFile.is_open()==false)
		{
			cerr << "Output file opening failed." << endl;
		}

		while (!loadFile.eof()) 
		{
	        getline(loadFile, line);	
			for(int j=0; j<line.length(); ++j)
			{
				widcol = line.length();
			}
			height++;	
		}

		height--;
		setHeight(height);
		setWidth(widcol);

	    loadFile.close();

		gameBoard = new Cell*[getHeight()];
			for(int i=0; i<getHeight(); i++)
				gameBoard[i] = new Cell[getWidth()];

		loadFile.open(filename);

		if(loadFile.is_open()==false)
		{
			cerr << "Output file opening failed." << endl;
		}
		int k = 0;
		while (!loadFile.eof()) 
		{
	        getline(loadFile, line);	
			for(int j=0; j<line.size(); ++j)
			{
				gameBoard[k][j].setUserSym(line[j]);
			}
			k++;	
		}
		//printBoard();
		loadFile.close();
	}

	//Oyunun tamaminin oynandigi kisimdir.
	void ConnectFourAbstract::playGame()
	{
		vector<string>letter = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
		char selectPlayer;
		auto user1Character = 'X', user2Character = 'O';
		string selectLetter;
		
		int total;
		cout << "#WELCOME TO CONNECT FOUR GAME#" << endl;
		cout << "Please enter width size: "<< endl;	
		cin >> boardWidth;
		cout << "Please enter height size: "<< endl;	
		cin >> boardHeight;

		while (!cin || boardHeight < 0|| boardWidth <0 ) 
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cerr<<"You entered wrong character\n";
			cerr << "Please try again: "<<endl;	

			cin >> boardWidth;
			cin >> boardHeight;
			
		}
		gameBoard = new Cell*[getHeight()];
			for(int i=0; i<getHeight(); i++)
				gameBoard[i] = new Cell[getWidth()];

		startingBoard();
		cout << "You must select player"<< endl;
		cin >> selectPlayer;
		cin.clear();
		cin.ignore();

	//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
		if(selectPlayer=='P')
		{
			cout << "START GAME WITH USER1 AND USER2" << endl;
			printBoard();
			
			for(int i=0; i<(boardHeight * boardWidth); ++i)
			{
				cout<<"User1 please you select a character in board"<<endl;
				play(selectLetter);
				cout<<"User2 please you select a character in board"<<endl;
				play(selectLetter);
			}			
		}
	//Oyunun bir kullanıcı ve bir bilgisayar arasında oynanma durumunu kontrol edildigi bolumdur.
		else if(selectPlayer=='C')
		{
			cout << "START GAME WITH COMPUTER AND USER" << endl;
			printBoard();
			
			for(int i=0; i<(boardHeight * boardWidth); ++i)
			{
				cout<<"User1 please you select a character in board"<<endl;
				play(selectLetter);
				play();
			}
		}

	//Yanlis girilen komut durumunda kontrol edilir.
		else
		{
			cerr<<"FAILURE COMMAND"<<endl;
			exit(1);
		}
	}

	//Computerin tek hamle yaptigi fonksiyondur.
	void ConnectFourAbstract::play()
	{
		vector<string>letter = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
		char selectPlayer;
		int total;
		
		cout<<"Wait!!!Computer(User2) will select a character in board"<<endl;			
		decltype(boardHeight) k = 0+(rand () % boardHeight);
		string randomLetter = letter[k];
		legalCheckFunction(randomLetter, 'O');

		totalLivingCells++;
		total = totalCell();
	}

	//Userin tek hamle yaptigi fonksiyondur.
	void ConnectFourAbstract::play(string selectLetter)
	{		
		char user= '.';
		getline(cin, selectLetter);
		if(selectLetter.length()==0)	
		{
				exit(1);
		}
		string parse1 = selectLetter.substr(0, selectLetter.find(" "));
		string parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));	
		
		totalLivingCells++;
		int total = totalCell();

		if(total%2==1)
		{
			//cout<<"User1 please you select a character in board"<<endl;
			user = 'X';	
		}
		if(total%2==0)
		{
			//cout<<"User2 please you select a character in board"<<endl;
			user = 'O';
		}

		if(parse1 == "SAVE")
		{
			saveFile(parse1,parse2);	
			getline(cin, parse1);	
			if(parse1.length()==0)	
			{
				exit(1);
			}
			legalLetterFunc(parse1,user);			
		}
		else if(parse1 == "LOAD" )
		{												
			loadFile(parse1,parse2);
			legalLetterFunc(parse1, user);			
		}
		else if(parse1 == "UNDO")
		{
			undoLoadFunc();
		}
		else
		{
			undoSaveFunc();	
			legalCheckFunction(parse1, user);
		}				
	}

	//Taslarin haraketinin legal oldugunun kontrolu yapılır.
	//Nokta olan yerlere hamle yapilabilirken nokta olmayan yerler atalnır. 
	void ConnectFourAbstract::legalCheckFunction(string selectLetter, char user1Character, int satir)
	{
		vector<string>letter = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
		int i = 0;

		for(i=0;i<getWidth();++i)
		{
			if(selectLetter == letter[i])
			{
				satir=i;
				i=getWidth();
			}
		}

		if(satir>=0)
			for (i=getHeight()-1; i>=0; --i)
			{
				if(gameBoard[i][satir].getUserSym()== '.') 
				{
					gameBoard[i][satir].setUserSym(user1Character);
					i=0;
				}
			}

	//Tas ların tüm kazanma durumlarinin kontrolünün yapildiği fonksiyonlarin cagirildigi bölümdür.
		else
			cerr<<"Select Character is not in board.Another player will play"<<endl;	
			printBoard();	
			rightMove(satir);
			downMove(satir);	
			crossLeftMove(satir);
		    crossRightMove(satir);
	}

	//Hamleelrin yapılmasında kullanilan fonksiyondur.Sartlara girerken kullanilmak icin yazilmistir.
	void ConnectFourAbstract::legalLetterFunc(string parse1,char user)
	{
		int satir=-1;
		vector<string>letter = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
		auto i = 0;

		for(i=0;i<getWidth();++i)
		{
			if(parse1 == letter[i])
			{
				satir=i;
				i=getWidth();
			}
		}

		if(satir>=0)
			for (i=getHeight()-1; i>=0; --i)
			{
				if(gameBoard[i][satir].getUserSym()=='.') 
				{
					gameBoard[i][satir].setUserSym(user) ;
					i=-1;
				}
			}
		printBoard();
	}

	//Oyunun sonunu gosteren fonksiyondur.
	void ConnectFourAbstract::endOfGame()const
	{
		int userCount = 0; 
		int computerCount = 0;

		for (int i = 0; i < getHeight(); ++i)

			for (int j = 0; j < getWidth(); ++j) 
			{
				if (gameBoard[i][j].getUserSym() == 'X')
				{
					userCount++;		
				}
				else if (gameBoard[i][j].getUserSym() == 'O')
				{
					computerCount++;
				}
			}

		if (userCount > computerCount)
		{
			cout << " You win user1" << endl;
		}
		else if (userCount < computerCount)
		{
			cout << "You win user2" << endl;
		}
		else
		{
			cout << "Sorry You are draw" << endl;
		}
	}
}
