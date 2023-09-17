#ifndef Craft_H
#define Craft_H
#include <bits/stdc++.h>
using namespace std;

class Craft{
	private:
		deque<pair<int,int>> body;
		deque<pair<int,int>> bullets;
	public:
		Craft();
		void fire();
		void move(char dir);
		bool craft_appearance(int y,int x);
		bool bullet_appearance(int y,int x);
		void bullet_fly();
		void remove_bullet(int y,int x);
};
#endif