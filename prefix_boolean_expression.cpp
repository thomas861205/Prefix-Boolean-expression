#include <iostream>
#include <string>

using namespace std;

string temp;
string combi[5];

typedef struct op{
	char ch;
	struct op *next;
} OP;

OP *APPEND(OP *, char, int);
OP *gene(string);
OP *evac(OP *);
void PRINT(OP *);
void replaceBool(string, char);
inline int isBool(char);
inline int getBool(char);
inline char boolToChar(int);

int main(){
	char ch;
	int i = 0;
	string line;

	cin >> line;
	temp = line;

	replaceBool(line, 'A');
	return 0;
}

OP *APPEND(OP *head, char ch, int is_head){
	static OP *rear = NULL;
	OP *node;

	if (is_head){
		head->ch = ch;
		rear = head;
	}
	else{
		node = new OP;
		node->ch = ch;
		node->next = NULL;
		rear->next = node;
		rear = node;
	}

	return head;
}

void PRINT(OP *head){
	OP *i;
	for (i = head; i!=NULL; i=i->next){
		cout << i->ch;
	}
	// cout<<endl;
}

inline int isBool(char ch){
	if (ch == '1' || ch == '0'){
		return 1;
	}
	else{
		return 0;
	}
}

inline int getBool(char ch){
	return ch == '1'? 1:0;
}

OP *evac(OP *head){
	OP *i;
	OP *temp = NULL;

	for (i = head; i!=NULL; ){
		if (i->ch == '|'){
			if (isBool((i->next)->ch) && isBool(((i->next)->next)->ch)){
				i->ch = boolToChar(getBool((i->next)->ch) || getBool(((i->next)->next)->ch));
				temp = ((i->next)->next)->next;
				i->next = temp;
				// delete i->next;
				// delete (i->next)->next;
			}
			else{
				i = i->next;
			}
		}
		else if (i->ch == '&'){
			if (isBool((i->next)->ch) && isBool(((i->next)->next)->ch)){
				i->ch = boolToChar(getBool((i->next)->ch) && getBool(((i->next)->next)->ch));
				temp = ((i->next)->next)->next;
				i->next = temp;
				// delete i->next;
				// delete (i->next)->next;
			}
			else{
				i = i->next;
			}
		}
		else{
			i = i->next;
		}
	}

	return head;
}

inline char boolToChar(int n){
	return n? '1':'0';
}

void replaceBool(string line, char ch){
	if (ch == 'A'){
		for (int j = 0; j < 2; j++){
			combi[0] = boolToChar(j);
			for (int i = 0; i < line.size(); i++){
				if (temp[i] == 'A'){
					line[i] = boolToChar(j);
				}
			}
			replaceBool(line, 'B');
		}
	}

	else if (ch == 'B'){
		for (int j = 0; j < 2; j++){
			combi[1] = boolToChar(j);
			for (int i = 0; i < line.size(); i++){
				if (temp[i] == 'B'){
					line[i] = boolToChar(j);
				}
			}
			replaceBool(line, 'C');
		}
	}

	else if (ch == 'C'){
		for (int j = 0; j < 2; j++){
			combi[2] = boolToChar(j);
			for (int i = 0; i < line.size(); i++){
				if (temp[i] == 'C'){
					line[i] = boolToChar(j);
				}
			}
			replaceBool(line, 'D');
		}
	}

	else if (ch == 'D'){
		for (int j = 0; j < 2; j++){
			combi[3] = boolToChar(j);
			for (int i = 0; i < line.size(); i++){
				if (temp[i] == 'D'){
					line[i] = boolToChar(j);
				}
			}
			for (int i = 0; i < 4; i++){
				cout << combi[i] << ' ';
			}
			gene(line);
		}
	}
}

OP *gene(string line){
	OP *head;
	int i = 0;

	head = new OP;
	head->next = NULL;

	while (line[i]!='\0'){
		APPEND(head, line[i], !i);
		i++;
	}
	while(!isBool(head->ch)){
		evac(head);
	}
	cout <<  head->ch << endl;
	return head;
}