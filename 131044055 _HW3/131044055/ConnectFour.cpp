/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hw3
 * Author: Eda Bahrioglu 131044055
 * 
 * Created on October 15, 2017, 11:57 PM
 */

#include "ConnectFour.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include<fstream>

using namespace std;

int ConnectFour::totalLivingCells = 0;

ConnectFour::Cell::Cell()
{
	setrow(0);
	setColumn(0);
	setUserSym('.');
}

ConnectFour::Cell::Cell(int row, int column)
{
	setrow(row);
	setColumn(column);
	setUserSym('.');
}

ConnectFour::Cell::Cell(int row ,int column, char userSymbol)
{
	setrow(row);
	setColumn(column);
	setUserSym(userSymbol);
}

void ConnectFour::Cell::setrow(const int rowValue)
{
	if(rowValue<0)
	{
		cerr<<"invalid command"<<endl;
	}
	row = rowValue;

}
				
void ConnectFour::Cell::setColumn(const int columnValue)
{
	if(columnValue<0)
	{
		cerr<<"invalid command"<<endl;
	}

	column = columnValue;
}
				
void ConnectFour::Cell::setUserSym(const char userSymValue)
{

	userSymbol = userSymValue;

}
			
ConnectFour::ConnectFour()
{
	setWidth(4);
	setHeight(4);
	setPlayer('P');
}
	   
ConnectFour::ConnectFour(int widthValue, int heightValue)
{
	setWidth(widthValue);
	setHeight(heightValue);
	setPlayer('P');
}

ConnectFour::ConnectFour(int widthValue, int heightValue, char PlayerLetter)
{
	setWidth(widthValue);
	setHeight(heightValue);
	setPlayer(PlayerLetter);
}

void ConnectFour::setWidth(int widthValue)
{
	if(boardWidth > 0 )
	{
		boardWidth = widthValue;
	}
	
}
	   
void ConnectFour::setHeight(int heightValue)
{
	if(boardHeight > 0)
	{
		boardHeight = heightValue;
	}

}

void ConnectFour::setPlayer(char PlayerLetter)
{
	
		player = PlayerLetter;
	

}

//Oyunun başlangıç durumundaki boş board un oluşturulduğu fonksiyondur.
bool ConnectFour::startingBoard() 
{

	vector<Cell>board;	
	int i,j;

	for (i = 0; i <getHeight() ; i++) 
	{		
		for (j = 0; j < getWidth(); j++)
		{	
			
			Cell temp(j, i,'.');
			board.push_back(temp);
		}
		gameCells.push_back(board);
	}

}

//Board ekranda gösterilir.
void ConnectFour::printBoard()
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
			
			cout << gameCells[i][j].getUserSym();
		}
		cout << endl;
	}

}

//parametre olarak gonderilen dosya ismindeki dosyaya oyunun istenilen andaki board unu kaydeder.
void ConnectFour::saveFile(string selectLetter, string filename)
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
			
			saveFile << gameCells[i][j].getUserSym();
		}
		saveFile << endl;
	}

	saveFile.close();
		printBoard();
		rightMove(satir);
		downMove(satir);	
		crossLeftMove(satir);
	    crossRightMove(satir);


}
//Dosyadan okudugu boardu ekrana basar ve oyunu kaldıgı kaydedilen yerden devam etirerek ilerletir.
void ConnectFour::loadFile(string selectLetter, string filename)
{

	ifstream loadFile;
	char ch;

	loadFile.open(filename);

	if(loadFile.is_open()==false)
	{
		cerr << "Output file opening failed." << endl;
		exit(1);
	}

	gameCells.clear(); 


	
	int i,j;

	for (i = 0; i <getHeight() ; i++) 
	{		
		vector<Cell>board;	
		for (j = 0; j < getWidth(); j++)
		{	
			loadFile >> ch;
			Cell temp(j, i,ch);
			board.push_back(temp);
		}
		gameCells.push_back(board);
	}
		printBoard();
		loadFile.close(); 

}

//iki obje rasinda karsilastirma yapar.
bool ConnectFour::compare(const ConnectFour &other) const
{
	int userplay1 = 0;
	int userplay2 = 0;
	int computerplay1 = 0;
	int computerplay2 = 0;
	int value1, value2;

	for (int i = 0; i < gameCells.size(); ++i) 
	{
		for (int j = 0; j < gameCells[i].size(); ++j) 
		{
			if (gameCells[i][j].getUserSym() == 'X')
				userplay1++;
			
			else if(gameCells[i][j].getUserSym() == 'O') 
				computerplay1++;
		}
	}

	for (int i = 0; i < other.gameCells.size(); ++i) 
	{
		for (int j = 0; j < other.gameCells[i].size(); ++j) 
		{
			if (other.gameCells[i][j].getUserSym() == 'X')
				userplay2++;

			else if(other.gameCells[i][j].getUserSym() == 'O')
				computerplay2++;
		}
	}

	value1 = userplay1 - computerplay1;
	value2 = userplay2 - computerplay2;

	if(value1 > value2)
		return true;
	else 
		return false;

}

