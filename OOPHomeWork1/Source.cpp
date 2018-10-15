#include <iostream>
using namespace std;

class time_
{
	int h, m, s;
public:
	void setH(int a) {
		if (a >= 0 && a <= 23) h = a;
		else h = 0;
	}
	void setM(int a) {
		if (a >= 0 && a <= 59) m = a;
		else m = 0;
	}
	void setS(int a) {
		if (a >= 0 && a <= 59) s = a;
		else s = 0;
	}
	void setTime(int a, int b, int c) {
		setH(a);
		setM(b);
		setS(c);
	}

	int getH() { return h; }
	int getM() { return m; }
	int getS() { return s; }
	
	void printTime() {
		if (h < 10) cout << "0";
		cout << h << ":";
		if (m < 10) cout << "0";
		cout << m << ":";
		if (s < 10) cout << "0";
		cout << s << endl;
	}

	//добавление 1 часа, 1 минуты, 1 секунды
	void addOneH() {
		h++;
		if (h == 24) h = 0;
	}
	void addOneM() {
		m++;
		if (m == 60) {
			addOneH();
			m = 0; }
	}
	void addOneS() {
		s++;
		if (s == 60) {
			addOneM();
			s = 0; }
	}

	//добавление любого кол-ва часов, минут, секунд
	void addH(int a) {
		h += a;
		if (h >= 24) h = h % 24;
	}
	void addM(int a) {
		m += a;
		if (m >= 60) {
			addH(m / 60);
			m = m % 60; }
	}
	void addS(int a) {
		s += a;
		if (s >= 60) {
			addM(s / 60);
			s = s % 60; }
	}
};

int main()
{
	time_ tt;
	tt.setTime(23, 59, 59);
	tt.addS(8815);
	tt.printTime();

	system("pause");
	return 0;
}