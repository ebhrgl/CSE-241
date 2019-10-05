/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFourPlus.cpp
 * Author: EDA BAHRIOGLU 131044055
 * 
 * Created on November 23, 2017, 2:07 PM
 */

#include "ConnectFourPlus.h"
#include <vector>
#include<fstream>
using namespace std; 

namespace CONNECTFOUR_HW6
{

	ConnectFourPlus::ConnectFourPlus() :ConnectFourAbstract()
	{}

	ConnectFourPlus::ConnectFourPlus(const ConnectFourPlus& orig) : ConnectFourAbstract(orig)
	{}

	ConnectFourPlus::~ConnectFourPlus() 
	{
		for(int i = 0; i < getHeight(); i++)
		{
	 		delete gameBoard[i];
	 	}
		delete gameBoard;
	}

	ConnectFourPlus& ConnectFourPlus::operator=(const ConnectFourPlus& rhs)
	{

		ConnectFourAbstract::operator=(rhs);
	}
	//Yatay yönde yapilan tas hareketleridir.4 yatay ayni tas yanyana gelmesi durumu kazanma durumudur.
	//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
	void ConnectFourPlus::rightMove(int &col)const
	{
		char user='.';
		auto count=0;
		int i,j;
		col=0;
	 
		while(col<getHeight())
		{
			count=0;
			for(i=1; i<getWidth(); ++i)
			{
				if(gameBoard[col][i-1].getUserSym() !='.' && gameBoard[col][i].getUserSym() !='.')

					if(gameBoard[col][i-1].getUserSym() == gameBoard[col][i].getUserSym())
					{
						user=gameBoard[col][i-1].getUserSym();
						++count;
					}
					else{
						count=0;
						user='.';		
					}

				if(count>=3)
				{
				
					if(user=='X')//4 x tasinin yanyana olup olmadigi kontrolu
					{
						cout<<"USER1 WIN"<<endl;
						//endOfGame();
					}
					else if(user=='O')//4 o tasinin yanyana olup olmadigi kontrolu
					{
						cout<<"USER2  WIN"<<endl;
						//endOfGame();
					}
				
					exit(1); 
				}
			}
			
			col++;
		}
	}

//Dikey yönde yapilan tas hareketleridir.4 dikey ayni tas yanyana gelmesi durumu kazanma durumudur.
//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
	void ConnectFourPlus::downMove(int &col)const
	{
		char user='.';
		auto count=0;
		int i,j;
		col=0;

		while(col<getWidth())
		{
			count=0;
			for(i=1; i<getHeight(); ++i)
			{
				if(gameBoard[i-1][col].getUserSym() !='.' && gameBoard[i][col].getUserSym() !='.')

					if(gameBoard[i-1][col].getUserSym() == gameBoard[i][col].getUserSym())
					{
						user = gameBoard[i-1][col].getUserSym();
						++count;
					}
					else{
						count=0;
						user='.';		
					}

				if(count>=3)
				{			
				
					if(user=='X')//4 x tasinin yanyana olup olmadigi kontrolu
					{
						cout<<"USER1 WIN"<<endl;
						//endOfGame();
					}
					else if(user=='O')//4 o tasinin yanyana olup olmadigi kontrolu
					{
						cout<<"USER2  WIN"<<endl;
						//endOfGame();
					}
					
					exit(1); 
				}
			}
			col++;
		}
	}



	void ConnectFourPlus::crossLeftMove(int &col)const
	{

	}
	void ConnectFourPlus::crossRightMove(int &col)const
	{

	}

	void ConnectFourPlus::undoSaveFunc()
	{

	}
	void ConnectFourPlus::undoLoadFunc()
	{
		
	}

}
