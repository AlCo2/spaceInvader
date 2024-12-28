#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

class Entity{
protected:
    int width;
    int hight;
    int x;
    int y;
public:
    Entity(int width, int hight, int x, int y);
    int getWidth();
    int getHight();
    int getY();
    int getX();
};

#endif // ENTITY_H_INCLUDED
