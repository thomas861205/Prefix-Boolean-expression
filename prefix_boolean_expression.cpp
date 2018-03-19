#include <iostream>

using namespace std;

typedef struct op
{
	char ch;
	struct op *next;
} OP;

OP *APPEND(OP *head, char ch){
	static OP *rear = NULL;
	OP *node;

	if (rear == NULL){
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
	cout<<endl;
}

int isBool(char ch){
	if (ch == '1' || ch == '0'){
		return 1;
	}
	else{
		return 0;
	}
}

int getBool(char ch){
	return ch == '1'? 1:0;
}

char toBool(bool n){
	return n? '1':'0';
}

OP *evac(OP *head){
	OP *i;
	OP *temp = NULL;

	for (i = head; i!=NULL; ){
		if (i->ch == '|'){
			if (isBool((i->next)->ch) && isBool(((i->next)->next)->ch)){
				i->ch = toBool(getBool((i->next)->ch) || getBool(((i->next)->next)->ch));
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
				i->ch = toBool(getBool((i->next)->ch) && getBool(((i->next)->next)->ch));
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

int main(){
	char ch;
	OP *head;

	head = new OP;
	head->next = NULL;

	while (cin >> ch){
		APPEND(head, ch);
	}
	PRINT(head);
	while(!isBool(head->ch)){
		evac(head);
		PRINT(head);
	}
	cout << "ans: " << head->ch;
	return 0;
}