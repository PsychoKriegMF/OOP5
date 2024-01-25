#include <iostream>

//конструкторы копирования и операторы класса
//операторы и специальные конструкторы в классах


/*
Правила работы операторов 

1.Операторы можно перегружать только для классов, для встроенных типов данных операторы не перегружают
2.Оператор нельзя перегружать изменяя его поведение
3.Ряд операторов запрещено перегружать: '.'  ?:  & - унарный амперсанд   ::   ->
*/

class Integer {
public:
	Integer() : data_(0) {}
	Integer(int num) : data_(num) {}

	//перегрузка оператора как дружественной функции

	friend Integer operator+ (Integer A, Integer B) {
		Integer result;
		result.data_ = A.data_ + B.data_;
		return result;
		//return Integer(this->data_ + obj.data_);
		}

	friend std::ostream& operator << (std::ostream& out, const Integer& obj);

	int GetNum() {
		return data_;
	}
	//Оператор перегружен как метод класса
	Integer& operator=(const Integer& other) {
		this->data_ = other.data_;
		return *this;
	}

private:
	int data_;
//===========
	//bool sign_;
	//unsigned long long units_;
	// такая реализация нужна для математически достоверных целых чисел

};
std::ostream& operator << (std::ostream & out, const Integer & obj) {
	return out << obj.data_;
}
//перегрузка оператора как независимой функции
Integer operator-(Integer a, Integer b) {
	return a.GetNum() - b.GetNum();
}
Integer operator*(Integer a, Integer b) {
	return a.GetNum() * b.GetNum();
}
Integer operator/(Integer a, Integer b) {
	return a.GetNum() / b.GetNum();
}
//Integer operator+(Integer a, Integer b) {
//	return a.GetNum() + b.GetNum();
//}


int main() {
	setlocale(LC_ALL, "ru");

	int a{ 5 };
	int b{ 8 };

	operator-(a, b);
	std::cout << a + b << '\n';
	std::cout << a - b << '\n';
	std::cout << a * b << '\n';
//===============================
	std::cout << a + 5 << '\n';
	std::cout << a - 5 << '\n';
	std::cout << a * 5 << '\n';
	std::cout << a / 5 << '\n';
//===============================
	std::cout << b - 5 << '\n';
	std::cout << b * 5 << '\n';
	std::cout << b / 5 << '\n';




	return 0;
}