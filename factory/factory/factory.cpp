#include <iostream>
#include <vector>

using namespace std;

class Factory {
public:
	// Factory Method
	static Factory *makeFactory(int choice);
	virtual void voice() = 0;
};

class Dog : public Factory {
public:
	void voice() {
		cout << "Gaff\n";
	}
};
class Cat : public Factory {
public:
	void voice() {
		cout << "Meau\n";
	}
};
class Man : public Factory {
public:
	void voice() {
		cout << "WOW\n";
	}
};


//method that control fabric
Factory *Factory::makeFactory(int choice) {
	if (choice == 1)
		return new Dog;
	else if (choice == 2)
		return new Cat;
	else
		return new Man;
}

int main() {
	//init rolles array
	vector<Factory*> roles;
	int choice;

	//set some data for each 
	while (true) {
		cout << "DOG(1) CAT(2) MAN(3) SAY(0): ";
		cin >> choice;

		//exit on 0
		if (choice == 0) break;

		//add correct object that depends on choise
		roles.push_back(Factory::makeFactory(choice));
	}

	for (int i = 0; i < roles.size(); i++) {
		roles[i]->voice();
	}
	
	for (int i = 0; i < roles.size(); i++) {
		delete roles[i];
	}
	
	system("PAUSE");
}

