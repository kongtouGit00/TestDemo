#include <iostream>

using namespace std;

class  TwoPhaseCons{

private:
	TwoPhaseCons(){

	};

	bool constructure(){

		return true;
	}

public:
	static TwoPhaseCons* NewInstance();
};

TwoPhaseCons* TwoPhaseCons::NewInstance(){

	TwoPhaseCons* ret = new TwoPhaseCons();

	if( !(ret && ret->constructure()) ){

		delete ret;
		ret = NULL;
	}

	return ret;
}

int mian(int argc, char** argv){

	TwoPhaseCons* obj = TwoPhaseCons::NewInstance();

	printf("obj = %p\n", obj);


	return 0;
}



