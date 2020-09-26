#include <iostream>
#include <locale>
#include "..\..\LP_Lab08S\LP_Lab08L\Dictionary.h"
using namespace Dictionary;

int main() {
	setlocale(LC_ALL, "rus");
	char ex1[] = "песели";
	Instance d1 = Create(ex1, 7);
	Entry e11 = { 1,"бордер колли" },
		e12 = { 2,"шнауцер" },
		e13 = { 3,"самоед" },
		e14 = { 4,"австралийская" },
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
		e05 = { 5,"бенгальская" },
		e06 = { 6,"русская голубая" },
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
	system("pause");
}
