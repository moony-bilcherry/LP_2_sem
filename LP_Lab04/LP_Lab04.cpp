//X= 9 + n, Y= 10 + n, Z= 11 + n, S= 1.0 + n
//n = 8
//x = 17; y = 18; z = 19; s = 9.0
#include <iostream>

int fun(int a) {
	return a + 5; 
}

int main() {
	// 4
	bool b1 = true, b2 = false;
	// 5
	char ch1 = 'K';
	// 6
	wchar_t wch1 = L'й';
	// 7
	short sh1 = 17; // 0001 0001 - 0x11 
	short sh2 = -17; // пк: -0001 0001, ок: 1110 1110, дк: 1110 1111 - 0xFFEF
	// 8
	short min_sh = 0x8001; // −32,767 - пк: 0111 1111 1111 1111 - ок: 1000 0000 0000 0000 - дк: 1000 0000 0000 0001
	short max_sh = 0x7FFF; // +32,767 - пк: 0111 1111 1111 1111
	// 9
	unsigned short min_ush = 0; // 0
	unsigned short max_ush = 0x0000FFFF; // 65,535 - пк: 1111 1111 1111 1111
	// 10
	int i1 = 18; // пк: 0001 0010 - 0x12
	int i2 = -18; // ок: 1110 1101, дк: 1110 1110 - 0xFFEE
	// 11
	int min_i = 0x8001; // −32,767
	int max_i = 0x7FFF; // +32,767
	// 12
	unsigned int min_ui = 0; // 0
	unsigned int max_ui = 0xFFFF; // 65,535
	// 13
	long l1 = 19; // пк: 0001 0011 - 0x13
	long l2 = -19; // ок: 1110 1100, дк: 1110 1101 - 0xFFFFFFED
	// 14
	long min_l = 0x80000001; // −2,147,483,647
	long max_l = 0x7FFFFFFF; // +2,147,483,647
	// 15
	unsigned long min_ul = 0; // 0
	unsigned long max_ul = 0xFFFFFFFF; // 4,294,967,295
	// 16
	float f1 = 9.3f; 
	/*  9(10) = 1001(2); 0.3(10)=01001100110011... ; 9.3 = + 1.00101001100110011... * 2^3;
	экспонента = 127+3 = 130(10) = 1000 0010; бит знака = 0;
	9.3 = 0100 0001 0001 0100 1100 1100 1100 1101 = 4 1 1 4 12 12 12 13 = 4114CCCD
	*/
	float f2 = -9.3f; // -9.3 = 1100 0001 0001 0100 1100 1100 1100 1101 = 12 1 1 4 12 12 12 13 = C114CCCD
	// 17
	float x = 23.635f, y = -23.625f;
	float S1 = x / 0;  //1.#INF
	float S2 = y / 0; //-1.#INF
	float S3 = sqrt(y); //-1.IND
	// 18
	char* pch = &ch1;
	wchar_t* pwch = &wch1;
	short* psh = &sh1;
	int* pi = &i1;
	float* pf = &S1;
	double d1 = 2.35; 
	double* pd = &d1;
	*pch += 3;
	*pwch += 3;
	*psh += 3;
	*pi += 3;
	*pf += 3;
	*pd += 3;
	// 19
	int(*pff)(int);
	pff = &fun;
	// 20
	char& lch = ch1;
	wchar_t& lwch = wch1;
	short& lsh = sh1;
	int& li = i1;
	float& lf = f1;
	double& ld = d1;

	system("pause");
	return 0;
}