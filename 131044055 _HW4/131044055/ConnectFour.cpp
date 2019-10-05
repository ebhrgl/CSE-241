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
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;

int ConnectFour::totalLivingCells = 0;

ConnectFour::Cell::Cell()
{

	setrow(0);
	setColumn(0);
	setUserSym('*');
	setincrement('*');
}

ConnectFour::Cell::Cell(int row, int column)
{
	setrow(row);
	setColumn(column);
	setUserSym('*');
	setincrement('*');
}

ConnectFour::Cell::Cell(int row ,int column, char userSymbol, char incrementChar)
{
	setrow(row);
	setColumn(column);
	setUserSym(userSymbol);
	setincrement(incrementChar);
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
		
void ConnectFour::Cell::setincrement(char incrementValue)
{
	incrementChar = incrementValue;
}

void ConnectFour::Cell::setCharline(char charValue)
{
	charline = charValue;
}

bool ConnectFour::Cell::operator==(const Cell &other) const
{

	if(getColumn() == other.getColumn() && getrow() == other.getrow())
		return true;
	else
		return false;

}

const ConnectFour::Cell operator++( ConnectFour::Cell& obje)
{
	char user1 = 'X';
	char user2 = 'Y';
	char computer= 'C';
	char empty = '*';
	ConnectFour x;
	for (int i = 0; i < obje.getrow() ; i++) 
	{		
		for (int j = 0; j < obje.getColumn(); j++)
		{			
			if(x.gameBoard[i][j].getincrement() == empty)
			{
				x.gameBoard[i][j].setincrement(user1); 
			}
			else if(x.gameBoard[i][j].getincrement() == user1)
			{
				x.gameBoard[i][j].setincrement(user2); 
			}
			else if(x.gameBoard[i][j].getincrement() == user2)
			{
				x.gameBoard[i][j].setincrement(computer);
			}
			else if(x.gameBoard[i][j].getincrement() == computer)
			{
				x.gameBoard[i][j].setincrement(empty);
			}
		}
	}
	return ConnectFour::Cell(obje.getrow(), obje.getColumn(), obje.getUserSym(), obje.getincrement());
}


const  ConnectFour::Cell operator++(ConnectFour::Cell& obje, int value)
{
	char user1 = 'X';
	char user2 = 'Y';
	char computer= 'C';
	char empty = '*';
	ConnectFour y;

	ConnectFour::Cell first(obje.getrow(), obje.getColumn(), obje.getUserSym(), obje.getincrement());

	for (int i = 0; i < obje.getrow() ; i++) 
	{		
		for (int j = 0; j < obje.getColumn(); j++)
		{			
			if(y.gameBoard[i][j].getincrement() == empty)
			{
				y.gameBoard[i][j].setincrement(user1); 
			}
			else if(y.gameBoard[i][j].getincrement() == user1)
			{
				y.gameBoard[i][j].setincrement(user2); 
			}
			else if(y.gameBoard[i][j].getincrement() == user2)
			{
				y.gameBoard[i][j].setincrement(computer);
			}
			else if(y.gameBoard[i][j].getincrement() == computer)
			{
				y.gameBoard[i][j].setincrement(empty);
			}
		}
	}
	return first;
}


istream& operator>>(istream& inputStream,ConnectFour::Cell& obje)
{
	int valueRow, valueCol;
	char symbolUser;

	cout<<"row->";
	inputStream >> valueRow;
	obje.setrow(valueRow);

	cout<<"column->";
	inputStream >> valueCol;
	obje.setColumn(valueCol);

	cout<<"symbol->";
	inputStream >> symbolUser;
	obje.setUserSym(symbolUser);

	return inputStream;
}


ostream& operator<<(ostream& outputStream, const ConnectFour::Cell& obje)
{
	outputStream << "row->";
	outputStream << obje.getrow();

	outputStream << "column->";
	outputStream << obje.getColumn();

	outputStream << "symbol";
	outputStream << obje.getUserSym();

	return outputStream; 
}


ConnectFour::ConnectFour()
{
	
	setWidth(5);
	setHeight(5);
	setPlayer('P');

	gameBoard = new Cell*[getHeight()];
	for(int i=0; i<getHeight(); i++)
		gameBoard[i] = new Cell[getWidth()];

	startingBoard();	
}
	   
ConnectFour::ConnectFour(int widthValue, int heightValue)
{
	
	setWidth(widthValue);
	setHeight(heightValue);
	setPlayer('P');

	gameBoard = new Cell*[getHeight()];
	for(int i=0; i<getHeight(); i++)
		gameBoard[i] = new Cell[getWidth()];

	startingBoard();
	
}

ConnectFour::ConnectFour(int widthValue, int heightValue, char PlayerLetter)
{
	//cout<<"en:"<<widthValue<<" boy:"<<heightValue<<" letter:"<<PlayerLetter<<endl;
	

	setWidth(widthValue);
	setHeight(heightValue);
	setPlayer(PlayerLetter);

	gameBoard = new Cell*[getHeight()];
	for(int i=0; i<getHeight(); i++)
		gameBoard[i] = new Cell[getWidth()];

	startingBoard();
	
}

ConnectFour::ConnectFour(string filename)
{
	readFunc(filename);
}

ConnectFour::ConnectFour(const ConnectFour& other)
{
	setHeight(other.getHeight());
    setWidth(other.getWidth());
   //setPlayer(other.getPlayer());
  

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
	//totalLivingCells++;
}

ConnectFour& ConnectFour::operator=(const ConnectFour& rhs)
{
	if(this == &rhs)
	{
		return *this;
	}
	else
	{
		setWidth(rhs.getWidth());
		setHeight(rhs.getHeight());

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

ConnectFour::~ConnectFour()
{
	for(int i = 0; i < getHeight(); i++)
	{
 		delete gameBoard[i];
 	}
	delete gameBoard;

	//totalLivingCells--;*/
}


void ConnectFour::setWidth(int widthValue)
{
	if(widthValue > 0 )
	{
		boardWidth = widthValue;
	}
	else
		boardWidth=4;
}
	   
void ConnectFour::setHeight(int heightValue)
{
	if(heightValue > 0)
	{
		boardHeight = heightValue;
	}
	else
		boardHeight=4;
}

void ConnectFour::setPlayer(char PlayerLetter)
{
	player = PlayerLetter;
}



//Board ekranda gösterilir.
void ConnectFour::printBoard() const
{
	string letter[] = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
	int i, j;
//cout<<"En:"<<getWidth()<<endl;
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
void ConnectFour::loadFile(string selectLetter, string filename)
{
	ifstream loadFile;

	loadFile.open(filename);

	if(loadFile.is_open()==false)
	{
		cerr << "Output file opening failed." << endl;
		exit(1);
	}

	int i,j;

	for (i = 0; i <getHeight() ; i++) 
	{			
		for (j = 0; j < getWidth(); j++)
		{	
			loadFile >> gameBoard[i][j];			
		}	
	}
	printBoard();
	loadFile.close(); 
}

//Oyunun başlangıç durumundaki boş board un oluşturulduğu fonksiyondur.
bool ConnectFour::startingBoard() 
{
	
	int i,j;
	for (i = 0; i <getHeight() ; i++) 
	{		
		for (j = 0; j < getWidth(); j++)
		{	
			gameBoard[i][j].setUserSym('*');
		}
		
	}

}

//Oyunun tamaminin oynandigi kisimdir.
void ConnectFour::playGame()
{
	char selectPlayer;
	auto user1Character = 'X', user2Character = 'O';
	int total,son=-1;

	selectPlayer = getPlayer();
	
	cout << "START GAME WITH COMPUTER AND USER" << endl;
	//printBoard();
		
	for(int i=0; i<(boardHeight * boardWidth); ++i)
	{
		play(user1Character);
		
		son=endOfGame();

		//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
		if(selectPlayer=='C' || selectPlayer=='c')
		{
			play();	
		}
		else if(selectPlayer=='P' || selectPlayer=='p')
		{
			play(user2Character);
		}
			
		total = totalCell();
		cout<<"totalcell = "<< total <<endl;
		son=endOfGame();

		if(son>0)
			i=(boardHeight * boardWidth);
	}
}

//Computerin tek hamle yaptigi fonksiyondur.
void ConnectFour::play()
{
	vector<string>letter = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
	char selectPlayer;
	int total;
	selectPlayer = getPlayer();
	cout<<"Wait!!!Computer(User2) will select a character in board"<<endl;		
	
	decltype(boardWidth) k = 0+(rand () % boardWidth);
	string randomLetter = letter[k];
	legalCheckFunction(randomLetter, 'O');

	totalLivingCells++;
}

//Userin tek hamle yaptigi fonksiyondur.
void ConnectFour::play(char user)
{
	string selectLetter;
	string ad;
	char selectPlayer;
	
	selectPlayer = getPlayer();

	if(user=='X')
		ad="User1";
	else
		ad="User2";
	
	cin.clear();
	cout<<ad<<" please you select a character in board"<<endl;
	getline(cin, selectLetter);
	cout<<"girilen:"<<selectLetter<<endl;
	string parse1 = selectLetter.substr(0, selectLetter.find(" "));
	string parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));

	if(parse1 == "SAVE")
	{
		saveFile(parse1,parse2);
		cout<<ad<<" please you select a character in board"<<endl;
		cin.clear();
		getline(cin, parse1);
	}
	else if(parse1 == "LOAD" )
	{		

		readFunc(parse2);
		cout<<ad<<" please you select a character in board"<<endl;
		getline(cin, parse1);
	}
	legalCheckFunction(parse1, user);
}

//Oyunun sonunu gosteren fonksiyondur.
int ConnectFour::endOfGame() const
{
	int konum=0,r,d,cl,cr;
	printBoard();	
	r=rightMove(konum);
	d=downMove(konum);	
	cl=crossLeftMove(konum);
	cr=crossRightMove(konum);
	if(r>0) 
		return r;
	else if(d>0)
		return d;
	else if(cl>0)
		return cl;
	else if(cr>0)
		return cr;
	else
		return 0;
}

//Taslarin haraketinin legal oldugunun kontrolu yapılır.
//Nokta olan yerlere hamle yapilabilirken nokta olmayan yerler atalnır. 
void ConnectFour::legalCheckFunction(string selectLetter, char user1Character, int satir)
{
	vector<string>letter = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","Q","R", "S", "T", "U","V", "W", "X", "Y", "Z"};
	vector<string>kletter = {"a", "b", "c", "d", "e", "f", "g", "h","i", "j", "k", "l", "m", "n", "o", "p","q","r", "s", "t", "u","v", "w", "x", "y", "z"};
	int i = 0;

	for(i=0;i<getWidth();++i)
	{
		if(selectLetter == letter[i] || selectLetter == kletter[i])
		{
			satir=i;
			i=getWidth();
		}
	}
//cout<<"karakter:"<<selectLetter<<" user:"<<user1Character<<" satir:"<<satir<<endl;
	if(satir>=0)
		for (i=getHeight()-1; i>=0; --i)
		{
			if(gameBoard[i][satir].getUserSym()== '*') 
			{
				//cout<<" satir:"<<i<<" sutun:"<<satir<<endl;
				gameBoard[i][satir].setUserSym(user1Character);
				i=0;
			}

		}
	else  //Tas ların tüm kazanma durumlarinin kontrolünün yapildiği fonksiyonlarin cagirildigi bölümdür.
		cerr<<"Select Character is not in board.Another player will play"<<endl;
		
	totalLivingCells++;
}

//Hamleelrin yapılmasında kullanilan fonksiyondur.Sartlara girerken kullanilmak icin yazilmistir.
void ConnectFour::legalLetterFunc() const
{
	int userCount = 0; 
	int computerCount = 0;

	for (int i = 0; i < sizeof(gameBoard); ++i)
		for (int j = 0; j < sizeof(gameBoard[i]); ++j) 
		{
			if (gameBoard[i][j].getUserSym() == 'X')
				userCount++;
			else if (gameBoard[i][j].getUserSym() == 'O')
				computerCount++;
		}

	if (userCount > computerCount)
		cout << " You win" << endl;
	else if (userCount < computerCount)
		cout << "You can't won game" << endl;
	else
		cout << "Sorry You are draw" << endl;
}

//Dikey yönde yapilan tas hareketleridir.4 dikey ayni tas yanyana gelmesi durumu kazanma durumudur.
//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
int ConnectFour::downMove(int &col)const
{
	char user;
	auto count=0;
	int i,j;
	col=0;

	while(col<getWidth())
	{
		count=0;
		for(i=1; i<getHeight(); ++i)
		{
			if(gameBoard[i-1][col].getUserSym() !='*' && gameBoard[i][col].getUserSym() !='*')
				if(gameBoard[i-1][col].getUserSym() == gameBoard[i][col].getUserSym())
				{
					user = gameBoard[i-1][col].getUserSym();
					++count;
				}
				else{
					count=0;
					//user='*';		
				}
			if(count>=5)
			{
				if(user=='X')//4 x tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER1 WIN"<<endl;
					//legalLetterFunc();
					return 1;
				}
				else if(user=='O')//4 o tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER2  WIN"<<endl;
					//legalLetterFunc();
					return 2;
				}
				//exit(1); 
				col=getWidth();
				i=getHeight();
			}
		}
		col++;
	}
	return 0;
	
}

