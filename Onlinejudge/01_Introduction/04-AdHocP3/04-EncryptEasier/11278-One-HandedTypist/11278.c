#include <stdio.h>
#include <string.h>

int qwerty_keys[1000];

void fill_qwerty_keys() {
  qwerty_keys['`'] = '`';
  qwerty_keys['1'] = '1';
  qwerty_keys['2'] = '2';
  qwerty_keys['3'] = '3';
  qwerty_keys['4'] = 'q';
  qwerty_keys['5'] = 'j';
  qwerty_keys['6'] = 'l';
  qwerty_keys['7'] = 'm';
  qwerty_keys['8'] = 'f';
  qwerty_keys['9'] = 'p';
  qwerty_keys['0'] = '/';
  qwerty_keys['-'] = '[';
  qwerty_keys['='] = ']';
  qwerty_keys['q'] = '4';
  qwerty_keys['w'] = '5';
  qwerty_keys['e'] = '6';
  qwerty_keys['r'] = '.';
  qwerty_keys['t'] = 'o';
  qwerty_keys['y'] = 'r';
  qwerty_keys['u'] = 's';
  qwerty_keys['i'] = 'u';
  qwerty_keys['o'] = 'y';
  qwerty_keys['p'] = 'b';
  qwerty_keys['['] = ';';
  qwerty_keys[']'] = '=';
  qwerty_keys['\\'] = '\\';
  qwerty_keys['a'] = '7';
  qwerty_keys['s'] = '8';
  qwerty_keys['d'] = '9';
  qwerty_keys['f'] = 'a';
  qwerty_keys['g'] = 'e';
  qwerty_keys['h'] = 'h';
  qwerty_keys['j'] = 't';
  qwerty_keys['k'] = 'd';
  qwerty_keys['l'] = 'c';
  qwerty_keys[';'] = 'k';
  qwerty_keys['\''] = '-';
  qwerty_keys['z'] = '0';
  qwerty_keys['x'] = 'z';
  qwerty_keys['c'] = 'x';
  qwerty_keys['v'] = ',';
  qwerty_keys['b'] = 'i';
  qwerty_keys['n'] = 'n';
  qwerty_keys['m'] = 'w';
  qwerty_keys[','] = 'v';
  qwerty_keys['.'] = 'g';
  qwerty_keys['/'] = '\'';

  qwerty_keys['~'] = '~';
  qwerty_keys['!'] = '!';
  qwerty_keys['@'] = '@';
  qwerty_keys['#'] = '#';
  qwerty_keys['$'] = 'Q';
  qwerty_keys['%'] = 'J';
  qwerty_keys['^'] = 'L';
  qwerty_keys['&'] = 'M';
  qwerty_keys['*'] = 'F';
  qwerty_keys['('] = 'P';
  qwerty_keys[')'] = '?';
  qwerty_keys['_'] = '{';
  qwerty_keys['+'] = '}';
  qwerty_keys['Q'] = '$';
  qwerty_keys['W'] = '%';
  qwerty_keys['E'] = '^';
  qwerty_keys['R'] = '>';
  qwerty_keys['T'] = 'O';
  qwerty_keys['Y'] = 'R';
  qwerty_keys['U'] = 'S';
  qwerty_keys['I'] = 'U';
  qwerty_keys['O'] = 'Y';
  qwerty_keys['P'] = 'B';
  qwerty_keys['{'] = ':';
  qwerty_keys['}'] = '+';
  qwerty_keys['|'] = '|';
  qwerty_keys['A'] = '&';
  qwerty_keys['S'] = '*';
  qwerty_keys['D'] = '(';
  qwerty_keys['F'] = 'A';
  qwerty_keys['G'] = 'E';
  qwerty_keys['H'] = 'H';
  qwerty_keys['J'] = 'T';
  qwerty_keys['K'] = 'D';
  qwerty_keys['L'] = 'C';
  qwerty_keys[':'] = 'K';
  qwerty_keys['"'] = '_';
  qwerty_keys['Z'] = ')';
  qwerty_keys['X'] = 'Z';
  qwerty_keys['C'] = 'X';
  qwerty_keys['V'] = '<';
  qwerty_keys['B'] = 'I';
  qwerty_keys['N'] = 'N';
  qwerty_keys['M'] = 'W';
  qwerty_keys['<'] = 'V';
  qwerty_keys['>'] = 'G';
  qwerty_keys['?'] = '"';

  qwerty_keys[' '] = ' ';
}

void solve(char *str) {
  int i, str_len;
  str_len = strlen(str);
  for (i = 0; i < str_len; i++) {
    printf("%c", qwerty_keys[str[i]]);
  }
  printf("\n");
}

int main() {
  fill_qwerty_keys();
  char str[1005];
  while (fgets(str, sizeof(str), stdin) != NULL) {
    str[strlen(str) - 1] = '\0';
    solve(str);
  }
  return 0;
}
