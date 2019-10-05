
/*
 * HW2_131044055_EDA_BAHRIOGLU
 * Source File
 *
 * Created on 04.10.2017 by EDA BAHRIOGLU
 */

#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <cstring>

const int MIN_SIZE = 4; // TabLo için minimum size
const int MAX_SIZE = 20; // Table için maximum size

using namespace std;
//Boardu ekrana basan fonksiyondur.
void printBoard(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize);

//Boardun başlangic durumundaki boş halini oluşturan fonksiyon
int startingBoard(char boardArray[MAX_SIZE][MAX_SIZE]);

//Default argumenli fonksiyondur.
//Taslarin hamleleri icin gidebilecekleri doğru alanlarin kontrolü yapılır.
void legalCheckFunction(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, string selectLetter, char user1Character, int satir=-1);

//Dikey haretin yapildigi ve dikey 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
void downMove(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, int &col);

//Yatay haretin yapildigi ve yatay 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
void rightMove(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, int &col);

//Soldan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
void crossLeftMove(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, int &col);

//Sagdan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
void crossRightMove(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize,int &col);

//Dosyaya yazma islemini yapan fonksiyondur.
void saveFile(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, string selectLetter,string filename);

//Dosyadan okuma  islemini yapan fonksiyondur.
void loadFile(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, string selectLetter, string filename);

//Hamleler için kullanilan fonksiyondur.
void legalLetterFunc(char boardArray[MAX_SIZE][MAX_SIZE], string parse1, const int &boardSize, char user);


int main(){
 
	
    char boardArray[MAX_SIZE][MAX_SIZE]; 
	string letter[] = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","R", "S", "T", "U"};
	char selectPlayer;
	auto user1Character = 'X', user2Character = 'O';
	string selectLetter;

	int size;	

	cout << "#WELCOME TO CONNECT FOUR GAME#" << endl;
	cout << "Please enter board size: "<< endl;
	size = startingBoard(boardArray);
	cout << "You must select player"<< endl;
	cin >> selectPlayer;
	cin.clear();
	cin.ignore();

//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
	if(selectPlayer=='P')
	{

		cout << "START GAME WITH USER1 AND USER2" << endl;
		printBoard(boardArray, size);
		
		for(int i=0; i<(size*(size/2)); ++i)
		{
			cout<<"User1 please you select a character in board"<<endl;
			cin.clear();
			getline(cin, selectLetter);
			string parse1 = selectLetter.substr(0, selectLetter.find(" "));
			string parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));
			
			
			if(parse1 == "SAVE")
			{
				cout<<"User1 please you select a character in board"<<endl;
				cin.clear();
				getline(cin, parse1);
				saveFile(boardArray,size, parse1,parse2);
				legalLetterFunc(boardArray, parse1, size, 'X');
				
			}
			else if(parse1 == "LOAD" )
			{		
												
				loadFile(boardArray,size, parse1,parse2);
				cout<<"User1 please you select a character in board"<<endl;
				getline(cin, parse1);
				legalLetterFunc(boardArray, parse1, size, 'X');
				
			}
			else
			{
				legalCheckFunction(boardArray,size, parse1, 'X');
			}
				cout<<"User2 please you select a character in board"<<endl;	
				cin.clear();
				getline(cin, selectLetter);
				parse1 = selectLetter.substr(0, selectLetter.find(" "));
				parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));					
				
					
			if(parse1 == "SAVE")
			{
				cout<<"User2 please you select a character in board"<<endl;	
				cin.clear();
				getline(cin, parse1);
				saveFile(boardArray,size, parse1,parse2);				
				legalLetterFunc(boardArray, parse1, size, 'O');
				
	
			}
			else if(parse1 == "LOAD" )
			{	
								
				loadFile(boardArray,size, parse1,parse2);
				cout<<"User2 please you select a character in board"<<endl;			
				getline(cin, parse1);	
				legalLetterFunc(boardArray, parse1, size, 'O');
				
			}
			else
			{	
				legalCheckFunction(boardArray,size, parse1, 'O');
			}

		}

	}
//Oyunun bir kullanıcı ve bir bilgisayar arasında oynanma durumunu kontrol edildigi bolumdur.
	else if(selectPlayer=='C')
	{
		cout << "START GAME WITH COMPUTER AND USER" << endl;
		printBoard(boardArray, size);

		for(int i=0; i<(size*(size/2)); ++i)
		{
			cout<<"User1 please you select a character in board"<<endl;
			cin.clear();
			getline(cin, selectLetter);
			string parse1 = selectLetter.substr(0, selectLetter.find(" "));
			string parse2 = selectLetter.substr(parse1.size(), selectLetter.find("\n"));
			
			
			if(parse1 == "SAVE")
			{
				cout<<"User1 please you select a character in board"<<endl;
				cin.clear();
				getline(cin, parse1);
				saveFile(boardArray,size, parse1,parse2);
				legalLetterFunc(boardArray, parse1, size, 'X');
				
			}
			else if(parse1 == "LOAD" )
			{		
												
				loadFile(boardArray,size, parse1,parse2);
				cout<<"User1 please you select a character in board"<<endl;
				getline(cin, parse1);
				legalLetterFunc(boardArray, parse1, size, 'X');
				
			}
			else
			{
				legalCheckFunction(boardArray,size, parse1, 'X');
			}

			cout<<"Wait!!!Computer(User2) will select a character in board"<<endl;		
	
			decltype(size) k = 0+(rand () % size);
			string randomLetter = letter[k];
			legalCheckFunction(boardArray,size, randomLetter, 'O');
				
		}

	}

