#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

struct GlobalStatus {
  int contestant;
  int solvedProblems;
  int penalty;
};

struct UserStatus {
  char status;
  int attempts;
  int penalty;

  void calculatePenalty(int time) { penalty = (attempts * 20) + time; }
};

struct ProblemStatus {
  int contestant;
  int problem;
  int time;
  char status;
};

vector<ProblemStatus> problemEntries;
vector<vector<UserStatus>> userScoreboard;
vector<GlobalStatus> globalScoreboard;

void clearData(int cantProblems) {
  for (int i = 0; i < cantProblems; i++) {
    problemEntries[i] = {0};
  }
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 11; j++) {
      userScoreboard[i][j] = {0};
    }
  }
  for (int i = 0; i < 101; i++) {
    globalScoreboard[i] = {0};
  }
  problemEntries.clear();
  userScoreboard.clear();
  globalScoreboard.clear();
}

bool customOrder(GlobalStatus gs1, GlobalStatus gs2) {
  if (gs1.solvedProblems > gs2.solvedProblems) {
    return true;
  } else if (gs1.solvedProblems < gs2.solvedProblems) {
    return false;
  } else {
    if (gs1.penalty < gs2.penalty) {
      return true;
    } else if (gs1.penalty > gs2.penalty) {
      return false;
    } else {
      if (gs1.contestant < gs2.contestant) {
        return true;
      } else {
        return false;
      }
    }
  }
}

void calculateScoreboard(int numberProblems) {
  GlobalStatus globalStatus = {0};
  bool participation = false;
  for (ProblemStatus problemStatus : problemEntries) {
    if (userScoreboard[problemStatus.contestant][problemStatus.problem]
            .status != 'C') {
      if (problemStatus.status == 'I') {
        userScoreboard[problemStatus.contestant][problemStatus.problem]
            .attempts++;
      } else if (problemStatus.status == 'C') {
        userScoreboard[problemStatus.contestant][problemStatus.problem].status =
            problemStatus.status;
        userScoreboard[problemStatus.contestant][problemStatus.problem]
            .calculatePenalty(problemStatus.time);
      }
      userScoreboard[problemStatus.contestant][problemStatus.problem].status =
          problemStatus.status;
    }
  }
  for (int i = 0; i < 101; i++) {
    participation = false;
    globalStatus.contestant = i;
    for (int j = 0; j < 11; j++) {

      if (userScoreboard[i][j].status == 'C') {
        globalStatus.solvedProblems++;
        globalStatus.penalty += userScoreboard[i][j].penalty;
        participation = true;
      } else if (userScoreboard[i][j].status == 'I' ||
                 userScoreboard[i][j].status == 'E' ||
                 userScoreboard[i][j].status == 'R' ||
                 userScoreboard[i][j].status == 'U') {
        participation = true;
      }
    }
    if (participation) {
      globalScoreboard.push_back(globalStatus);
    }
    globalStatus = {0};
  }
  sort(globalScoreboard.begin(), globalScoreboard.end(), customOrder);
}

void printOutput() {
  for (GlobalStatus gb : globalScoreboard) {
    printf("%d %d %d\n", gb.contestant, gb.solvedProblems, gb.penalty);
  }
}

void readInput() {
  userScoreboard.reserve(110);
  for (int i = 0; i < 110; i++) {
    userScoreboard[i].reserve(15);
  }
  globalScoreboard.reserve(110);

  int n;
  scanf("%d", &n);
  getchar();
  getchar();
  int cont = 0;
  char input[100];
  int contestant, problem, time;
  ProblemStatus problemStatus = {0};
  while (n--) {
    cont = 0;
    while (fgets(input, sizeof(input), stdin) != NULL) {
      if (input[0] == '\n') {
        break;
      }
      sscanf(input, "%d%d%d %c", &problemStatus.contestant,
             &problemStatus.problem, &problemStatus.time,
             &problemStatus.status);
      problemEntries.push_back(problemStatus);
      problemStatus = {0};
      cont++;
    }
    calculateScoreboard(cont);
    printOutput();
    clearData(cont);
    if (n >= 1) {
      printf("\n");
    }
  }
}

int main() {
  readInput();
  return 0;
}
