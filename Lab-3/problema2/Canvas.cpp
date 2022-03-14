#include "Canvas.h"

#include <cstdio>
#include <cstdlib>

Canvas::Canvas(int width, int height) {
  this->width = width;
  this->height = height;
  this->m = (char**)malloc(height * sizeof(char*));

  for (int i = 0; i < height; i++) {
    this->m[i] = (char*)malloc(width * sizeof(char));
  }
}

void Canvas::DrawCircle(int x, int y, int r, char ch) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if ((i - x) * (i - x) + (j - y) * (j - y) >= r * r - r &&
          (i - x) * (i - x) + (j - y) * (j - y) <= r * r + r)
        this->SetPoint(i, j, ch);
      else
        this->SetPoint(i, j, ' ');
    }
  }
}

void Canvas::FillCircle(int x, int y, int r, char ch) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
        this->SetPoint(i, j, ch);
      else
        this->SetPoint(i, j, ' ');
    }
  }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
  for (int i = left; i <= right; i++) {
    this->SetPoint(bottom, i, ch);
    this->SetPoint(top, i, ch);
  }

  for (int i = top; i <= bottom; i++) {
    this->SetPoint(i, right, ch);
    this->SetPoint(i, left, ch);
  }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (i >= top && i <= bottom && j >= left && j <= right)
        this->SetPoint(i, j, ch);
      else
        this->SetPoint(i, j, ' ');
    }
  }
}

void Canvas::SetPoint(int x, int y, char ch) { this->m[x][y] = ch; }

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
  int dx = abs(x2 - x1);
  int sx = x1 < x2 ? 1 : -1;
  int dy = -abs(y2 - y1);
  int sy = y1 < y2 ? 1 : -1;
  int error = dx + dy;

  while (true) {
    this->SetPoint(x1, y1, ch);

    if (x1 == x2 && y1 == y2) break;

    int e2 = 2 * error;

    if (e2 >= dy) {
      if (x1 == x2) break;
      error = error + dy;
      x1 = x1 + sx;
    }

    if (e2 <= dx) {
      if (y1 == y2) break;
      error = error + dx;
      y1 = y1 + sy;
    }
  }
}

void Canvas::Print() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", this->m[i][j]);
    }
    printf("\n");
  }
}
void Canvas::Clear() {
  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++) this->SetPoint(i, j, ' ');
}