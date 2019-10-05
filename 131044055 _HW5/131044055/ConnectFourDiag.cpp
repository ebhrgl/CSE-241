/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConnectFourDiag.cpp
 * Author: EDA BAHRIOGLU 131044055
 * 
 * Created on November 23, 2017, 2:08 PM
 */



#include "ConnectFourDiag.h"
#include <vector>
#include<fstream>
using namespace std; 

namespace CONNECTFOUR_HW6
{
	ConnectFourDiag::ConnectFourDiag() :ConnectFourAbstract()
	{}

	ConnectFourDiag::ConnectFourDiag(const ConnectFourDiag& orig)  :ConnectFourAbstract(orig)
	{}

	ConnectFourDiag::~ConnectFourDiag() 
	{
		for(int i = 0; i < getHeight(); i++)
		{
	 		delete gameBoard[i];
	 	}
		delete gameBoard;
	}

	ConnectFourDiag& ConnectFourDiag::operator=(const ConnectFourDiag& rhs)
	{

		ConnectFourAbstract::operator=(rhs);
	}
//Sol taraftan baslayan capraz harekettir.4 tasın soldan yanayana gelmesi durumunda oyun kazanılır.
	void ConnectFourDiag::crossLeftMove(int &col)const
	{
		char user='.';
		int i,j;
		auto Ocount=0;
		auto Xcount=0;	
		col=0;

		while(col<getWidth())
		{
		
			for(i=1; i<getHeight(); ++i)
			{
				if(gameBoard[i-1][col].getUserSym() !='.' && gameBoard[i][col+1].getUserSym() !='.')

					if(gameBoard[i-1][col].getUserSym() == gameBoard[i][col+1].getUserSym())
					{
						
						if(gameBoard[i-1][col].getUserSym() == 'X')
						{
							++Xcount;				
			
						}
						else if(gameBoard[i-1][col].getUserSym() == 'O')
						{
							++Ocount;									
						}
						else
						{				
							user='.';	
							Ocount=0;					
						}
					}	
			}
			
			col++;
		}	

			if(Xcount >= 3)//4 x tasinin yanyana olup olmadigi kontrolu
			{	
				cout<<"USER1 WIN"<<endl;
				//endOfGame();
				exit(1);
			}
			else if(Ocount >= 3)//4 o tasinin yanyana olup olmadigi kontrolu
			{	
		
				cout<<"USER2 WIN"<<endl;
				//endOfGame();
				exit(1);
			}
	}

	//Sag taraftan baslayan capraz harekettir.4 tasın sagdan yanayana gelmesi durumunda oyun kazanılır.
	void ConnectFourDiag::crossRightMove(int &col)const
	{
		char user='.';
		int i,j;
		auto Ocount=0;
		auto Xcount=0;		
		col=0;

		while(col<getWidth())
		{	
			for(i=0; i<getHeight()-1; ++i)
			{
				if(gameBoard[i][col+1].getUserSym() !='.' && gameBoard[i+1][col].getUserSym() !='.')
					if(gameBoard[i][col+1].getUserSym() == gameBoard[i+1][col].getUserSym())
					{
						if(gameBoard[i][col+1].getUserSym() =='X')
						{
							++Xcount;					
						}			
						else if(gameBoard[i][col+1].getUserSym() == 'O')
						{
							++Ocount;								
						}
						else
						{						
							user='.';
							Ocount=0;						
						}
					}
					
			}		
			col++;
		}

			if(Xcount >= 3)//4 x tasinin yanyana olup olmadigi kontrolu
			{	
				cout<<"USER1 WIN"<<endl;
				//endOfGame();	
				exit(1);
			}
		
			else if(Ocount >= 3 )//4 o tasinin yanyana olup olmadigi kontrolu
		    {	
				
				cout<<"USER2 WIN"<<endl;
				//endOfGame();
				exit(1);
			}
	}


	void ConnectFourDiag::rightMove(int &col)const
	{

	}
	void ConnectFourDiag::downMove(int &col)const
	{
		
	}

	void ConnectFourDiag::undoSaveFunc()
	{
	}
	void ConnectFourDiag::undoLoadFunc()
	{
	}
}
