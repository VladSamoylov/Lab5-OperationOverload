#include <iostream>
#include <iomanip>

using namespace std;

class RealNumber {
private:
	double* mas;
	int n;
public:
	RealNumber();
	RealNumber(const int&);
	RealNumber(const RealNumber&);
	RealNumber operator=(const RealNumber&);
	RealNumber operator+(const RealNumber&);
	RealNumber operator-(const RealNumber&);

	void Show();
	~RealNumber();
};

RealNumber::RealNumber() {

	this->mas = nullptr;
	this->n = 0;
}

RealNumber::RealNumber(const int& n) {

	this->n = n;
	this->mas = new double[this->n];
	for (int i = 0; i < this->n; i++) {
		this->mas[i] = (rand() % 21) - 10;
	}
}

RealNumber::RealNumber(const RealNumber& rn) {

	this->n = rn.n;
	this->mas = new double[this->n];
	for (int i = 0; i < rn.n; i++) {
		this->mas[i] = rn.mas[i];
	}
}

void RealNumber::Show() {

	cout << "{";
	for (int i = 0; i < this->n; i++) {
		cout << setw(4) << this->mas[i];
	}
	cout << " }" << endl;
}

RealNumber::~RealNumber() {

	delete[] this->mas;
}

RealNumber RealNumber::operator=(const RealNumber& rn) {

	if (this->n != rn.n && this->mas != nullptr) { delete[] this->mas; }
	else if (this->n != rn.n) this->mas = new double[rn.n];
	for (int i = 0; i < rn.n; i++) {
		this->mas[i] = rn.mas[i];
	}
	return *this;
}

RealNumber RealNumber::operator+(const RealNumber& rn) {

	if (this->n > rn.n) {
		RealNumber tmp(*this);
		for (int i = 0; i < rn.n; i++) {
			tmp.mas[i] += rn.mas[i];
		}
		return tmp;
	}
	else if (this->n < rn.n) {
		RealNumber tmp(rn);
		for (int i = 0; i < this->n; i++) {
			tmp.mas[i] += this->mas[i];
		}
		return tmp;
	}
	else {
		RealNumber tmp(this->n);
		for (int i = 0; i < tmp.n; i++) {
			tmp.mas[i] = this->mas[i] + rn.mas[i];
		}
		return tmp;
	}	
}

RealNumber RealNumber::operator-(const RealNumber& rn) {


}

int main() {

	srand(time(nullptr));
	RealNumber rn1(5), rn2(5), rn3(5);

	cout << "rn1: "; rn1.Show();
	cout << "rn2: "; rn2.Show();
	cout << "rn3: "; rn3.Show();
	cout << "-----------------------\n";

	(rn1 + rn2).Show();
	rn3 = rn1 + rn2;

	cout << "rn1: "; rn1.Show();
	cout << "rn2: "; rn2.Show();
	cout << "rn3: "; rn3.Show();



	return 0;
}