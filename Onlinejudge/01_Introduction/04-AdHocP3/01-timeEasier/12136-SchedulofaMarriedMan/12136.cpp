#include <bits/stdc++.h>

using namespace std;

void mark_hour(int h, int m, bool *calendar) {
  int position;
  position = (h * 100) + m;
  calendar[position] = 1;
}

void mark_time(int h1, int m1, int h2, int m2, bool *calendar) {
  while (h1 != h2 || m1 != m2) {
    mark_hour(h1, m1, calendar);
    m1++;
    if (m1 == 60) {
      m1 = 0;
      h1++;
      if (h1 == 24) {
        h1 = 0;
      }
    }
  }
  mark_hour(h2, m2, calendar);
}

bool check_free(int h1, int m1, int h2, int m2, bool *calendar) {
  int position;
  while (h1 != h2 || m1 != m2) {
    position = (h1 * 100) + m1;
    if (calendar[position] == 1) {
      return false;
    }
    m1++;
    if (m1 == 60) {
      m1 = 0;
      h1++;
      if (h1 == 24) {
        h1 = 0;
      }
    }
  }
  position = (h2 * 100) + m2;
  if (calendar[position] == 1) {
    return false;
  }
  return true;
}

void solve(int h1, int m1, int h2, int m2, bool *calendar, int test_case) {
  printf("Case %d: %s Meeting\n", test_case,
         check_free(h1, m1, h2, m2, calendar) ? "Hits" : "Mrs");
}

void clear_calendar(bool *calendar) {
  for (int i = 0; i < 3600; i++) {
    calendar[i] = 0;
  }
}

int main() {
  int n, h1, m1, h2, m2, h3, m3, h4, m4, test_case = 1;
  bool calendar[3600] = {0};
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d:%d %d:%d %d:%d %d:%d", &h1, &m1, &h2, &m2, &h3, &m3, &h4, &m4);
    mark_time(h1, m1, h2, m2, calendar);
    solve(h3, m3, h4, m4, calendar, test_case);
    test_case++;
    clear_calendar(calendar);
  }
  return 0;
}
