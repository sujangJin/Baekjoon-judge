#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<int> st;
int T, cnt,pop;
char a[5];
int main()
{
	scanf("%d", &T);
	while (T--){
		scanf("%s", a);
		if (!strcmp(a, "push")){
			scanf("%d", &cnt);
			st.push(cnt);
		}
		else if (!strcmp(a, "top")){
			if (st.size() > 0)
				printf("%d\n", st.top());
			else
				printf("-1\n");
		}
		else if (!strcmp(a, "size"))
			printf("%d\n", st.size());
		else if (!strcmp(a, "empty"))
			printf("%d\n", st.empty());
		else if (!strcmp(a, "pop")){
			if (st.size() > 0){
				pop = st.top();
				st.pop();
				printf("%d\n", pop);
			}
			else {
				printf("-1\n");
			}
		}

	}

	return 0;
}