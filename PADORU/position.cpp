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
	char arr[4][1250];
	for(LL t = 0; t < 4; t ++ ){
		for(LL i = 0; i < 25; i ++ ) {
			string str;
			getline(cin, str);
			for(LL j = 0; j < 50; j ++ )
				arr[t][i*50+j] = str[j];
		}
	}
	map<char, vector<LL> > mp;
	map<char, LL> chr;
	chr[' '] = 0;
	chr['.'] = 1;
	chr[':'] = 2;
	chr['-'] = 3;
	chr['='] = 4;
	chr['+'] = 5;
	chr['#'] = 6;
	chr['%'] = 7;
	chr['*'] = 8;
	mt19937 mt(time(0));
	uniform_int_distribution<LL> dis(1, 10);
	vector<string> vec;
	system("cls");
	for(LL t = 0; t < 4; t ++ ) {
		if(t == 0) {
			for(LL t2 = 0; t2 < 10; t2 ++ ) {
				string str = "";
				str += "$_(" + to_string(t) + "," + to_string(t2 * 125) + ",";
				for(LL i = t2*125; i < t2*125+125; i ++ ) {
					int c = chr[arr[t][i]];
					str += to_string(c);
					if(i == t2*125+124)
						str += ");";
					else
						str += ",";
				}
				vec.pb(str);
			}
			continue;
		}
		mp.clear();
		for(LL i = 0; i < 1250; i ++ )
			mp[arr[t][i]].pb(i);
		for(auto &i : mp) {
			char c = i.F;
			LL Rnd = dis(mt);
			if(Rnd <= 2) {
				LL l = -1, r = -1;
				for(auto &j : i.S) {
					if(l == -1)
						l = r = j;
					else if(j == r + 1)
						r = j;
					else {
						LL rnd = dis(mt);
						if(rnd <= 4)
							vec.pb("_(" + to_string(t) + "," + to_string(l) + "," + to_string(r) + "," + to_string(chr[c]) + ");");
						else if(rnd <= 8)
							vec.pb("$(" + to_string(t) + "," + to_string(l) + "," + to_string(r-l+1) + "," + to_string(chr[c]) + ");");
						else {
							for(LL i = l; i <= r; i ++ )
								vec.pb("__(" + to_string(t) + "," + to_string(i) + "," + to_string(chr[c]) + ");");
						}
						l = r = j;
					}
				}
				vec.pb("_(" + to_string(t) + "," + to_string(l) + "," + to_string(r) + "," + to_string(chr[c]) + ");");
			}
			else {
				string str = "";
				str += "_$(" + to_string(t) + "," + to_string(chr[c]) + ",";
				LL l = -1, r = -1;
				for(auto &j : i.S) {
					if(l == -1)
						l = r = j;
					else if(j == r + 1)
						r = j;
					else {
						str += to_string(l*2047+r) + ",";
						l = r = j;
					}
				}
				str += to_string(l*2047+r) + ");";
				vec.pb(str);
			}
		}
	}
	// random_shuffle(vec.begin(), vec.end());
	for(auto &i : vec)
		cout << i << endl;
}

int main() {
	IO;
	//\
	cin >> T;
	while(T -- )
		solve();
}
