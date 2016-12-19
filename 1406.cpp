#include<stack>
#include<cstdio>
const int string_max = 1e5;
using namespace std;
char s[string_max + 1], com;
int N;
stack<char> left, right;

void stInit(char * s){
	for (int i = 0; s[i] != '\0'; i++)
		left.push(s[i]);
}

void editor(char com){
	char tmp;

	if (com == 'P'){
		scanf("%c\n", &tmp);
		left.push(tmp);
	}
	else if (com == 'L'){
		if (left.size() > 0){
			tmp = left.top();
			left.pop();
			right.push(tmp);
		}
	}
	else if (com == 'D'){
		if (right.size() > 0){
			tmp = right.top();
			right.pop();
			left.push(tmp);
		}
	}
	else if (com == 'B'){
		if (left.size() > 0){
			left.pop();
		}
	}
}

void merge_print(){
	char tmp;
	int l_size = left.size();
	for (int i = 0; i < l_size; i++){
		tmp = left.top();
		right.push(tmp);
		left.pop();
	}
	if(left.size() > 0) right.push(left.top());
	int size = right.size();
	for (int i = 0; i < size; i++){
		printf("%c",right.top());
		right.pop();
	}
}

int main()
{
	scanf("%s\n",s);
	stInit(s);

	scanf("%d\n",&N);
	while (N--){
		scanf("%c ",&com);
		editor(com);
	}
	merge_print();
	return 0;
}