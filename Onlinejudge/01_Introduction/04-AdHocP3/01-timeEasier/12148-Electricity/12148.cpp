#include <bits/stdc++.h>

using namespace std;

int get_days_in_month(int month, int year) {
  if (month == 2) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      return 29;
    } else {
      return 28;
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  } else {
    return 31;
  }
}

bool check_contiguous(int first_day, int first_month, int first_year,
                      int second_day, int second_month, int second_year) {
  int days_in_first_month = get_days_in_month(first_month, first_year);

  first_day++;
  if (first_day > days_in_first_month) {
    first_day = 1;
    first_month++;
    if (first_month > 12) {
      first_month = 1;
      first_year++;
    }
  }
  if (first_day == second_day && first_month == second_month &&
      first_year == second_year) {
    return true;
  }
  return false;
}

void solve(int n) {
  int i, sum, cont, first_day, first_month, first_year, first_kwh, second_day,
      second_month, second_year, second_kwh;
  sum = 0;
  cont = 0;
  scanf("%d%d%d%d", &first_day, &first_month, &first_year, &first_kwh);
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d%d%d", &second_day, &second_month, &second_year, &second_kwh);
    if (check_contiguous(first_day, first_month, first_year, second_day,
                         second_month, second_year)) {
      sum += second_kwh - first_kwh;
      cont++;
    }
    first_day = second_day;
    first_month = second_month;
    first_year = second_year;
    first_kwh = second_kwh;
  }
  printf("%d %d\n", cont, sum);
}

int main() {
  int n;
  while (scanf("%d", &n) && n != 0) {
    solve(n);
  }
  return 0;
}
