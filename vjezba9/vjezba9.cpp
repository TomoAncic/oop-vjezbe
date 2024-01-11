#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
T min(T& a, T& b) {
	if (a < b)
	{
		return a;
	}
	else{
		return b;
	}
}

template <typename T>
class skup {
private:
	vector<T> elementi;
public:
	void dodaj(const T& element) {
		elementi.push_back(element);
	}

	void isbrisi(const T& element) {
		auto i = find(elementi.begin(), elementi.end(), element);
		if (i != elementi.end())
		{
			elementi.erase(i);
		}
	} 
	 
	bool sadrzi(const T& element) {
		for(auto& i : elementi)
		{
			if (i == element)
			{
				return true;
			}
		}
		return false;
	}

	void prikazi() const{
		cout << "Skup: " << endl;
		for (auto& element : elementi)
		{
			cout << element << " " << endl;
		}
	}
};

bool poredaj(char a, char b) {
	if (tolower(a) < tolower(b))
	{
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
void sortiraj(T* niz, int duzina){
	sort(niz, niz + duzina);
}

template<>
void sortiraj(char* niz, int duzina) {
	sort(niz, niz + duzina, poredaj);
}

template <typename T>
class point {
private:
	T x;
	T y;
public:
	point(T x, T y) {
		this->x = x;
		this->y = y;
	}

	T returnX() const{
		return x;
	}

	T returnY() const{
		return y;
	}
};

template <typename T>
class point {
private:
	T x, y;

public:
	point(T x, T y) : x(x), y(y) {}

	double operator-(const point& other) const {
		T dx = x - other.x;
		T dy = y - other.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	friend std::ostream& operator<<(std::ostream& os, const point& p) {
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}
};

int main()
{
	//int a = 10;
	//int b = 1;
	//cout << "Manji od brojeva: " << min(a, b) << endl;

	//string str1 = "ovo";
	//string str2 = "programiranje";
	//cout << "Manji od stringova: " << min(str1, str2) << endl;


	//skup<int> a;
	//a.dodaj(1);
	//a.dodaj(2);
	//a.dodaj(3);
	//a.prikazi();
	//a.isbrisi(2);
	//a.prikazi();
	//cout << "Da li sadrzi skup broj 3: " << (a.sadrzi(3)) << endl;


	//char niz[] = "programiranje";
	//int duzina = sizeof(niz) - 1;
	//sortiraj(niz, duzina);
	//cout << "Sortiran niz: " << niz << endl;

	//int niz1[] = { 1,11,43,3,2 };
	//int duzina1 = sizeof(niz1) / sizeof(int);
	//sortiraj(niz1, duzina1);
	//cout << "Sortiran niz: " << endl;
	//for (int i = 0; i < duzina1; i++)
	//{
	//	cout << niz1[i] << " ";
	//}

	point<int> p1(2, 3), p2(3, 4);
	cout << " udaljenost tocaka " << p1 << " i " << p2 << " je " << p1 - p2 << endl;
}