//Yanlis girilen komut durumunda kontrol edilir.
	else
	{
		cerr<<"FAILURE COMMAND"<<endl;
		exit(1);
	}

	return 0;

}

//Board ekranda gösterilir.
void printBoard(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize) 
{
	string letter[] = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","R", "S", "T", "U"};
	int i, j;
	
	for (i = 0; i < boardSize; i++)
		cout << letter[i];
		cout << endl;

	for (i = 0; i < boardSize; i++) 
	{
		for (j = 0; j < boardSize; j++)
			cout << boardArray[i][j];
			cout << endl;
			j = 0;
	}
}


//Oyunun başlangıç durumundaki boş board un oluşturulduğu fonksiyondur.
int startingBoard(char boardArray[MAX_SIZE][MAX_SIZE]) {

	int boardSize;
	int j; 

	cin >> boardSize;

	while (!cin || boardSize < MIN_SIZE || boardSize > MAX_SIZE || boardSize % 2 == 1) 
	{
		cin.clear();
		cin.ignore(1000,'\n');
		cerr<<"You entered wrong character\n";
		cerr << "Please try again: "<<endl;	

		cin >> boardSize;
	}

	for (int i = 0; i < boardSize; i++) 
	{
		
		for (j = 0; j < boardSize; j++)
			boardArray[i][j] = '.';   
			j = 0;

	}

	return boardSize;
}

//Taslarin haraketinin legal oldugunun kontrolu yapılır.
//Nokta olan yerlere hamle yapilabilirken nokta olmayan yerler atalnır. 
void legalCheckFunction(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, string selectLetter, char user1Character, int satir){


	string letter[] = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","R", "S", "T", "U"};
	auto i = 0;

	for(i=0;i<boardSize;++i)
	{
		if(selectLetter == letter[i]){
			satir=i;
			i=boardSize;
		}
	}

	if(satir>=0)
		for (i=boardSize-1; i>=0; --i)
		{
			if(boardArray[i][satir] == '.') {
				boardArray[i][satir] = user1Character;
				i=-1;
			}
		}
//Tas ların tüm kazanma durumlarinin kontrolünün yapildiği fonksiyonlarin cagirildigi bölümdür.
	else
		cerr<<"Select Character is not in board.Another player will play"<<endl;
			
		printBoard(boardArray,boardSize);
		rightMove(boardArray,boardSize,satir);
		downMove(boardArray,boardSize,satir);	
		crossLeftMove(boardArray,boardSize,satir);
		crossRightMove(boardArray,boardSize,satir);
}

//Yatay yönde yapilan tas hareketleridir.4 yatay ayni tas yanyana gelmesi durumu kazanma durumudur.
//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
void rightMove(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, int &col)
{
	char user='.';
	auto count=0;
	int i,j;
	col=0;
 
	while(col<boardSize)
	{
		count=0;
		for(i=1; i<boardSize; ++i)
		{
			if(boardArray[col][i-1] !='.' && boardArray[col][i] !='.')

				if(boardArray[col][i-1] == boardArray[col][i])
				{
					user=boardArray[col][i-1];
					++count;
				}
				else{
					count=0;
					user='.';		
				}

			if(count>=3)
			{
				for(j=i;j>i-4;--j)//Harf kücültme kontrolu

					boardArray[col][j] = user+32;
					printBoard(boardArray,boardSize);

				if(user=='X')//4 x tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER1 WIN"<<endl;
				}
				else if(user=='O')//4 o tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER2  WIN"<<endl;
				}
			
				exit(1); 
			}
		}
		
		col++;
	}
}

//Dikey yönde yapilan tas hareketleridir.4 dikey ayni tas yanyana gelmesi durumu kazanma durumudur.
//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
void downMove(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, int &col)
{
	char user='.';
	auto count=0;
	int i,j;
	col=0;

	while(col<boardSize)
	{
		count=0;
		for(i=1; i<boardSize; ++i)
		{
			if(boardArray[i-1][col] !='.' && boardArray[i][col] !='.')

				if(boardArray[i-1][col] == boardArray[i][col])
				{
					user=boardArray[i-1][col];
					++count;
				}
				else{
					count=0;
					user='.';		
				}

			if(count>=3)
			{
			
				for(j=i;j>i-4;--j)//Harf kücültme kontrolu

					boardArray[j][col] = user+32;
					printBoard(boardArray,boardSize);
			
				if(user=='X')//4 x tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER1 WIN"<<endl;
				}
				else if(user=='O')//4 o tasinin yanyana olup olmadigi kontrolu
				{
					cout<<"USER2  WIN"<<endl;
				}
				
				exit(1); 
			}
		}
		col++;
	}
}


