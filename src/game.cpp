#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <raymath.h>
#include <vector>

class Particle
{
    private:
        Color color;
    public:
        static Vector2 dimension; 
        Vector2 vel;
        Vector2 position;

    Particle(Color color, Vector2 position) :
        color(color),
        position(position)
    {}

    void Update()
    {
        position = Vector2Add(vel, position);
    }

    void Draw()
    {
        //DrawPixelV(position, color);
        DrawRectangleV(position, dimension, color);
    }
};

Vector2 Particle::dimension = Vector2 {5, 5};


struct Relation
{
    unsigned short target;
    float strength;
    Relation(unsigned short target, float strength) :
        target(target),
        strength(strength)
    {}
};

class Type;
std::vector<Type*> container;
class Type
{
    public:
    unsigned short id;
    unsigned int number;
    Color color;
    
    std::vector<Particle*> particles;
    std::vector<Relation*> relations;
    
    Type(unsigned short id, unsigned int number, Color color) :
        id(id),
        number(number),
        color(color)
    {
        for (unsigned int i = 0; i < number; i++)
        {
            particles.push_back(new Particle(color, Vector2 {(float)GetRandomValue(0, GetRenderWidth()), (float)GetRandomValue(0, GetRenderHeight())}));
        }
        printf("Type Pointer: %p\n", this);
    }

    void addRelation(unsigned short _target, float _strength)
    {
        relations.push_back(new Relation(_target, _strength));
    }

    void Update()
    {
        for (Particle *p : particles)
        {
            p->Update();
        }
    }

    void Draw()
    {
        for (Particle *p : particles)
        {
            p->Draw();
        }
    }
};


time_t t;
void Setup()
{
    container.push_back(new Type(0, 50, RED));
    container.push_back(new Type(0, 20, GREEN));
    container.push_back(new Type(0, 20, BLUE));
}

void Update()
{
    for (Type *t : container)
    {
        t->Update();
    }
}

void Draw()
{
    ClearBackground(BLACK);
    for (Type *t : container)
    {
        t->Draw();
    }
}