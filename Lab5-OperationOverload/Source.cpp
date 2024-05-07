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
	void Generate();
	RealNumber operator=(const RealNumber&);
	RealNumber operator+(const RealNumber&);
	RealNumber operator-(const RealNumber&);
	double operator*(const RealNumber&);
	RealNumber operator<<(int);
	friend RealNumber operator>>(RealNumber&, int);
	double& operator[](const int&);
	void Show();
	~RealNumber();
};

/**
 * @brief Конструктор класу RealNumber за замовченням
*/
RealNumber::RealNumber() {

	this->mas = nullptr;
	this->n = 0;
}

/**
 * @brief Параметричний конструктор класу RealNumber
 * @param n Кількість чисел дійсного типу в масиві 
*/
RealNumber::RealNumber(const int& n) {

	this->n = n;
	this->mas = new double[this->n];
	for (int i = 0; i < this->n; i++) {
		this->mas[i] = (rand() % 21) - 10;
	}
}

/**
 * @brief Конструктор копіювання класу RealNumber
 * @param rn Об'єкт для копіювання
*/
RealNumber::RealNumber(const RealNumber& rn) {

	this->n = rn.n;
	this->mas = new double[this->n];
	for (int i = 0; i < rn.n; i++) {
		this->mas[i] = rn.mas[i];
	}
}

/**
 * @brief Метод, який генерує новий масив дійсного типу
*/
void RealNumber::Generate() {

	if (this->mas != nullptr) delete[] this->mas;
	this->n = (rand() % 10) + 1;
	this->mas = new double[this->n];
	for (int i = 0; i < this->n; i++) {
		this->mas[i] = (rand() % 21) - 10;
	}
}

/**
 * @brief Метод, який відображає зміст масиву
*/
void RealNumber::Show() {

	cout << "{";
	for (int i = 0; i < this->n; i++) {
		cout << setw(4) << right << this->mas[i];
	}
	cout << " }" << endl;
}

/**
 * @brief Деструктор
*/
RealNumber::~RealNumber() {

	delete[] this->mas;
}

/**
 * @brief Перевантаження бінарного оператору =
 * @param rn Об'єкт правого аргументу
 * @return Повернення поточного об'єкту
*/
RealNumber RealNumber::operator=(const RealNumber& rn) {

	if (this->n != rn.n) {
		if (this->mas != nullptr) delete[] this->mas;
		this->n = rn.n;
		this->mas = new double[this->n];
	}
	for (int i = 0; i < rn.n; i++) {
		this->mas[i] = rn.mas[i];
	}
	return *this;
}

/**
 * @brief Перевантаження бінарного оператору +
 * @param rn Об'єкт правого аргументу
 * @return Повернення тимчасового об'єкту
*/
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

/**
 * @brief Перевантаження бінарного оператору -
 * @param rn Об'єкт правого аргументу
 * @return Повернення тимчасового об'єкту
*/
RealNumber RealNumber::operator-(const RealNumber& rn) {

	if (this->n > rn.n) {
		RealNumber tmp(*this);
		for (int i = 0; i < rn.n; i++) {
			tmp.mas[i] -= rn.mas[i];
		}
		return tmp;
	}
	else if (this->n < rn.n) {
		RealNumber tmp(rn);
		for (int i = 0; i < this->n; i++) {
			tmp.mas[i] = this->mas[i] - tmp.mas[i];
			}
		for (int j = this->n; j < rn.n; j++) {
			tmp.mas[j] = 0 - tmp.mas[j];
		}
		return tmp;
	}
	else {
		RealNumber tmp(this->n);
		for (int i = 0; i < tmp.n; i++) {
			tmp.mas[i] = this->mas[i] - rn.mas[i];
		}
		return tmp;
	}
}

