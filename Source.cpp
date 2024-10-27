#include "Linked_List.h"
#include <iostream>

using namespace std;

int main() {
	Linked_List <int> ls;
	ls.push_back(5);
	ls.push_back(4);
	ls.push_back(2);
	ls.push_back(1);
	ls.insert(3,2);
	ls.display();
	//ls.clear();
	//cout << ls.getsize() << endl;
	//cout << ls.search(5) << endl;
	cout << "================\n";
	//ls.pop_front();
	//ls.pop_front();
	ls.pop_back();
	ls.push_back(12);
	ls.display();
	cout << "===========\n" << ls.getsize();
	return 0;
}