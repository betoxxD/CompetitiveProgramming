#include <bits/stdc++.h>
#include <cstdio>

std::string lettersC5[300];

void setC5Letters()
{

	lettersC5[0] = ".***..";
	lettersC5[1] = "*...*.";
	lettersC5[2] = "*****.";
	lettersC5[3] = "*...*.";
	lettersC5[4] = "*...*.";

	lettersC5[5] = "****..";
	lettersC5[6] = "*...*.";
	lettersC5[7] = "****..";
	lettersC5[8] = "*...*.";
	lettersC5[9] = "****..";

	lettersC5[10] = ".****.";
	lettersC5[11] = "*...*.";
	lettersC5[12] = "*.....";
	lettersC5[13] = "*.....";
	lettersC5[14] = ".****.";

	lettersC5[15] = "****..";
	lettersC5[16] = "*...*.";
	lettersC5[17] = "*...*.";
	lettersC5[18] = "*...*.";
	lettersC5[19] = "****..";

	lettersC5[20] = "*****.";
	lettersC5[21] = "*.....";
	lettersC5[22] = "***...";
	lettersC5[23] = "*.....";
	lettersC5[24] = "*****.";

	lettersC5[25] = "*****.";
	lettersC5[26] = "*.....";
	lettersC5[27] = "***...";
	lettersC5[28] = "*.....";
	lettersC5[29] = "*.....";

	lettersC5[30] = ".****.";
	lettersC5[31] = "*.....";
	lettersC5[32] = "*..**.";
	lettersC5[33] = "*...*.";
	lettersC5[34] = ".***..";

	lettersC5[35] = "*...*.";
	lettersC5[36] = "*...*.";
	lettersC5[37] = "*****.";
	lettersC5[38] = "*...*.";
	lettersC5[39] = "*...*.";

	lettersC5[40] = "*****.";
	lettersC5[41] = "..*...";
	lettersC5[42] = "..*...";
	lettersC5[43] = "..*...";
	lettersC5[44] = "*****.";

	lettersC5[45] = "..***.";
	lettersC5[46] = "...*..";
	lettersC5[47] = "...*..";
	lettersC5[48] = "*..*..";
	lettersC5[49] = ".**...";

	lettersC5[50] = "*...*.";
	lettersC5[51] = "*..*..";
	lettersC5[52] = "***...";
	lettersC5[53] = "*..*..";
	lettersC5[54] = "*...*.";

	lettersC5[55] = "*.....";
	lettersC5[56] = "*.....";
	lettersC5[57] = "*.....";
	lettersC5[58] = "*.....";
	lettersC5[59] = "*****.";

	lettersC5[60] = "*...*.";
	lettersC5[61] = "**.**.";
	lettersC5[62] = "*.*.*.";
	lettersC5[63] = "*...*.";
	lettersC5[64] = "*...*.";

	lettersC5[65] = "*...*.";
	lettersC5[66] = "**..*.";
	lettersC5[67] = "*.*.*.";
	lettersC5[68] = "*..**.";
	lettersC5[69] = "*...*.";

	lettersC5[70] = ".***..";
	lettersC5[71] = "*...*.";
	lettersC5[72] = "*...*.";
	lettersC5[73] = "*...*.";
	lettersC5[74] = ".***..";

	lettersC5[75] = "****..";
	lettersC5[76] = "*...*.";
	lettersC5[77] = "****..";
	lettersC5[78] = "*.....";
	lettersC5[79] = "*.....";

	lettersC5[80] = ".***..";
	lettersC5[81] = "*...*.";
	lettersC5[82] = "*...*.";
	lettersC5[83] = "*..**.";
	lettersC5[84] = ".****.";

	lettersC5[85] = "****..";
	lettersC5[86] = "*...*.";
	lettersC5[87] = "****..";
	lettersC5[88] = "*..*..";
	lettersC5[89] = "*...*.";

	lettersC5[90] = ".****.";
	lettersC5[91] = "*.....";
	lettersC5[92] = ".***..";
	lettersC5[93] = "....*.";
	lettersC5[94] = "****..";

	lettersC5[95] = "*****.";
	lettersC5[96] = "*.*.*.";
	lettersC5[97] = "..*...";
	lettersC5[98] = "..*...";
	lettersC5[99] = ".***..";

	lettersC5[100] = "*...*.";
	lettersC5[101] = "*...*.";
	lettersC5[102] = "*...*.";
	lettersC5[103] = "*...*.";
	lettersC5[104] = ".***..";

	lettersC5[105] = "*...*.";
	lettersC5[106] = "*...*.";
	lettersC5[107] = ".*.*..";
	lettersC5[108] = ".*.*..";
	lettersC5[109] = "..*...";

	lettersC5[110] = "*...*.";
	lettersC5[111] = "*...*.";
	lettersC5[112] = "*.*.*.";
	lettersC5[113] = "**.**.";
	lettersC5[114] = "*...*.";

	lettersC5[115] = "*...*.";
	lettersC5[116] = ".*.*..";
	lettersC5[117] = "..*...";
	lettersC5[118] = ".*.*..";
	lettersC5[119] = "*...*.";

	lettersC5[120] = "*...*.";
	lettersC5[121] = ".*.*..";
	lettersC5[122] = "..*...";
	lettersC5[123] = "..*...";
	lettersC5[124] = "..*...";

	lettersC5[125] = "*****.";
	lettersC5[126] = "...*..";
	lettersC5[127] = "..*...";
	lettersC5[128] = ".*....";
	lettersC5[129] = "*****.";

	lettersC5[130] = "......";
	lettersC5[131] = "......";
	lettersC5[132] = "......";
	lettersC5[133] = "......";
	lettersC5[134] = "......";
}

