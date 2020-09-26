#include "FST.h"
#include <iostream>

	// Реализация конструктора структуры RELATION

FST::RELATION::RELATION(char c, short ns)		
{
	symbol = c;
	nnode = ns;
};

	//Реализация конструктора структуры NODE

FST::NODE::NODE()								//по умолчанию		
{
	n_relation = 0;
	RELATION* relations = NULL;
};

FST::NODE::NODE(short n, RELATION rel, ...)		//с параметрами
{
	n_relation = n;
	RELATION* p = &rel;
	relations = new RELATION[n];
	for (short i = 0; i < n; i++) relations[i] = p[i];
};

	//Реализация конструктора структуры FST

FST::FST::FST(char* s, short ns, NODE n, ...)
{
	string = s;
	nstates = ns;
	nodes = new NODE[ns];
	NODE* p = &n;
	for (int k = 0; k < ns; k++) nodes[k] = p[k];
	rstates = new short[nstates];
	memset(rstates, 0xff, sizeof(short) * nstates);
	rstates[0] = 0;
	position = -1;
};

	//Реализация функции execute

bool FST::step(FST& fst, short*& rstates)
{
	bool rc = false;
	std::swap(rstates, fst.rstates);	//смена автомата
	for (short i = 0; i < fst.nstates; i++)
	{
		if (rstates[i] == fst.position)
			for (short j = 0; j < fst.nodes[i].n_relation; j++)
			{
				if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
				{
					fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
					rc = true;
				};
			}
	};
	return rc;
};

bool FST::execute(FST& fst)				//выполнить распонавание цепочки
{
	short* rstates = new short[fst.nstates]; memset(rstates, 0xff, sizeof(short) * fst.nstates);
	short lstring = strlen(fst.string);
	bool rc = true;
	for (short i = 0; i < lstring && rc; i++)
	{
		fst.position++;					//продвинули позицию
		rc = step(fst, rstates);		//о
	};
	delete[] rstates;
	return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
};

void FST::FST_linecheck(char* someline) {
	FST myFST(					// нка a(b)*(cb^+(d|e)f)^+b*g
		someline,								// строка для распознавания
		7,										// количество состояний
		NODE(1, RELATION('a', 1)),											// S0
		NODE(2, RELATION('b', 1), RELATION('c', 2)),						// S1
		NODE(1, RELATION('b', 3)),											// S2
		NODE(3, RELATION('b', 3), RELATION('d', 4), RELATION('e', 4)),		// S3
		NODE(1, RELATION('f', 5)),											// S4
		NODE(3, RELATION('b', 5), RELATION('c', 2), RELATION('g', 6)),		// S5
		NODE()																// S6
		);

	if (execute(myFST)) {
		std::cout << "Цепочка " << myFST.string << " распознана." << std::endl;
	}
	else {
		std::cout << "Цепочка " << myFST.string << " не распознана." << std::endl;
	}
}