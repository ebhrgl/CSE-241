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
	vector <ConnectFour> myGame;
	vector <int> result;
	auto CountGames = 5, i=0;
	auto mod='S';
	char selectPlayer;
	int boardWidth,boardHeight;
	ConnectFour game1;

	cout << "#WELCOME TO CONNECT FOUR GAME#" << endl;
	cout<< "Oyun modunu seçiniz: ";
	cin>>mod;
	while (mod != 'S' && mod != 's' && mod != 'M' && mod != 'm' ) 
	{
		cin.clear();
		cin.ignore(1000,'\n');
		cerr<<"You entered wrong character\n";
		cerr << "Please try again: "<<endl;	

		cin >> mod;
	}

	if (mod == 'S' || mod == 's')
		CountGames=1;


	while(i<CountGames)
	{
		if(CountGames>1)
			cout<<endl<<"Obje"<<i+1<<endl;

		cout << "Please enter text file: ";
		string file;
		cin>>file;
		game1.readFunc(file);
		

		cout << endl << "You must select player (player|computer): ";
		cin >> selectPlayer;
		while (!cin || selectPlayer != 'p' && selectPlayer != 'P' && selectPlayer != 'c' && selectPlayer != 'C') 
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cerr<<"You entered wrong character\n";
			cerr << "Please try again: "<<endl;	

			cin >> selectPlayer;
		}
		cin.clear();
		cin.ignore();
		ConnectFour obje(file);
		myGame.push_back(obje);
		result.push_back(0);
		++i;
	}
	
	int tercih=0,son=-1;

	if(CountGames==1)
	{	
		myGame[0].setPlayer(selectPlayer);
		myGame[0].playGame();
	}
	else
	{	
		while(tercih<myGame.size()+1)
		{
			cout << "Çıkmak için "<<myGame.size()+1<<endl<<"Obje seçiniz [1-"<< myGame.size()<< "]:";
			cin >> tercih;
			while (!cin || tercih < 0 || tercih > myGame.size()+1) 
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cerr<<"You entered wrong character\n";
				cerr << "Please try again: "<<endl;
				cin >> tercih;
			}
			cin.ignore();
			if(tercih==myGame.size()+1)
				exit(1);
			else if(result[tercih-1]>0){

				myGame[tercih-1].printBoard();
				cout<<"Obje"<<tercih<<" is finished."<<endl;
			}
			else {
					
				myGame[tercih-1].setPlayer(selectPlayer);
				//selectPlayer=myGame[tercih-1].getPlayer();

				myGame[tercih-1].printBoard();

				myGame[tercih-1].play('X');	
				myGame[tercih-1].printBoard();
				son=myGame[tercih-1].endOfGame();
				//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
				if(selectPlayer=='C' || selectPlayer=='c')
				{
					selectPlayer=myGame[tercih-1].getPlayer();
					myGame[tercih-1].play();	
					//cout<<"totalcell = "<< myGame[tercih-1].totalCell() <<endl;	
				}
				else if(selectPlayer=='P' || selectPlayer=='p')
				{
					selectPlayer=myGame[tercih-1].getPlayer();
					myGame[tercih-1].play('O');	
				}
			
				son=myGame[tercih-1].endOfGame();
				cout<<"totalcell = "<< myGame[tercih-1].totalCell() <<endl;	
				if(son>0)
					result[tercih-1]=1;
			}
		}
		if(myGame[tercih-1] == myGame[tercih])
			return true;
		else
			return false;
	}

	return 0;
}