enum Font {
	fC1,
	fC5
};

char grid[100][100];

// Grid actions ------------------------------------------------------------

void fillGrid()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			grid[i][j] = '.';
		}
	}
}

void printGrid()
{
	for (int i = 1; i <= 60; i++) {
		for (int j = 1; j <= 60; j++) {
			std::printf("%c", grid[i][j]);
		}
		std::printf("\n");
	}
}

void addC1(int row, int col, std::string arg)
{
	for (int i = 0; i < arg.size(); i++) {
		if (col <= 0) {
			col++;
			continue;
		}
		if (arg[i] != ' ')
			grid[row][col] = arg[i];
		col++;
	}
}

void addC5(int row, int col, std::string arg)
{
	// TODO: Evaluate negative numbers and overplaced strings
	int letterNumber;
	std::string letterC5;
	int localRow, localCol = col;
	for (int i = 0; i < arg.size(); i++) {
		localRow = row;
		letterNumber = (arg[i] - 'A') * 5;
		for (int j = 0; j < 5; i++) {
			letterC5 = lettersC5[letterNumber + j];
			for (int k = 0; k < letterC5.size(); k++) {
				if (localCol > 60) {
					break;
				}
				if (localCol < 1) {
					localCol++;
					continue;
				}
				if (letterC5[k] != '.') {
					grid[localRow][localCol] = letterC5[k];
				}
			}
			localRow++;
		}
		localCol++;
	}
}

// Calculate spaces -------------------------------------------------------

int calculateRightColumn(Font font, std::string arg)
{
	int col = 0;
	int argSize = arg.size();
	if (font == fC1) {
		return 60 - argSize + 1;
	} else {
		return (60 - argSize * 6) + 1;
	}
	return col;
}

int calculateCenterColumn(Font font, std::string arg)
{
	int argSize = arg.size();
	if (font == fC1) {
		int col = (60 - argSize) / 2;
		if (argSize % 2 == 0 || argSize > 60) {
			return col + 1;
		} else {
			return col + 2;
		}
	} else {
		return ((60 - (6 * argSize)) / 2) + 1;
	}
	return 0;
}

// Commands ---------------------------------------------------------------

void P(Font font, int row, int col, std::string arg)
{
	if (font == fC1) {
		addC1(row, col, arg);
	} else {
		addC5(row, col, arg);
	}
}

void L(Font font, int row, std::string arg)
{
	if (font == fC1) {
		addC1(row, 1, arg);
	} else {
		addC5(row, 1, arg);
	}
}

void R(Font font, int row, std::string arg)
{
	int col = calculateRightColumn(font, arg);
	if (font == fC1) {
		addC1(row, col, arg);
	} else {
		addC5(row, col, arg);
	}
}

void C(Font font, int row, std::string arg)
{
	int col = calculateCenterColumn(font, arg);
	if (font == fC1) {
		addC1(row, col, arg);
	} else {
		addC5(row, col, arg);
	}
}

void readInput()
{
}

int main()
{
	fillGrid();
	setC5Letters();
	// TEST cases;
	P(fC1, 1, 5, "Hola, andamos representando, donde queremos");
	L(fC1, 2, "Andamos representando en la izquierda");
	R(fC1, 3, "Andamos representando en la derecha");
	C(fC1, 4, "Andamos representando en el centro");
	C(fC1, 5, "Andamos representando en el centroo");
	C(fC1, 6, "123456789012345678901234567890123456789012345678901234567890");
	C(fC1, 7, "0123456789012345678901234567890123456789012345678901234567890");
	C(fC1, 8, "90123456789012345678901234567890123456789012345678901234567890");
	C(fC5, 9, "Andamos representando en el centroo");
	C(fC1, 60, "890123456789012345678901234567890123456789012345678901234567890");
	C(fC1, 59, "7890123456789012345678901234567890123456789012345678901234567890");
	printGrid();
	return 0;
}
