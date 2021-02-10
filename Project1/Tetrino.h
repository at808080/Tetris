#ifndef H_TETRINO
#define H_TETRINO

#include "Matrix.h"
#include "Vector2i.h"
#include "InputHandler.h"
class Tetrino :
    public Matrix
{
public:

    Tetrino(int width_, int height_, Vector2i pos_);
    Vector2i GetPos();
    void SetPos(Vector2i pos_);

    void Down();
    void Left();
    void Right();

    void Update();
private:
    Vector2i m_Position;
};

#endif