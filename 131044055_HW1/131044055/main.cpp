
/*
 * HW1_131044055_EDA_BAHRIOGLU
 * Source File
 *
 * Created on 25.09.2017 by EDA BAHRIOGLU
 */

#include <iostream>
#include <cstdlib>
#include <ctype.h>

const int MIN_SIZE = 4; // TabLo için minimum size
const int MAX_SIZE = 20; // Table için maximum size

//Boardu ekrana basan fonksiyondur.
void printBoard(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize);

//Boardun başlangic durumundaki boş halini oluşturan fonksiyon
int startingBoard(char boardArray[MAX_SIZE][MAX_SIZE]);

//Taslarin hamleleri icin gidebilecekleri doğru alanlarin kontrolü yapılır.
void legalCheckFunction(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize, char selectLetter, char user1Character);

//Dikey haretin yapildigi ve dikey 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
void downMove(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize);

//Yatay haretin yapildigi ve yatay 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
void rightMove(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize);

//Soldan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
void crossLeftMove(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize);

//Sagdan baslayan capraz haretin yapildigi ve capraz 4 lunun kazanılma durumunu kontrol eden fonksiyondur.
void crossRightMove(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize);

using namespace std;

int main(){
  
    char boardArray[MAX_SIZE][MAX_SIZE]; 
	int size,k;
	char letter[MAX_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','R', 'S', 'T', 'U'};
	char selectPlayer;
	char user1Character = 'X', user2Character = 'O', selectLetter;

	cout << "#WELCOME TO CONNECT FOUR GAME#" << endl;
	cout << "Please enter board size: "<< endl;
	size = startingBoard(boardArray);
	

	cout << "You must select player"<< endl;
	cin >> selectPlayer;

//Oyunun iki user arasında oynanma durumunu kontrol edildigi bolumdur.
	if(selectPlayer=='P')
	{

		cout << "START GAME WITH USER1 AND USER2" << endl;
		printBoard(boardArray, size);

		for(int i=0; i<(size*(size/2)); ++i)
		{
			cout<<"User1 please you select a character in board"<<endl;
			cin>>selectLetter;
			legalCheckFunction(boardArray,size, selectLetter, 'X');			
			
			cout<<"User2 please you select a character in board"<<endl;
			cin>>selectLetter;
			legalCheckFunction(boardArray,size, selectLetter, 'O');
				
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
			cin>>selectLetter;		
		    legalCheckFunction(boardArray,size, selectLetter, 'X');

			cout<<"Wait!!!Computer(User2) will select a character in board"<<endl;				
			k = 0+(rand () % size);
			char randomLetter = letter[k];
			legalCheckFunction(boardArray,size, randomLetter, 'O');
				
		}

	}

//Yanlis girilen komut durumunda kontrol edilir.
	else
	{
		cout<<"FAILURE COMMAND"<<endl;
	}
	
	return 0;

}

//Board ekranda gösterilir.
void printBoard(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize) 
{
	char letter[MAX_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','R', 'S', 'T', 'U'};
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
		cout<<"You entered wrong character\n";
		cout << "Please try again: "<<endl;	
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
void legalCheckFunction(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize, char selectLetter, char user1Character){

	int satir=-1;
	char letter[MAX_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I', 'J', 'K', 'L', 'M', 'N', 'O', 'P','R', 'S', 'T', 'U'};
	int i = 0;

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
		cout<<"Select Character is not in board.Another player will play"<<endl;
			
		printBoard(boardArray,boardSize);
		rightMove(boardArray,boardSize);
		downMove(boardArray,boardSize);	
		crossLeftMove(boardArray,boardSize);
		crossRightMove(boardArray,boardSize);
}

//Yatay yönde yapilan tas hareketleridir.4 yatay ayni tas yanyana gelmesi durumu kazanma durumudur.
//Kazanilma durumu son durumda harflerin kucultulmasıyla kontrol edilir.
void rightMove(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize)
{
	char user='.';
	int col=0,count=0,i,j;

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
void downMove(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize)
{
	char user='.';
	int col=0,count=0,i,j;

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
void crossLeftMove(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize)
{
	
	char user='.';
	int col=0,i,j;
	int Ocount=0;
	int Xcount=0;	

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
void crossRightMove(char boardArray[MAX_SIZE][MAX_SIZE], int boardSize)
{	
	char user='.';
	int col=0,i,j;
	int Ocount=0;
	int Xcount=0;	
	
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
			
			printBoard(boardArray,boardSize);
			cout<<"USER2 WIN"<<endl;
			exit(1);
		}
		
}
