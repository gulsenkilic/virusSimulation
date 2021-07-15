//GÜLSEN KILIÇ 1306180038
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
vector <char> V1;
vector <int> V2;
vector <int> V3;
vector<int>V4;
vector<int>V5;
vector<int>V6;
int r = 0;
class entity {
public:
	char gate[5];
	void entityFunction(string str) {
		int s = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
		if (str[8] == ' ') {
			for (int i = 9; i < 14; i++) {
				gate[i - 9] = str[i];
				if (str[i] == 'A' || str[i] == 'B') {
					s++;
					s3++;
				}
				if (str[i] == 'C' || str[i] == 'D') {
					s3++;
				}
			}
			if (s != 0) {
				V2.push_back(1);
			}
			else V2.push_back(0);
			if (s3 >= 3 && s != 0) {
				V3.push_back(1);
			}
			else V3.push_back(0);

		}
		else {

			for (int i = 10; i < 15; i++) {
				gate[i - 10] = str[i];
				if (str[i] == 'A' || str[i] == 'B') {
					s++;
					s3++;

				}
				if (str[i] == 'C' || str[i] == 'D') {
					s3++;
				}
			}
			if (s != 0) {
				V2.push_back(1);
			}
			else V2.push_back(0);
			if (s3 >= 3 && s != 0) {
				V3.push_back(1);
			}
			else V3.push_back(0);
		}
	}
};
class turn {
public:
	int m, n;
	void turnFunction(string str, int size, int count, int turn_count) {
		if (count < 3) {
			char vertarr[50][50];
			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 50; j++) {
					vertarr[i][j] = { ' ' };
				}
			}
			int sayac = 0;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == 'x') {
					if (str[i - 2] == ' ') {
						m = (int)str[i - 1] - 48;
					}
					else m = ((int)str[i - 2] - 48) * 10 + (int)str[i - 1] - 48;
					if (V1.size() == sayac + 1) {
						if (str[i + 2] == str[str.size() - 1]) {

							n = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48;
						}
						else n = (int)str[i + 1] - 48;
					}
					else {
						if (str[i + 2] == ' ') {
							n = (int)str[i + 1] - 48;
						}
						else n = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48;
					}

					vertarr[m][n] = V1[sayac];
					sayac++;
				}
			}
			ofstream writeTurn;
			writeTurn.open("turn.txt", ios::app);
			writeTurn << "turn" << " " << count << endl;
			for (int i = 0; i < size + 2; i++) {
				for (int j = 0; j < size + 2; j++) {
					if (i == 0 || i == size + 1 || j == 0 || j == size + 1) {
						writeTurn << "*";
					}
					else writeTurn << vertarr[i][j];
				}
				writeTurn << endl;
			}
			writeTurn.close();
		}
		if (count >= 3) {
			char vertarr[50][50];
			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 50; j++) {
					vertarr[i][j] = { ' ' };
				}
			}
			int sayac = 0;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == 'x') {
					if (str[i - 2] == ' ') {
						m = (int)str[i - 1] - 48;
					}
					else m = ((int)str[i - 2] - 48) * 10 + (int)str[i - 1] - 48;

					if (V1.size() == sayac + 1) {
						if (str[i + 2] == str[str.size() - 1]) {

							n = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48;
						}
						else n = (int)str[i + 1] - 48;
					}
					else {
						if (str[i + 2] == ' ') {
							n = (int)str[i + 1] - 48;
						}
						else n = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48;
					}
					if (turn_count == count) {
						V5.push_back(m);
						V5.push_back(n);
					}
					vertarr[m][n] = V1[sayac];
					sayac++;
				}
			}
			ofstream writeTurn;
			writeTurn.open("turn.txt", ios::app);
			writeTurn << "turn" << " " << count << endl;
			for (int i = 0; i < size + 2; i++) {
				for (int j = 0; j < size + 2; j++) {
					if (i == 0 || i == size + 1 || j == 0 || j == size + 1) {
						writeTurn << "*";
					}
					else writeTurn << vertarr[i][j];
				}
				writeTurn << endl;
			}
			writeTurn.close();
			control(str, count);

		}
	}
	void control(string str, int count) {
		int a, b, c, d;
		int sayac = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'x') {
				if (V1[sayac] == 'X') {
					if (str[i - 2] == ' ') {
						a = (int)str[i - 1] - 48 - 3;
						b = (int)str[i - 1] - 48 + 3;
					}
					else {
						a = ((int)str[i - 2] - 48) * 10 + (int)str[i - 1] - 48 - 3;
						b = ((int)str[i - 2] - 48) * 10 + (int)str[i - 1] - 48 + 3;
					}
					if (V1.size() == sayac + 1) {
						if (str[i + 2] == str[str.size() - 1]) {

							c = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48 - 3;
							d = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48 + 3;

						}
						else {
							c = (int)str[i + 1] - 48 - 3;
							d = (int)str[i + 1] - 48 + 3;
						}
					}
					else {
						if (str[i + 2] == ' ') {
							c = (int)str[i + 1] - 48 - 3;
							d = (int)str[i + 1] - 48 + 3;
						}
						else {
							c = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48 - 3;
							d = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48 + 3;
						}
					}
					control2(str, a, b, c, d, count);
					sayac++;
				}
				else sayac++;
			}
		}
	}

	void control2(string str, int a, int b, int c, int d, int count) {
		int sayac = 0;
		int g = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'x') {
				if (str[i - 2] == ' ') {
					m = (int)str[i - 1] - 48;
				}
				else m = ((int)str[i - 2] - 48) * 10 + (int)str[i - 1] - 48;
				if (V1.size() == sayac + 1) {
					if (str[i + 2] == str[str.size() - 1]) {

						n = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48;
					}
					else n = (int)str[i + 1] - 48;
				}
				else {
					if (str[i + 2] == ' ') {
						n = (int)str[i + 1] - 48;
					}
					else n = ((int)str[i + 1] - 48) * 10 + (int)str[i + 2] - 48;
				}
				if (m >= a && m <= b) {
					if (n >= c && n <= d) {

						if (V2[sayac] == 1 && V1[sayac] != 'X' && V1[sayac] != 'D') {
							V1[sayac] = 'X';
							V4[sayac]++;
						}
						if (V1[sayac] == 'X' && V4[sayac] == 2 && count == 15 && V3[sayac] == 1) {
							V1[sayac] = 'D';
						}
						if (V1[sayac] == 'X' && V4[sayac] >= 1 && count >= 17 && V3[sayac] == 1) {
							V1[sayac] = 'D';
						}
						if (V1[sayac] == 'X' && V4[sayac] >= 1 && count >= 33 && V3[sayac] == 0) {
							V1[sayac] = 'O';
							V2[sayac]--;
							V6.push_back(sayac);
							r++;
						}
						if (V1[sayac] == 'X' && V4[sayac] == 2 && count == 31 && V3[sayac] == 0) {
							V1[sayac] = 'O';
							V2[sayac]--;
							V6.push_back(sayac);
							r++;
						}
						sayac++;
					}
					else sayac++;
				}
				else sayac++;
			}
		}
	}

};
int main() {
	string str;
	int sayac = 0, size, turn_count;
	int count = 0;

	ifstream read;
	read.open("input.txt");
	while (getline(read, str)) {
		if (sayac == 0) {
			if (str.size() == 6) {
				size = (int)str[5] - 48;
				cout << size;
			}
			else size = ((int)str[5] - 48) * 10 + (int)str[6] - 48;
		}
		if (sayac == 1) {
			if (str.size() == 12) {
				turn_count = (int)str[11] - 48;
			}
			if (str.size() == 13) {
				turn_count = ((int)str[11] - 48) * 10 + (int)str[12] - 48;
			}
			if (str.size() == 14) {
				turn_count = ((int)str[11] - 48) * 100 + ((int)str[12] - 48) * 10 + (int)str[13] - 48;
			}
		}
		if (str[0] == 'e') {
			entity entity1;
			int n = str.size();
			if (str[n - 8] == 'i') {
				V1.push_back((char)88);
				V4.push_back(2);

			}
			else {
				V1.push_back((char)79);
				V4.push_back(0);
			}
			entity1.entityFunction(str);
		}

		if (str[0] == 't' && sayac != 1) {
			count++;
			turn turn1;
			turn1.turnFunction(str, size, count, turn_count);
		}
		sayac++;
	}
	read.close();
	int x = 0, o = 0, d = 0;
	for (int i = 0; i < V1.size(); i++) {
		if (V1[i] == 'X') {
			x++;
		}
		if (V1[i] == 'O') {
			o++;
		}
		if (V1[i] == 'D') {
			d++;
		}
	}
	if (r != 0) {
		o = o - r;
	}
	int j = 0;
	ofstream outputYazma;
	outputYazma.open("output.txt", ios::app);
	outputYazma << "Normal:" << " " << o << endl;
	outputYazma << "Infected:" << " " << x << endl;
	outputYazma << "Dead:" << " " << d << endl;
	outputYazma << "Recovered:" << " " << r << endl;

	for (int i = 0; i < V1.size(); i++) {
		outputYazma << "entity" << " " << i + 1 << " ";
		outputYazma << V5[j] << "x" << V5[j + 1] << " ";
		if (V1[i] == 'X') {
			outputYazma << "Infected" << endl;
		}
		if (V1[i] == 'O') {
			outputYazma << "Normal" << " ";
			for (int s = 0; s < V6.size(); s++) {
				if (V6[s] == i) {
					outputYazma << "immune";
				}
			}
			outputYazma << endl;
		}
		if (V1[i] == 'D') {
			outputYazma << "Dead" << endl;
		}
		j = j + 2;
	}

	for (int i = 0; i < V6.size(); i++) {
		cout << V6[i] << endl;
	}
	outputYazma.close();
	return 0;
}