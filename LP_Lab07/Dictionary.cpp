#include "Dictionary.h"
using namespace Dictionary;

Instance Dictionary::Create(char name[DICTNAMEMAXSIZE], int size) {
	if (strlen(name) > DICTNAMEMAXSIZE) throw THROW01;		//превышен размер имени словар€
	if (size > DICTMAXSIZE) throw THROW02;					//превышен размер максимальной емкости словар€
	Instance *inst = new Instance;							//выделение пам€ти в куче, т.е. динамической пам€ти
	strcpy_s(inst->name, name);
	inst->size = 0;
	inst->dictionary = new Entry[size];						
	inst->maxsize = size;
	return *inst;
}

void Dictionary::AddEntry(Instance& inst, Entry ed) {
	if (inst.size == inst.maxsize) throw THROW03;			//переполнение словар€
	for (int i = 0; i < inst.size; i++) {					
		if (inst.dictionary[i].id == ed.id) throw THROW04;	//дублирование индентификатора
	}
	strcpy_s(inst.dictionary[inst.size].name, ed.name);
	inst.dictionary[inst.size].id = ed.id;
	inst.size++;
}

void Dictionary::DelEntry(Instance& inst, int id) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = i; j < inst.maxsize; j++)
				inst.dictionary[j] = inst.dictionary[j + 1];
			inst.maxsize--;
			cout << "Ёлемент " << inst.dictionary[i].name << " с id " << inst.dictionary[i].id << " удален";
			break;
		}
		if ((i + 1) == inst.size) throw THROW06;			//не найден элемент
	}							
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			for (int j = 0; j < inst.size; j++) {
				if (inst.dictionary[j].id == new_ed.id) throw THROW08;	//дублирование идентификатора
			}
			inst.dictionary[i] = new_ed;
		}
		if ((i + 1) == inst.size) throw THROW07;						//не найден элемент
	}
}

Entry Dictionary::GetEntr(Instance inst, int id) {
	for (int i = 0; i < inst.size; i++) {
		if (inst.dictionary[i].id == id) {
			return inst.dictionary[i];
		}
		if ((i + 1) == inst.size) throw THROW05;						//не найден элемент
	}
}

void Dictionary::Print(Instance d) {							//напечатать словарь
	cout << "------ " << d.name << " ------" << endl;
	cout << "id\t" << "элемент\t" << endl;
	for (int i = 0; i < d.size; i++) {
		if(d.dictionary[i].name!="")
		cout << d.dictionary[i].id << "\t" << d.dictionary[i].name << endl;
	}
}

void Dictionary::Delete(Instance* d) {							//удалить словать
	cout << "словарь удален" << endl;
	strcpy_s(d->name, "");
	d->maxsize = 0;
	d->size = 0;
	delete[] d->dictionary;
}