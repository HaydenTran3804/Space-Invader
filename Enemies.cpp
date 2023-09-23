#include<bits/stdc++.h>
#include "Enemies.h"
using namespace std;

Enemies :: Enemies(){
	for(int i = 1;i<=5;i++){
		if(i != 4){
			int y = 10 - i;
			int x = round(48/(i+1));
			for(int j=1;j<=i;j++){
				army.push_back({y,x * j});
			}
		}
	}
}
void Enemies :: move(){
	srand(time(NULL));
	int random_dir = rand() % 4 + 1;
	if(random_dir == 1 && army.back().first - 1 > 0){
		int size = army.size();
		while(size--){
			pair<int,int> soldier = army.front();
			army.pop_front();
			soldier.first -= 1;
			army.push_back(soldier);
		}
	} 
	if(random_dir == 2 && army.front().first + 1 < 10){
		int size = army.size();
		while(size--){
			pair<int,int> soldier = army.front();
			army.pop_front();
			soldier.first += 1;
			army.push_back(soldier);
		}
	} 
	if(random_dir == 3 && army.back().second + 1 < 49){
		int size = army.size();
		while(size--){
			pair<int,int> soldier = army.front();
			army.pop_front();
			soldier.second += 1;
			army.push_back(soldier);
		}
	} 
	if(random_dir == 4 && army.back().second - 32 - 1 > 0){
		int size = army.size();
		while(size--){
			pair<int,int> soldier = army.front();
			army.pop_front();
			soldier.second -= 1;
			army.push_back(soldier);
		}
}
}
bool Enemies :: appearance(int y,int x){
	deque<pair<int,int>> tmp = army;
	while(!tmp.empty()){
		if(tmp.front().first == y && tmp.front().second == x){
			return true;
		}
		tmp.pop_front();
	}
	return false;
}
void Enemies :: fire(){
	int bullet_resource;
	if(army.size() >= 5){
		srand(time(NULL));
		bullet_resource = rand() % 5 + 1;
	} else{
		srand(time(NULL));
		bullet_resource = rand() % army.size() + 1;
	}
	deque<pair<int,int>> tmp = army;
	while(bullet_resource > 1){
		tmp.pop_front();
		--bullet_resource;
	}
	bullets.push_back({tmp.front().first + 1,tmp.front().second});
	
}
void Enemies :: bullet_fly(){
	int size = bullets.size();
	while(size--){
		pair<int,int> bullet = bullets.front();
		bullets.pop_front();
		bullet.first += 1;
		if(bullet.first < 49){
			bullets.push_back(bullet);
		}
}
}
bool Enemies :: bullet_appearance(int y,int x){
	deque<pair<int,int>> tmp = bullets;
	while(!tmp.empty()){
		if(tmp.front().first == y && tmp.front().second == x){
			return true;
		}
		tmp.pop_front();
	}
	return false;
}
void Enemies :: remove_destroyed(int y,int x){
	int size = army.size();
	while(size--){
		pair<int,int> soldier = army.front();
		army.pop_front();
		if(soldier.first != y || soldier.second != x){
			army.push_back(soldier);
		}
	}
}
void Enemies :: remove_bullet(int y,int x){
	int size = bullets.size();
	while(size--){
	pair<int,int> bullet = bullets.front();
		bullets.pop_front();
		if(bullet.first != y && bullet.second != x){
			bullets.push_back(bullet);
		}
	}
}
deque<pair<int,int>> Enemies :: get_army(){
	return army;
}
