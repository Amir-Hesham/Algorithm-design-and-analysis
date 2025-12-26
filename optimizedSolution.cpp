#include <iostream>
#include<vector>
using namespace std;
void readd(vector <vector <int>>& v, int n, int m)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> v[i][j];
	cout << "===========================================\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}
void prefix(int n, int m, vector<vector<int>>& v)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			v[i][j] += v[i-1][j] + v[i][j-1] - v[i - 1][j - 1];
	cout << "===========================================\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}
int calcOptimized(int x1, int y1, int x2, int y2, int n, int m, vector<vector<int>>& v)
{
	long long sum = 0;
	sum = v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1];
	return sum;
}
int main()
{
	cout << "enter the array size as n x m : ";
	int n, m; cin >> n >> m;
	vector <vector<int>> v(n + 1, vector<int>(m + 1));
	cout << "enter the array : " << endl;
	readd(v, n, m);
	prefix(n, m, v);
	cout << "enter the num of the queries : ";
	int q; cin >> q;
	while (q-- > 0)
	{
		cout << "enter the coordinates as x1 , y1 , x2 , y2 : ";
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << "==================================\n";
		cout << "the sum you want is : ";
		cout << calcOptimized(x1, y1, x2, y2, n, m, v) << endl;
	}
}

