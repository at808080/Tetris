#ifndef H_BOARD
#define H_BOARD

#include "Matrix.h"
#include "Tetrino.h"

enum CollisionDirection {
	Left = 0,
	Right = 1, 
	Down = 2
};
class Board :
    public Matrix
{
public:
	Board(int width_, int height_);
	void SetOccupant(Tetrino t_, bool b_);
	bool CheckForCollision(Tetrino t_, CollisionDirection d_);
	bool CheckForCollisionRotation(Tetrino t_);
private:

};

#endif