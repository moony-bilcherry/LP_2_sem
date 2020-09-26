#pragma once
#include <iostream>

namespace FST
{
	struct RELATION					//ребро:символ -> вершина графа переходов КА
	{
		char symbol;				//символ перехода
		short nnode;				//номер смежной вершины
		RELATION(
			char c = 0x00,			//символ перехода
			short ns = NULL			//новое состояние
			);
	};

	struct NODE						//вершина графа переходов
	{
		short n_relation;			//количество инциндентных ребер
		RELATION* relations;		//инциндентные ребра
		NODE();						
		NODE(
			short n,				//количество инциндентных ребер
			RELATION rel, ...		//список ребер
			);
	};

	struct FST						//недетерминированный конечный автомат
	{
		char* string;				//цепочка (строка, завершается 0х00)
		short position;				//текущая позиция в цепочке
		short nstates;				//количество состояний автомата
		NODE* nodes;				//граф переходов: [0] - начальное состояние, [nstates-1] 
		short* rstates;				
		FST(
			char* s,
			short ns,
			NODE n, ...
			);
	};
	bool execute(FST& fst);
	bool step(FST& fst, short*& rstates);
	void FST_linecheck(char* string);
};