#pragma once
#pragma once
#include <cstring>
#include <iostream>
using namespace std;

#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30

#define THROW01 "Create: превышен размер имени словар€";
#define THROW02 "Create: превышен размер максимальной емкости словар€";
#define THROW03 "AddEntry: переполнение словар€";
#define THROW04 "AddEntry: дублирование индентификатора";
#define THROW05 "GetEntry: не найден элемент";
#define THROW06 "DelEntry: не найден элемент";
#define THROW07 "UpdEntry: не найден элемент";
#define THROW08 "UpdEntry: дублирование идентификатора";

namespace Dictionary {
	struct Entry {								//элемент словар€
		int id;									//его уникальный идентификатор
		char name[ENTRYNAMEMAXSIZE];			//символьна€ информаци€
	};
	struct Instance {							//экземпл€р словар€
		char name[DICTNAMEMAXSIZE];				//название словар€
		int maxsize;							//макс.	емкость словар€
		int size;								//текущий размер словар€ < DICTNAMEMAXSIZE
		Entry* dictionary;						//указатель на массив эл-тов словар€
	};

	Instance Create(char name[DICTNAMEMAXSIZE], int size);	//создать словарь
	void AddEntry(Instance& inst, Entry ed);				//добавить элемент в словарь
	void DelEntry(Instance& inst, int id);					//удалить элемент словар€
	void UpdEntry(Instance& inst, int id, Entry new_ed);	//изменить элемент словар€
	Entry GetEntr(Instance inst, int id);					//получить элемент словар€ по id
	void Print(Instance d);									//печать словар€
	void Delete(Instance* d);								//удаление словар€
}