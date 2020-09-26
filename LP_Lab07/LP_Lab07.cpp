#include "stdafx.h"
#include "Dictionary.h"
using namespace Dictionary;

#if (defined(TEST_DICTIONARY) + defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) > 1) 
#error установлено больше одного макроса;
#endif

int main()
{
	setlocale(LC_ALL, "rus");
	try {
	char ex0[] = "ѕреподаватели";
	Instance d3 = Create(ex0, 5);
	Entry e1 = { 1,"√ладкий" }, //элементы словар€
		e2 = { 2,"¬е€лкин" },
		e3 = { 3,"—мелов" },
		e4 = { 4,"”рбанович" },
		e5 = { 5,"ѕацей" },
		e6 = { 31,"„ист€кова" };
	AddEntry(d3, e4);

#ifdef TEST_CREATE_01									//превышен размер имени словар€
		char ex1[] = "эта—трока—лишкомƒлинна€—ледовательноќшибка";
		Instance d4 = Create(ex1, 5);
#endif 

#ifdef TEST_CREATE_02									//превышен размер максимальной емкости словар€
		char ex1[] = "допустим";
		Instance d5 = Create(ex1, DICTMAXSIZE + 1);		//размер словар€ на 1 больше допустимого
#endif

#ifdef TEST_ADDENTRY_03									//переполнение словар€
		char ex1[] = "допустим";
		Instance inst = Create(ex1, DICTMAXSIZE);
		for (int i = 0; i < 101; i++) {
			Entry test = { i,"гав" };
			AddEntry(inst, test);
		}
#endif

#ifdef TEST_ADDENTRY_04									//дублирование индентификатора
		char ex1[] = "допустим";
		Instance inst = Create(ex1, 2);
		Entry test1 = { 1,"гав" };
		Entry test2 = { 1,"м€у" };
		AddEntry(inst, test1);
		AddEntry(inst, test2);
#endif

#ifdef TEST_GETENTRY_05									//GetEntry: не найден элемент
		Entry ex05 = GetEntr(d3, 10);
#endif

#ifdef TEST_DELENTRY_06									//DelEntry: не найден элемент
		DelEntry(d3, 7);
#endif

#ifdef TEST_UPDENTRY_07									//UpdEntry: не найден элемент
		Entry newentry1 = { 6,"допустим" };
		UpdEntry(d3, 8, newentry1);
#endif

#ifdef TEST_UPDENTRY_08
		Entry newentry1 = { 4,"допустим" };
		UpdEntry(d3, 4, newentry1);
#endif

#ifdef  TEST_DICTIONARY
		char ex1[] = "песели";
		Instance d1 = Create(ex1, 7);
		Entry e11 = { 1,"бордер колли" }, 
			e12 = { 2,"шнауцер" },
			e13 = { 3,"самоед" },
			e14 = { 4,"австралийска€" },
			e15 = { 5,"корги" },
			e16 = { 6,"мопс" },
			e17 = { 7,"зенненхунд" };
		AddEntry(d1, e11);
		AddEntry(d1, e12);
		AddEntry(d1, e13);
		AddEntry(d1, e14);
		AddEntry(d1, e15);
		AddEntry(d1, e16);
		AddEntry(d1, e17);
		Print(d1);
		
		char ex2[] = "котики";
		Instance d2 = Create(ex2, 7);
		Entry e01 = { 1,"скоттиш фолд" },
			e02 = { 2,"мейн-кун" },
			e03 = { 3,"персидский" },
			e04 = { 4,"абиссинский" },
			e05 = { 5,"бенгальска€" },
			e06 = { 6,"русска€ голуба€" },
			e07 = { 7,"сфинкс" };
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