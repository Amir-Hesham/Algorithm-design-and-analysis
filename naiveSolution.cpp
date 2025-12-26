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
			cout<< v[i][j]<<" ";
		cout << endl;
	}
}
int calcNaive(int x1, int y1, int x2, int y2, int n, int m, vector<vector<int>>& v)
{
	long long sum = 0;
	for (int i = x1; i <= x2; i++)
		for (int j = y1; j <= y2; j++)
			sum += v[i][j];
	return sum;
}
int main()
{
	cout << "enter the array size as n x m : ";
	int n, m; cin >> n >> m;
	vector <vector<int>> v(n + 1, vector<int>(m + 1));
	cout << "enter the array : " << endl;
	readd(v, n, m);
	cout << "enter the num of the queries : ";
	int q; cin >> q;
	while (q-- > 0)
	{
		cout << "enter the coordinates as x1 , y1 , x2 , y2 : ";
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << "==================================\n";
		cout << "the sum you want is : ";
		cout << calcNaive(x1, y1, x2, y2, n, m, v) << endl;
	}
}

