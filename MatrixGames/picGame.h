#ifndef PICGAME_H_
#define PICGAME_H_

void PictureGame();
int GetSizeFromUser();
void BuildMatrix(int* mat, int size);
void UserOptions(int* choice);
void RotateCW(int* mat, int rows, int cols);
void RotateCCW(int* mat, int rows, int cols);
void FlipHorizontal(int* mat, int rows, int cols);
void FlipVertical(int* mat, int rows, int cols);

#endif