//Oyunun tamaminin oynandigi kisimdir.
void ConnectFour::playGame()
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
			cin.clear();
			getline(cin, selectLetter);
			string parse1 = selectLetter.substr(0, selectLetter.find(" "));
			string parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));
			
			totalLivingCells++;

			if(parse1 == "SAVE")
			{
				saveFile(parse1,parse2);
				cout<<"User1 please you select a character in board"<<endl;
				cin.clear();
				getline(cin, parse1);
				
				legalLetterFunc(parse1,'X');
				
			}
			else if(parse1 == "LOAD" )
			{		
												
				loadFile(parse1,parse2);
				cout<<"User1 please you select a character in board"<<endl;
				getline(cin, parse1);
				legalLetterFunc(parse1, 'X');
				
			}
			else
			{
				legalCheckFunction(parse1, 'X');
			}
				cout<<"User2 please you select a character in board"<<endl;	
				cin.clear();
				getline(cin, selectLetter);
				parse1 = selectLetter.substr(0, selectLetter.find(" "));
				parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));					
				totalLivingCells++;
	
			if(parse1 == "SAVE")
			{
				saveFile(parse1,parse2);	
				cout << "kac kere" << endl;
				cout<<"User2 please you select a character in board"<<endl;	
				cin.clear();
				getline(cin, parse1);
							
				legalLetterFunc(parse1,'O');
			
	
			}
			else if(parse1 == "LOAD" )
			{	
								
				loadFile(parse1,parse2);
				cout<<"User2 please you select a character in board"<<endl;			
				getline(cin, parse1);	
				legalLetterFunc(parse1,'O');
				
	
			}
			else
			{	
				legalCheckFunction(parse1, 'O');
			}
				total = totalCell();

				cout<<"totalcell = "<< total <<endl;

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
			cin.clear();
			getline(cin, selectLetter);
			string parse1 = selectLetter.substr(0, selectLetter.find(" "));
			string parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));
			
			totalLivingCells++;
			if(parse1 == "SAVE")
			{
				saveFile(parse1,parse2);
				cout<<"User1 please you select a character in board"<<endl;
				cin.clear();
				getline(cin, parse1);				
				legalLetterFunc(parse1,'X');
				
			}
			else if(parse1 == "LOAD" )
			{		
												
				loadFile(parse1,parse2);
				cout<<"User1 please you select a character in board"<<endl;
				getline(cin, parse1);
				legalLetterFunc(parse1, 'X');
				
			}
			else
			{
				legalCheckFunction(parse1, 'X');
			}

			cout<<"Wait!!!Computer(User2) will select a character in board"<<endl;		
	
			decltype(boardHeight) k = 0+(rand () % boardHeight);
			string randomLetter = letter[k];
			legalCheckFunction(randomLetter, 'O');
			totalLivingCells++;
			total = totalCell();

			cout<<"totalcell = "<< total <<endl;	
		}

	}

//Yanlis girilen komut durumunda kontrol edilir.
	else
	{
		cerr<<"FAILURE COMMAND"<<endl;
		exit(1);
	}

}

//Dikey yönde yapilan tas hareketleridir.4 dikey ayni tas yanyana gelmesi durumu kazanma durumudur.
//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
void ConnectFour::downMove(int &col)const
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
			if(gameCells[i-1][col].getUserSym() !='.' && gameCells[i][col].getUserSym() !='.')

				if(gameCells[i-1][col].getUserSym() == gameCells[i][col].getUserSym())
				{
					user = gameCells[i-1][col].getUserSym();
					++count;
				}
				else{
					count=0;
					user='.';		
				}

			if(count>=3)
			{			
				/*for(j=i;j>i-4;--j)//Harf kücültme kontrolu

					gameCells[j][col].getColumn() = user + 32;
					printBoard();*/
			
				if(user=='X')//4 x tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER1 WIN"<<endl;
					endOfGame();
				}
				else if(user=='O')//4 o tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER2  WIN"<<endl;
					endOfGame();
				}
				
				exit(1); 
			}
		}
		col++;
	}

}

//Yatay yönde yapilan tas hareketleridir.4 yatay ayni tas yanyana gelmesi durumu kazanma durumudur.
//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
void ConnectFour::rightMove(int &col)const
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
			if(gameCells[col][i-1].getUserSym() !='.' && gameCells[col][i].getUserSym() !='.')

				if(gameCells[col][i-1].getUserSym() == gameCells[col][i].getUserSym())
				{
					user=gameCells[col][i-1].getUserSym();
					++count;
				}
				else{
					count=0;
					user='.';		
				}

			if(count>=3)
			{
			/*for(j=i;j>i-4;--j)//Harf kücültme kontrolu

					gameCells[j][col].getColumn() = user + 32;
					printBoard();*/

				if(user=='X')//4 x tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER1 WIN"<<endl;
					endOfGame();
				}
				else if(user=='O')//4 o tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER2  WIN"<<endl;
					endOfGame();
				}
			
				exit(1); 
			}
		}
		
		col++;
	}
}

