#ifndef _PIECES_
#define _PIECES_

class Pieces {
public:
    int getBlockType(int pPiices, int pRotation, int pX, int pY);
    int getXInitialPosition(int pPieces, int pRotation);
    int getYInitialPosition(int pPieces, int pRotation);

};

#endif
