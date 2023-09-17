#ifndef Enemies_H
#define Enemies_H
#include <bits/stdc++.h>
using namespace std;

class Enemies{
	private:
		deque<pair<int,int>> army;
		deque<pair<int,int>> bullets;
	public:
		Enemies();
		bool appearance(int y,int x);
		void fire();
		void move();
		void bullet_fly();
		bool bullet_appearance(int y,int x);
		void remove_destroyed(int y,int x);
		void remove_bullet(int y,int x);
		deque<pair<int,int>> get_army();
		
};
#endif