//Sol taraftan baslayan capraz harekettir.4 tasın soldan yanayana gelmesi durumunda oyun kazanılır.
void ConnectFour::crossLeftMove(int &col)const
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
			if(gameCells[i-1][col].getUserSym() !='.' && gameCells[i][col+1].getUserSym() !='.')

				if(gameCells[i-1][col].getUserSym() == gameCells[i][col+1].getUserSym())
				{
					
					if(gameCells[i-1][col].getUserSym() == 'X')
					{
						++Xcount;				
		
					}
					else if(gameCells[i-1][col].getUserSym() == 'O')
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
			/*for(i=1; i<boardSize; ++i)//Harf kücültme kontrolu
			{
				for(j=i;j>i-4;--j)

					boardArray[j][col+1] = boardArray[j-1][col]+32;
					
			}
			printBoard(boardArray,boardSize);*/
			cout<<"USER1 WIN"<<endl;
			endOfGame();
			exit(1);
		}
		else if(Ocount >= 3)//4 o tasinin yanyana olup olmadigi kontrolu
		{	
	
			cout<<"USER2 WIN"<<endl;
			endOfGame();
			exit(1);
		}
}

//Sag taraftan baslayan capraz harekettir.4 tasın sagdan yanayana gelmesi durumunda oyun kazanılır.
void ConnectFour::crossRightMove(int &col)const
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
			if(gameCells[i][col+1].getUserSym() !='.' && gameCells[i+1][col].getUserSym() !='.')
				if(gameCells[i][col+1].getUserSym() == gameCells[i+1][col].getUserSym())
				{
					if(gameCells[i][col+1].getUserSym() =='X')
					{
						++Xcount;					
					}			
					else if(gameCells[i][col+1].getUserSym() == 'O')
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
			
			/*for(i=0; i<getWidth()-1; ++i)//Harf kücültme kontrolu
			{
				//for(j=i;j>i-4;--j)

					//boardArray[j+1][col] = boardArray[j][col+1]+32;
					//gameCells[j+1][col]=gameCells[j][col+1]+32;
		
					
			}	
			printBoard(height,width);	*/
			cout<<"USER1 WIN"<<endl;
			endOfGame();
			
			exit(1);
		}
	
		else if(Ocount >= 3 )//4 o tasinin yanyana olup olmadigi kontrolu
	    {	
			
			cout<<"USER2 WIN"<<endl;
			endOfGame();
			exit(1);
		}
}


//Taslarin haraketinin legal oldugunun kontrolu yapılır.
//Nokta olan yerlere hamle yapilabilirken nokta olmayan yerler atalnır. 
void ConnectFour::legalCheckFunction(string selectLetter, char user1Character, int satir)
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
			if(gameCells[i][satir].getUserSym()== '.') 
			{
				gameCells[i][satir].setUserSym(user1Character) ;
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
void ConnectFour::legalLetterFunc(string parse1,char user)
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
			if(gameCells[i][satir].getUserSym()=='.') 
			{
				gameCells[i][satir].setUserSym(user) ;
				i=-1;
			}
		}

	printBoard();
		

}

//Oyunun sonunu gosteren fonksiyondur.
void ConnectFour::endOfGame()const
{
	int userCount = 0; 
	int computerCount = 0;

	for (int i = 0; i < gameCells.size(); ++i)
		for (int j = 0; j < gameCells[i].size(); ++j) 
		{
			if (gameCells[i][j].getUserSym() == 'X')
				userCount++;
			else if (gameCells[i][j].getUserSym() == 'O')
				computerCount++;
		}

	if (userCount > computerCount)
		cout << " You win" << endl;
	else if (userCount < computerCount)
		cout << "You can't won game" << endl;
	else
		cout << "Sorry You are draw" << endl;
}

//Computerin tek hamle yaptigi fonksiyondur.
void ConnectFour::play()
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
	cout<<"totalcell = "<< total <<endl;	
}

//Userin tek hamle yaptigi fonksiyondur.
void ConnectFour::play(string selectLetter)

{
	vector<string>letter = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
	char selectPlayer;

	cout<<"User1 please you select a character in board"<<endl;
	cin.clear();
	getline(cin, selectLetter);
	string parse1 = selectLetter.substr(0, selectLetter.find(" "));
	string parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));
			
	totalLivingCells++;

	if(parse1 == "SAVE")
	{
		saveFile(parse1,parse2);
		cout<<"User please you select a character in board"<<endl;
		cin.clear();
		getline(cin, parse1);
				
		legalLetterFunc(parse1,'X');
				
	}
	else if(parse1 == "LOAD" )
	{		
												
		loadFile(parse1,parse2);
		cout<<"User please you select a character in board"<<endl;
		getline(cin, parse1);
		legalLetterFunc(parse1, 'X');
				
	}
	else
	{
		legalCheckFunction(parse1, 'X');
	}
				
		int total = totalCell();
		cout<<"totalcell = "<< total <<endl;
		
}
