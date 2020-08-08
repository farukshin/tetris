#ifndef _BOARD_
#define _BOARD_

#include "Pieces.h"

#define BOARD_LINE_WIGTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIGTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGING 20
#define MIN_HORIZONTAL_MARGING 20
#define PIECE_BLOCKS 5

class Board {
public:
    Board(Pieces *pPieces, int pScreenHeight);

    int getXPosInPixels(int pPos);
    int getYPosInPixels(int pPos);
    bool isFreeBlock(int pX, int pY);
    bool isPossibleMovement(int pX, int pY, int PPieces, int tpRotation);
    void storePiece(int pX, int pY, int pPieces, int pRotation);
    void deletePossibleLine();
    bool isGameOver();

private:
    enum {
        POS_FREE, POS_FILLED
    };

    int mBoard[BOARD_WIGTH][BOARD_HEIGHT];
    Pieces *mPieces;
    int mScreenHeight;
    void initBoard();
    void deleteLine(int pY);

};

#endif
