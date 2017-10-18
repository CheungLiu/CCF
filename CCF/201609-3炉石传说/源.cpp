#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define role 1-player
const int RED = 0;
const int BLACK = 1;
struct status {
	int life, power;
	status(int a, int b) :life(a), power(b) {}
};
vector<status> vcon[2];
int main(int argc, char** argv) {
	int player = RED, n;
	int health, attacker, defender, position, attack;
	vcon[RED].push_back(status(30, 0));
	vcon[BLACK].push_back(status(30, 0));
	string action;
	cin >> n;
	while (n--) {
		cin >> action;
		if (action == "summon") {
			cin >> position >> attack >> health;
			vcon[player].insert(vcon[player].begin() + position, status(health, attack));
		}
		else if (action == "attack") {
			cin >> attacker >> defender;
			vcon[player][attacker].life -= vcon[role][defender].power;
			vcon[role][defender].life -= vcon[player][attacker].power;
			if (vcon[player][attacker].life <= 0) {
				vcon[player].erase(vcon[player].begin() + attacker);
			}
			if (defender != 0 && vcon[role][defender].life <= 0) {
				vcon[role].erase(vcon[role].begin() + defender);
			}
		}
		else if (action == "end") {
			player = role;
		}
	}
	if (vcon[RED][0].life <= 0) {
		cout << -1 << endl;
	}
	else if (vcon[BLACK][0].life <= 0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	cout << vcon[RED][0].life << endl;
	cout << vcon[RED].size() - 1;
	for (int i = 1; i<vcon[RED].size(); i++) {
		cout << " " << vcon[RED][i].life;
	}
	cout << endl;
	cout << vcon[BLACK][0].life << endl;
	cout << vcon[BLACK].size() - 1;
	for (int i = 1; i<vcon[BLACK].size(); i++) {
		cout << " " << vcon[BLACK][i].life;
	}
	cout << endl;
	return 0;
}