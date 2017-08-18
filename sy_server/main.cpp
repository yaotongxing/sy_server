#include <cstdio>
#include "../Builder/Director.h"
#include <iostream>
using namespace std;
int main()
{

	Director* dir = new Director();
	dir->BuilderProject1();
	cout << endl;
	dir->BuilderProject2();

	delete dir;
    return 0;
}