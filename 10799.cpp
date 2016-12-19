#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
const int MAX = 100000;
char input[MAX], before;
int res;

void split(char ch)
{
	if (ch == '(') st.push(ch);
	else if (ch == ')'){
		st.pop();
		if (before == ch) res++;
		else res += st.size();
	}

	before = ch;
}

int main() {
	scanf("%s", input);
	int i = 0;
	while (input[i] != '\0'){
		split(input[i]);
		i++;
	}
	printf("%d", res);
	return 0;
}