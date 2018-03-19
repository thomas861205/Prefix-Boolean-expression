#include <iostream>

using namespace std;

int isBool(char ch){
	if (ch == '1' || ch == '0')
		return 1;
	else
		return 0;
}

int evac(char * input){

	if (*input == '|'){
		if (isBool( *(input+1)) && isBool( *(input+2)))
			return evac(input+1) || evac(input+2);
		else
			return evac(input+1);
	}

	else if (*input == '&'){
		if (isBool( *(input+1)) && isBool( *(input+2)))
			return evac(input+1) && evac(input+2);
	}
	else if(isBool(*input)){
		return ch=='1'?1:0;
	}
	else return -1;
}

int main(){
	char input[] = "|&10|00";
	cout << evac(input);
	return 0;
}