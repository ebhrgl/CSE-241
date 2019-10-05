/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFourPlusUndo.cpp
 * Author: EDA BAHRIOGLU 131044055
 * 
 * Created on November 23, 2017, 2:08 PM
 */

#include "ConnectFourPlusUndo.h"
#include<fstream>
using namespace std; 

namespace CONNECTFOUR_HW6
{

	ConnectFourPlusUndo::ConnectFourPlusUndo() :ConnectFourPlus()
	{
	}

	ConnectFourPlusUndo::ConnectFourPlusUndo(const ConnectFourPlusUndo& orig) :ConnectFourPlus(orig)
	{
	}

	ConnectFourPlusUndo::~ConnectFourPlusUndo() 
	{
		for(int i = 0; i < getHeight(); i++)
		{
	 		delete gameBoard[i];
	 	}
		delete gameBoard;
	}

	ConnectFourPlusUndo& ConnectFourPlusUndo::operator=(const ConnectFourPlusUndo& rhs)
	{
		ConnectFourPlusUndo::operator=(rhs);
	}

	//Undo islimi icin bir undo dosyasina her hamle icin kaydetme islemi yapar.
	void ConnectFourPlusUndo::undoSaveFunc()
	{

		ofstream saveFile;
		saveFile.open("UNDO.TXT");
		
		int k,l;
		if(saveFile.is_open()==false)
		{
			cerr << "Output file opening failed." << endl;
			exit(1);
		}

		int satir=-1;

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

//Undo islemi icin kaydedilen her hamleyi okur.
	void ConnectFourPlusUndo::undoLoadFunc()
	{
		ifstream loadFile;
	    string line;
	    int height=0;
		int widcol =0;

		loadFile.open("UNDO.TXT");

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

		loadFile.open("UNDO.TXT");

		if(loadFile.is_open()==false)
		{
			cerr << "Output file opening failed." << endl;
		}
		int m = 0;
		while (!loadFile.eof()) 
		{
	        getline(loadFile, line);	
			for(int j=0; j<line.size(); ++j)
			{
				gameBoard[m][j].setUserSym(line[j]);
			}
			m++;	
		}
		printBoard();
		loadFile.close();

	}

}
