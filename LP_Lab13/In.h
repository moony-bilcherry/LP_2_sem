#pragma once

#define IN_MAX_LEN_TEXT 1024*1024               //����. ������ ��������� ���� = 1 ��
#define IN_CODE_ENDL '\n'                       //������ ����� ������

#define IN_CODE_TABLE {\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, '|'/*\n*/, IN::F, IN::F,	IN::I, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::T,	IN::T, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::T/*0*/,	IN::F, IN::T/*2*/, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F,IN::F, IN::T/*N*/, IN::F,\
	IN::F,	IN::F, IN::F, IN::T, IN::F,	IN::F, IN::F, IN::T, IN::I/*X*/, IN::T/*Y*/, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F,\
	IN::F,  IN::T/*a*/, IN::T/*b*/, IN::T/*c*/, IN::T/*d*/, IN::T/*e*/, IN::T/*f*/, IN::T/*g*/, IN::T/*h*/,IN::T/*i*/, IN::F, IN::T/*k*/, IN::T/*l*/,IN::F, IN::T/*n*/, IN::F,\
	IN::F,	IN::F, IN::T/*r*/, IN::T/*s*/, IN::T/*t*/, IN::T, IN::F, IN::F, IN::F,IN::T/*y*/, IN::F, IN::F, IN::T/*|*/, IN::F, IN::F, IN::F,\
																													\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	'-'/*�*/, IN::F, IN::F, IN::F, IN::F, IN::T/*�*/, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T/*�*/, IN::F, IN::F,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F,\
	IN::T/*�*/,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::T/*�*/, IN::F, IN::T/*�*/, IN::T/*�*/, IN::F, IN::T/*�*/, IN::F, IN::F,\
	IN::T/*�*/,	IN::T/*�*/, IN::T/*�*/, IN::F, IN::F, IN::F, IN::F, IN::T/*�*/, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T/*�*/\
}

namespace In {
	struct IN {
		enum { T = 1024, F = 2048, I = 4096 };
		int size;
		int lines;
		int ignor;
		unsigned char* text;
		int code[256] = IN_CODE_TABLE;
	};
	IN getin(wchar_t infile[]);
};