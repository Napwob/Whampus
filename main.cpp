#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int map[20][3];
int whpl;
int whwp;


void wheretogo()
{	
	cout<<"Where to go next?"<<endl;
	int move;
	while(true)
    	{
    		cin>>move;
    		if(move == map[whpl][0] || move == map[whpl][1] || move == map[whpl][2]) 
    		{
    			whpl=move;
    			break;
    		}
    		cout<<"You cannot go there"<<endl;
    		cout<<"Still, where to go next?"<<endl;
    	}	
}
void wheretoshoot()
{
	cout<<"Write on magic arrow numbers of rooms"<<endl;
	int shootmap[5];
	cin>>shootmap[0];
	for(int i=0;i<4;i++)
	{
		cin>>shootmap[i];
	}
	cout<<"reg";
}

void whattodo()
{	
	string answer;
	cout<<"What to do(move(m) or shoot(s))?"<<endl;	
	cin>>answer;
	if(answer == "move" || answer == "m" || answer == "M" || answer == "Move") 
	{
		wheretogo();
	}
	if(answer == "shoot" || answer == "s" || answer == "Shoot" || answer == "S") 
	{
		wheretoshoot();
	}
}

void game()
{
    while(true)
    {
    	cout<<"You are in the room "<<whpl<<endl;
    	cout<<"You can go to "<<map[whpl][0]<<" "<<map[whpl][1]<<" "<<map[whpl][2]<<endl;
    	if(map[whpl][0] == whwp || map[whpl][1] == whwp || map[whpl][2] == whwp) cout <<"Wampus is nearby!"<<endl;;
    	whattodo();
    	
    	if(whpl == whwp) 
    	{
    		cout<<"You are dead"<<endl;
    		break;
    	}
    	printf("\e[1;1H\e[2J");
    }
}

int main()
{
    ifstream fin("map.txt"); 
    for(int i=1;i<=20;i++)
    {
    	fin>>map[i][0];
    	fin>>map[i][1];
    	fin>>map[i][2];	
    }
    fin>>whpl;
    fin>>whwp;
    printf("\e[1;1H\e[2J");
    game();
    
    return 0;
}
