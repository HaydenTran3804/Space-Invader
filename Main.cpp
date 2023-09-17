#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "Craft.cpp"
#include "Enemies.cpp"
using namespace std;

void board(Craft &craft,Enemies &enemies,int &hp){
	for(int i=0;i<25;i++){
		cout << "\t\t\t\t";
		for(int j=0;j<50;j++){
			if(craft.craft_appearance(i,j) == true && enemies.bullet_appearance(i,j) == true){
				enemies.remove_bullet(i,j);
				hp -= 1;
			}
			if(enemies.appearance(i,j) == true && craft.bullet_appearance(i,j) == true){
				enemies.remove_destroyed(i,j);
				craft.remove_bullet(i,j);
				cout << " ";
			}else if(craft.craft_appearance(i,j)){
				cout << "o";
			} else	if(i == 0 || i == 24 || j == 0 || j == 49){
				cout << "#";
			} else	if(enemies.appearance(i,j)){
				cout << "Y";
			} else	if(craft.bullet_appearance(i,j)){
				cout << "^";
			} else if(enemies.bullet_appearance(i,j)){
				cout << "V";
			} else{
				cout << " ";
			}
			
		}
		cout << endl;
	}
}
int main(){
	int hp = 9;
	
	Craft craft;
	Enemies enemies;
	int fire_count = 0;
	char dir = 'h';
    while(true){
		board(craft,enemies,hp);
    	if(hp == 0){
    		cout <<endl<< "/t/t/t/t/t/tYou lose" << endl;
    		system("PAUSE");
		}
		cout << "HP: " << hp;
	if(kbhit()){
		switch(getch()){
			case 'w': dir = 'w';break;
			case 's': dir = 's';break;
			case 'd': dir = 'd';break;
			case 'a': dir = 'a';break;
		}	
		craft.move(dir);
	
	} else{
		craft.move(dir);
	}
	enemies.move();
	if(fire_count == 10){
		craft.fire();
		enemies.fire();
		fire_count = 0;
	}
	enemies.bullet_fly();
	craft.bullet_fly();
	++fire_count;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});

}
	cout << endl << system("PAUSE");
}