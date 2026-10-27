#include <iostream>

// Practice 10 — Freesia Garcia
// CIS 5 Week 10 · Gradebook tools

void printScores(const int scores[], int n) {
  for (int i = 0; i < n; i++) std::cout << scores[i] << " ";
  std::cout << "\n";
}

void curve(int scores[], int n, int points) {
  for (int i = 0; i < n; i++) {
    scores[i] += points;
  }
}

void minMax(const int scores[], int n, int& lo, int& hi) {
  lo = scores[0];
  hi = scores[0];

  for (int i=1; i < n; i++) {
    if (scores[i] < lo)
    lo = scores[i];

    if (scores[i] > hi)
    hi = scores [i];
  }
}

bool findScore(const int scores[], int n, int target, int* where) {
  for (int i = 0; i < n; i++) {
    if (scores[i] == target) {
      if (where != nullptr) {
        *where = i;
      }

      return true;
      }
    }

  return false;
}

int main() {
  int scores[5] = {72, 88, 95, 60, 81};
  const int N = 5;

  std::cout << "Before: ";
  printScores(scores, N);

  int lo = 0, hi = 0;
  minMax(scores, N, lo, hi);
  std::cout << "Low: " << lo << "  High: " << hi << "\n";

  curve(scores, N, 5);
  std::cout << "After curve +5: ";
  printScores(scores, N);

  int at = -1;
  if (findScore(scores, N, 100, &at)) std::cout << "100 found at index " << at << "\n";
  if (!findScore(scores, N, 50, nullptr)) std::cout << "50 not found\n";
  return 0;
}
