#include<bits/stdc++.h>
#define IO cin.tie(0) -> sync_with_stdio(0)
#define endl "\n"
#define F first
#define S second
#define X first
#define Y second
#define pLL pair<LL, LL>
#define mkp make_pair
#define pb emplace_back
#define pf emplace_front
#define ppb pop_back
#define ppf pop_front
#define LL lolita
#define lolita long long
using namespace std;

const LL mod = 1e9 + 7, inf = numeric_limits<LL>::max() / 2, maxN = 0;
LL T = 1;

void solve() {
  string str = "hasiresoriyo~\nkazenoyouni~~\ntsukimiharawo\nPADORUPADORU~\n";
	cout << "{";
	for(auto &i : str)
		cout << (int)i-100 << ",";
	cout << "}";
}

int main() {
	//\
	IO;
	//\
	cin >> T;
	while(T -- )
		solve();
}
