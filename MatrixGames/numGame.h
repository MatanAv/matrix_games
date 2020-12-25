#ifndef NUMGAME_H_
#define NUMGAME_H_

#define SHUFFLE_COUNT 30

void NumberGame();
void GetRowsAndColsFromUser(int* rows, int* cols);
int* CreateBoard(int* mat, int rows, int cols);
int* ShuffleBoard(int* mat, int rows, int cols, int* zeroP);
int* MakeStep(int* mat, int rows, int cols, int* zeroP, int* checkStep);
int CheckAscendingOrder(const int* mat, int size);

#endif
