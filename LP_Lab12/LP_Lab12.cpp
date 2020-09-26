#include "FST.h"
#include <iostream>

using namespace std;

//a(b)*(cb^+(d|e)f)^+b*g

int main() {
	setlocale(LC_CTYPE, "Russian");

	char line1[] = "acbdfg";
	FST::FST_linecheck(line1);

	char line2[] = "abcbbefg";
	FST::FST_linecheck(line2);

	char line3[] = "acbbdfbbg";
	FST::FST_linecheck(line3);

	char line4[] = "abbcbbefbg";
	FST::FST_linecheck(line4);

	char line5[] = "abbbcbefg";
	FST::FST_linecheck(line5);

	char line6[] = "abbbcbbdfbbg";
	FST::FST_linecheck(line6);

	char line7[] = "acbefbbbbg";
	FST::FST_linecheck(line7);

	char line8[] = "abbbefg";				//в цепочке нет обязательного символа 'c'
	FST::FST_linecheck(line8);

	char line9[] = "aabbcbbefbg";			//более одного символа 'a'
	FST::FST_linecheck(line9);

	return 0;
}
