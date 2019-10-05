#include<iostream>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cmath>
#include "ConnectFour.h"

using namespace std;
int main() 
{

	cout<<"Please change a mode"<<endl;
	char mode;
	ConnectFour obje, obje1, obje2, obje4, obje5;
	ConnectFour y;
	char selectPlayer;
	int width, height;
	string obj;
	string selecLetter;
	
	cin>>mode;

	if(mode == 'S')
	{
		
		y.playGame();
	}


	else if(mode == 'M')
	{
		
		cout << "#WELCOME TO CONNECT FOUR GAME#" << endl;
		for(int i=0; i<30; ++i)
		{
	
			cout<<"Please choose a object"<<endl;
			cout<<"Obje 1 OR 2 OR 3 OR 4 OR 5"<<endl;
			cin>>obj;
			cout << "Please enter width size: "<< endl;	
			cin >> width;
			cout << "Please enter height size: "<< endl;	
			cin >> height;

			if(obj == "1")
			{
		
				while (!cin || height < 0|| width <0 ) 
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cerr<<"You entered wrong character\n";
					cerr << "Please try again: "<<endl;
						

				}
				obje1.setHeight(height);
				obje1.setWidth(width);

				obje1.startingBoard();

				cout << "You must select player"<< endl;	
				cin >> selectPlayer;
				cin.clear();
				cin.ignore();	
				obje1.printBoard();
					
				
				//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
				if(selectPlayer=='P')
				{

					obje1.play(selecLetter);
					obje1.play(selecLetter);
				
				}
				else if(selectPlayer=='C')
				{

					obje1.play(selecLetter);
					obje1.play();
								
				}
	
			}

			else if(obj == "2")
			{
		
				while (!cin || height < 0|| width <0 ) 
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cerr<<"You entered wrong character\n";
					cerr << "Please try again: "<<endl;
						

				}
				obje2.setHeight(height);
				obje2.setWidth(width);

				obje2.startingBoard();

				cout << "You must select player"<< endl;	
				cin >> selectPlayer;
				cin.clear();
				cin.ignore();	
				obje2.printBoard();
					
				
				//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
				if(selectPlayer=='P')
				{

					obje2.play(selecLetter);
					obje2.play(selecLetter);
				
				}
				else if(selectPlayer=='C')
				{

					obje2.play(selecLetter);
					obje2.play();
								
				}
	
			}


			else if(obj == "3")
			{
			
				while (!cin || height < 0|| width <0 ) 
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cerr<<"You entered wrong character\n";
					cerr << "Please try again: "<<endl;
						

				}
				ConnectFour obje3;
				obje3.setHeight(height);
				obje3.setWidth(width);

				obje3.startingBoard();

				cout << "You must select player"<< endl;	
				cin >> selectPlayer;
				cin.clear();
				cin.ignore();	
				obje3.printBoard();
					
				
				//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
				if(selectPlayer=='P')
				{

					obje3.play(selecLetter);
					obje3.play(selecLetter);
				
				}
				else if(selectPlayer=='C')
				{

					obje3.play(selecLetter);
					obje3.play();
								
				}
	
			}
			else if(obj == "4")
			{
			
				while (!cin || height < 0|| width <0 ) 
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cerr<<"You entered wrong character\n";
					cerr << "Please try again: "<<endl;
						

				}
				obje4.setHeight(height);
				obje4.setWidth(width);

				obje4.startingBoard();

				cout << "You must select player"<< endl;	
				cin >> selectPlayer;
				cin.clear();
				cin.ignore();	
				obje4.printBoard();
					
				
				//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
				if(selectPlayer=='P')
				{

					obje4.play(selecLetter);
					obje4.play(selecLetter);
				
				}
				else if(selectPlayer=='C')
				{

					obje4.play(selecLetter);
					obje4.play();
								
				}
	
			}

			else if(obj == "5")
			{
			
				while (!cin || height < 0|| width <0 ) 
				{
					cin.clear();
					cin.ignore(1000,'\n');
					cerr<<"You entered wrong character\n";
					cerr << "Please try again: "<<endl;
						

				}
				obje5.setHeight(height);
				obje5.setWidth(width);

				obje5.startingBoard();

				cout << "You must select player"<< endl;	
				cin >> selectPlayer;
				cin.clear();
				cin.ignore();	
				obje5.printBoard();
								
				//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
				if(selectPlayer=='P')
				{

					obje5.play(selecLetter);
					obje5.play(selecLetter);
				
				}
				else if(selectPlayer=='C')
				{

					obje5.play(selecLetter);
					obje5.play();
								
				}
	
			}
		}

	}
	
	

		if(obje1.compare(obje2)==true)

			cout <<"obje1 is better for the user than obje4" << endl;
		else
			cout <<"obje4 is better for the user than obje1" << endl;




	return 0;

}

