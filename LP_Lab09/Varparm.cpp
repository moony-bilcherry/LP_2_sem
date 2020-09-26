#include "Varparm.h"
#include <stdarg.h>
#include <locale>

namespace Varparm {
		//произведение параметров начиная со 2-го (1-й - количество элементов)
	int ivarparm(int n, ...) {
		if (n == 0) return 0;						//если параметров 0
		int multi = 1;
		int* p = &n;								//указатель на первый множитель
		p++;
		for (int i = 0; i < n; i++) {
			multi *= *(p + i);
		}
		return multi;
	}
		//произведение параметров начиная со 2-го
	int svarparm(short n, ...) {
		if (n == 0) return 0;						//если параметров 0
		short multi = 1;
		int* p = (int*)(&n);						//преобразовываем указатель 
		p++;
		for (int i = 0; i < n; i++) {
			multi *= *(p + i);
		}
		return (int)multi;
	}

		//числа суммируются, пока не передано максимальное
	double fvarparm(float n, ...) {
		//через макросы из stdarg.h:
		/*if (n == FLT_MAX) return 0;
		va_list arg;
		float sum = n, f1 = 0;
		va_start(arg, n);
		while ((f1 = va_arg(arg, double)) != FLT_MAX) {
			sum += f1;
		}
		va_end(arg);*/

		if (n == FLT_MAX) return 0;
		double* p = (double*)(&n + 1);
		double sum = n;
		int k = 0;
		while (p[k] != (double)FLT_MAX) 		{
			sum += p[k];
			k++;
		}
		return sum;
	}
		//числа суммируются, пока не передано максимальное
	double dvarparm(double d, ...) {
		double* p = &d, sum = 0;
		int k = 0;
		while (p[k] != DBL_MAX) {
			sum += p[k];
			k++;
		}
		return sum;
	}
}
