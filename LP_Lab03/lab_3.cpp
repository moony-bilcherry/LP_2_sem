#include <iostream>
#include <cstdlib>
using namespace std;

//ErchinskayaNataliya2002
//ЕрчинскаяНаталия2002
//Ерчинская2002Nataliya

//Windows-1251
// 45 72 63 68 69 6E 73 6B 61 79 61 4E 61 74 61 6C 69 79 61 32 30 30 32
// C5 F0 F7 E8 ED F1 EA E0 FF CD E0 F2 E0 EB E8 FF 32 30 30 32
// C5 F0 F7 E8 ED F1 EA E0 FF 32 30 30 32 4E 61 74 61 6C 69 79 61

// UTF-8
// 45 72 63 68 69 6E 73 6B 61 79 61 4E 61 74 61 6C 69 79 61 32 30 30 32
// D0 95 D1 80 D1 87 D0 B8 D0 BD D1 81 D0 BA D0 B0 D1 8F D0 9D D0 B0 D1 82 D0 B0 D0 BB D0 B8 D1 8F 32 30 30 32
// D0 95 D1 80 D1 87 D0 B8 D0 BD D1 81 D0 BA D0 B0 D1 8F 32 30 30 32 4E 61 74 61 6C 69 79 61

// UTF-16
// 00 45 00 72 00 63 00 68 00 69 00 6e 00 73 00 6b 00 61 00 79 00 61 00 4e 00 61 00 74 00 61 00 6c 00 69 00 79 00 61 00 32 00 30 00 30 00 32
// 04 15 04 40 04 47 04 38 04 3d 04 41 04 3a 04 30 04 4f 04 1d 04 30 04 42 04 30 04 3b 04 38 04 4f 00 32 00 30 00 30 00 32
// 04 15 04 40 04 47 04 38 04 3d 04 41 04 3a 04 30 04 4f 00 32 00 30 00 30 00 32 00 4e 00 61 00 74 00 61 00 6c 00 69 00 79 00 61


char rf[] = "ЕрчинскаяНаталия2002";
char lr[] = "Ерчинская2002Nataliya";

wchar_t Llf[] = L"ErchinskayaNataliya2002";
wchar_t Lrf[] = L"ЕрчинскаяНаталия2002";
wchar_t Llr[] = L"Ерчинская2002Nataliya";

char* UpperW1251(char* destination, char* source) {
	for (int i = 0; i < strlen(source); i++)
		if ((source[i] > 96 && source[i] < 123) || ((source[i] >= -32) && (source[i] <= -1)))
			destination[i] = source[i] - 32;
		else destination[i] = source[i];
	return destination;
}

int main() {

	setlocale(LC_ALL, "Russian");
	char lf[] = "ErchinskayaNataliya2002";
	cout << "'S' - 's' = " << 'S' - 's' << endl;
	cout << "'L' - 'l' = " << 'L' - 'l' << endl;
	cout << "'Б' - 'б' = " << 'Б' - 'б' << endl;
	cout << "'Г' - 'г' = " << 'Г' - 'г' << endl;
	cout << "'Э' - 'э' = " << 'Э' - 'э' << endl;

	char source[] = "12345sdfghjlйцгшщз";
	char destination[] = "124567890123456789";

	UpperW1251(destination, source);
	cout << destination << endl;

	system("pause");
	return 0;
}
