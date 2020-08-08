#include <Board.h>

Board::Board (Pieces *pPieces, int pScreenHeight) {
    mScreenHeight = pScreenHeight;
    mPieces = pPieces;
    initBoard();
}

void Board::initBoard() {
    for (int i=0; i<BOARD_WIGTH;i++)
        for (int j=0; j<BOARD_HEIGHT;j++)
            mBoard[i][j]=POS_FREE;
}

void Board::storePiece(int pX, int pY, int pPieces, int pRotation) {
    for (int i1=pX, i2=0; i1<pX+PIECE_BLOCKS; i1++, i2++)
        for (int j1=pY, j2=0; j1<pY+PIECE_BLOCKS; j1++, j2++)
            if (mPieces->getBlockType(pPieces, pRotation, j2, i2)!=0)
                mBoard[i1][j1] = POS_FILLED;
}

bool Board::isGameOver() {
    for (int i=0; i<BOARD_WIGTH; i++)
        if (mBoard[i][0]==POS_FILLED)
            return true;

    return false;
}

void Board::deleteLine(int pY) {
    for (int j=pY; j>0;j--)
        for (int i=0; i<BOARD_WIGTH; i++)
            mBoard[i][j] = mBoard[i][j-1];
}

void Board::deletePossibleLine() {
    for (int j = 0; j < BOARD_HEIGHT; j++)
    {
        int i = 0;
        while (i < BOARD_WIGTH)
        {
            if (mBoard[i][j] != POS_FILLED)
                break;
            i++;
        }

        if (i == BOARD_WIGTH)
            deleteLine(j);
    }
}

bool Board::isFreeBlock(int pX, int pY) {
    return mBoard[pX][pY] == POS_FREE;
}


int Board::getXPosInPixels(int pPos)
{
    return  ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIGTH / 2))) + (pPos * BLOCK_SIZE));
}

int Board::getYPosInPixels(int pPos)
{
    return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}

bool Board::isPossibleMovement(int pX, int pY, int pPiece, int pRotation)
{
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            if (i1 < 0 || i1 > BOARD_WIGTH  - 1	|| j1 > BOARD_HEIGHT - 1)
                if (mPieces->getBlockType(pPiece, pRotation, j2, i2) != 0)
                    return false;

            if (j1 >= 0)
                if ((mPieces->getBlockType(pPiece, pRotation, j2, i2) != 0) && (!isFreeBlock(i1, j1)))
                    return false;

        }

    return true;
}
