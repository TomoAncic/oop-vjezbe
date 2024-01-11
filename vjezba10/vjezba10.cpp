#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

void funk(const string& datoteka, const string& rijec, const string& podstring)
{
	ifstream file(datoteka);
	if (!file.is_open()) {
		cout << "Datoteka se ne moze otvoriti." << endl;
		return;
	}

	istream_iterator<string> iterator(file);
	istream_iterator<string> kraj;
	vector<string> rijeci(iterator, kraj);
	file.close();

	vector<int> pozicije;
	for (auto i = rijeci.begin(); (i = find(i, rijeci.end(), rijec)) != rijeci.end(); i++)
	{
		pozicije.push_back(distance(rijeci.begin(), i));
	}

	rijeci.erase(remove_if(rijeci.begin(), rijeci.end(), [&podstring](const string& str) {
		return str.find(podstring) != string::npos;
		}
	),rijeci.end());

	transform(rijeci.begin(), rijeci.end(), rijeci.begin(), [](string& str) {
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
		});

	copy(rijeci.begin(), rijeci.end(), ostream_iterator<string>(cout, "\n"));
	cout << "Pozicije pojavljivanja trazene rijeci: ";
	copy(pozicije.begin(), pozicije.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

struct Point {
    double x, y;


    double distance() const {
        return std::sqrt(x * x + y * y);
    }
};


std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}


void processPoints() {
    std::ifstream file("points.txt");
    std::vector<Point> points;

    std::copy(std::istream_iterator<Point>(file),
        std::istream_iterator<Point>(),
        std::back_inserter(points));


    std::sort(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            return a.distance() < b.distance();
        });


    double radius = 5.0;
    int count = std::count_if(points.begin(), points.end(),
        [radius](const Point& p) {
            return p.distance() <= radius;
        });
    std::cout << "Broj tocaka unutar kruga: " << count << std::endl;


    double specificDistance = 3.0; 
    Point newPoint = { 0, 0 };
    std::replace_if(points.begin(), points.end(),
        [specificDistance](const Point& p) {
            return std::abs(p.distance() - specificDistance) < 1e-6;
        }, newPoint);

    std::reverse(points.begin(), points.end());
    std::for_each(points.begin(), points.end(), [](const Point& p) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
        });
}


int main()
{
	//funk("words.txt", "je", "programiranje");
    processPoints();
}
