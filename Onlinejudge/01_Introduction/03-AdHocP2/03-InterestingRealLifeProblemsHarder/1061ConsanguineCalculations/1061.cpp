#include <bits/stdc++.h>

using namespace std;

void getAlleles(char blod_type[], char *allele_1, char *allele_2) {
  if (blod_type[0] == 'A') {
    if (blod_type[1] == 'B') {
      *allele_1 = 'A';
      *allele_2 = 'B';
    } else {
      *allele_1 = 'A';
      *allele_2 = 'O';
    }
  } else if (blod_type[0] == 'B') {
    *allele_1 = 'B';
    *allele_2 = 'O';
  } else if (blod_type[0] == 'O') {
    *allele_1 = 'O';
    *allele_2 = 'O';
  }
}

char getRh(char blod_type[]) {
  if (isalpha(blod_type[1])) {
    return blod_type[2];
  }
  return blod_type[1];
}

void calculateChildABO(char parent_1[], char parent_2[], bool *is_a,
                       bool *is_ab, bool *is_b, bool *is_o) {
  char allele_1 = ' ';
  char allele_2 = ' ';
  char allele_3 = ' ';
  char allele_4 = ' ';
  // Get Alleles of both parents
  getAlleles(parent_1, &allele_1, &allele_2);
  getAlleles(parent_2, &allele_3, &allele_4);

  // Searching for A
  if ((allele_1 == 'A' && allele_3 == 'A') ||
      (allele_1 == 'A' && allele_3 == 'O') ||
      (allele_2 == 'A' && allele_3 == 'A') ||
      (allele_2 == 'A' && allele_3 == 'O') ||
      (allele_1 == 'A' && allele_4 == 'A') ||
      (allele_1 == 'A' && allele_4 == 'O') ||
      (allele_2 == 'A' && allele_4 == 'A') ||
      (allele_2 == 'A' && allele_4 == 'O') ||
      (allele_1 == 'O' && allele_3 == 'A') ||
      (allele_2 == 'O' && allele_3 == 'A') ||
      (allele_1 == 'O' && allele_4 == 'A') ||
      (allele_2 == 'O' && allele_4 == 'A')) {
    *is_a = 1;
  }

  // Searching for AB
  if ((allele_1 == 'A' && allele_3 == 'B') ||
      (allele_2 == 'A' && allele_3 == 'B') ||
      (allele_1 == 'A' && allele_4 == 'B') ||
      (allele_2 == 'A' && allele_4 == 'B') ||
      (allele_1 == 'B' && allele_3 == 'A') ||
      (allele_2 == 'B' && allele_3 == 'A') ||
      (allele_1 == 'B' && allele_4 == 'A') ||
      (allele_2 == 'B' && allele_4 == 'A')) {
    *is_ab = 1;
  }

  // Searching for B
  if ((allele_1 == 'B' && allele_3 == 'B') ||
      (allele_1 == 'B' && allele_3 == 'O') ||
      (allele_2 == 'B' && allele_3 == 'B') ||
      (allele_2 == 'B' && allele_3 == 'O') ||
      (allele_1 == 'B' && allele_4 == 'B') ||
      (allele_1 == 'B' && allele_4 == 'O') ||
      (allele_2 == 'B' && allele_4 == 'B') ||
      (allele_2 == 'B' && allele_4 == 'O') ||
      (allele_1 == 'O' && allele_3 == 'B') ||
      (allele_2 == 'O' && allele_3 == 'B') ||
      (allele_1 == 'O' && allele_4 == 'B') ||
      (allele_2 == 'O' && allele_4 == 'B')) {
    *is_b = 1;
  }

  // Searching for O
  if ((allele_1 == 'O' && allele_3 == 'O') ||
      (allele_2 == 'O' && allele_3 == 'O') ||
      (allele_1 == 'O' && allele_4 == 'O') ||
      (allele_2 == 'O' && allele_4 == 'O')) {
    *is_o = 1;
  }
}

void calculateChildBlod(char parent_1[], char parent_2[]) {
  // Define the variables
  char rh_p_1, rh_p_2;
  bool is_a, is_ab, is_b, is_o;
  bool print_positive;

  is_a = 0;
  is_ab = 0;
  is_b = 0;
  is_o = 0;

  // Get Rh of both parents;
  print_positive = false;
  rh_p_1 = getRh(parent_1);
  rh_p_2 = getRh(parent_2);
  if (rh_p_1 == '+' or rh_p_2 == '+') {
    print_positive = true;
  }

  // Caculate ABO of the child
  calculateChildABO(parent_1, parent_2, &is_a, &is_ab, &is_b, &is_o);

  bool printed = false;

  int count_founded = 0;

  count_founded = is_a + is_ab + is_b + is_o;

  if (!is_a && !is_ab && !is_b && !is_o) {
    printf("IMPOSSIBLE\n");
  } else {
    if (count_founded > 1 || print_positive) {
      printf("{");
    }
    if (is_o) {
      printf("O-");
      if (print_positive) {
        printf(", O+");
      }
      printed = true;
    }

    if (is_ab) {
      if (printed) {
        printf(", ");
        printed = false;
      }
      printf("AB-");
      if (print_positive) {
        printf(", AB+");
      }
      printed = true;
    }
    if (is_b) {
      if (printed) {
        printf(", ");
        printed = false;
      }
      printf("B-");
      if (print_positive) {
        printf(", B+");
      }
      printed = true;
    }
    if (is_a) {
      if (printed) {
        printf(", ");
        printed = false;
      }
      printf("A-");
      if (print_positive) {
        printf(", A+");
      }
      printed = true;
    }
    if (count_founded > 1 || print_positive) {
      printf("}");
    }
    printf("\n");
  }
}