/**
 * @brief Перевантаження бінарного оператору *
 * @param rn Об'єкт правого аргументу
 * @return Результату скалярного множення двох об'єктів
*/
double RealNumber::operator*(const RealNumber& rn){

	double scalar_product = 0.0;
	if (this->n > rn.n) {
		for (int i = 0; i < rn.n; i++) {
			scalar_product += this->mas[i] * rn.mas[i];
		}
	}
	else if (this->n < rn.n) {
		for (int i = 0; i < this->n; i++) {
			scalar_product += this->mas[i] * rn.mas[i];
		}
	}
	else {
		for (int i = 0; i < this->n; i++) {
			scalar_product += this->mas[i] * rn.mas[i];
		}
	}
	
	return scalar_product;
}

/**
 * @brief Перевантаження оператору =
 * @param index Елемент для отримання за індексом
 * @return Значення елементу за індексом
*/
double& RealNumber::operator[](const int& index) {

	if (index < 0 || index >= this->n) {
		cerr << "Current index don't find !" << endl;
		cout << "Return the element of maximum masive index [" << this->n - 1 << "] = ";
		return this->mas[this->n - 1];
	}
	else return this->mas[index];
}

/**
 * @brief Перевантаження оператору <<
 * @param notused Не використовується
 * @return Повернення поточного об'єкту
*/
RealNumber RealNumber::operator<<(int notused) {

	if (this->mas == nullptr) return *this;
	double tmp = this->mas[0];
	for (int i = 0; i < this->n - 1; i++) {
		this->mas[i] = this->mas[i + 1];
	}
	this->mas[this->n - 1] = tmp;

	return *this;
}

/**
 * @brief Дружня функція, яка перевантажує оператор >>
 * @param rn Об'єкт лівого аргументу
 * @param notused Не використовується
 * @return Повернення об'єкту
*/
RealNumber operator>>(RealNumber& rn, int notused) {

	if (rn.mas == nullptr) return rn;
	double tmp = rn.mas[rn.n - 1];
	for (int i = rn.n - 1; i > 0; i--) {
		rn.mas[i] = rn.mas[i - 1];
	}
	rn.mas[0] = tmp;

	return rn;
}

/**
 * @brief Функція, яка перевіряє правильність введення даних користувачем
 * @param x Данні для перевірки
*/
void CheckData(int& x) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			if (x > 2147483647 || x < -2147483648) {
				cerr << "Out of range of values (-2147483648 to 2147483647)! Nearest value is set! " << endl;
				if (x > 2147483647) x = 2147483647;
				else if (x < -2147483648) x = -2147483648;
				break;
			}	
			else {
				cerr << "You enter wrong data! Please enter correct int data: \n";
				cin >> x;
			}			
			cin.ignore(666, '\n');
		}
		else break;
	}
}

int main() {

	srand(static_cast<unsigned int>(time(nullptr)));
	int work = 1;
	RealNumber rn1(2), rn2(3), rn3;

	while (work != 0) {
		cout << "rn1: "; rn1.Show();
		cout << "rn2: "; rn2.Show();
		cout << "rn3: "; rn3.Show();
		cout << setw(80) << setfill('-') << " " << setfill(' ') << endl;
		cout << setw(20) << left << "rn1 + rn2: "; (rn1 + rn2).Show();
		cout << setw(20) << left << "rn3 = rn1 - rn2: "; rn3 = rn1 - rn2; rn3.Show();
		cout << setw(20) << left << "rn3<<: "; rn3 << 1; rn3.Show();
		cout << setw(20) << left << "rn3>>: "; rn3 >> 1; rn3.Show(); cout << endl;
		cout << setw(20) << left << "Scalar product (rn1 * rn2): " << rn1 * rn2 << endl;
		cout << setw(20) << left << "Get 4 element of rn3[4]: " << rn3[4] << endl;

		if (work != 0) {
			cout << "\nRetry? 1 - yes / 0 - no" << endl;
			cin >> work;
			CheckData(work);
			rn1.Generate();
			rn2.Generate();
		}
	}

	return 0;
}