//Yatay yönde yapilan tas hareketleridir.4 yatay ayni tas yanyana gelmesi durumu kazanma durumudur.
//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
int ConnectFour::rightMove(int &col)const
{
	char user='*';
	auto count=0;
	int i,j;
	col=0;
 
	while(col<getHeight())
	{
		count=0;
		for(i=1; i<getWidth(); ++i)
		{
			if(gameBoard[col][i-1].getUserSym() !='*' && gameBoard[col][i].getUserSym() !='*')
				if(gameBoard[col][i-1].getUserSym() == gameBoard[col][i].getUserSym())
				{
					user=gameBoard[col][i-1].getUserSym();
					++count;
				}
				else{
					count=0;
					user='*';		
				}
			if(count>=5)
			{
				if(user=='X')//4 x tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER1 WIN"<<endl;
					//legalLetterFunc();
					return 1;
				}
				else if(user=='O')//4 o tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER2  WIN"<<endl;
					//legalLetterFunc();
					return 2;
				}
				//exit(1); 
				i=getWidth();
				col=getHeight();
			}
		}
		col++;
	}
	return 0;
}

//Sol taraftan baslayan capraz harekettir.4 tasın soldan yanayana gelmesi durumunda oyun kazanılır.
int ConnectFour::crossLeftMove(int &col)const
{
	char user='*';
	int i,j;
	auto Ocount=0;
	auto Xcount=0;	
	col=0;

	while(col<getWidth())
	{
		for(i=1; i<getHeight(); ++i)
		{
			if(gameBoard[i-1][col].getUserSym() !='*' && gameBoard[i][col+1].getUserSym() !='*')
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
						user='*';	
						Ocount=0;					
					}
				}
		}
		col++;
	}	
	if(Xcount >= 3)//4 x tasinin yanyana olup olmadigi kontrolu
	{
		cout<<"USER1 WIN"<<endl;
		//legalLetterFunc();
		return 1;
			//exit(1);
	}
	else if(Ocount >= 3)//4 o tasinin yanyana olup olmadigi kontrolu
	{	
		cout<<"USER2 WIN"<<endl;
		//legalLetterFunc();
		return 2;
			//exit(1);
	}
	return 0;
}

