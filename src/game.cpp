#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <raymath.h>



class Particle
{
    private:
        Color color;
    public:
        static Vector2 dimension; 
        Vector2 vel;
        Vector2 position;

    void Setup(Color _color, Vector2 _position)
    {
        color = _color;
        position = _position;
    }

    void Update()
    {
        position = Vector2Add(vel, position);
    }

    void Draw()
    {
        DrawRectangleV(position, dimension, color);
    }
};


#define PARTICLE_NUM 50

Particle particles[PARTICLE_NUM];
Vector2 Particle::dimension = Vector2 {5, 5};

time_t t;
void Setup()
{
    printf("Setup!\n");
    for (Particle &p : particles)
    {
        p.Setup(Color {255, 0, 0, 255}, Vector2 {(float)GetRandomValue(0, GetRenderWidth()), (float)GetRandomValue(0, GetRenderHeight())});
    }
}

void Update()
{
    for (Particle &p : particles)
    {
        for (Particle &k : particles)
        {
            float r = Vector2Distance(p.position, k.position);
            if (r > 0)
            {
                p.vel = Vector2Add(p.vel, Vector2Scale((Vector2Subtract(k.position, p.position)), 1 / r));
            }
        }
        p.Update();
    }
}

void Draw()
{
    ClearBackground(BLACK);
    for (Particle &p : particles)
    {
        p.Draw();
    }
}