//Sol taraftan baslayan capraz harekettir.4 tasın soldan yanayana gelmesi durumunda oyun kazanılır.
void crossLeftMove(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, int &col)
{
	
	char user='.';
	int i,j;
	auto Ocount=0;
	auto Xcount=0;	
	col=0;

	while(col<boardSize)
	{
	
		for(i=1; i<boardSize; ++i)
		{
			if(boardArray[i-1][col] !='.' && boardArray[i][col+1] !='.')

				if(boardArray[i-1][col] == boardArray[i][col+1])
				{
					
					if(boardArray[i-1][col] == 'X')
					{
						++Xcount;				
		
					}
					else if(boardArray[i-1][col] == 'O')
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

			exit(1);
		}
		else if(Ocount >= 3)//4 o tasinin yanyana olup olmadigi kontrolu
		{	
	
			cout<<"USER2 WIN"<<endl;
	
			exit(1);
		}

}

//Sag taraftan baslayan capraz harekettir.4 tasın sagdan yanayana gelmesi durumunda oyun kazanılır.
void crossRightMove(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize, int &col)
{	
	char user='.';
	int i,j;
	auto Ocount=0;
	auto Xcount=0;		
	col=0;

	while(col<boardSize)
	{	
		for(i=0; i<boardSize-1; ++i)
		{
			if(boardArray[i][col+1] !='.' && boardArray[i+1][col] !='.')
				if(boardArray[i][col+1] == boardArray[i+1][col])
				{
					if(boardArray[i][col+1] =='X')
					{
						++Xcount;					
					}			
					else if(boardArray[i][col+1] == 'O')
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
			
			/*for(i=0; i<boardSize-1; ++i)//Harf kücültme kontrolu
			{
				for(j=i;j>i-4;--j)

					boardArray[j+1][col] = boardArray[j][col+1]+32;
					
			}	
			printBoard(boardArray,boardSize);	*/	
			cout<<"USER1 WIN"<<endl;

			
			exit(1);
		}
	
		else if(Ocount >= 3 )//4 o tasinin yanyana olup olmadigi kontrolu
	    {	
			
			cout<<"USER2 WIN"<<endl;

			exit(1);
		}
		
}

//parametre olarak gonderilen dosya ismindeki dosyaya oyunun istenilen andaki board unu kaydeder.
void saveFile(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize ,string selectLetter, string filename)
{
	ofstream saveFile;
	saveFile.open(filename);
	
		int k,l;
		if(saveFile.is_open()==false)
		{
			cerr << "Output file opening failed." << endl;
			exit(1);
		}

		auto satir=-1;
		string letter[] = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","R", "S", "T", "U"};
		auto i = 0;

		for(i=0;i<boardSize;++i)
		{
			if(selectLetter == letter[i]){
				satir=i;
				i=boardSize;
			}
		}

		//	printBoard(boardArray,boardSize);
			rightMove(boardArray,boardSize,satir);
			downMove(boardArray,boardSize,satir);	
			crossLeftMove(boardArray,boardSize,satir);
			crossRightMove(boardArray,boardSize,satir);


		for (k = 0; k < boardSize; k++) 
		{
			for (l = 0; l < boardSize; l++)
				saveFile << boardArray[k][l];
				saveFile << endl;
				l = 0;
		}
				
	saveFile.close();
	
}

//Dosyadan okudugu boardu ekrana basar ve oyunu kaldıgı kaydedilen yerden devam etirerek ilerletir.
void loadFile(char boardArray[MAX_SIZE][MAX_SIZE], const int &boardSize,string selectLetter, string filename)
{
	ifstream loadFile;
	string row;
			
	int k,l;
	
	loadFile.open(filename);

	if(loadFile.is_open()==false)
	{
		cerr << "Output file opening failed." << endl;
		exit(1);
	}
		
		for (k = 0; k < boardSize; k++) 
		{
			for (l = 0; l < boardSize; l++)
				loadFile >> boardArray[k][l];
				
		}
			
		printBoard(boardArray,boardSize);
		loadFile.close();	
}

 
//Hamleelrin yapılmasında kullanilan fonksiyondur.Sartlara girerken kullanilmak icin yazilmistir.
void legalLetterFunc(char boardArray[MAX_SIZE][MAX_SIZE], string parse1, const int &boardSize, char user)
{
	int satir=-1;
	string letter[] = {"A", "B", "C", "D", "E", "F", "G", "H","I", "J", "K", "L", "M", "N", "O", "P","R", "S", "T", "U"};
	auto i = 0;

	for(i=0;i<boardSize;++i)
	{
		if(parse1 == letter[i])
		{
			satir=i;
			i=boardSize;
		}
	}

	if(satir>=0)
		for (i=boardSize-1; i>=0; --i)
		{
			if(boardArray[i][satir] == '.') 
			{
				boardArray[i][satir] = user;
				i=-1;
			}
		}

	printBoard(boardArray,boardSize);

}
