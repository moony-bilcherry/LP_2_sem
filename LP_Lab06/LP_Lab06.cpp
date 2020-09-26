#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned int year;

struct  Date {
	day dd;
	month mm;
	year yyyy;
};

//1. перегрузка операторов 

bool operator==(Date d1, Date d2) { 
	return ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd == d2.dd));
}

bool operator>(Date d1, Date d2) {
	return ((d1.yyyy > d2.yyyy) || ((d1.yyyy == d2.yyyy) && (d1.mm > d2.mm)) || ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd > d2.dd)));
}

bool operator<(Date d1, Date d2) {
	return ((d1.yyyy < d2.yyyy) || ((d1.yyyy == d2.yyyy) && (d1.mm < d2.mm)) || ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd < d2.dd)));
}

//2. Разработайте две операции для данных указанного типа, реализовав каждую из них в виде функции. (точка в пространстве)

struct coordinates {
	int x;
	int y;
	int z;
};

float distance(coordinates p1, coordinates p2) {
	return sqrt((pow((p2.x - p1.x), 2)) + (pow((p2.y - p1.y), 2)) + (pow((p2.z - p1.z), 2)));
}

void vect(coordinates p1, coordinates p2) {
	cout << "вектор из двух точек = (" << p2.x - p1.x << "," << p2.y - p1.y << "," << p2.z - p1.z << ")" << endl;
}

coordinates operator+(coordinates c1, coordinates c2) {
	coordinates c3;
	c3.x = c1.x + c2.x;
	c3.y = c1.y + c2.y;
	c3.z = c1.z + c2.z;
	return c3;
}


int main()
{
	setlocale(LC_ALL, "rus");

	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1993 };
	Date date3 = { 7,1,1980 };

	cout << "задание 1" << endl << endl;

	if (date1 < date2)
		cout << "истина" << endl;
	else
		cout << "ложь" << endl;

	if (date1 > date2)
		cout << "истина" << endl;
	else
		cout << "ложь" << endl;

	if (date1 == date2)
		cout << "истина" << endl;
	else
		cout << "ложь" << endl;

	if (date1 == date3)
		cout << "истина" << endl;
	else
		cout << "ложь" << endl;

	cout << endl << "задание 2" << endl << endl;

	coordinates point1 = { 4,16,30 };
	coordinates point2 = { 28,4,17 };

	cout << "расстояние между точками = " << distance(point1, point2) << endl;
	vect(point1, point2);
	system("pause");
	return 0;
}