//Sag taraftan baslayan capraz harekettir.4 tasın sagdan yanayana gelmesi durumunda oyun kazanılır.
int ConnectFour::crossRightMove(int &col)const
{
	char user='*';
	int i,j;
	auto Ocount=0;
	auto Xcount=0;		
	col=0;

	while(col<getWidth())
	{	
		for(i=0; i<getHeight()-1; ++i)
		{
			if(gameBoard[i][col+1].getUserSym() !='*' && gameBoard[i+1][col].getUserSym() !='*')
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
						user='*';
						Ocount=0;						
					}
				}
		}		
		col++;
	}
	if(Xcount >= 3)//4 x tasinin yanyana olup olmadigi kontrolu
	{	
		cout<<"USER1 WIN"<<endl;
		//legalLetterFunc();
		return 1;
	}
	else if(Ocount >= 3 )//4 o tasinin yanyana olup olmadigi kontrolu
	{
		cout<<"USER2 WIN"<<endl;
		//legalLetterFunc();
		return 2;
	}
	return 0;
}
bool ConnectFour::operator==(const ConnectFour& other)const
{
	int userplay1 = 0;
	int userplay2 = 0;
	int computerplay1 = 0;
	int computerplay2 = 0;
	int value1, value2;

	for (int i = 0; i < sizeof(gameBoard); ++i) 
	{
		for (int j = 0; j < sizeof(gameBoard[i]); ++j) 
		{
			if (gameBoard[i][j].getUserSym() == 'X')
				userplay1++;
			
			else if(gameBoard[i][j].getUserSym() == 'O') 
				computerplay1++;
		}
	}

	for (int i = 0; i < sizeof(other.gameBoard); ++i) 
	{
		for (int j = 0; j < sizeof(other.gameBoard[i]); ++j) 
		{
			if (other.gameBoard[i][j].getUserSym() == 'X')
				userplay2++;

			else if(other.gameBoard[i][j].getUserSym() == 'O')
				computerplay2++;
		}
	}

	value1 = userplay1 - computerplay1;
	value2 = userplay2 - computerplay2;

	if(value1 == value2)
		return true;
	else 
		return false;
}

bool ConnectFour::operator!=(const ConnectFour& other)const
{
	int userplay1 = 0;
	int userplay2 = 0;
	int computerplay1 = 0;
	int computerplay2 = 0;
	int value1, value2;

	for (int i = 0; i < sizeof(gameBoard); ++i) 
	{
		for (int j = 0; j < sizeof(gameBoard[i]); ++j) 
		{
			if (gameBoard[i][j].getUserSym() == 'X')
				userplay1++;
			
			else if(gameBoard[i][j].getUserSym() == 'O') 
				computerplay1++;
		}
	}

	for (int i = 0; i < sizeof(other.gameBoard); ++i) 
	{
		for (int j = 0; j < sizeof(other.gameBoard[i]); ++j) 
		{
			if (other.gameBoard[i][j].getUserSym() == 'X')
				userplay2++;

			else if(other.gameBoard[i][j].getUserSym() == 'O')
				computerplay2++;
		}
	}

	value1 = userplay1 - computerplay1;
	value2 = userplay2 - computerplay2;

	if(value1 != value2)
		return true;
	else 
		return false;
}

void ConnectFour::readFunc(string filename)
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
	printBoard();
	loadFile.close();

}