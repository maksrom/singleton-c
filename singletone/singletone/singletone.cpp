#include <iostream>

using namespace std;

class Singleton {
private:
	static bool flag;
	static Singleton *single;
	Singleton() {
	}
public:
	static Singleton* getInstance();
	void someMethod();
	~Singleton()
	{
		flag = false;
	}
};
//realization
bool Singleton::flag = false;
//defined NULL 0
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance() {
	if (!flag) {
		single = new Singleton();
		flag = true;

		//TODO: delete it 
		cout << "Ñreate singletone" << endl;

		return single;

	}
	else {
		//TODO: delete it 
		cout << "work with existing singletone" << endl;
		return single;
	}
}

void Singleton::someMethod() {
	cout << "Method of the singleton class" << endl;
}

void main() {
	Singleton *sc1, *sc2, *sc23;
	sc1 = Singleton::getInstance();
	sc1->someMethod();
	sc2 = Singleton::getInstance();
	sc2->someMethod();
	sc23 = Singleton::getInstance();
	sc23->someMethod();


	system("PAUSE");
}