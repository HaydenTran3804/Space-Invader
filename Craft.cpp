#include<bits/stdc++.h>
#include "Craft.h"
using namespace std;

Craft :: Craft(){
	body.push_back({22,24});
	body.push_back({23,23});
	body.push_back({23,24});
	body.push_back({23,25});
}
bool Craft :: craft_appearance(int y,int x){
	deque<pair<int,int>> tmp = body;
	
	while(!tmp.empty()){
		if(tmp.front().first == y && tmp.front().second == x){
			return true;
			break;
		}
		tmp.pop_front();
	}
	return false;
}
void Craft :: move(char dir){
	int times = body.size();
	while(times--){
		pair<int,int> head = body.front();
		body.pop_front();
		if(dir == 'w'){
			head.first -= 1;
		}
		if(dir == 's'){
			head.first += 1;
		}
		if(dir == 'a'){
			head.second -= 1;
		}
		if(dir == 'd'){
			head.second += 1;
		}
		body.push_back(head);
	}
}
void Craft :: fire(){
	pair<int,int> head_craft = body.front();
	bullets.push_back({head_craft.first-1,head_craft.second});

}
void Craft :: bullet_fly(){
		int size = bullets.size();
	while(size--){
		pair<int,int> tmp = bullets.front();
		bullets.pop_front();
		tmp.first -= 1;
		if(tmp.first > 0){
			bullets.push_back(tmp);
		}
	}
	
}
bool Craft :: bullet_appearance(int y,int x){
	deque<pair<int,int>> tmp = bullets;
	
	while(!tmp.empty()){
		if(tmp.front().first == y && tmp.front().second == x){
			return true;
		}
		tmp.pop_front();
	}
	return false;
}
void Craft :: remove_bullet(int y,int x){
		int size = bullets.size();
	while(size--){
		pair<int,int> bullet = bullets.front();
		bullets.pop_front();
		
		if(bullet.first != y && bullet.second != x){
			bullets.push_back(bullet);
		}
	}
}