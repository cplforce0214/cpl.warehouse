#include <bits/stdc++.h>
using namespace std;
char pre[1000], mid[1000];
int son[1000][3];
int n; 
int dfs(int l1, int r1, int l2, int r2) {
	if (l1 > r1 || l2 > r2) {
		return -1; 
	}
	int root = pre[l1];
	int pos = l2;
	while (mid[pos] != root) {
		pos++;
	}
	int len = pos - l2;
	son[root][0] = dfs(l1 + 1, l1 + len, l2, pos - 1);
	son[root][1] = dfs(l1 + len + 1, r1, pos + 1, r2);
	return root;
}
void write(int x) {
	if (x == -1) {
		return;
	}
	write(son[x][0]);
	write(son[x][1]);
	printf("%c", x);
}
int main () {
	cin >> pre + 1 >> mid + 1;
	n = strlen(mid + 1);
	dfs(1, n, 1, n);
	write(pre[1]);
	return 0;
}
