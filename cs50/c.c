

int find_empty_row(int locked[][MAX_ROW]) {
  int i, j;

  for (i = 0; i < MAX_COL; i++) {
    for (j = 0; j < MAX_ROW; j++) {
      if (locked[i][j]) {
        break;
      }
    }
    if (j == MAX_ROW) {
      return i;
    }
  }

  return -1;
}
