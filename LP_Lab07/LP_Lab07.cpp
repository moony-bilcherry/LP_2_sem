#include "stdafx.h"
#include "Dictionary.h"
using namespace Dictionary;

#if (defined(TEST_DICTIONARY) + defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) > 1) 
#error ����������� ������ ������ �������;
#endif

int main()
{
	setlocale(LC_ALL, "rus");
	try {
	char ex0[] = "�������������";
	Instance d3 = Create(ex0, 5);
	Entry e1 = { 1,"�������" }, //�������� �������
		e2 = { 2,"�������" },
		e3 = { 3,"������" },
		e4 = { 4,"���������" },
		e5 = { 5,"�����" },
		e6 = { 31,"���������" };
	AddEntry(d3, e4);

#ifdef TEST_CREATE_01									//�������� ������ ����� �������
		char ex1[] = "������������������������������������������";
		Instance d4 = Create(ex1, 5);
#endif 

#ifdef TEST_CREATE_02									//�������� ������ ������������ ������� �������
		char ex1[] = "��������";
		Instance d5 = Create(ex1, DICTMAXSIZE + 1);		//������ ������� �� 1 ������ �����������
#endif

#ifdef TEST_ADDENTRY_03									//������������ �������
		char ex1[] = "��������";
		Instance inst = Create(ex1, DICTMAXSIZE);
		for (int i = 0; i < 101; i++) {
			Entry test = { i,"���" };
			AddEntry(inst, test);
		}
#endif

#ifdef TEST_ADDENTRY_04									//������������ ���������������
		char ex1[] = "��������";
		Instance inst = Create(ex1, 2);
		Entry test1 = { 1,"���" };
		Entry test2 = { 1,"���" };
		AddEntry(inst, test1);
		AddEntry(inst, test2);
#endif

#ifdef TEST_GETENTRY_05									//GetEntry: �� ������ �������
		Entry ex05 = GetEntr(d3, 10);
#endif

#ifdef TEST_DELENTRY_06									//DelEntry: �� ������ �������
		DelEntry(d3, 7);
#endif

#ifdef TEST_UPDENTRY_07									//UpdEntry: �� ������ �������
		Entry newentry1 = { 6,"��������" };
		UpdEntry(d3, 8, newentry1);
#endif

#ifdef TEST_UPDENTRY_08
		Entry newentry1 = { 4,"��������" };
		UpdEntry(d3, 4, newentry1);
#endif

#ifdef  TEST_DICTIONARY
		char ex1[] = "������";
		Instance d1 = Create(ex1, 7);
		Entry e11 = { 1,"������ �����" }, 
			e12 = { 2,"�������" },
			e13 = { 3,"������" },
			e14 = { 4,"�������������" },
			e15 = { 5,"�����" },
			e16 = { 6,"����" },
			e17 = { 7,"����������" };
		AddEntry(d1, e11);
		AddEntry(d1, e12);
		AddEntry(d1, e13);
		AddEntry(d1, e14);
		AddEntry(d1, e15);
		AddEntry(d1, e16);
		AddEntry(d1, e17);
		Print(d1);
		
		char ex2[] = "������";
		Instance d2 = Create(ex2, 7);
		Entry e01 = { 1,"������� ����" },
			e02 = { 2,"����-���" },
			e03 = { 3,"����������" },
			e04 = { 4,"�����������" },
			e05 = { 5,"�����������" },
			e06 = { 6,"������� �������" },
			e07 = { 7,"������" };
		AddEntry(d2, e01);
		AddEntry(d2, e02);
		AddEntry(d2, e03);
		AddEntry(d2, e04);
		AddEntry(d2, e05);
		AddEntry(d2, e06);
		AddEntry(d2, e07);
		Print(d2);
		Delete(&d1);
		Delete(&d2);
#endif
	}
	catch (const char* e) {
		cout << e << endl;
	};
	system("pause");
	return 0;
}