bool checkIfCombWorks(char child_blood[], bool is_a, bool is_ab, bool is_b,
                      bool is_o) {
  if (child_blood[0] == 'A' && child_blood[1] == 'B') {
    if (is_ab) {
      return true;
    }
  } else if (child_blood[0] == 'A') {
    if (is_a) {
      return true;
    }
  } else if (child_blood[0] == 'B') {
    if (is_b) {
      return true;
    }
  } else if (child_blood[0] == 'O') {
    if (is_o) {
      return true;
    }
  }

  return false;
}

void calculateParentABO(char parent_blood[], char child_blood[], bool *is_a,
                        bool *is_ab, bool *is_b, bool *is_o) {
  bool a, ab, b, o;
  a = 0;
  ab = 0;
  b = 0;
  o = 0;

  char a_c[2] = {'A'};
  char ab_c[2] = {'A', 'B'};
  char b_c[2] = {'B'};
  char o_c[2] = {'O'};

  // a combinations
  calculateChildABO(parent_blood, a_c, &a, &ab, &b, &o);
  if (checkIfCombWorks(child_blood, a, ab, b, o)) {
    *is_a = 1;
  }
  a = ab = b = o = 0;
  calculateChildABO(parent_blood, ab_c, &a, &ab, &b, &o);
  if (checkIfCombWorks(child_blood, a, ab, b, o)) {
    *is_ab = 1;
  }
  a = ab = b = o = 0;
  calculateChildABO(parent_blood, b_c, &a, &ab, &b, &o);
  if (checkIfCombWorks(child_blood, a, ab, b, o)) {
    *is_b = 1;
  }
  a = ab = b = o = 0;
  calculateChildABO(parent_blood, o_c, &a, &ab, &b, &o);
  if (checkIfCombWorks(child_blood, a, ab, b, o)) {
    *is_o = 1;
  }
}

void searchParentABO(char parent[], char child[]) {
  char rh_p, rh_c;
  bool is_a, is_ab, is_b, is_o;
  bool print_negative;
  is_a = 0;
  is_ab = 0;
  is_b = 0;
  is_o = 0;
  print_negative = true;

  rh_p = getRh(parent);
  rh_c = getRh(child);

  calculateParentABO(parent, child, &is_a, &is_ab, &is_b, &is_o);

  if (rh_c == '+' && rh_p == '-') {
    print_negative = false;
  }

  bool printed = false;

  int count_founded = 0;

  count_founded = is_a + is_ab + is_b + is_o;

  if (!is_a && !is_ab && !is_b && !is_o) {
    printf("IMPOSSIBLE ");
  } else {
    if (count_founded > 1 || print_negative) {
      printf("{");
    }
    if (is_o) {
      if (print_negative) {
        printf("O-, ");
      }
      printf("O+");
      printed = true;
    }
    if (is_ab) {
      if (printed) {
        printf(", ");
        printed = false;
      }
      if (print_negative) {
        printf("AB-, ");
      }
      printf("AB+");
      printed = true;
    }
    if (is_b) {
      if (printed) {
        printf(", ");
        printed = false;
      }
      if (print_negative) {
        printf("B-, ");
      }
      printf("B+");
      printed = true;
    }
    if (is_a) {
      if (printed) {
        printf(", ");
        printed = false;
      }
      if (print_negative) {
        printf("A-, ");
      }
      printf("A+");
      printed = true;
    }

    if (count_founded > 1 || print_negative) {
      printf("}");
    }

    printf(" ");
  }
}

void solve() {
  char p_1[5], p_2[5], c[5];
  int case_number = 1;
  while (scanf("%s%s%s", p_1, p_2, c) != EOF && p_1[0] != 'E') {

    printf("Case %d: ", case_number++);

    if (p_1[0] == '?') {
      searchParentABO(p_2, c);
      printf("%s %s\n", p_2, c);
    } else if (p_2[0] == '?') {
      printf("%s ", p_1);
      searchParentABO(p_1, c);
      printf("%s\n", c);
    } else {
      printf("%s %s ", p_1, p_2);
      calculateChildBlod(p_1, p_2);
    }
  }
}

int main() {
  solve();
  return 0;
}
