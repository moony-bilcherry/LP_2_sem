#include "Varparm.h"
#include "Call.h"

using namespace std;
using namespace Varparm;
using namespace Call;

int defaultparm(int a1, int a2, int a3, int a4, int a5, int a6 = 2, int a7 = 3) {
	return (a1 + a2 + a3 + a4 + a5 + a6 + a7) / 7;
}

int main() {
	//Продемонстрируйте работу функций (см. таблицу 1) с общим количеством параметров 1, 2, 3, 7 для каждой
	cout << "\tivarparm:" << endl;
	cout << "ivarparm(0) = " << ivarparm(0) << endl;
	cout << "ivarparm(1,4) = " << ivarparm(1,4) << endl;
	cout << "ivarparm(2,5,3) = " << ivarparm(2,5,3) << endl;
	cout << "ivarparm(6,7,4,6,2,5,3) = " << ivarparm(6, 7, 4, 6, 2, 5, 3) << endl;

	cout << "\tsvarparm:" << endl;
	cout << "svarparm(0) = " << svarparm(0) << endl;
	cout << "svarparm(1,4) = " << svarparm(1, 4) << endl;
	cout << "svarparm(2,5,3) = " << svarparm(2, 5, 3) << endl;
	cout << "svarparm(6,7,4,6,2,5,3) = " << svarparm(6, 7, 4, 6, 2, 5, 3) << endl;

	cout << "\tfvarparm:" << endl;
	cout << "fvarparm(FLT_MAX) = " << fvarparm(FLT_MAX) << endl;
	cout << "fvarparm(5.3, FLT_MAX) = " << fvarparm(5.3, FLT_MAX) << endl;
	cout << "fvarparm(3.2, 5.4, FLT_MAX) = " << fvarparm(3.2, 5.4, FLT_MAX) << endl;
	cout << "fvarparm(6.1, 7.0, 4.7, 6.2, 2.1, 5.5, FLT_MAX) = " << fvarparm(6.1, 7.0, 4.7, 6.2, 2.1, 5.5, FLT_MAX) << endl;

	cout << "\tdvarparm:" << endl;
	cout << "dvarparm(DBL_MAX) = " << dvarparm(DBL_MAX) << endl;
	cout << "dvarparm(5.3, DBL_MAX) = " << dvarparm(5.3, DBL_MAX) << endl;
	cout << "dvarparm(3.2, 5.4, DBL_MAX) = " << dvarparm(3.2, 5.4, DBL_MAX) << endl;
	cout << "dvarparm(6.1, 7.0, 4.7, 6.2, 2.1, 5.5, DBL_MAX) = " << dvarparm(6.1, 7.0, 4.7, 6.2, 2.1, 5.5, DBL_MAX) << endl << endl;

	int a = 2, b = 3, c = 4;
	cout << "cdevl = " << cdevl(a, b, c) << endl;
	cout << "cstd = " << cstd(a, 3, 4) << endl;
	cout << "cfst = " << cfst(2, 3, 4) << endl << endl;

	cout << "5 param (1--5): " << defaultparm(1, 2, 3, 4, 5) << endl;
	cout << "7 param (1--7): " << defaultparm(1, 2, 3, 4, 5, 6, 7) << endl;
}