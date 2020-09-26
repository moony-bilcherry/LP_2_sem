#include "Varparm.h"
#include <stdarg.h>
#include <locale>

namespace Varparm {
		//������������ ���������� ������� �� 2-�� (1-� - ���������� ���������)
	int ivarparm(int n, ...) {
		if (n == 0) return 0;						//���� ���������� 0
		int multi = 1;
		int* p = &n;								//��������� �� ������ ���������
		p++;
		for (int i = 0; i < n; i++) {
			multi *= *(p + i);
		}
		return multi;
	}
		//������������ ���������� ������� �� 2-��
	int svarparm(short n, ...) {
		if (n == 0) return 0;						//���� ���������� 0
		short multi = 1;
		int* p = (int*)(&n);						//��������������� ��������� 
		p++;
		for (int i = 0; i < n; i++) {
			multi *= *(p + i);
		}
		return (int)multi;
	}

		//����� �����������, ���� �� �������� ������������
	double fvarparm(float n, ...) {
		//����� ������� �� stdarg.h:
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
		//����� �����������, ���� �� �������� ������������
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
