#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
char token='x';
string player1,player2;
bool tie;
void structure()
{
     // creating structure
     cout<<"    |    |    \n";
     cout<<""<<space[0][0]<<"   |" <<space[0][1]<<"   |" <<space[0][2]<<"    \n";
     cout<<"____|____|____\n";
     cout<<"    |    |    \n";
     cout<<""<<space[1][0]<<"   |" <<space[1][1]<<"   |" <<space[1][2]<<"    \n";
     cout<<"____|____|____\n"; 
     cout<<"    |    |    \n";
     cout<<""<<space[2][0]<<"   |" <<space[2][1]<<"   |" <<space[2][2]<<"    \n";
     cout<<"    |    |    \n"; 
}

void places()
{
	int  digit;
	
	if(token=='x')
	{
		cout<<"\n"<<player1<<" please enter your position ";
		cin>>digit;
	}  

    if(token=='0') 
    {
    	cout<<"\n"<<player2<<" please enter your position ";
		cin>>digit;
	}

    if(digit==1)
    {
    	row=0;
    	column=0;
	}
	if(digit==2)
    {
    	row=0;
    	column=1;
	}
	if(digit==3)
    {
    	row=0;
    	column=2;
	}
	if(digit==4)
    {
    	row=1;
    	column=0;
	}
	if(digit==5)
    {
    	row=1;
    	column=1;
	}
	if(digit==6)
    {
    	row=1;
    	column=2;
	}
	if(digit==7)
    {
    	row=2;
    	column=0;
	}
	if(digit==8)
    {
    	row=2;
    	column=1;
	}
	if(digit==9)
    {
    	row=2;
    	column=2;
	}
     else if(digit<1||digit>9){
     	cout<<"Invalid!!!\n";
	 }
	 if(token=='x' &&space[row][column]!='x' && space[row][column]!='0')
	 {
	 	space[row][column]='x';
	 	token='0';
	 }
	 else if(token=='0' &&space[row][column]!='x' && space[row][column]!='0')
	 {
	 	space[row][column]='0';
	 	token='x';
	 }
	 else
	 {
	 	cout<<"\ninvalid move or not possible or tie";
	 	places();
	 }
	 structure();
	 
}
bool validate(){
	// valdate for row and column ( 3-3 ka triplet form krna h basically)
	for(int i=0;i<3;i++)
	{
		if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
		{
		return true;}
		
		if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
		{
		return true;}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(space[i][j]!='x'|| space[i][j]!='0')
			{
				return false;  // this shows that the game is still going on  
			}
		}
	}
	tie=true;
	return false;
	
}
int main()
{
	
     cout<<"enter the name of the first player \n";
     getline(cin,player1);
     cout<<"enter the name of the second player \n";
     getline(cin,player2);
     // showing the name of the players
     cout<<"\n"<<player1<<" is the first player\n";
     cout<<player2<<" is the second player\n";
     
     char a={1};
	while(!validate())
	{
		structure();
		places();
		validate();
	}
	
	if(token=='x'&& tie==false)
	{
		cout<<"\n"<<player2<<" wins\n"<<a;
		
	}
	
	else if(token=='0'&& tie==false)
	{
		cout<<"\n"<<player1<<"wins\n";
	}
	else
	{
		cout<<"It's a draw\n";
	}
}
